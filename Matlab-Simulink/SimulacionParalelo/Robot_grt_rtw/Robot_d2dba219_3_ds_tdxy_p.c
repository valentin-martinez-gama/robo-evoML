/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Robot/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Robot_d2dba219_3_ds_tdxy_p.h"
#include "Robot_d2dba219_3_ds_sys_struct.h"
#include "Robot_d2dba219_3_ds_externals.h"
#include "Robot_d2dba219_3_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Robot_d2dba219_3_ds_tdxy_p(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mTDXY_P;
  out.mNumCol = 24ULL;
  out.mNumRow = 6ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  out.mJc[5] = 0;
  out.mJc[6] = 0;
  out.mJc[7] = 0;
  out.mJc[8] = 1;
  out.mJc[9] = 1;
  out.mJc[10] = 1;
  out.mJc[11] = 1;
  out.mJc[12] = 4;
  out.mJc[13] = 7;
  out.mJc[14] = 10;
  out.mJc[15] = 11;
  out.mJc[16] = 11;
  out.mJc[17] = 11;
  out.mJc[18] = 11;
  out.mJc[19] = 11;
  out.mJc[20] = 11;
  out.mJc[21] = 11;
  out.mJc[22] = 11;
  out.mJc[23] = 11;
  out.mJc[24] = 11;
  out.mIr[0] = 1;
  out.mIr[1] = 2;
  out.mIr[2] = 3;
  out.mIr[3] = 4;
  out.mIr[4] = 2;
  out.mIr[5] = 3;
  out.mIr[6] = 4;
  out.mIr[7] = 2;
  out.mIr[8] = 3;
  out.mIr[9] = 4;
  out.mIr[10] = 5;
  (void)sys;
  (void)t2;
  return 0;
}
