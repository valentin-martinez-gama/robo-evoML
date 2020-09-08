/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Robot/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Robot_d2dba219_3_ds_m_p.h"
#include "Robot_d2dba219_3_ds_sys_struct.h"
#include "Robot_d2dba219_3_ds_externals.h"
#include "Robot_d2dba219_3_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Robot_d2dba219_3_ds_m_p(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mM_P;
  out.mNumCol = 24ULL;
  out.mNumRow = 24ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 1;
  out.mJc[2] = 2;
  out.mJc[3] = 3;
  out.mJc[4] = 4;
  out.mJc[5] = 7;
  out.mJc[6] = 10;
  out.mJc[7] = 13;
  out.mJc[8] = 14;
  out.mJc[9] = 14;
  out.mJc[10] = 14;
  out.mJc[11] = 14;
  out.mJc[12] = 14;
  out.mJc[13] = 14;
  out.mJc[14] = 14;
  out.mJc[15] = 14;
  out.mJc[16] = 14;
  out.mJc[17] = 14;
  out.mJc[18] = 14;
  out.mJc[19] = 14;
  out.mJc[20] = 14;
  out.mJc[21] = 14;
  out.mJc[22] = 14;
  out.mJc[23] = 14;
  out.mJc[24] = 14;
  out.mIr[0] = 0;
  out.mIr[1] = 3;
  out.mIr[2] = 1;
  out.mIr[3] = 2;
  out.mIr[4] = 4;
  out.mIr[5] = 5;
  out.mIr[6] = 6;
  out.mIr[7] = 4;
  out.mIr[8] = 5;
  out.mIr[9] = 6;
  out.mIr[10] = 4;
  out.mIr[11] = 5;
  out.mIr[12] = 6;
  out.mIr[13] = 7;
  (void)sys;
  (void)t2;
  return 0;
}
