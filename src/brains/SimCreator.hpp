/*
 * Copyright (c) 2005 The University of Notre Dame. All Rights Reserved.
 *
 * The University of Notre Dame grants you ("Licensee") a
 * non-exclusive, royalty free, license to use, modify and
 * redistribute this software in source and binary code form, provided
 * that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
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
 * SUPPORT OPEN SCIENCE!  If you use OpenMD or its source code in your
 * research, please cite the appropriate papers when you publish your
 * work.  Good starting points are:
 *                                                                      
 * [1]  Meineke, et al., J. Comp. Chem. 26, 252-271 (2005).             
 * [2]  Fennell & Gezelter, J. Chem. Phys. 124, 234104 (2006).          
 * [3]  Sun, Lin & Gezelter, J. Chem. Phys. 128, 234107 (2008).          
 * [4]  Kuang & Gezelter,  J. Chem. Phys. 133, 164101 (2010).
 * [5]  Vardeman, Stocker & Gezelter, J. Chem. Theory Comput. 7, 834 (2011).
 */
 
/**
 * @file SimCreator.hpp
 * @author tlin
 * @date 11/02/2004
 * @version 1.0
 */

#ifndef BRAINS_SIMCREATOR_HPP
#define BRAINS_SIMCREATOR_HPP

#include <iostream>
#include "primitives/Molecule.hpp"
#include "brains/SimInfo.hpp"
#include "io/Globals.hpp"
#include "brains/ForceField.hpp"

namespace OpenMD {

  /**
   * @class SimCreator SimCreator.hpp "brains/SimCreator.hpp"
   *
   * The only responsibility of SimCreator is to parse the meta-data
   * file and create a SimInfo instance based on the information
   * returned by parser.
   */
  class SimCreator {
  public:

    virtual ~SimCreator() {}

    /**
     * Setup Simulation
     * @return a pointer to SimInfo
     * @param mdFileName the meta-data file name
     * @param loadInitCoords should the initial coordinates be loaded from a file?
     */
    SimInfo* createSim(const std::string & mdFileName, bool loadInitCoords = true);
        
  private:
        
    /**
     * Parses the meta-data file
     * @param mdFileName the meta-data file name
     * @param rawMetaData the raw meta-data stream
     * @param mdFileVersion the version of code used to create the meta-data file
     * @param metaDataStartingLine the starting line of the meta-data block
     * @return a pointer to the simulation parameters in a #Globals object
     */
    Globals*  parseFile(std::istream& rawMetaData, const std::string& mdFileName, int mdFileVersion, int metaDataStartingLine);


    /** create the molecules belong to current processor*/
    virtual void createMolecules(SimInfo* info);

    /**
     * Figure out the data storage layout based on what kinds of
     * objects are being simulated
     */
    int computeStorageLayout(SimInfo* info);
    
    /** 
     * Sets the global index for atoms, rigidbodies and cutoff groups
     * and fill up globalGroupMembership and globalMolMembership
     * arrays which map atoms' global index to the global index of the
     * groups (or molecules) they belong to.  These array are never
     * changed during the simulation.
     */
    void setGlobalIndex(SimInfo* info);

    void gatherParameters(SimInfo *info, const std::string& mdfile);             
        
    /**
     * Divide the molecules among the processors 
     */
         
    void divideMolecules(SimInfo* info);

    /** Load initial coordinates */
    void loadCoordinates(SimInfo* info, const std::string& mdFileName);     

    std::string mdFileName_;  //save the meta-data file name which may be used later

  };

} //end namespace OpenMD
#endif //BRAINS_SIMCREATOR_HPP

