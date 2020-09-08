/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Robot/Solver Configuration'.
 */

#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "ne_std.h"
#include "ne_dae.h"
#include "sm_ssci_run_time_errors.h"
#include "sm_RuntimeDerivedValuesBundle.h"
#include "Robot_d2dba219_1_geometries.h"

PmfMessageId Robot_d2dba219_1_compOutputs(const RuntimeDerivedValuesBundle *rtdv,
  const double *state, const int *modeVector, const double *input, const double *
  inputDot, const double *inputDdot, const double *discreteState, double *output,
  NeuDiagnosticManager *neDiagMgr)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) rtdvd;
  (void) rtdvi;
  (void) modeVector;
  (void) input;
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  output[0] = state[8];
  output[1] = state[6];
  output[2] = state[0];
  output[3] = state[1];
  output[4] = state[4];
  output[5] = state[5];
  return NULL;
}
