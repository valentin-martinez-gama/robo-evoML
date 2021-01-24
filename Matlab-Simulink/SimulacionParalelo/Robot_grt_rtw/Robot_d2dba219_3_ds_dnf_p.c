/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Robot/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Robot_d2dba219_3_ds_dnf_p.h"
#include "Robot_d2dba219_3_ds_sys_struct.h"
#include "Robot_d2dba219_3_ds_externals.h"
#include "Robot_d2dba219_3_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Robot_d2dba219_3_ds_dnf_p(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDNF_P;
  out.mNumCol = 53ULL;
  out.mNumRow = 24ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  out.mJc[5] = 0;
  out.mJc[6] = 0;
  out.mJc[7] = 0;
  out.mJc[8] = 0;
  out.mJc[9] = 0;
  out.mJc[10] = 0;
  out.mJc[11] = 0;
  out.mJc[12] = 0;
  out.mJc[13] = 0;
  out.mJc[14] = 0;
  out.mJc[15] = 0;
  out.mJc[16] = 0;
  out.mJc[17] = 0;
  out.mJc[18] = 0;
  out.mJc[19] = 0;
  out.mJc[20] = 0;
  out.mJc[21] = 0;
  out.mJc[22] = 0;
  out.mJc[23] = 0;
  out.mJc[24] = 0;
  out.mJc[25] = 0;
  out.mJc[26] = 0;
  out.mJc[27] = 0;
  out.mJc[28] = 0;
  out.mJc[29] = 0;
  out.mJc[30] = 0;
  out.mJc[31] = 0;
  out.mJc[32] = 0;
  out.mJc[33] = 0;
  out.mJc[34] = 0;
  out.mJc[35] = 0;
  out.mJc[36] = 0;
  out.mJc[37] = 0;
  out.mJc[38] = 0;
  out.mJc[39] = 0;
  out.mJc[40] = 0;
  out.mJc[41] = 0;
  out.mJc[42] = 0;
  out.mJc[43] = 0;
  out.mJc[44] = 0;
  out.mJc[45] = 0;
  out.mJc[46] = 0;
  out.mJc[47] = 0;
  out.mJc[48] = 0;
  out.mJc[49] = 0;
  out.mJc[50] = 0;
  out.mJc[51] = 0;
  out.mJc[52] = 0;
  out.mJc[53] = 0;
  (void)sys;
  (void)t2;
  return 0;
}
