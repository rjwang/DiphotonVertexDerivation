#ifndef DiphotonVertexDerivation_DiphotonVertexDerivation_H
#define DiphotonVertexDerivation_DiphotonVertexDerivation_H


#include <EventLoop/Algorithm.h>

// GRL
#include "GoodRunsLists/GoodRunsListSelectionTool.h"

#include "JetSelectorTools/JetCleaningTool.h"

#include "JetResolution/JERTool.h"

#include "MuonMomentumCorrections/MuonCalibrationAndSmearingTool.h"

#include "PATInterfaces/SystematicRegistry.h"

// include files for using the trigger tools
#include "TrigConfxAOD/xAODConfigTool.h"
#include "TrigDecisionTool/TrigDecisionTool.h"

#include <TH1.h>


#include <TTree.h>


class DiphotonVertexDerivation : public EL::Algorithm
{
  // put your configuration variables here as public variables.
  // that way they can be set directly from CINT and python.
public:
  // float cutValue;




  // variables that don't get filled at submission time should be
  // protected from being send from the submission node to the worker
  // node (done by the //!)
public:
  // Tree *myTree; //!
  // TH1 *myHist; //!


  // this is a standard constructor
  DiphotonVertexDerivation ();

  // these are the functions inherited from Algorithm
  virtual EL::StatusCode setupJob (EL::Job& job);
  virtual EL::StatusCode fileExecute ();
  virtual EL::StatusCode histInitialize ();
  virtual EL::StatusCode changeInput (bool firstFile);
  virtual EL::StatusCode initialize ();
  virtual EL::StatusCode execute ();
  virtual EL::StatusCode postExecute ();
  virtual EL::StatusCode finalize ();
  virtual EL::StatusCode histFinalize ();

  // this is needed to distribute the algorithm to the workers
  ClassDef(DiphotonVertexDerivation, 1);
};

#endif
