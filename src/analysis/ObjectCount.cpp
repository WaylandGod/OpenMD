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

#include <algorithm>
#include <functional>
#include "analysis/ObjectCount.hpp"
#include "utils/simError.h"
#include "io/DumpReader.hpp"
#include "primitives/Molecule.hpp"

namespace OpenMD {

  ObjectCount::ObjectCount(SimInfo* info, 
                           const std::string& sele)
    : NonSpatialStatistics(info, sele, 1), selectionScript_(sele), 
      seleMan_(info), evaluator_(info) {

    string prefixFileName = info->getPrefixFileName();
    setOutputName(prefixFileName + ".counts");
    
    evaluator_.loadScriptString(sele);
    
    if (!evaluator_.isDynamic()) {
      seleMan_.setSelectionSet(evaluator_.evaluate());
    }
    counts_.clear();
    counts_.resize(10, 0);
  }

  ObjectCount::~ObjectCount() {
    //counts_.clear();
  }

  void ObjectCount::processHistogram() {
    nAvg_ = nsum_ / nProcessed_;
    n2Avg_ = n2sum_ / nProcessed_;
    sDev_ = sqrt(n2Avg_ - nAvg_*nAvg_);
  }


  void ObjectCount::processFrame(int istep) {
    nsum_ = 0;
    n2sum_ = 0;
     
    if (evaluator_.isDynamic()) {
      seleMan_.setSelectionSet(evaluator_.evaluate());
    }
    
    unsigned int count = seleMan_.getSelectionCount();
    
    if (counts_.size() <= count)  {
      counts_.resize(count, 0);
    }
    
    counts_[count]++;
    
    nsum_ += count;
    n2sum_ += count * count;
  }

  void ObjectCount::processStuntDouble(StuntDouble* sd, int bin) {
    // Fill in later
  }
    
  
  void ObjectCount::writeOutput() {
    std::ofstream ofs(outputFilename_.c_str(), std::ios::binary);
    if (ofs.is_open()) {
      ofs << "#counts\n";
      ofs << "#selection: (" << selectionScript_ << ")\n";
      ofs << "# <N> = "<< nAvg_ << "\n";
      ofs << "# <N^2> = " << n2Avg_ << "\n";
      ofs << "# sqrt(<N^2> - <N>^2)  = " << sDev_ << "\n";
      ofs << "# N\tcounts[N]\n";
      for (unsigned int i = 0; i < counts_.size(); ++i) {
        ofs << i << "\t" << counts_[i] << "\n";
      }
      
    } else {
      
      sprintf(painCave.errMsg, "ObjectCount: unable to open %s\n", 
	      outputFilename_.c_str());
      painCave.isFatal = 1;
      simError();  
    }
    ofs.close();
  }
  
}


