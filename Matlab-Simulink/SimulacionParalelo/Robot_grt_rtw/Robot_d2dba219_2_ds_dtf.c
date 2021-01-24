/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Robot/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Robot_d2dba219_2_ds_dtf.h"
#include "Robot_d2dba219_2_ds_sys_struct.h"
#include "Robot_d2dba219_2_ds_externals.h"
#include "Robot_d2dba219_2_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Robot_d2dba219_2_ds_dtf(const NeDynamicSystem *t0, const
  NeDynamicSystemInput *t134, NeDsMethodOutput *t135)
{
  PmRealVector out;
  real_T nonscalar2[8];
  real_T nonscalar3[8];
  real_T intermediate_der99;
  real_T t15[1];
  real_T t34;
  real_T t41;
  real_T t42;
  real_T t43;
  real_T t44;
  real_T t45;
  real_T t46;
  real_T t47;
  real_T t48;
  real_T t49;
  real_T t58;
  real_T t59;
  real_T t60;
  real_T t61;
  real_T t74;
  real_T t75;
  real_T t77;
  real_T t78;
  real_T t80;
  real_T t81;
  real_T t83;
  real_T t92;
  real_T t103;
  real_T t112;
  real_T t113;
  ETTS0 efOut;
  size_t _in1ivar;
  real_T b_efOut[1];
  ETTS0 c_efOut;
  real_T d_efOut[1];
  ETTS0 e_efOut;
  real_T f_efOut[1];
  real_T g_efOut[1];
  real_T h_efOut[1];
  real_T i_efOut[1];
  real_T U_idx_0;
  real_T X_idx_11;
  real_T X_idx_12;
  real_T X_idx_13;
  real_T X_idx_8;
  real_T X_idx_9;
  real_T X_idx_10;
  real_T X_idx_0;
  int32_T M_idx_25;
  int32_T M_idx_23;
  int32_T M_idx_24;
  real_T X_idx_2;
  real_T X_idx_3;
  real_T X_idx_1;
  (void)t0;
  M_idx_23 = t134->mM.mX[23];
  M_idx_24 = t134->mM.mX[24];
  M_idx_25 = t134->mM.mX[25];
  U_idx_0 = t134->mU.mX[0];
  X_idx_0 = t134->mX.mX[0];
  X_idx_1 = t134->mX.mX[1];
  X_idx_2 = t134->mX.mX[2];
  X_idx_3 = t134->mX.mX[3];
  X_idx_8 = t134->mX.mX[8];
  X_idx_9 = t134->mX.mX[9];
  X_idx_10 = t134->mX.mX[10];
  X_idx_11 = t134->mX.mX[11];
  X_idx_12 = t134->mX.mX[12];
  X_idx_13 = t134->mX.mX[13];
  out = t135->mDTF;
  nonscalar2[0] = -0.78539816339744828;
  nonscalar2[1] = 0.0;
  nonscalar2[2] = 0.78539816339744828;
  nonscalar2[3] = 2.3561944901923448;
  nonscalar2[4] = 3.9269908169872414;
  nonscalar2[5] = 5.497787143782138;
  nonscalar2[6] = 6.2831853071795862;
  nonscalar2[7] = 7.0685834705770345;
  nonscalar3[0] = 0.014854461355243567;
  nonscalar3[1] = 0.0;
  nonscalar3[2] = -0.014854461355243567;
  nonscalar3[3] = -0.014854461355243567;
  nonscalar3[4] = 0.014854461355243567;
  nonscalar3[5] = 0.014854461355243567;
  nonscalar3[6] = 0.0;
  nonscalar3[7] = -0.014854461355243567;
  intermediate_der99 = -X_idx_11 + X_idx_8;
  t83 = -X_idx_11 + X_idx_9;
  t92 = -X_idx_11 + X_idx_10;
  X_idx_8 = X_idx_0 * 7.0 + -1.5707963267948966;
  t41 = X_idx_8;
  t42 = X_idx_8 + -2.0943951023931953;
  t43 = X_idx_8 + 2.0943951023931953;
  t44 = cos(X_idx_8) * 0.66666666666666663;
  t45 = cos(X_idx_8 + -2.0943951023931953) * 0.66666666666666663;
  t46 = cos(X_idx_8 + 2.0943951023931953) * 0.66666666666666663;
  t47 = -sin(X_idx_8) * 0.66666666666666663;
  t48 = -sin(X_idx_8 + -2.0943951023931953) * 0.66666666666666663;
  t49 = -sin(X_idx_8 + 2.0943951023931953) * 0.66666666666666663;
  X_idx_8 = (atan2(fabs(-sin(X_idx_8 + 2.0943951023931953)), -cos(X_idx_8 +
    2.0943951023931953)) * (real_T)(M_idx_25 != 0) + -atan2(fabs(-sin(X_idx_8 +
    2.0943951023931953)), -cos(X_idx_8 + 2.0943951023931953)) * (real_T)
             (M_idx_25 == 0)) + 3.1415926535897931;
  t15[0ULL] = X_idx_8;
  _in1ivar = 8ULL;
  tlu2_linear_nearest_prelookup((void *)&efOut.mField0, (void *)&efOut.mField1,
    (void *)&efOut.mField2, (void *)nonscalar2, (void *)t15, (void *)&_in1ivar);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_value((void *)&b_efOut, (void *)efOut.mField0, (void *)
    efOut.mField1, (void *)efOut.mField2, (void *)nonscalar3, (void *)&_in1ivar);
  X_idx_8 = (atan2(fabs(-sin(t41)), -cos(t41)) * (real_T)(M_idx_23 != 0) +
             -atan2(fabs(-sin(t41)), -cos(t41)) * (real_T)(M_idx_23 == 0)) +
    3.1415926535897931;
  t15[0ULL] = X_idx_8;
  _in1ivar = 8ULL;
  tlu2_linear_nearest_prelookup((void *)&c_efOut.mField0, (void *)
    &c_efOut.mField1, (void *)&c_efOut.mField2, (void *)nonscalar2, (void *)t15,
    (void *)&_in1ivar);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_value((void *)&d_efOut, (void *)c_efOut.mField0, (void *)
    c_efOut.mField1, (void *)c_efOut.mField2, (void *)nonscalar3, (void *)
    &_in1ivar);
  X_idx_8 = (atan2(fabs(-sin(t42)), -cos(t42)) * (real_T)(M_idx_24 != 0) +
             -atan2(fabs(-sin(t42)), -cos(t42)) * (real_T)(M_idx_24 == 0)) +
    3.1415926535897931;
  t15[0ULL] = X_idx_8;
  _in1ivar = 8ULL;
  tlu2_linear_nearest_prelookup((void *)&e_efOut.mField0, (void *)
    &e_efOut.mField1, (void *)&e_efOut.mField2, (void *)nonscalar2, (void *)t15,
    (void *)&_in1ivar);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_value((void *)&f_efOut, (void *)e_efOut.mField0, (void *)
    e_efOut.mField1, (void *)e_efOut.mField2, (void *)nonscalar3, (void *)
    &_in1ivar);
  X_idx_10 = -sin(t41) * 0.0 * 0.66666666666666663;
  X_idx_0 = -sin(t42) * 0.0 * 0.66666666666666663;
  t58 = -sin(t43) * 0.0 * 0.66666666666666663;
  t59 = -(cos(t41) * 0.0) * 0.66666666666666663;
  t60 = -(cos(t42) * 0.0) * 0.66666666666666663;
  t61 = -(cos(t43) * 0.0) * 0.66666666666666663;
  t74 = -sin(t41) * 0.0;
  t75 = -(cos(t41) * 0.0);
  t77 = -sin(t42) * 0.0;
  t78 = -(cos(t42) * 0.0);
  t80 = -sin(t43) * 0.0;
  t81 = -(cos(t43) * 0.0);
  X_idx_8 = -sin(t43);
  t34 = -cos(t43);
  t103 = fabs(-sin(t43)) * fabs(-sin(t43)) + -cos(t43) * -cos(t43);
  t112 = -fabs(-sin(t43));
  if (X_idx_8 > 0.0) {
    t113 = 1.0;
  } else {
    t113 = X_idx_8 < 0.0 ? -1.0 : 0.0;
  }

  if (X_idx_8 > 0.0) {
    X_idx_8 = 1.0;
  } else {
    X_idx_8 = X_idx_8 < 0.0 ? -1.0 : 0.0;
  }

  X_idx_8 = (-(cos(t43) * 0.0) * (t34 / (t103 == 0.0 ? 1.0E-16 : t103)) * t113 +
             -(-sin(t43) * 0.0) * (t112 / (t103 == 0.0 ? 1.0E-16 : t103))) *
    (real_T)(M_idx_25 != 0) + -(-(cos(t43) * 0.0) * (t34 / (t103 == 0.0 ?
    1.0E-16 : t103)) * X_idx_8 + -(-sin(t43) * 0.0) * (t112 / (t103 == 0.0 ?
    1.0E-16 : t103))) * (real_T)(M_idx_25 == 0);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_derivatives((void *)&g_efOut, (void *)efOut.mField0,
    (void *)efOut.mField1, (void *)efOut.mField2, (void *)nonscalar3, (void *)
    &_in1ivar);
  t43 = g_efOut[0] * X_idx_8;
  t34 = -sin(t41);
  t103 = -cos(t41);
  t112 = fabs(-sin(t41)) * fabs(-sin(t41)) + -cos(t41) * -cos(t41);
  t113 = -fabs(-sin(t41));
  if (t34 > 0.0) {
    X_idx_8 = 1.0;
  } else {
    X_idx_8 = t34 < 0.0 ? -1.0 : 0.0;
  }

  if (t34 > 0.0) {
    X_idx_9 = 1.0;
  } else {
    X_idx_9 = t34 < 0.0 ? -1.0 : 0.0;
  }

  X_idx_8 = (-(cos(t41) * 0.0) * (t103 / (t112 == 0.0 ? 1.0E-16 : t112)) *
             X_idx_8 + -(-sin(t41) * 0.0) * (t113 / (t112 == 0.0 ? 1.0E-16 :
    t112))) * (real_T)(M_idx_23 != 0) + -(-(cos(t41) * 0.0) * (t103 / (t112 ==
    0.0 ? 1.0E-16 : t112)) * X_idx_9 + -(-sin(t41) * 0.0) * (t113 / (t112 == 0.0
    ? 1.0E-16 : t112))) * (real_T)(M_idx_23 == 0);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_derivatives((void *)&h_efOut, (void *)c_efOut.mField0,
    (void *)c_efOut.mField1, (void *)c_efOut.mField2, (void *)nonscalar3, (void *)
    &_in1ivar);
  t34 = h_efOut[0] * X_idx_8;
  t41 = -sin(t42);
  t103 = -cos(t42);
  t112 = fabs(-sin(t42)) * fabs(-sin(t42)) + -cos(t42) * -cos(t42);
  t113 = -fabs(-sin(t42));
  if (t41 > 0.0) {
    X_idx_8 = 1.0;
  } else {
    X_idx_8 = t41 < 0.0 ? -1.0 : 0.0;
  }

  if (t41 > 0.0) {
    X_idx_9 = 1.0;
  } else {
    X_idx_9 = t41 < 0.0 ? -1.0 : 0.0;
  }

  X_idx_8 = (-(cos(t42) * 0.0) * (t103 / (t112 == 0.0 ? 1.0E-16 : t112)) *
             X_idx_8 + -(-sin(t42) * 0.0) * (t113 / (t112 == 0.0 ? 1.0E-16 :
    t112))) * (real_T)(M_idx_24 != 0) + -(-(cos(t42) * 0.0) * (t103 / (t112 ==
    0.0 ? 1.0E-16 : t112)) * X_idx_9 + -(-sin(t42) * 0.0) * (t113 / (t112 == 0.0
    ? 1.0E-16 : t112))) * (real_T)(M_idx_24 == 0);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_derivatives((void *)&i_efOut, (void *)e_efOut.mField0,
    (void *)e_efOut.mField1, (void *)e_efOut.mField2, (void *)nonscalar3, (void *)
    &_in1ivar);
  t41 = i_efOut[0] * X_idx_8;
  out.mX[0] = -(((((((intermediate_der99 - d_efOut[0] * U_idx_0 * 7.0) *
                     X_idx_10 + -(t34 * U_idx_0 * 7.0) * t44) + (t83 - f_efOut[0]
    * U_idx_0 * 7.0) * X_idx_0) + -(t41 * U_idx_0 * 7.0) * t45) + (t92 -
    b_efOut[0] * U_idx_0 * 7.0) * t58) + -(t43 * U_idx_0 * 7.0) * t46) *
                1.732050807568877);
  out.mX[1] = -(((((((intermediate_der99 - d_efOut[0] * U_idx_0 * 7.0) * t59 +
                     -(t34 * U_idx_0 * 7.0) * t47) + (t83 - f_efOut[0] * U_idx_0
    * 7.0) * t60) + -(t41 * U_idx_0 * 7.0) * t48) + (t92 - b_efOut[0] * U_idx_0 *
    7.0) * t61) + -(t43 * U_idx_0 * 7.0) * t49) * 1.5);
  out.mX[2] = -(((-(t34 * U_idx_0 * 7.0) * 0.33333333333333331 + -(t41 * U_idx_0
    * 7.0) * 0.33333333333333331) + -(t43 * U_idx_0 * 7.0) * 0.33333333333333331)
                * 3.0);
  out.mX[3] = ((t34 + 0.0 * t41) + 0.0 * t43) * U_idx_0 * 7.0;
  out.mX[4] = ((0.0 * t34 + t41) + 0.0 * t43) * U_idx_0 * 7.0;
  out.mX[5] = ((0.0 * t34 + 0.0 * t41) + t43) * U_idx_0 * 7.0;
  out.mX[6] = -((t74 * X_idx_2 + t75 * X_idx_3) + 0.0 * X_idx_1);
  out.mX[7] = -((t77 * X_idx_2 + t78 * X_idx_3) + 0.0 * X_idx_1);
  out.mX[8] = -((t80 * X_idx_2 + t81 * X_idx_3) + 0.0 * X_idx_1);
  out.mX[9] = -(((-(t34 * ((X_idx_11 * -1.0010000000000002E-9 + -X_idx_12) +
    -X_idx_13)) + -(t41 * X_idx_12)) + -(t43 * X_idx_13)) * 7.0);
  (void)t0;
  (void)t135;
  return 0;
}
