 /*
 * Copyright (c) 2005 The University of Notre Dame. All Rights Reserved.
 *
 * The University of Notre Dame grants you ("Licensee") a
 * non-exclusive, royalty free, license to use, modify and
 * redistribute this software in source and binary code form, provided
 * that the following conditions are met:
 *
 * 1. Acknowledgement of the program authors must be made in any
 *    publication of scientific results based in part on use of the
 *    program.  An acceptable form of acknowledgement is citation of
 *    the article in which the program was described (Matthew
 *    A. Meineke, Charles F. Vardeman II, Teng Lin, Christopher
 *    J. Fennell and J. Daniel Gezelter, "OOPSE: An Object-Oriented
 *    Parallel Simulation Engine for Molecular Dynamics,"
 *    J. Comput. Chem. 26, pp. 252-271 (2005))
 *
 * 2. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 3. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 * This software is provided "AS IS," without a warranty of any
 * kind. All express or implied conditions, representations and
 * warranties, including any implied warranty of merchantability,
 * fitness for a particular purpose or non-infringement, are hereby
 * excluded.  The University of Notre Dame and its licensors shall not
 * be liable for any damages suffered by licensee as a result of
 * using, modifying or distributing the software or its
 * derivatives. In no event will the University of Notre Dame or its
 * licensors be liable for any lost revenue, profit or data, or for
 * direct, indirect, special, consequential, incidental or punitive
 * damages, however caused and regardless of the theory of liability,
 * arising out of the use of or inability to use software, even if the
 * University of Notre Dame has been advised of the possibility of
 * such damages.
 */
 
 /**
  * @file ForceManager.cpp
  * @author tlin
  * @date 11/09/2004
  * @time 10:39am
  * @version 1.0
  */

#include "brains/ForceManager.hpp"
#include "primitives/Molecule.hpp"
#include "UseTheForce/doForces_interface.h"
#include "utils/simError.h"
namespace oopse {

void ForceManager::calcForces(bool needPotential, bool needStress) {

    if (!info_->isFortranInitialized()) {
        info_->update();
    }

    preCalculation();
    
    calcShortRangeInteraction();

    calcLongRangeInteraction(needPotential, needStress);

    postCalculation();
        
}

void ForceManager::preCalculation() {
    SimInfo::MoleculeIterator mi;
    Molecule* mol;
    Molecule::AtomIterator ai;
    Atom* atom;
    Molecule::RigidBodyIterator rbIter;
    RigidBody* rb;
    
    // forces are zeroed here, before any are accumulated.
    // NOTE: do not rezero the forces in Fortran.
    for (mol = info_->beginMolecule(mi); mol != NULL; mol = info_->nextMolecule(mi)) {
        for(atom = mol->beginAtom(ai); atom != NULL; atom = mol->nextAtom(ai)) {
            atom->zeroForcesAndTorques();
        }
        
        //change the positions of atoms which belong to the rigidbodies
        for (rb = mol->beginRigidBody(rbIter); rb != NULL; rb = mol->nextRigidBody(rbIter)) {
            rb->zeroForcesAndTorques();
        }        
    }
    
}

void ForceManager::calcShortRangeInteraction() {
    Molecule* mol;
    RigidBody* rb;
    Bond* bond;
    Bend* bend;
    Torsion* torsion;
    SimInfo::MoleculeIterator mi;
    Molecule::RigidBodyIterator rbIter;
    Molecule::BondIterator bondIter;;
    Molecule::BendIterator  bendIter;
    Molecule::TorsionIterator  torsionIter;

    //calculate short range interactions    
    for (mol = info_->beginMolecule(mi); mol != NULL; mol = info_->nextMolecule(mi)) {

        //change the positions of atoms which belong to the rigidbodies
        for (rb = mol->beginRigidBody(rbIter); rb != NULL; rb = mol->nextRigidBody(rbIter)) {
            rb->updateAtoms();
        }

        for (bond = mol->beginBond(bondIter); bond != NULL; bond = mol->nextBond(bondIter)) {
            bond->calcForce();
        }

        for (bend = mol->beginBend(bendIter); bend != NULL; bend = mol->nextBend(bendIter)) {
            bend->calcForce();
        }

        for (torsion = mol->beginTorsion(torsionIter); torsion != NULL; torsion = mol->nextTorsion(torsionIter)) {
            torsion->calcForce();
        }

    }
    
    double  shortRangePotential = 0.0;
    for (mol = info_->beginMolecule(mi); mol != NULL; mol = info_->nextMolecule(mi)) {
        shortRangePotential += mol->getPotential();
    }

    Snapshot* curSnapshot = info_->getSnapshotManager()->getCurrentSnapshot();
    curSnapshot->statData[Stats::SHORT_RANGE_POTENTIAL] = shortRangePotential;
}

void ForceManager::calcLongRangeInteraction(bool needPotential, bool needStress) {
    Snapshot* curSnapshot;
    DataStorage* config;
    double* frc;
    double* pos;
    double* trq;
    double* A;
    double* electroFrame;
    double* rc;
    
    //get current snapshot from SimInfo
    curSnapshot = info_->getSnapshotManager()->getCurrentSnapshot();

    //get array pointers
    config = &(curSnapshot->atomData);
    frc = config->getArrayPointer(DataStorage::dslForce);
    pos = config->getArrayPointer(DataStorage::dslPosition);
    trq = config->getArrayPointer(DataStorage::dslTorque);
    A   = config->getArrayPointer(DataStorage::dslAmat);
    electroFrame = config->getArrayPointer(DataStorage::dslElectroFrame);

    //calculate the center of mass of cutoff group
    SimInfo::MoleculeIterator mi;
    Molecule* mol;
    Molecule::CutoffGroupIterator ci;
    CutoffGroup* cg;
    Vector3d com;
    std::vector<Vector3d> rcGroup;
    
    if(info_->getNCutoffGroups() > 0){

    for (mol = info_->beginMolecule(mi); mol != NULL; mol = info_->nextMolecule(mi)) {
        for(cg = mol->beginCutoffGroup(ci); cg != NULL; cg = mol->nextCutoffGroup(ci)) {
            cg->getCOM(com);
            rcGroup.push_back(com);
        }
    }// end for (mol)
       
        rc = rcGroup[0].getArrayPointer();
    } else {
        // center of mass of the group is the same as position of the atom  if cutoff group does not exist
        rc = pos;
    }
  
    //initialize data before passing to fortran
    double longRangePotential = 0.0;
    Mat3x3d tau;
    short int passedCalcPot = needPotential;
    short int passedCalcStress = needStress;
    int isError = 0;

    doForceLoop( pos,
            rc,
            A,
            electroFrame,
            frc,
            trq,
            tau.getArrayPointer(),
            &longRangePotential, 
            &passedCalcPot,
            &passedCalcStress,
            &isError );

    if( isError ){
        sprintf( painCave.errMsg,
             "Error returned from the fortran force calculation.\n" );
        painCave.isFatal = 1;
        simError();
    }

    //store the tau and long range potential    
    curSnapshot->statData[Stats::LONG_RANGE_POTENTIAL] = longRangePotential;
    curSnapshot->statData.setTau(tau);
}


void ForceManager::postCalculation() {
    SimInfo::MoleculeIterator mi;
    Molecule* mol;
    Molecule::RigidBodyIterator rbIter;
    RigidBody* rb;
    
    // collect the atomic forces onto rigid bodies
    for (mol = info_->beginMolecule(mi); mol != NULL; mol = info_->nextMolecule(mi)) {
        for (rb = mol->beginRigidBody(rbIter); rb != NULL; rb = mol->nextRigidBody(rbIter)) {
            rb->calcForcesAndTorques();
        }
    }

}

} //end namespace oopse