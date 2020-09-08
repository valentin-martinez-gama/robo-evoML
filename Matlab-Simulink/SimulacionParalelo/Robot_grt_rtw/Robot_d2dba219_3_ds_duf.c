/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Robot/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Robot_d2dba219_3_ds_duf.h"
#include "Robot_d2dba219_3_ds_sys_struct.h"
#include "Robot_d2dba219_3_ds_externals.h"
#include "Robot_d2dba219_3_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Robot_d2dba219_3_ds_duf(const NeDynamicSystem *t0, const
  NeDynamicSystemInput *t36, NeDsMethodOutput *t37)
{
  PmRealVector out;
  real_T nonscalar2[8];
  real_T nonscalar3[8];
  real_T intrm_sf_mf_17;
  real_T zc_int12[3];
  real_T t6[1];
  real_T t24;
  real_T t25;
  real_T t26;
  real_T t27;
  real_T t28;
  real_T t29;
  ETTS0 efOut;
  size_t _in1ivar;
  real_T b_efOut[1];
  ETTS0 c_efOut;
  real_T d_efOut[1];
  ETTS0 e_efOut;
  real_T f_efOut[1];
  real_T X_idx_0;
  real_T X_idx_2;
  real_T X_idx_3;
  int32_T M_idx_25;
  int32_T M_idx_23;
  int32_T M_idx_24;
  (void)t0;
  M_idx_23 = t36->mM.mX[23];
  M_idx_24 = t36->mM.mX[24];
  M_idx_25 = t36->mM.mX[25];
  X_idx_0 = t36->mX.mX[0];
  X_idx_2 = t36->mX.mX[2];
  X_idx_3 = t36->mX.mX[3];
  out = t37->mDUF;
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
  intrm_sf_mf_17 = X_idx_0 * 7.0 + -1.5707963267948966;
  t24 = cos(intrm_sf_mf_17) * 0.66666666666666663;
  t25 = cos(intrm_sf_mf_17 + -2.0943951023931953) * 0.66666666666666663;
  t26 = cos(intrm_sf_mf_17 + 2.0943951023931953) * 0.66666666666666663;
  t27 = -sin(intrm_sf_mf_17) * 0.66666666666666663;
  t28 = -sin(intrm_sf_mf_17 + -2.0943951023931953) * 0.66666666666666663;
  t29 = -sin(intrm_sf_mf_17 + 2.0943951023931953) * 0.66666666666666663;
  X_idx_0 = (atan2(fabs(-sin(intrm_sf_mf_17 + 2.0943951023931953)), -cos
                   (intrm_sf_mf_17 + 2.0943951023931953)) * (real_T)(M_idx_25 !=
              0) + -atan2(fabs(-sin(intrm_sf_mf_17 + 2.0943951023931953)), -cos
              (intrm_sf_mf_17 + 2.0943951023931953)) * (real_T)(M_idx_25 == 0))
    + 3.1415926535897931;
  t6[0ULL] = X_idx_0;
  _in1ivar = 8ULL;
  tlu2_linear_nearest_prelookup((void *)&efOut.mField0, (void *)&efOut.mField1,
    (void *)&efOut.mField2, (void *)nonscalar2, (void *)t6, (void *)&_in1ivar);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_value((void *)&b_efOut, (void *)efOut.mField0, (void *)
    efOut.mField1, (void *)efOut.mField2, (void *)nonscalar3, (void *)&_in1ivar);
  X_idx_0 = (atan2(fabs(-sin(intrm_sf_mf_17)), -cos(intrm_sf_mf_17)) * (real_T)
             (M_idx_23 != 0) + -atan2(fabs(-sin(intrm_sf_mf_17)), -cos
              (intrm_sf_mf_17)) * (real_T)(M_idx_23 == 0)) + 3.1415926535897931;
  t6[0ULL] = X_idx_0;
  _in1ivar = 8ULL;
  tlu2_linear_nearest_prelookup((void *)&c_efOut.mField0, (void *)
    &c_efOut.mField1, (void *)&c_efOut.mField2, (void *)nonscalar2, (void *)t6,
    (void *)&_in1ivar);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_value((void *)&d_efOut, (void *)c_efOut.mField0, (void *)
    c_efOut.mField1, (void *)c_efOut.mField2, (void *)nonscalar3, (void *)
    &_in1ivar);
  X_idx_0 = (atan2(fabs(-sin(intrm_sf_mf_17 + -2.0943951023931953)), -cos
                   (intrm_sf_mf_17 + -2.0943951023931953)) * (real_T)(M_idx_24
              != 0) + -atan2(fabs(-sin(intrm_sf_mf_17 + -2.0943951023931953)),
              -cos(intrm_sf_mf_17 + -2.0943951023931953)) * (real_T)(M_idx_24 ==
              0)) + 3.1415926535897931;
  t6[0ULL] = X_idx_0;
  _in1ivar = 8ULL;
  tlu2_linear_nearest_prelookup((void *)&e_efOut.mField0, (void *)
    &e_efOut.mField1, (void *)&e_efOut.mField2, (void *)nonscalar2, (void *)t6,
    (void *)&_in1ivar);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_value((void *)&f_efOut, (void *)e_efOut.mField0, (void *)
    e_efOut.mField1, (void *)e_efOut.mField2, (void *)nonscalar3, (void *)
    &_in1ivar);
  zc_int12[0ULL] = d_efOut[0];
  zc_int12[1ULL] = f_efOut[0];
  zc_int12[2ULL] = b_efOut[0];
  out.mX[0] = -((((-(d_efOut[0] * 7.0) * t24 + -(f_efOut[0] * 7.0) * t25) +
                  -(b_efOut[0] * 7.0) * t26) - (-(X_idx_3 *
    3.0200000000000002E-5 * 7.0))) * 1.732050807568877);
  out.mX[1] = -((((-(d_efOut[0] * 7.0) * t27 + -(f_efOut[0] * 7.0) * t28) +
                  -(b_efOut[0] * 7.0) * t29) - X_idx_2 * 3.0200000000000002E-5 *
                 7.0) * 1.5);
  out.mX[2] = -(((-(d_efOut[0] * 7.0) * 0.33333333333333331 + -(f_efOut[0] * 7.0)
                  * 0.33333333333333331) + -(b_efOut[0] * 7.0) *
                 0.33333333333333331) * 3.0);
  out.mX[3] = zc_int12[0ULL] * 7.0;
  out.mX[4] = zc_int12[1ULL] * 7.0;
  out.mX[5] = zc_int12[2ULL] * 7.0;
  (void)t0;
  (void)t37;
  return 0;
}
