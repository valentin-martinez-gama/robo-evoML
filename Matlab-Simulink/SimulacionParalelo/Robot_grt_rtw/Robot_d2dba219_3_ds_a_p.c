/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Robot/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Robot_d2dba219_3_ds_a_p.h"
#include "Robot_d2dba219_3_ds_sys_struct.h"
#include "Robot_d2dba219_3_ds_externals.h"
#include "Robot_d2dba219_3_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Robot_d2dba219_3_ds_a_p(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mA_P;
  out.mNumCol = 24ULL;
  out.mNumRow = 24ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 1;
  out.mJc[3] = 2;
  out.mJc[4] = 3;
  out.mJc[5] = 3;
  out.mJc[6] = 3;
  out.mJc[7] = 3;
  out.mJc[8] = 3;
  out.mJc[9] = 4;
  out.mJc[10] = 5;
  out.mJc[11] = 6;
  out.mJc[12] = 8;
  out.mJc[13] = 10;
  out.mJc[14] = 12;
  out.mJc[15] = 13;
  out.mJc[16] = 13;
  out.mJc[17] = 13;
  out.mJc[18] = 13;
  out.mJc[19] = 13;
  out.mJc[20] = 13;
  out.mJc[21] = 13;
  out.mJc[22] = 13;
  out.mJc[23] = 13;
  out.mJc[24] = 13;
  out.mIr[0] = 3;
  out.mIr[1] = 1;
  out.mIr[2] = 2;
  out.mIr[3] = 3;
  out.mIr[4] = 3;
  out.mIr[5] = 3;
  out.mIr[6] = 3;
  out.mIr[7] = 8;
  out.mIr[8] = 8;
  out.mIr[9] = 9;
  out.mIr[10] = 8;
  out.mIr[11] = 10;
  out.mIr[12] = 11;
  (void)sys;
  (void)t2;
  return 0;
}
