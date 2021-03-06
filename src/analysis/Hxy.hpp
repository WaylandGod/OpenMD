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
 * [4] Kuang & Gezelter,  J. Chem. Phys. 133, 164101 (2010).
 * [4] , Stocker & Gezelter, J. Chem. Theory Comput. 7, 834 (2011). *
 *  Created by Xiuquan Sun on 05/09/06.
 *  @author  Xiuquan Sun
 *  @version $Id$
 *
 */
#ifndef ANALYSIS_HXY_HPP
#define ANALYSIS_HXY_HPP

#include "config.h"

#if defined(HAVE_FFTW_H) || defined(HAVE_DFFTW_H) || defined(HAVE_FFTW3_H)

#ifdef HAVE_FFTW_H
#include <fftw.h>
#endif

#ifdef HAVE_DFFTW_H
#include <dfftw.h>
#endif

#ifdef HAVE_FFTW3_H
#include <fftw3.h>
#define c_re(c) ((c)[0])
#define c_im(c) ((c)[1])
#endif
#endif

#include "analysis/RadialDistrFunc.hpp"
#include "analysis/NonSpatialStatistics.hpp"
#include "utils/Accumulator.hpp"

namespace OpenMD {
  
  class Hxy : public NonSpatialStatistics {
    
  public:
    Hxy(SimInfo* info, const std::string& sele,
        int nbins_x, int nbins_y, int nbins_z, int nrbins);
    virtual ~Hxy();        
    virtual void processFrame(int frame);
    
    
  private:
    virtual void processStuntDouble(StuntDouble* sd, int bin);
    
    RealType getDensity(RealType dist, RealType sigma, RealType rcut);
    
    int nProcessed_;
    std::string selectionScript_;
    SelectionEvaluator evaluator_;
    SelectionManager seleMan_;
    
    unsigned int nBinsX_;
    unsigned int nBinsY_;
    unsigned int nBinsZ_;
    RealType dfreq_;

    std::vector<std::vector<std::vector<RealType> > > dens_;
    std::vector<std::vector<RealType> > minHeight_;
    std::vector<std::vector<RealType> > maxHeight_;    
    std::vector<RealType> mag1, newmag1;
    std::vector<RealType> mag2, newmag2;

    OutputData* freq_;
    OutputData* top_;
    OutputData* bottom_;

    bool usePeriodicBoundaryConditions_;
  };
  
}
#endif



