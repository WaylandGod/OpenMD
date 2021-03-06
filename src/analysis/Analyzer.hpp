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
 
#ifndef INTEGRATORS_ANALYZER_HPP
#define INTEGRATORS_ANALYZER_HPP
#include "brains/SimInfo.hpp"
#include "math/RandNumGen.hpp"
#include "selection/SelectionEvaluator.hpp"
#include "selection/SelectionManager.hpp"
#include "analysis/StaticAnalyser.hpp"
#include <iostream>

using namespace std;
namespace OpenMD {

  /**
   * @class Analyzer Analyzer.hpp "Analyzer/Analyzer.hpp"
   * @brief 
   *     
   * Analyzer is a class which performs on-the-fly analytics of a system.
   * This class allows users to specify analysis modules to be computed
   * while the simulation is running, as opposed to post-processing methods
   * traditionally done from the (.dump) file at the end of the simulation.
   */

  class Analyzer {
  public:
    Analyzer(SimInfo* info);
    virtual ~Analyzer();
    
    void doAnalyzer();
    void getStarted();
    void parseOutputFileFormat(const std::string& format);
    void writeOutput();


  private:
   
    enum AnalyzerMethod {
      analyzerBo,
      analyzerIor,
      analyzerFor,
      analyzerBad,
      analyzerCount,
      analyzerGofr,
      analyzerGofz,
      analyzerRTheta,
      analyzerROmega,
      analyzerRz,
      analyzerThetaOmega,
      analyzerRThetaOmega,
      analyzerGxyz,
      analyzerTwoDGofr,
      analyzerP2,
      analyzerSCD,
      analyzerDensity,
      analyzerSlabDensity,
      analyzerPipeDensity,
      analyzerPAngle,
      analyzerHxy,
      analyzerRhoR,
      analyzerAngleR,
      analyzerHullVol,
      analyzerRodLength,
      analyzerTetParam,
      analyzerTetParamZ,
      analyzerTetParamDens,
      analyzerTetParamXYZ,
      analyzerRNEMDz,
      analyzerRNEMDr,
      analyzerRNEMDrt,
      analyzerNitrile,
      analyzerMultipole,
      analyzerSurfDiffusion,
      analyzerCN,
      analyzerSCN,
      analyzerGCN,
      analyzerHBond,
      analyzerPotDiff,
      analyzerTetHB,
      analyzerKirkwood,
      analyzerKirkwoodQ,
      analyzerDensityField,
      analyzerVelocityField,
      analyzerVelocityZ
    };

    SimInfo* info_;
    
    map<string, AnalyzerMethod> stringToMethod_;
    AnalyzerMethod analyzerMethod_;
    
    bool doAnalyzer_;
    RealType queryTime_;

    SelectionEvaluator evaluator_;
    SelectionManager seleMan_;


    RealType step;
    RealType nbins;
    RealType nbinsX;
    RealType nbinsY;
    RealType nbinsZ;
    RealType nrbins;
    RealType nAngleBins;
    RealType rCut;
    RealType ooCut;
    RealType thetaCut;
    RealType OHCut;
    RealType dz;
    RealType length;
    RealType zLength;
    RealType zOffSet;
    std::string sele1;
    std::string sele2;
    std::string sele3;
    std::string comSele;
    RealType seleOffSet;
    RealType seleOffSet2;
    std::string molName;
    RealType begin;
    RealType end;
    RealType radius;
    RealType voxelSize;
    RealType gaussWidth;
    std::string privilegedAxis;
    std::string privilegedAxis2;
    RealType maxLen;
    RealType zmaxLen;
    Mat3x3d hmat;

    StaticAnalyser* analyser_;
    
  };
}
#endif //INTEGRATORS_ANALYZER_HPP
