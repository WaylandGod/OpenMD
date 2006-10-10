/* Copyright (c) 2006 The University of Notre Dame. All Rights Reserved.
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
 *
 *
 *  randomBuilder.cpp
 *
 *  Created by Charles F. Vardeman II on 10 Apr 2006.
 *  @author  Charles F. Vardeman II
 *  @version $Id: randomBuilder.cpp,v 1.6 2006-10-10 18:34:12 gezelter Exp $
 *
 */


#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <fstream>

#include "applications/randomBuilder/randomBuilderCmd.h"
#include "lattice/LatticeFactory.hpp"
#include "utils/MoLocator.hpp"
#include "lattice/Lattice.hpp"
#include "brains/Register.hpp"
#include "brains/SimInfo.hpp"
#include "brains/SimCreator.hpp"
#include "io/DumpWriter.hpp"
#include "math/Vector3.hpp"
#include "math/SquareMatrix3.hpp"
#include "utils/StringUtils.hpp"

using namespace std;
using namespace oopse;

void createMdFile(const std::string&oldMdFileName, 
                  const std::string&newMdFileName,
                  std::vector<int> nMol);

int main(int argc, char *argv []) {

  // register force fields
  registerForceFields();
  registerLattice();
    
  gengetopt_args_info args_info;
  std::string latticeType;
  std::string inputFileName;
  std::string outputFileName;
  Lattice *simpleLat;
  RealType latticeConstant;
  std::vector<RealType> lc;
  const RealType rhoConvertConst = 1.661;
  RealType density;
  int nx, ny, nz;
  Mat3x3d hmat;
  MoLocator *locator;
  std::vector<Vector3d> latticePos;
  std::vector<Vector3d> latticeOrt;
  int nMolPerCell;
  DumpWriter *writer;

  // parse command line arguments
  if (cmdline_parser(argc, argv, &args_info) != 0)
    exit(1);

  density = args_info.density_arg;

  //get lattice type
  latticeType = "FCC";

  simpleLat = LatticeFactory::getInstance()->createLattice(latticeType);
    
  if (simpleLat == NULL) {
    sprintf(painCave.errMsg, "Lattice Factory can not create %s lattice\n",
	    latticeType.c_str());
    painCave.isFatal = 1;
    simError();
  }
  nMolPerCell = simpleLat->getNumSitesPerCell();

  //get the number of unit cells in each direction:

  nx = args_info.nx_arg;

  if (nx <= 0) {
    sprintf(painCave.errMsg, "The number of unit cells in the x direction "
            "must be greater than 0.");
    painCave.isFatal = 1;
    simError();
  }

  ny = args_info.ny_arg;

  if (ny <= 0) {
    sprintf(painCave.errMsg, "The number of unit cells in the y direction "
            "must be greater than 0.");
    painCave.isFatal = 1;
    simError();
  }

  nz = args_info.nz_arg;

  if (nz <= 0) {
    sprintf(painCave.errMsg, "The number of unit cells in the z direction "
            "must be greater than 0.");
    painCave.isFatal = 1;
    simError();
  }

  int nSites = nMolPerCell * nx * ny * nz;

  //get input file name
  if (args_info.inputs_num)
    inputFileName = args_info.inputs[0];
  else {
    sprintf(painCave.errMsg, "No input .md file name was specified "
            "on the command line");
    painCave.isFatal = 1;
    simError();
  }

  //parse md file and set up the system

  SimCreator oldCreator;
  SimInfo* oldInfo = oldCreator.createSim(inputFileName, false);
  Globals* simParams = oldInfo->getSimParams();

  // Calculate lattice constant (in Angstroms)

  std::vector<Component*> components = simParams->getComponents();
  std::vector<RealType> molFractions;
  std::vector<RealType> molecularMasses;
  std::vector<int> nMol;
  int nComponents = components.size();

  if (nComponents == 1) {
    molFractions.push_back(1.0);    
  } else {
    if (args_info.molFraction_given == nComponents) {
      for (int i = 0; i < nComponents; i++) {
        molFractions.push_back(args_info.molFraction_arg[i]);
      }
    } else if (args_info.molFraction_given == nComponents-1) {
      RealType remainingFraction = 1.0;
      for (int i = 0; i < nComponents-1; i++) {
        molFractions.push_back(args_info.molFraction_arg[i]);
        remainingFraction -= molFractions[i];
      }
      molFractions.push_back(remainingFraction);
    } else {    
      sprintf(painCave.errMsg, "randomBuilder can't figure out molFractions "
              "for all of the components in the <MetaData> block.");
      painCave.isFatal = 1;
      simError();
    }
  }

  // do some sanity checking:
  
  RealType totalFraction = 0.0;

  for (int i = 0; i < nComponents; i++) {
    if (molFractions.at(i) < 0.0) {
      sprintf(painCave.errMsg, "One of the requested molFractions was"
              " less than zero!");
      painCave.isFatal = 1;
      simError();
    }
    if (molFractions.at(i) > 1.0) {
      sprintf(painCave.errMsg, "One of the requested molFractions was"
              " greater than one!");
      painCave.isFatal = 1;
      simError();
    }
    totalFraction += molFractions.at(i);
  }
  if (abs(totalFraction - 1.0) > 1e-6) {
    sprintf(painCave.errMsg, "The sum of molFractions was not close enough to 1.0");
    painCave.isFatal = 1;
    simError();
  }

  int remaining = nSites;
  for (int i=0; i < nComponents-1; i++) {    
    nMol.push_back(int((RealType)nSites * molFractions.at(i)));
    remaining -= nMol.at(i);
  }
  nMol.push_back(remaining);

  // recompute actual mol fractions and perform final sanity check:

  int totalMolecules = 0;
  RealType totalMass = 0.0;
  for (int i=0; i < nComponents; i++) {
    molFractions[i] = (RealType)(nMol.at(i))/(RealType)nSites;
    totalMolecules += nMol.at(i);
    molecularMasses.push_back(getMolMass(oldInfo->getMoleculeStamp(i),
                                         oldInfo->getForceField()));
    totalMass += (RealType)(nMol.at(i)) * molecularMasses.at(i);
  }
  RealType avgMass = totalMass / (RealType) totalMolecules;

  if (totalMolecules != nSites) {
    sprintf(painCave.errMsg, "Computed total number of molecules is not equal "
            "to the number of lattice sites!");
    painCave.isFatal = 1;
    simError();
  }
     
  latticeConstant = pow(rhoConvertConst * nMolPerCell * avgMass / density,
			(RealType)(1.0 / 3.0));
  
  // Set the lattice constant
  
  lc.push_back(latticeConstant);
  simpleLat->setLatticeConstant(lc);
  
  // Calculate the lattice sites and fill the lattice vector.

  // Get the standard orientations of the cell sites

  latticeOrt = simpleLat->getLatticePointsOrt();

  vector<Vector3d> sites;
  vector<Vector3d> orientations;
  
  for(int i = 0; i < nx; i++) {
    for(int j = 0; j < ny; j++) {
      for(int k = 0; k < nz; k++) {

	// Get the position of the cell sites

	simpleLat->getLatticePointsPos(latticePos, i, j, k);

	for(int l = 0; l < nMolPerCell; l++) {
	  sites.push_back(latticePos[l]);
          orientations.push_back(latticeOrt[l]);
	}
      }
    }
  }
  
  outputFileName = args_info.output_arg;

  // create a new .md file on the fly which corrects the number of molecules

  createMdFile(inputFileName, outputFileName, nMol);

  if (oldInfo != NULL)
    delete oldInfo;

  // We need to read in the new SimInfo object, then Parse the 
  // md file and set up the system

  SimCreator newCreator;
  SimInfo* newInfo = newCreator.createSim(outputFileName, false);

  // fill Hmat

  hmat(0, 0) = nx * latticeConstant;
  hmat(0, 1) = 0.0;
  hmat(0, 2) = 0.0;

  hmat(1, 0) = 0.0;
  hmat(1, 1) = ny * latticeConstant;
  hmat(1, 2) = 0.0;

  hmat(2, 0) = 0.0;
  hmat(2, 1) = 0.0;
  hmat(2, 2) = nz * latticeConstant;

  // Set Hmat

  newInfo->getSnapshotManager()->getCurrentSnapshot()->setHmat(hmat);

  // place the molecules

  // Randomize a vector of ints:

  vector<int> ids;
  for (int i = 0; i < sites.size(); i++) ids.push_back(i);
  std::random_shuffle(ids.begin(), ids.end());

  Molecule* mol;
  int l = 0;
  for (int i = 0; i < nComponents; i++){
    locator = new MoLocator(newInfo->getMoleculeStamp(i), 
                            newInfo->getForceField());
    for (int n = 0; n < nMol.at(i); n++) {
      mol = newInfo->getMoleculeByGlobalIndex(l);
      locator->placeMol(sites[ids[l]], orientations[ids[l]], mol);
      l++;
    }
  }
  
  // Create DumpWriter and write out the coordinates

  writer = new DumpWriter(newInfo, outputFileName);

  if (writer == NULL) {
    sprintf(painCave.errMsg, "error in creating DumpWriter");
    painCave.isFatal = 1;
    simError();
  }

  writer->writeDump();

  // deleting the writer will put the closing at the end of the dump file.

  delete writer;

  sprintf(painCave.errMsg, "A new OOPSE MD file called \"%s\" has been "
          "generated.\n", outputFileName.c_str());
  painCave.isFatal = 0;
  simError();
  return 0;
}

void createMdFile(const std::string&oldMdFileName, 
                  const std::string&newMdFileName, 
                  std::vector<int> nMol) {
  ifstream oldMdFile;
  ofstream newMdFile;
  const int MAXLEN = 65535;
  char buffer[MAXLEN];
  
  //create new .md file based on old .md file

  oldMdFile.open(oldMdFileName.c_str());
  newMdFile.open(newMdFileName.c_str());
  
  oldMdFile.getline(buffer, MAXLEN);
 
  int i = 0;
  while (!oldMdFile.eof()) {
    
    //correct molecule number
    if (strstr(buffer, "nMol") != NULL) {
      if(i<nMol.size()){
	sprintf(buffer, "\tnMol = %i;", nMol.at(i));
	newMdFile << buffer << std::endl;
	i++;
      }
    } else
      newMdFile << buffer << std::endl;
    
    oldMdFile.getline(buffer, MAXLEN);
  }
  
  oldMdFile.close();
  newMdFile.close();
}

