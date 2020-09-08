/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Robot/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Robot_d2dba219_2_ds_mode.h"
#include "Robot_d2dba219_2_ds_sys_struct.h"
#include "Robot_d2dba219_2_ds_externals.h"
#include "Robot_d2dba219_2_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Robot_d2dba219_2_ds_mode(const NeDynamicSystem *t0, const
  NeDynamicSystemInput *t15, NeDsMethodOutput *t16)
{
  PmIntVector out;
  boolean_T t1;
  boolean_T t2;
  boolean_T t3;
  boolean_T t4;
  boolean_T t5;
  boolean_T t6;
  int32_T t7_idx_23;
  int32_T t7_idx_24;
  int32_T t7_idx_25;
  real_T X_idx_8;
  real_T X_idx_9;
  real_T X_idx_10;
  real_T U_idx_1;
  real_T U_idx_2;
  real_T U_idx_3;
  real_T U_idx_4;
  real_T U_idx_5;
  real_T U_idx_6;
  real_T X_idx_0;
  (void)t0;
  U_idx_1 = t15->mU.mX[1];
  U_idx_2 = t15->mU.mX[2];
  U_idx_3 = t15->mU.mX[3];
  U_idx_4 = t15->mU.mX[4];
  U_idx_5 = t15->mU.mX[5];
  U_idx_6 = t15->mU.mX[6];
  X_idx_0 = t15->mX.mX[0];
  X_idx_8 = t15->mX.mX[8];
  X_idx_9 = t15->mX.mX[9];
  X_idx_10 = t15->mX.mX[10];
  out = t16->mMODE;
  X_idx_0 = X_idx_0 * 7.0 + -1.5707963267948966;
  if (-X_idx_8 + 24.0 > 0.8) {
    t1 = (U_idx_1 > 0.5);
  } else {
    t1 = false;
  }

  if (X_idx_8 > 0.8) {
    t2 = (U_idx_2 > 0.5);
  } else {
    t2 = false;
  }

  if (-X_idx_9 + 24.0 > 0.8) {
    t3 = (U_idx_3 > 0.5);
  } else {
    t3 = false;
  }

  if (X_idx_9 > 0.8) {
    t4 = (U_idx_4 > 0.5);
  } else {
    t4 = false;
  }

  if (-X_idx_10 + 24.0 > 0.8) {
    t5 = (U_idx_5 > 0.5);
  } else {
    t5 = false;
  }

  if (X_idx_10 > 0.8) {
    t6 = (U_idx_6 > 0.5);
  } else {
    t6 = false;
  }

  t7_idx_23 = (int32_T)(-sin(X_idx_0) >= 0.0);
  t7_idx_24 = (int32_T)(-sin(X_idx_0 + -2.0943951023931953) >= 0.0);
  t7_idx_25 = (int32_T)(-sin(X_idx_0 + 2.0943951023931953) >= 0.0);
  out.mX[0] = (int32_T)((-X_idx_8 + 24.0) - 0.8 <= U_idx_1 - 0.5);
  out.mX[1] = (int32_T)(X_idx_8 - 0.8 <= U_idx_2 - 0.5);
  out.mX[2] = (int32_T)(X_idx_8 + -24.0 < -pmf_get_inf());
  out.mX[3] = (int32_T)t1;
  out.mX[4] = (int32_T)(-X_idx_8 > 0.8);
  out.mX[5] = (int32_T)(-X_idx_8 < -pmf_get_inf());
  out.mX[6] = (int32_T)t2;
  out.mX[7] = (int32_T)(X_idx_9 + -24.0 > 0.8);
  out.mX[8] = (int32_T)(X_idx_9 + -24.0 < -pmf_get_inf());
  out.mX[9] = (int32_T)t3;
  out.mX[10] = (int32_T)(-X_idx_9 > 0.8);
  out.mX[11] = (int32_T)(-X_idx_9 < -pmf_get_inf());
  out.mX[12] = (int32_T)((-X_idx_9 + 24.0) - 0.8 <= U_idx_3 - 0.5);
  out.mX[13] = (int32_T)t4;
  out.mX[14] = (int32_T)(X_idx_10 + -24.0 > 0.8);
  out.mX[15] = (int32_T)(X_idx_10 + -24.0 < -pmf_get_inf());
  out.mX[16] = (int32_T)t5;
  out.mX[17] = (int32_T)(-X_idx_10 > 0.8);
  out.mX[18] = (int32_T)(-X_idx_10 < -pmf_get_inf());
  out.mX[19] = (int32_T)t6;
  out.mX[20] = (int32_T)(X_idx_9 - 0.8 <= U_idx_4 - 0.5);
  out.mX[21] = (int32_T)((-X_idx_10 + 24.0) - 0.8 <= U_idx_5 - 0.5);
  out.mX[22] = (int32_T)(X_idx_10 - 0.8 <= U_idx_6 - 0.5);
  out.mX[23] = t7_idx_23;
  out.mX[24] = t7_idx_24;
  out.mX[25] = t7_idx_25;
  out.mX[26] = (int32_T)(X_idx_8 + -24.0 > 0.8);
  (void)t0;
  (void)t16;
  return 0;
}
