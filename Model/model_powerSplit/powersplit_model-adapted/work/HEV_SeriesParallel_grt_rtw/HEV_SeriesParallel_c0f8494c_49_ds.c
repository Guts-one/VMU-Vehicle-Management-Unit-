/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'HEV_SeriesParallel/Electrical/Solver Configuration'.
 */
/* HEV_SeriesParallel_c0f8494c_49_ds.c - body for module HEV_SeriesParallel_c0f8494c_49_ds */

#include "ne_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_y.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_ic.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_f.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_dxy_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_slv.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_mcon_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_slf.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_dxicr_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_dxicrm_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_obs_exp.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_mode.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_zc.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_q1_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_eq_tol.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_dxm_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_lv.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_acon_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_imin.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_mnl_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_vdf.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_qx_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_mdxy_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_apar_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_vpf.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_imax.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_vsf.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_nldv.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sclv.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_dxf.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_tdxy_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_obs_act.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_dxy.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_var_tol.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_dnf_v_x.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_tdxf_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_log.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_icrm_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_assert.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_obs_all.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_mpar_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_obs_il.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_slf0.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_vmf.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_dxf_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_acon.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_dnf_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_dxcer_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_dxdelt_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_qx.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds.h"
#include "ssc_ml_fun.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_external_struct.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_externals.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sys_struct.h"

static int32_T ds_mcon(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_mpar(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_mnl(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_vmm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dxm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_ddm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dum_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dum(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dtm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dpm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dpm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_apar(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_bcon_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_bcon(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_bpar_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_bpar(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_ccon_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ccon(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_cpar_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_cpar(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_duf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_duf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dtf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_ddf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dpdxf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_dpdxf(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dwf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dwf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_tduf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dnf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_cer(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dxcer(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddcer(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddcer_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_icr(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_icr_im(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_icr_id(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_icr_il(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxicr(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddicr(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddicr_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_tduicr_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_icrm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dxicrm(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddicrm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddicrm(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_freqs(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_solverhits(const NeDynamicSystem *ds, const
  NeDynamicSystemInput *in, NeDsMethodOutput *out);
static int32_T ds_mduy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_tduy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_duy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_duy(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dty_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dty(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_cache_r(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_cache_i(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_update_r(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_update_i(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_update2_r(const NeDynamicSystem *ds, const
  NeDynamicSystemInput *in, NeDsMethodOutput *out);
static int32_T ds_update2_i(const NeDynamicSystem *ds, const
  NeDynamicSystemInput *in, NeDsMethodOutput *out);
static int32_T ds_lock_r(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_lock_i(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_lock2_r(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_lock2_i(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_sfo(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_sfp(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_init_r(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_init_i(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_passert(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_iassert(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_del_t(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_del_v(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_del_v0(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_del_tmax(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxdelt(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dudelt_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dudelt(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtdelt_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtdelt(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dp_l(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dp_i(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dp_j(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dp_r(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_qu(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_qt(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_q1(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_qu_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_qt_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dimin(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dimax(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static NeDsMethodOutput *ds_output_mcon_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mcon(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mpar_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mpar(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mnl_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_mnl(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_vmm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_ddm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_ddm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dum_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dum(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dtm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dtm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dpm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dpm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_acon_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_acon(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_apar_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_apar(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_bcon_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_bcon(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_bpar_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_bpar(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_ccon_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_ccon(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_cpar_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_cpar(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_f(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_vdf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_vmf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_vpf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_vsf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_slf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_slf0(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_duf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_duf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dtf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dtf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_ddf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_ddf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dpdxf_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dpdxf(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dwf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dwf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tduf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tdxf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dnf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dnf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dnf_v_x(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_cer(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxcer(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxcer_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_ddcer(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_ddcer_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_ic(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr_im(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr_id(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr_il(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxicr(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_ddicr(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_ddicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_tduicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_icrm_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icrm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxicrm_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dxicrm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_ddicrm_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_ddicrm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_freqs(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_solverhits(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_mduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_y(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxy(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_duy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_duy(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dty_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dty(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mode(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_zc(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_cache_r(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_cache_i(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_update_r(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_update_i(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_update2_r(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_update2_i(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_lock_r(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_lock_i(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_lock2_r(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_lock2_i(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_sfo(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_sfp(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_init_r(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_init_i(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_log(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_assert(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_passert(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_iassert(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_del_t(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_del_v(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_del_v0(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_del_tmax(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dxdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dxdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dudelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dudelt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dtdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dtdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_obs_exp(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_obs_act(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_obs_all(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_obs_il(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_l(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_i(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_j(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_r(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qx(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qu(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_q1(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qx_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qu_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qt_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_q1_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_var_tol(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_eq_tol(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_lv(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_slv(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_nldv(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_sclv(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_imin(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_imax(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dimin(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dimax(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static void release_reference(NeDynamicSystem *ds);
static void get_reference(NeDynamicSystem *ds);
static NeDynamicSystem *diagnostics(NeDynamicSystem *ds, boolean_T);
static void expand(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                   PmRealVector *out, boolean_T kp);
static void rtpmap(const NeDynamicSystem * ds, const PmIntVector* inl, const
                   PmIntVector* ini, const PmIntVector* inj, const PmRealVector*
                   inr, PmIntVector* outl, PmIntVector* outi, PmIntVector* outj,
                   PmRealVector* outr);
static NeEquationData s_equation_data[58] = { { "", 0U, 8,
    NE_EQUATION_DOMAIN_TIME, "", 0U, 0U, TRUE, 1.0, "1", }, { "", 0U, 8,
    NE_EQUATION_DOMAIN_TIME, "", 0U, 0U, TRUE, 1.0, "1", }, { "", 0U, 8,
    NE_EQUATION_DOMAIN_TIME, "", 0U, 0U, TRUE, 1.0, "1", }, { "", 0U, 8,
    NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", 1U, 0U,
    TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/Motion Sensor",
    1U, 1U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 5U, 2U, TRUE, 1.0, "1", },
  { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 2U, 7U, FALSE, 1.0, "1", },
  { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Electrical/Generic/Lossy Ultracapacitor", 1U, 9U, TRUE,
    1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", 1U, 10U, TRUE,
    1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/Motion Sensor", 1U,
    11U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Engine/Sensor/Ideal Rotational Motion Sensor", 1U, 12U,
    TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft/Ideal Rotational Motion Sensor",
    1U, 13U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft/Ideal Rotational Motion Sensor",
    1U, 14U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft/Ideal Rotational Motion Sensor",
    1U, 15U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Vehicle/Sensor Speed and  Power/Ideal Rotational Motion Sensor",
    1U, 16U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Vehicle/Vehicle Body", 1U, 17U, FALSE, 1.0, "1", }, { "",
    0U, 8, NE_EQUATION_DOMAIN_TIME, "HEV_SeriesParallel/Vehicle/Vehicle Body",
    1U, 18U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Electrical/Generator/System/Inertia", 2U, 19U, TRUE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Electrical/Motor/System/Inertia", 2U, 21U, TRUE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Engine/Engine Shaft Inertia", 2U, 23U, TRUE, 1.0, "1", },
  { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Vehicle/Inertia Diff LTire", 2U, 25U, TRUE, 1.0, "1", },
  { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Vehicle/Inertia Diff RTire", 2U, 27U, TRUE, 1.0, "1", },
  { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Vehicle/Inertia GBox Diff", 2U, 29U, TRUE, 1.0, "1", },
    { "", 0U, 8, NE_EQUATION_DOMAIN_TIME, "HEV_SeriesParallel/Vehicle/Left Tire",
    2U, 31U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Vehicle/Right Tire", 2U, 33U, TRUE, 1.0, "1", }, { "",
    0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", 5U, 35U,
    TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", 3U, 40U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", 1U, 43U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 44U, FALSE, 1.0, "1",
  }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", 5U, 45U, TRUE,
    1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", 3U, 50U, FALSE,
    1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", 1U, 53U, FALSE,
    1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Engine/Generic Engine", 1U, 54U, FALSE, 1.0, "1", }, {
    "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Engine/Generic Engine", 6U, 55U, FALSE, 1.0, "1", }, {
    "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Engine/Generic Engine", 3U, 61U, FALSE, 1.0, "1", }, {
    "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", 1U, 64U, TRUE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", 1U, 65U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", 1U, 66U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", 1U, 67U, TRUE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", 1U, 68U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", 1U, 69U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Vehicle/Inertia GBox Diff", 1U, 70U, TRUE, 1.0, "1", },
    { "", 0U, 8, NE_EQUATION_DOMAIN_TIME, "HEV_SeriesParallel/Vehicle/Left Tire",
    1U, 71U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Vehicle/Left Tire", 1U, 72U, FALSE, 1.0, "1", }, { "",
    0U, 8, NE_EQUATION_DOMAIN_TIME, "HEV_SeriesParallel/Vehicle/Left Tire", 1U,
    73U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Vehicle/Left Tire", 1U, 74U, FALSE, 1.0, "1", }, { "",
    0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Vehicle/Rear Differential", 1U, 75U, TRUE, 1.0, "1", },
    { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Vehicle/Right Tire", 1U, 76U, TRUE, 1.0, "1", }, { "",
    0U, 8, NE_EQUATION_DOMAIN_TIME, "HEV_SeriesParallel/Vehicle/Right Tire", 1U,
    77U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Vehicle/Right Tire", 1U, 78U, FALSE, 1.0, "1", }, { "",
    0U, 8, NE_EQUATION_DOMAIN_TIME, "HEV_SeriesParallel/Vehicle/Right Tire", 1U,
    79U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Vehicle/Vehicle Body", 1U, 80U, TRUE, 1.0, "1", }, { "",
    0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", 1U, 81U, TRUE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", 1U, 82U, TRUE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Vehicle/Inertia GBox Diff", 1U, 83U, TRUE, 1.0, "1", },
    { "", 0U, 8, NE_EQUATION_DOMAIN_TIME, "HEV_SeriesParallel/Vehicle/Left Tire",
    1U, 84U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Vehicle/Rear Differential", 1U, 85U, TRUE, 1.0, "1", },
    { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "HEV_SeriesParallel/Vehicle/Right Tire", 1U, 86U, TRUE, 1.0, "1", } };

static NeCERData *s_cer_data = NULL;
static NeICRData s_icr_data[6] = { { "", 0U, 0,
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 0U, }, { "", 0U, 0,
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", 1U, 1U, }, { "", 0U,
    0, "HEV_SeriesParallel/Power Split Device/Planetary Gear", 1U, 2U, }, { "",
    0U, 0, "HEV_SeriesParallel/Vehicle/Rear Differential", 1U, 3U, }, { "", 0U,
    0, "HEV_SeriesParallel/Vehicle/Rear Differential", 1U, 4U, }, { "", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Rear Differential", 1U, 5U, } };

static NeVariableData s_variable_data[58] = { {
    "Electrical.Generic.Lossy_Ultracapacitor.vc", 0U, 0,
    "HEV_SeriesParallel/Electrical/Generic/Lossy Ultracapacitor", 1.0, "1", 0.0,
    TRUE, FALSE, { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Capacitor voltage", }, {
    "Electrical.Generator.System.Motor_and_Drive.torque_ref", 0U, 0,
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", 1.0, "1",
    0.0, TRUE, FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Demanded torque", }, {
    "Electrical.Generator.System.Sensor_shaft.Motion_Sensor.phi", 0U, 0,
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/Motion Sensor",
    1.0, "1", 0.0, TRUE, FALSE, { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Angle", },
  { "Electrical.Generic.Battery.num_cycles", 0U, 0,
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1.0, "1", 0.0, TRUE, FALSE,
    { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Discharge cycles", }, {
    "Electrical.Generic.Battery.charge", 0U, 0,
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1.0, "1", 0.0, TRUE, FALSE,
    { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Charge", }, {
    "Electrical.Motor.System.Motor_and_Drive.torque_ref", 0U, 0,
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", 1.0, "1", 0.0,
    TRUE, FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Demanded torque", }, {
    "Electrical.Motor.System.Sensor_shaft.Motion_Sensor.phi", 0U, 0,
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/Motion Sensor", 1.0,
    "1", 0.0, TRUE, FALSE, { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Angle", }, {
    "Engine.Sensor.Ideal_Rotational_Motion_Sensor.phi", 0U, 0,
    "HEV_SeriesParallel/Engine/Sensor/Ideal Rotational Motion Sensor", 1.0, "1",
    0.0, TRUE, FALSE, { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Angle", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.P.w", 0U, 1,
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", 1.0, "1", 0.0, TRUE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Carrier_Shaft.Ideal_Rotational_Motion_Sensor.phi",
    0U, 0,
    "HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft/Ideal Rotational Motion Sensor",
    1.0, "1", 0.0, TRUE, FALSE, { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Angle", },
  { "Power_Split_Device.Sensor_Ring_Shaft.Ideal_Rotational_Motion_Sensor.phi",
    0U, 0,
    "HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft/Ideal Rotational Motion Sensor",
    1.0, "1", 0.0, TRUE, FALSE, { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Angle", },
  { "Power_Split_Device.Sensor_Sun_Shaft.Ideal_Rotational_Motion_Sensor.phi", 0U,
    0,
    "HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft/Ideal Rotational Motion Sensor",
    1.0, "1", 0.0, TRUE, FALSE, { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Angle", },
  { "Vehicle.Left_Tire.tire_inertia.w", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Left Tire", 1.0, "1", 0.0, TRUE, FALSE, { 1,
      "1x1" }, NE_INIT_MODE_MANDATORY, "Rotational velocity", }, {
    "Vehicle.Vehicle_Body.v", 0U, 0, "HEV_SeriesParallel/Vehicle/Vehicle Body",
    1.0, "1", 0.0, TRUE, FALSE, { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Velocity",
  }, { "Vehicle.Right_Tire.tire_inertia.w", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Right Tire", 1.0, "1", 0.0, TRUE, FALSE, { 1,
      "1x1" }, NE_INIT_MODE_MANDATORY, "Rotational velocity", }, {
    "Vehicle.Sensor_Speed_and_Power.Ideal_Rotational_Motion_Sensor.phi", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Sensor Speed and  Power/Ideal Rotational Motion Sensor",
    1.0, "1", 0.0, TRUE, FALSE, { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Angle", },
  { "Vehicle.Vehicle_Body.elevation", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Vehicle Body", 1.0, "1", 0.0, TRUE, FALSE, { 1,
      "1x1" }, NE_INIT_MODE_MANDATORY, "Elevation change", }, {
    "Electrical.DC_DC_Converter.Ideal_Transformer.p2.v", 0U, 1,
    "HEV_SeriesParallel/Electrical/DC-DC Converter/Ideal Transformer", 1.0, "1",
    0.0, FALSE, FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Voltage", }, {
    "Electrical.Generic.Battery.i", 0U, 0,
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Current (positive in)", }, {
    "Electrical.Generator.System.Inertia.w", 0U, 0,
    "HEV_SeriesParallel/Electrical/Generator/System/Inertia", 1.0, "1", 0.0,
    FALSE, FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Rotational velocity", }, {
    "Electrical.Generator.System.Motor_and_Drive.torque_elec", 0U, 0,
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", 1.0, "1",
    0.0, FALSE, FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Electrical torque", },
    { "Engine.Engine_Shaft_Inertia.w", 0U, 0,
    "HEV_SeriesParallel/Engine/Engine Shaft Inertia", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.gear.sun_planet.t_S", 0U, 0,
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Sun torque", }, {
    "Electrical.Generator.System.Inertia.w.w_ir_dummy_derivative_0", 0U, 0,
    "HEV_SeriesParallel/Electrical/Generator/System/Inertia", 1.0, "1", 0.0,
    FALSE, FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE,
    "Secondary variable obtained from variable w during index reduction.", }, {
    "Electrical.Motor.System.Motor_and_Drive.i", 0U, 0,
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", 1.0, "1", 0.0,
    FALSE, FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Current", }, {
    "Electrical.Generator.System.Motor_and_Drive.torqueLimit", 0U, 0,
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", 1.0, "1",
    0.0, FALSE, FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE,
    "Maximum torque magnitude", }, { "Electrical.Motor.System.Inertia.w", 0U, 0,
    "HEV_SeriesParallel/Electrical/Motor/System/Inertia", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Rotational velocity", }, {
    "Electrical.Motor.System.Motor_and_Drive.torque_elec", 0U, 0,
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", 1.0, "1", 0.0,
    FALSE, FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Electrical torque", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.t_R", 0U, 0,
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Ring torque", }, {
    "Vehicle.Inertia_GBox_Diff.t", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Inertia GBox Diff", 1.0, "1", 0.0, FALSE, FALSE,
    { 1, "1x1" }, NE_INIT_MODE_NONE, "Torque", }, {
    "Vehicle.Rear_Differential.base_gear.tB", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Rear Differential", 1.0, "1", 0.0, FALSE, FALSE,
    { 1, "1x1" }, NE_INIT_MODE_NONE, "Base torque", }, {
    "Electrical.Motor.System.Inertia.w.w_ir_dummy_derivative_1", 0U, 0,
    "HEV_SeriesParallel/Electrical/Motor/System/Inertia", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE,
    "Secondary variable obtained from variable w during index reduction.", }, {
    "Electrical.Motor.System.Motor_and_Drive.torqueLimit", 0U, 0,
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", 1.0, "1", 0.0,
    FALSE, FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Maximum torque magnitude", },
  { "Engine.Generic_Engine.trq", 0U, 0,
    "HEV_SeriesParallel/Engine/Generic Engine", 1.0, "1", 0.0, FALSE, FALSE, { 1,
      "1x1" }, NE_INIT_MODE_NONE, "Torque", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.t_C", 0U, 0,
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Carrier torque", }, {
    "Power_Split_Device.Planetary_Gear.gear.sun_planet.t_C", 0U, 0,
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Carrier torque", }, {
    "Engine.Engine_Shaft_Inertia.w.w_ir_dummy_derivative_2", 0U, 0,
    "HEV_SeriesParallel/Engine/Engine Shaft Inertia", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE,
    "Secondary variable obtained from variable w during index reduction.", }, {
    "Engine.Generic_Engine.FC", 0U, 0,
    "HEV_SeriesParallel/Engine/Generic Engine", 1.0, "1", 0.0, FALSE, FALSE, { 1,
      "1x1" }, NE_INIT_MODE_NONE, "FC", }, {
    "Engine.Generic_Engine.controlled_throttle", 0U, 0,
    "HEV_SeriesParallel/Engine/Generic Engine", 1.0, "1", 0.0, FALSE, FALSE, { 1,
      "1x1" }, NE_INIT_MODE_NONE, "Controlled throttle", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.P.w.w_ir_replaced_dot_2",
    0U, 0, "HEV_SeriesParallel/Power Split Device/Planetary Gear", 1.0, "1", 0.0,
    FALSE, FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE,
    "Secondary variable obtained from variable w during index reduction.", }, {
    "Power_Split_Device.Planetary_Gear.gear.sun_planet.t_P", 0U, 0,
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Planet torque", }, {
    "Vehicle.Left_Tire.tire_inertia.t", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Left Tire", 1.0, "1", 0.0, FALSE, FALSE, { 1,
      "1x1" }, NE_INIT_MODE_NONE, "Torque", }, {
    "Vehicle.Left_Tire.tire_road_interaction.f_tread", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Left Tire", 1.0, "1", 0.0, FALSE, FALSE, { 1,
      "1x1" }, NE_INIT_MODE_NONE, "Tread force", }, {
    "Vehicle.Inertia_Diff_LTire.w", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Inertia Diff LTire", 1.0, "1", 0.0, FALSE, FALSE,
    { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Rotational velocity", }, {
    "Vehicle.Inertia_Diff_LTire.w.w_ir_dummy_derivative_3", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Inertia Diff LTire", 1.0, "1", 0.0, FALSE, FALSE,
    { 1, "1x1" }, NE_INIT_MODE_NONE,
    "Secondary variable obtained from variable w during index reduction.", }, {
    "Vehicle.Right_Tire.tire_inertia.t", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Right Tire", 1.0, "1", 0.0, FALSE, FALSE, { 1,
      "1x1" }, NE_INIT_MODE_NONE, "Torque", }, {
    "Vehicle.Right_Tire.tire_road_interaction.f_tread", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Right Tire", 1.0, "1", 0.0, FALSE, FALSE, { 1,
      "1x1" }, NE_INIT_MODE_NONE, "Tread force", }, {
    "Vehicle.Inertia_Diff_RTire.w", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Inertia Diff RTire", 1.0, "1", 0.0, FALSE, FALSE,
    { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Rotational velocity", }, {
    "Vehicle.Inertia_Diff_RTire.w.w_ir_dummy_derivative_4", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Inertia Diff RTire", 1.0, "1", 0.0, FALSE, FALSE,
    { 1, "1x1" }, NE_INIT_MODE_NONE,
    "Secondary variable obtained from variable w during index reduction.", }, {
    "Vehicle.Inertia_GBox_Diff.w", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Inertia GBox Diff", 1.0, "1", 0.0, FALSE, FALSE,
    { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Rotational velocity", }, {
    "Vehicle.Inertia_GBox_Diff.w.w_ir_dummy_derivative_5", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Inertia GBox Diff", 1.0, "1", 0.0, FALSE, FALSE,
    { 1, "1x1" }, NE_INIT_MODE_NONE,
    "Secondary variable obtained from variable w during index reduction.", }, {
    "Vehicle.Left_Tire.N", 0U, 0, "HEV_SeriesParallel/Vehicle/Left Tire", 1.0,
    "1", 0.0, FALSE, FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "N", }, {
    "Vehicle.Left_Tire.S", 0U, 0, "HEV_SeriesParallel/Vehicle/Left Tire", 1.0,
    "1", 0.0, FALSE, FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "S", }, {
    "Vehicle.Left_Tire.tire_inertia.w.w_ir_replaced_dot_0", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Left Tire", 1.0, "1", 0.0, FALSE, FALSE, { 1,
      "1x1" }, NE_INIT_MODE_NONE,
    "Secondary variable obtained from variable w during index reduction.", }, {
    "Vehicle.Right_Tire.tire_road_interaction.f_hub", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Right Tire", 1.0, "1", 0.0, FALSE, FALSE, { 1,
      "1x1" }, NE_INIT_MODE_NONE, "Hub force", }, { "Vehicle.Vehicle_Body.f", 0U,
    0, "HEV_SeriesParallel/Vehicle/Vehicle Body", 1.0, "1", 0.0, FALSE, FALSE, {
      1, "1x1" }, NE_INIT_MODE_NONE, "Longitudinal force", }, {
    "Vehicle.Right_Tire.S", 0U, 0, "HEV_SeriesParallel/Vehicle/Right Tire", 1.0,
    "1", 0.0, FALSE, FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "S", }, {
    "Vehicle.Right_Tire.tire_inertia.w.w_ir_replaced_dot_1", 0U, 0,
    "HEV_SeriesParallel/Vehicle/Right Tire", 1.0, "1", 0.0, FALSE, FALSE, { 1,
      "1x1" }, NE_INIT_MODE_NONE,
    "Secondary variable obtained from variable w during index reduction.", } };

static NeVariableData *s_discrete_data = NULL;
static NeObservableData s_observable_data[497] = { {
    "Electrical.DC_DC_Converter.Ideal_Transformer.i1",
    "HEV_SeriesParallel/Electrical/DC-DC Converter/Ideal Transformer", { 1,
      "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Primary current", }, {
    "Electrical.DC_DC_Converter.Ideal_Transformer.i2",
    "HEV_SeriesParallel/Electrical/DC-DC Converter/Ideal Transformer", { 1,
      "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Secondary current", }, {
    "Electrical.DC_DC_Converter.Ideal_Transformer.n1.v",
    "HEV_SeriesParallel/Electrical/DC-DC Converter/Ideal Transformer", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.DC_DC_Converter.Ideal_Transformer.n2.v",
    "HEV_SeriesParallel/Electrical/DC-DC Converter/Ideal Transformer", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.DC_DC_Converter.Ideal_Transformer.p1.v",
    "HEV_SeriesParallel/Electrical/DC-DC Converter/Ideal Transformer", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.DC_DC_Converter.Ideal_Transformer.p2.v",
    "HEV_SeriesParallel/Electrical/DC-DC Converter/Ideal Transformer", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.DC_DC_Converter.Ideal_Transformer.v1",
    "HEV_SeriesParallel/Electrical/DC-DC Converter/Ideal Transformer", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Primary voltage", }, {
    "Electrical.DC_DC_Converter.Ideal_Transformer.v2",
    "HEV_SeriesParallel/Electrical/DC-DC Converter/Ideal Transformer", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Secondary voltage", }, {
    "Electrical.DC_DC_Converter.x1.v",
    "HEV_SeriesParallel/Electrical/DC-DC Converter", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.DC_DC_Converter.x2.v",
    "HEV_SeriesParallel/Electrical/DC-DC Converter", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.DC_DC_Converter.x3.v",
    "HEV_SeriesParallel/Electrical/DC-DC Converter", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.DC_DC_Converter.x4.v",
    "HEV_SeriesParallel/Electrical/DC-DC Converter", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, { "Electrical.ERef.V.v",
    "HEV_SeriesParallel/Electrical/ERef", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Electrical_Reference.V.v",
    "HEV_SeriesParallel/Electrical/Electrical Reference", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Electrical.Gen.w",
    "HEV_SeriesParallel/Electrical", { 1, "1x1" }, "rad/s", 1.0, "1/s",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Electrical.Generator.R.w", "HEV_SeriesParallel/Electrical/Generator", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", },
    { "Electrical.Generator.System.GF.Shaft",
    "HEV_SeriesParallel/Electrical/Generator/System/GF", { 1, "1x1" }, "1", 1.0,
    "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Shaft", }, {
    "Electrical.Generator.System.GF.Simulink_PS_Converter_output0",
    "HEV_SeriesParallel/Electrical/Generator/System/GF/Simulink-PS\nConverter",
      { 1, "1x1" }, "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "Simulink_PS_Converter_output0", }, {
    "Electrical.Generator.System.Inertia.I.w",
    "HEV_SeriesParallel/Electrical/Generator/System/Inertia", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Generator.System.Inertia.J.w",
    "HEV_SeriesParallel/Electrical/Generator/System/Inertia", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Electrical.Generator.System.Inertia.t",
    "HEV_SeriesParallel/Electrical/Generator/System/Inertia", { 1, "1x1" },
    "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Electrical.Generator.System.Inertia.w",
    "HEV_SeriesParallel/Electrical/Generator/System/Inertia", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Generator.System.MRRef.W.w",
    "HEV_SeriesParallel/Electrical/Generator/System/MRRef", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Generator.System.Meas_V.Voltage_Sensor.V",
    "HEV_SeriesParallel/Electrical/Generator/System/Meas V/Voltage Sensor", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "V", }, {
    "Electrical.Generator.System.Meas_V.Voltage_Sensor.n.v",
    "HEV_SeriesParallel/Electrical/Generator/System/Meas V/Voltage Sensor", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Generator.System.Meas_V.Voltage_Sensor.p.v",
    "HEV_SeriesParallel/Electrical/Generator/System/Meas V/Voltage Sensor", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Generator.System.Meas_V.Voltage_Sensor_V0",
    "HEV_SeriesParallel/Electrical/Generator/System/Meas V/PS-Simulink\nConverter4",
    { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage_Sensor_V0", }, {
    "Electrical.Generator.System.Meas_V.x0.v",
    "HEV_SeriesParallel/Electrical/Generator/System/Meas V", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Generator.System.Meas_V.x1.v",
    "HEV_SeriesParallel/Electrical/Generator/System/Meas V", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Generator.System.Motor_and_Drive.F",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "OFF", }, {
    "Electrical.Generator.System.Motor_and_Drive.Omega",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "w", }, {
    "Electrical.Generator.System.Motor_and_Drive.R.w",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Generator.System.Motor_and_Drive.Tr",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Tr", }, {
    "Electrical.Generator.System.Motor_and_Drive.Vm.v",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Generator.System.Motor_and_Drive.Vp.v",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Generator.System.Motor_and_Drive.faultExtTrigger",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "OFF", }, {
    "Electrical.Generator.System.Motor_and_Drive.faulted",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Faulted flag", }, {
    "Electrical.Generator.System.Motor_and_Drive.isSwitchedOff",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Switch state", }, {
    "Electrical.Generator.System.Motor_and_Drive.C.w",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Generator.System.Motor_and_Drive.i",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Electrical.Generator.System.Motor_and_Drive.power_dissipated",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "W", 1.0, "kW", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Power dissipated", }, {
    "Electrical.Generator.System.Motor_and_Drive.t",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Electrical.Generator.System.Motor_and_Drive.torqueLimit",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Maximum torque magnitude", }, {
    "Electrical.Generator.System.Motor_and_Drive.torqueLimitContinuous",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "Calculated continuous torque limit (always positive)", }, {
    "Electrical.Generator.System.Motor_and_Drive.torque_elec",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Electrical torque", }, {
    "Electrical.Generator.System.Motor_and_Drive.torque_ref",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Demanded torque", }, {
    "Electrical.Generator.System.Motor_and_Drive.v",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Generator.System.Motor_and_Drive.w",
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", { 1, "1x1"
    }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Angular velocity", }, {
    "Electrical.Generator.System.PS_Terminator1.I",
    "HEV_SeriesParallel/Electrical/Generator/System/PS Terminator1", { 1, "1x1"
    }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I", }, {
    "Electrical.Generator.System.Power_Sensor.Current_Sensor.I",
    "HEV_SeriesParallel/Electrical/Generator/System/Power Sensor/Current Sensor",
    { 1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I", }, {
    "Electrical.Generator.System.Power_Sensor.Current_Sensor.i1",
    "HEV_SeriesParallel/Electrical/Generator/System/Power Sensor/Current Sensor",
    { 1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Electrical.Generator.System.Power_Sensor.Current_Sensor.n.v",
    "HEV_SeriesParallel/Electrical/Generator/System/Power Sensor/Current Sensor",
    { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Generator.System.Power_Sensor.Current_Sensor.p.v",
    "HEV_SeriesParallel/Electrical/Generator/System/Power Sensor/Current Sensor",
    { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Generator.System.Power_Sensor.PS_Product1.I1",
    "HEV_SeriesParallel/Electrical/Generator/System/Power Sensor/PS Product1", {
      1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I1", }, {
    "Electrical.Generator.System.Power_Sensor.PS_Product1.I2",
    "HEV_SeriesParallel/Electrical/Generator/System/Power Sensor/PS Product1", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I2", }, {
    "Electrical.Generator.System.Power_Sensor.PS_Product1.O",
    "HEV_SeriesParallel/Electrical/Generator/System/Power Sensor/PS Product1", {
      1, "1x1" }, "A*V", 1.0, "kW", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "O", }, {
    "Electrical.Generator.System.Power_Sensor.PS_Product1_O0",
    "HEV_SeriesParallel/Electrical/Generator/System/Power\nSensor/PS-Simulink\nConverter4",
    { 1, "1x1" }, "W", 1.0, "kW", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "PS_Product1_O0", }, {
    "Electrical.Generator.System.Power_Sensor.Voltage_Sensor.V",
    "HEV_SeriesParallel/Electrical/Generator/System/Power Sensor/Voltage Sensor",
    { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "V", }, {
    "Electrical.Generator.System.Power_Sensor.Voltage_Sensor.n.v",
    "HEV_SeriesParallel/Electrical/Generator/System/Power Sensor/Voltage Sensor",
    { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Generator.System.Power_Sensor.Voltage_Sensor.p.v",
    "HEV_SeriesParallel/Electrical/Generator/System/Power Sensor/Voltage Sensor",
    { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Generator.System.Power_Sensor.ref.v",
    "HEV_SeriesParallel/Electrical/Generator/System/Power Sensor", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Generator.System.Power_Sensor.x0.v",
    "HEV_SeriesParallel/Electrical/Generator/System/Power Sensor", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Generator.System.Power_Sensor.x1.v",
    "HEV_SeriesParallel/Electrical/Generator/System/Power Sensor", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Generator.System.R.w",
    "HEV_SeriesParallel/Electrical/Generator/System", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Electrical.Generator.System.Sensor_shaft.C.w",
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Electrical.Generator.System.Sensor_shaft.MRRef.W.w",
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/MRRef", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Generator.System.Sensor_shaft.Motion_Sensor.A",
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/Motion Sensor",
    { 1, "1x1" }, "rad", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "A", }, {
    "Electrical.Generator.System.Sensor_shaft.Motion_Sensor.C.w",
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/Motion Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Generator.System.Sensor_shaft.Motion_Sensor.R.w",
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/Motion Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Generator.System.Sensor_shaft.Motion_Sensor.W",
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/Motion Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "W", }, {
    "Electrical.Generator.System.Sensor_shaft.Motion_Sensor.alpha",
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/Motion Sensor",
    { 1, "1x1" }, "rad/s^2", 1.0, "1/s^2", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_NONE, TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "\\u03B1", }, { "Electrical.Generator.System.Sensor_shaft.Motion_Sensor.phi",
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/Motion Sensor",
    { 1, "1x1" }, "deg", 1.0, "1", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_MANDATORY, FALSE, TRUE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE,
    "Angle", }, { "Electrical.Generator.System.Sensor_shaft.Motion_Sensor_A0",
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor\nshaft/PS-Simulink\nConverter2",
    { 1, "1x1" }, "rad", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Motion_Sensor_A0", }, {
    "Electrical.Generator.System.Sensor_shaft.Motion_Sensor_W0",
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor\nshaft/PS-Simulink\nConverter1",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Motion_Sensor_W0", }, {
    "Electrical.Generator.System.Sensor_shaft.R.w",
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Electrical.Generator.System.Sensor_shaft.Torque_Sensor.C.w",
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/Torque Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Generator.System.Sensor_shaft.Torque_Sensor.R.w",
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/Torque Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Generator.System.Sensor_shaft.Torque_Sensor.T",
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/Torque Sensor",
    { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "T", }, {
    "Electrical.Generator.System.Sensor_shaft.Torque_Sensor.t",
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/Torque Sensor",
    { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Electrical.Generator.System.Sensor_shaft.Torque_Sensor_T0",
    "HEV_SeriesParallel/Electrical/Generator/System/Sensor\nshaft/PS-Simulink\nConverter3",
    { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Torque_Sensor_T0", }, {
    "Electrical.Generator.System.x0.v",
    "HEV_SeriesParallel/Electrical/Generator/System", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Generator.System.x1.v",
    "HEV_SeriesParallel/Electrical/Generator/System", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Generator.x0.v", "HEV_SeriesParallel/Electrical/Generator", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Generator.x1.v", "HEV_SeriesParallel/Electrical/Generator", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Generic.Battery.G2",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "S", 1.0,
    "S", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "G2", }, {
    "Electrical.Generic.Battery.H.T",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "K", 1.0,
    "K", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Electrical.Generic.Battery.num_cycles",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "1", 1.0,
    "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Discharge cycles", }, {
    "Electrical.Generic.Battery.N",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "1", 1.0,
    "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Number of discharge cycles", }, {
    "Electrical.Generic.Battery.temperature",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "K", 1.0,
    "K", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Electrical.Generic.Battery.i",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current (positive in)", }, {
    "Electrical.Generic.Battery.R1_age_multiplier",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "1", 1.0,
    "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "R1_age_multiplier", }, {
    "Electrical.Generic.Battery.xAH",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "C", 1.0,
    "C", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Faded battery capacity", }, {
    "Electrical.Generic.Battery.x1",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "1", 1.0,
    "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE,
    "Fraction of charge used when voltage is V1", }, {
    "Electrical.Generic.Battery.xV1",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "xV1", }, {
    "Electrical.Generic.Battery.y1",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "1", 1.0,
    "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE,
    "Voltage as a fraction of nominal voltage when charge is AH1", }, {
    "Electrical.Generic.Battery.beta",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "1", 1.0,
    "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE,
    "Voltage versus state-of-charge equation coefficient, beta", }, {
    "Electrical.Generic.Battery.charge",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "A*hr", 1.0,
    "C", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Charge", }, {
    "Electrical.Generic.Battery.x",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "1", 1.0,
    "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "State of charge", }, {
    "Electrical.Generic.Battery.Vbat",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Battery internal voltage, Vbat", }, {
    "Electrical.Generic.Battery.alpha",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "1", 1.0,
    "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE,
    "Voltage versus state-of-charge equation coefficient, alpha", }, {
    "Electrical.Generic.Battery.n.v",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Generic.Battery.p.v",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Generic.Battery.vrc1",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "vrc1", }, {
    "Electrical.Generic.Battery.vrc2",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "vrc2", }, {
    "Electrical.Generic.Battery.vrc3",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "vrc3", }, {
    "Electrical.Generic.Battery.vrc4",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "vrc4", }, {
    "Electrical.Generic.Battery.vrc5",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "vrc5", }, {
    "Electrical.Generic.Battery.power_dissipated",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "kW", 1.0,
    "kW", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Power dissipated", }, {
    "Electrical.Generic.Battery.q",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "C", 1.0,
    "C", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "q", }, { "Electrical.Generic.Battery.v",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Generic.Current_Sensor.I",
    "HEV_SeriesParallel/Electrical/Generic/Current Sensor", { 1, "1x1" }, "A",
    1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I", }, {
    "Electrical.Generic.Current_Sensor.i1",
    "HEV_SeriesParallel/Electrical/Generic/Current Sensor", { 1, "1x1" }, "A",
    1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Electrical.Generic.Current_Sensor.n.v",
    "HEV_SeriesParallel/Electrical/Generic/Current Sensor", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Generic.Current_Sensor.p.v",
    "HEV_SeriesParallel/Electrical/Generic/Current Sensor", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Generic.Lossy_Ultracapacitor.i",
    "HEV_SeriesParallel/Electrical/Generic/Lossy Ultracapacitor", { 1, "1x1" },
    "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Electrical.Generic.Lossy_Ultracapacitor.n.v",
    "HEV_SeriesParallel/Electrical/Generic/Lossy Ultracapacitor", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Generic.Lossy_Ultracapacitor.p.v",
    "HEV_SeriesParallel/Electrical/Generic/Lossy Ultracapacitor", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Generic.Lossy_Ultracapacitor.vc",
    "HEV_SeriesParallel/Electrical/Generic/Lossy Ultracapacitor", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Capacitor voltage", }, {
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.I",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge",
    { 1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I", }, {
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.PS_Product.I1",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge/PS Product",
    { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I1", }, {
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.PS_Product.I2",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge/PS Product",
    { 1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I2", }, {
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.PS_Product.O",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge/PS Product",
    { 1, "1x1" }, "A*V", 1.0, "kW", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "O", }, {
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.PS_Product1.I1",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge/PS Product1",
    { 1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I1", }, {
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.PS_Product1.I2",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge/PS Product1",
    { 1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I2", }, {
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.PS_Product1.O",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge/PS Product1",
    { 1, "1x1" }, "A^2", 1.0, "A^2", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "O", }, {
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.PS_Product_O0",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery\npower & charge/PS-Simulink\nConverter",
    { 1, "1x1" }, "W", 1.0, "kW", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "PS_Product_O0", }, {
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.R.I",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge/R",
    { 1, "1x1" }, "A^2", 1.0, "A^2", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I", }, {
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.R.O",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge/R",
    { 1, "1x1" }, "A^2*Ohm", 1.0, "kW", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_NONE, FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "O", },
    { "Electrical.Generic.Measurements1.Calculate_battery_power_charge.R_O0",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery\npower & charge/PS-Simulink\nConverter2",
    { 1, "1x1" }, "W", 1.0, "kW", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "R_O0", }, {
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.V",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge",
    { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "V", }, {
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.x1_6060.I",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge/-1//(60*60)",
    { 1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I", }, {
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.x1_6060.O",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge/-1//(60*60)",
    { 1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "O", }, {
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.x1_6060_O0",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery\npower & charge/PS-Simulink\nConverter1",
    { 1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "x1_6060_O0", }, {
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge_I0",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1/PS-Simulink\nConverter2",
    { 1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "Calculate_battery_power_charge_I0", }, {
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge_V0",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1/PS-Simulink\nConverter1",
    { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "Calculate_battery_power_charge_V0", }, {
    "Electrical.Generic.Measurements1.IBatt",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1", { 1, "1x1" }, "A",
    1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "IBatt", }, {
    "Electrical.Generic.Measurements1.VBatt",
    "HEV_SeriesParallel/Electrical/Generic/Measurements1", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "VBatt", }, {
    "Electrical.Generic.Voltage_Sensor.V",
    "HEV_SeriesParallel/Electrical/Generic/Voltage Sensor", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "V", }, {
    "Electrical.Generic.Voltage_Sensor.n.v",
    "HEV_SeriesParallel/Electrical/Generic/Voltage Sensor", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Generic.Voltage_Sensor.p.v",
    "HEV_SeriesParallel/Electrical/Generic/Voltage Sensor", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Electrical.Generic.x0.v",
    "HEV_SeriesParallel/Electrical/Generic", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Generic.x1.v", "HEV_SeriesParallel/Electrical/Generic", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Mot.w", "HEV_SeriesParallel/Electrical", { 1, "1x1" }, "rad/s",
    1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Electrical.Motor.R.w", "HEV_SeriesParallel/Electrical/Motor", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Electrical.Motor.System.GF.Conn1",
    "HEV_SeriesParallel/Electrical/Motor/System/GF", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Conn1", }, {
    "Electrical.Motor.System.GF.Simulink_PS_Converter_output0",
    "HEV_SeriesParallel/Electrical/Motor/System/GF/Simulink-PS\nConverter", { 1,
      "1x1" }, "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Simulink_PS_Converter_output0",
  }, { "Electrical.Motor.System.Inertia.I.w",
    "HEV_SeriesParallel/Electrical/Motor/System/Inertia", { 1, "1x1" }, "rad/s",
    1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Motor.System.Inertia.J.w",
    "HEV_SeriesParallel/Electrical/Motor/System/Inertia", { 1, "1x1" }, "rad/s",
    1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Electrical.Motor.System.Inertia.t",
    "HEV_SeriesParallel/Electrical/Motor/System/Inertia", { 1, "1x1" }, "N*m",
    1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Electrical.Motor.System.Inertia.w",
    "HEV_SeriesParallel/Electrical/Motor/System/Inertia", { 1, "1x1" }, "rad/s",
    1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Motor.System.MRRef.W.w",
    "HEV_SeriesParallel/Electrical/Motor/System/MRRef", { 1, "1x1" }, "rad/s",
    1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Motor.System.Meas_V.Voltage_Sensor.V",
    "HEV_SeriesParallel/Electrical/Motor/System/Meas V/Voltage Sensor", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "V", }, {
    "Electrical.Motor.System.Meas_V.Voltage_Sensor.n.v",
    "HEV_SeriesParallel/Electrical/Motor/System/Meas V/Voltage Sensor", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Motor.System.Meas_V.Voltage_Sensor.p.v",
    "HEV_SeriesParallel/Electrical/Motor/System/Meas V/Voltage Sensor", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Motor.System.Meas_V.Voltage_Sensor_V0",
    "HEV_SeriesParallel/Electrical/Motor/System/Meas V/PS-Simulink\nConverter4",
    { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage_Sensor_V0", }, {
    "Electrical.Motor.System.Meas_V.x0.v",
    "HEV_SeriesParallel/Electrical/Motor/System/Meas V", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Motor.System.Meas_V.x1.v",
    "HEV_SeriesParallel/Electrical/Motor/System/Meas V", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Motor.System.Motor_and_Drive.F",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "OFF", }, {
    "Electrical.Motor.System.Motor_and_Drive.Omega",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "w", }, {
    "Electrical.Motor.System.Motor_and_Drive.R.w",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Motor.System.Motor_and_Drive.Tr",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Tr", }, {
    "Electrical.Motor.System.Motor_and_Drive.Vm.v",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Motor.System.Motor_and_Drive.Vp.v",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Motor.System.Motor_and_Drive.faultExtTrigger",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "OFF", }, {
    "Electrical.Motor.System.Motor_and_Drive.faulted",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Faulted flag", }, {
    "Electrical.Motor.System.Motor_and_Drive.isSwitchedOff",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Switch state", }, {
    "Electrical.Motor.System.Motor_and_Drive.C.w",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Motor.System.Motor_and_Drive.i",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Electrical.Motor.System.Motor_and_Drive.power_dissipated",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "W", 1.0, "kW", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Power dissipated", }, {
    "Electrical.Motor.System.Motor_and_Drive.t",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Electrical.Motor.System.Motor_and_Drive.torqueLimit",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Maximum torque magnitude", }, {
    "Electrical.Motor.System.Motor_and_Drive.torqueLimitContinuous",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "Calculated continuous torque limit (always positive)", }, {
    "Electrical.Motor.System.Motor_and_Drive.torque_elec",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Electrical torque", }, {
    "Electrical.Motor.System.Motor_and_Drive.torque_ref",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Demanded torque", }, {
    "Electrical.Motor.System.Motor_and_Drive.v",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Motor.System.Motor_and_Drive.w",
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Angular velocity", }, {
    "Electrical.Motor.System.PS_Terminator.I",
    "HEV_SeriesParallel/Electrical/Motor/System/PS Terminator", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I", }, {
    "Electrical.Motor.System.Power_Sensor.Current_Sensor.I",
    "HEV_SeriesParallel/Electrical/Motor/System/Power Sensor/Current Sensor", {
      1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I", }, {
    "Electrical.Motor.System.Power_Sensor.Current_Sensor.i1",
    "HEV_SeriesParallel/Electrical/Motor/System/Power Sensor/Current Sensor", {
      1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Electrical.Motor.System.Power_Sensor.Current_Sensor.n.v",
    "HEV_SeriesParallel/Electrical/Motor/System/Power Sensor/Current Sensor", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Motor.System.Power_Sensor.Current_Sensor.p.v",
    "HEV_SeriesParallel/Electrical/Motor/System/Power Sensor/Current Sensor", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Motor.System.Power_Sensor.PS_Product1.I1",
    "HEV_SeriesParallel/Electrical/Motor/System/Power Sensor/PS Product1", { 1,
      "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I1", }, {
    "Electrical.Motor.System.Power_Sensor.PS_Product1.I2",
    "HEV_SeriesParallel/Electrical/Motor/System/Power Sensor/PS Product1", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I2", }, {
    "Electrical.Motor.System.Power_Sensor.PS_Product1.O",
    "HEV_SeriesParallel/Electrical/Motor/System/Power Sensor/PS Product1", { 1,
      "1x1" }, "A*V", 1.0, "kW", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "O", }, {
    "Electrical.Motor.System.Power_Sensor.PS_Product1_O0",
    "HEV_SeriesParallel/Electrical/Motor/System/Power\nSensor/PS-Simulink\nConverter4",
    { 1, "1x1" }, "W", 1.0, "kW", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "PS_Product1_O0", }, {
    "Electrical.Motor.System.Power_Sensor.Voltage_Sensor.V",
    "HEV_SeriesParallel/Electrical/Motor/System/Power Sensor/Voltage Sensor", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "V", }, {
    "Electrical.Motor.System.Power_Sensor.Voltage_Sensor.n.v",
    "HEV_SeriesParallel/Electrical/Motor/System/Power Sensor/Voltage Sensor", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Motor.System.Power_Sensor.Voltage_Sensor.p.v",
    "HEV_SeriesParallel/Electrical/Motor/System/Power Sensor/Voltage Sensor", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical.Motor.System.Power_Sensor.ref.v",
    "HEV_SeriesParallel/Electrical/Motor/System/Power Sensor", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Motor.System.Power_Sensor.x0.v",
    "HEV_SeriesParallel/Electrical/Motor/System/Power Sensor", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Motor.System.Power_Sensor.x1.v",
    "HEV_SeriesParallel/Electrical/Motor/System/Power Sensor", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Motor.System.R.w", "HEV_SeriesParallel/Electrical/Motor/System",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", },
    { "Electrical.Motor.System.Sensor_shaft.C.w",
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Electrical.Motor.System.Sensor_shaft.MRRef.W.w",
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/MRRef", { 1, "1x1"
    }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Motor.System.Sensor_shaft.Motion_Sensor.A",
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/Motion Sensor", { 1,
      "1x1" }, "rad", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "A", }, {
    "Electrical.Motor.System.Sensor_shaft.Motion_Sensor.C.w",
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/Motion Sensor", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Motor.System.Sensor_shaft.Motion_Sensor.R.w",
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/Motion Sensor", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Motor.System.Sensor_shaft.Motion_Sensor.W",
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/Motion Sensor", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "W", }, {
    "Electrical.Motor.System.Sensor_shaft.Motion_Sensor.alpha",
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/Motion Sensor", { 1,
      "1x1" }, "rad/s^2", 1.0, "1/s^2", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_NONE, TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "\\u03B1", }, { "Electrical.Motor.System.Sensor_shaft.Motion_Sensor.phi",
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/Motion Sensor", { 1,
      "1x1" }, "deg", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY,
    FALSE, TRUE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Angle", }, {
    "Electrical.Motor.System.Sensor_shaft.Motion_Sensor_A0",
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor\nshaft/PS-Simulink\nConverter2",
    { 1, "1x1" }, "rad", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Motion_Sensor_A0", }, {
    "Electrical.Motor.System.Sensor_shaft.Motion_Sensor_W0",
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor\nshaft/PS-Simulink\nConverter1",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Motion_Sensor_W0", }, {
    "Electrical.Motor.System.Sensor_shaft.R.w",
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Electrical.Motor.System.Sensor_shaft.Torque_Sensor.C.w",
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/Torque Sensor", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Motor.System.Sensor_shaft.Torque_Sensor.R.w",
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/Torque Sensor", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Electrical.Motor.System.Sensor_shaft.Torque_Sensor.T",
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/Torque Sensor", { 1,
      "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "T", }, {
    "Electrical.Motor.System.Sensor_shaft.Torque_Sensor.t",
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/Torque Sensor", { 1,
      "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Electrical.Motor.System.Sensor_shaft.Torque_Sensor_T0",
    "HEV_SeriesParallel/Electrical/Motor/System/Sensor\nshaft/PS-Simulink\nConverter3",
    { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Torque_Sensor_T0", }, {
    "Electrical.Motor.System.x0.v", "HEV_SeriesParallel/Electrical/Motor/System",
    { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Motor.System.x1.v", "HEV_SeriesParallel/Electrical/Motor/System",
    { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Electrical.Motor.x0.v", "HEV_SeriesParallel/Electrical/Motor", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, { "Electrical.Motor.x1.v",
    "HEV_SeriesParallel/Electrical/Motor", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, { "Engine.Damper.C.w",
    "HEV_SeriesParallel/Engine/Damper", { 1, "1x1" }, "rad/s", 1.0, "1/s",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Engine.Damper.R.w", "HEV_SeriesParallel/Engine/Damper", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Engine.Damper.t", "HEV_SeriesParallel/Engine/Damper", { 1, "1x1" }, "N*m",
    1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, { "Engine.Damper.w",
    "HEV_SeriesParallel/Engine/Damper", { 1, "1x1" }, "rad/s", 1.0, "1/s",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Engine.Damper.power_dissipated", "HEV_SeriesParallel/Engine/Damper", { 1,
      "1x1" }, "kg*m^2/s^3", 1.0, "kg*m^2/s^3", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_NONE, FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, FALSE,
    "power_dissipated", }, { "Engine.Engine_Shaft_Inertia.I.w",
    "HEV_SeriesParallel/Engine/Engine Shaft Inertia", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Engine.Engine_Shaft_Inertia.J.w",
    "HEV_SeriesParallel/Engine/Engine Shaft Inertia", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Engine.Engine_Shaft_Inertia.t",
    "HEV_SeriesParallel/Engine/Engine Shaft Inertia", { 1, "1x1" }, "N*m", 1.0,
    "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Engine.Engine_Shaft_Inertia.w",
    "HEV_SeriesParallel/Engine/Engine Shaft Inertia", { 1, "1x1" }, "rpm", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Engine.Generic_Engine.B.w", "HEV_SeriesParallel/Engine/Generic Engine", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Engine.Generic_Engine.F.w", "HEV_SeriesParallel/Engine/Generic Engine", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Engine.Generic_Engine.FC", "HEV_SeriesParallel/Engine/Generic Engine", { 1,
      "1x1" }, "kg/s", 1.0, "kg/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "FC", }, {
    "Engine.Generic_Engine.P", "HEV_SeriesParallel/Engine/Generic Engine", { 1,
      "1x1" }, "W", 1.0, "kW", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "P", }, {
    "Engine.Generic_Engine.ThrNorm", "HEV_SeriesParallel/Engine/Generic Engine",
    { 1, "1x1" }, "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Thr", }, {
    "Engine.Generic_Engine.TrqCmd", "HEV_SeriesParallel/Engine/Generic Engine",
      { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Trq", }, {
    "Engine.Generic_Engine.controlled_throttle",
    "HEV_SeriesParallel/Engine/Generic Engine", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Controlled throttle", }, {
    "Engine.Generic_Engine.lagged_throttle",
    "HEV_SeriesParallel/Engine/Generic Engine", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Lagged throttle", }, {
    "Engine.Generic_Engine.w", "HEV_SeriesParallel/Engine/Generic Engine", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Engine.Generic_Engine.lam", "HEV_SeriesParallel/Engine/Generic Engine", { 1,
      "1x1" }, "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "lam", }, {
    "Engine.Generic_Engine.trqWOT", "HEV_SeriesParallel/Engine/Generic Engine",
      { 1, "1x1" }, "J", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, FALSE,
    "Torque at wide-open throttle", }, { "Engine.Generic_Engine.trq",
    "HEV_SeriesParallel/Engine/Generic Engine", { 1, "1x1" }, "N*m", 1.0, "J",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Engine.MRRef_Engine_Housing.W.w",
    "HEV_SeriesParallel/Engine/MRRef Engine Housing", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Engine.Sensor.Engine.w", "HEV_SeriesParallel/Engine/Sensor", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Engine.Sensor.Ideal_Rotational_Motion_Sensor.A",
    "HEV_SeriesParallel/Engine/Sensor/Ideal Rotational Motion Sensor", { 1,
      "1x1" }, "rad", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "A", }, {
    "Engine.Sensor.Ideal_Rotational_Motion_Sensor.C.w",
    "HEV_SeriesParallel/Engine/Sensor/Ideal Rotational Motion Sensor", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Engine.Sensor.Ideal_Rotational_Motion_Sensor.R.w",
    "HEV_SeriesParallel/Engine/Sensor/Ideal Rotational Motion Sensor", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Engine.Sensor.Ideal_Rotational_Motion_Sensor.W",
    "HEV_SeriesParallel/Engine/Sensor/Ideal Rotational Motion Sensor", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "W", }, {
    "Engine.Sensor.Ideal_Rotational_Motion_Sensor.alpha",
    "HEV_SeriesParallel/Engine/Sensor/Ideal Rotational Motion Sensor", { 1,
      "1x1" }, "rad/s^2", 1.0, "1/s^2", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_NONE, TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "\\u03B1", }, { "Engine.Sensor.Ideal_Rotational_Motion_Sensor.phi",
    "HEV_SeriesParallel/Engine/Sensor/Ideal Rotational Motion Sensor", { 1,
      "1x1" }, "rad", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY,
    FALSE, TRUE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Angle", }, {
    "Engine.Sensor.Ideal_Rotational_Motion_Sensor_W0",
    "HEV_SeriesParallel/Engine/Sensor/PS-Simulink\nConverter1", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Ideal_Rotational_Motion_Sensor_W0", },
    { "Engine.Sensor.Ideal_Torque_Sensor.C.w",
    "HEV_SeriesParallel/Engine/Sensor/Ideal Torque Sensor", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Engine.Sensor.Ideal_Torque_Sensor.R.w",
    "HEV_SeriesParallel/Engine/Sensor/Ideal Torque Sensor", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Engine.Sensor.Ideal_Torque_Sensor.T",
    "HEV_SeriesParallel/Engine/Sensor/Ideal Torque Sensor", { 1, "1x1" }, "N*m",
    1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "T", }, {
    "Engine.Sensor.Ideal_Torque_Sensor.t",
    "HEV_SeriesParallel/Engine/Sensor/Ideal Torque Sensor", { 1, "1x1" }, "N*m",
    1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Engine.Sensor.Ideal_Torque_Sensor_T0",
    "HEV_SeriesParallel/Engine/Sensor/PS-Simulink\nConverter", { 1, "1x1" },
    "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Ideal_Torque_Sensor_T0", }, {
    "Engine.Sensor.Mechanical_Rotational_Reference.W.w",
    "HEV_SeriesParallel/Engine/Sensor/Mechanical Rotational Reference", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Engine.Sensor.Trans.w", "HEV_SeriesParallel/Engine/Sensor", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Engine.Sh.w", "HEV_SeriesParallel/Engine", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Engine.Simulink_PS_Converter_output0",
    "HEV_SeriesParallel/Engine/Simulink-PS\nConverter", { 1, "1x1" }, "1", 1.0,
    "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Simulink_PS_Converter_output0", }, {
    "Power_Split_Device.C.w", "HEV_SeriesParallel/Power Split Device", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", },
    { "Power_Split_Device.Planetary_Gear.C.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.H.T",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" }, "K",
    1.0, "K", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Power_Split_Device.Planetary_Gear.R.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.S.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.gear.C.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.gear.H.T",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" }, "K",
    1.0, "K", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Power_Split_Device.Planetary_Gear.gear.R.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.gear.S.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.C.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.H.T",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" }, "K",
    1.0, "K", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.P.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.R.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.temperature",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" }, "K",
    1.0, "K", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.t_P",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" }, "N*m",
    1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Planet torque", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.damper.C.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.damper.R.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.damper.t",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" }, "N*m",
    1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.damper.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.damper.power_dissipated",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "kg*m^2/s^3", 1.0, "kg*m^2/s^3", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "power_dissipated", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.power_dissipated",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" }, "J/s",
    1.0, "J/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Heat generated from friction", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.t_C",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" }, "N*m",
    1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Carrier torque", }, {
    "Power_Split_Device.Planetary_Gear.gear.ring_planet.t_R",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" }, "N*m",
    1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Ring torque", }, {
    "Power_Split_Device.Planetary_Gear.gear.sun_planet.C.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.gear.sun_planet.H.T",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" }, "K",
    1.0, "K", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Power_Split_Device.Planetary_Gear.gear.sun_planet.P.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.gear.sun_planet.S.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.gear.sun_planet.temperature",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" }, "K",
    1.0, "K", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Power_Split_Device.Planetary_Gear.gear.sun_planet.t_S",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" }, "N*m",
    1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Sun torque", }, {
    "Power_Split_Device.Planetary_Gear.gear.sun_planet.damper.C.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.gear.sun_planet.damper.R.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.gear.sun_planet.damper.t",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" }, "N*m",
    1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Power_Split_Device.Planetary_Gear.gear.sun_planet.damper.w",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Planetary_Gear.gear.sun_planet.damper.power_dissipated",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" },
    "kg*m^2/s^3", 1.0, "kg*m^2/s^3", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "power_dissipated", }, {
    "Power_Split_Device.Planetary_Gear.gear.sun_planet.power_dissipated",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" }, "J/s",
    1.0, "J/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Heat generated from friction", }, {
    "Power_Split_Device.Planetary_Gear.gear.sun_planet.t_C",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" }, "N*m",
    1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Carrier torque", }, {
    "Power_Split_Device.Planetary_Gear.gear.sun_planet.t_P",
    "HEV_SeriesParallel/Power Split Device/Planetary Gear", { 1, "1x1" }, "N*m",
    1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Planet torque", }, {
    "Power_Split_Device.R.w", "HEV_SeriesParallel/Power Split Device", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", },
    { "Power_Split_Device.S.w", "HEV_SeriesParallel/Power Split Device", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", },
    { "Power_Split_Device.Sensor_Carrier_Shaft.Ideal_Rotational_Motion_Sensor.A",
    "HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "A", }, {
    "Power_Split_Device.Sensor_Carrier_Shaft.Ideal_Rotational_Motion_Sensor.C.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Carrier_Shaft.Ideal_Rotational_Motion_Sensor.R.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Carrier_Shaft.Ideal_Rotational_Motion_Sensor.W",
    "HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "W", }, {
    "Power_Split_Device.Sensor_Carrier_Shaft.Ideal_Rotational_Motion_Sensor.alpha",
    "HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad/s^2", 1.0, "1/s^2", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_NONE, TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "\\u03B1", }, {
    "Power_Split_Device.Sensor_Carrier_Shaft.Ideal_Rotational_Motion_Sensor.phi",
    "HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad", 1.0, "1", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_MANDATORY, FALSE, TRUE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE,
    "Angle", }, {
    "Power_Split_Device.Sensor_Carrier_Shaft.Ideal_Rotational_Motion_Sensor_W0",
    "HEV_SeriesParallel/Power\nSplit\nDevice/Sensor\nCarrier Shaft/PS-Simulink\nConverter1",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "Ideal_Rotational_Motion_Sensor_W0", }, {
    "Power_Split_Device.Sensor_Carrier_Shaft.Ideal_Torque_Sensor.C.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft/Ideal Torque Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Carrier_Shaft.Ideal_Torque_Sensor.R.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft/Ideal Torque Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Carrier_Shaft.Ideal_Torque_Sensor.T",
    "HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft/Ideal Torque Sensor",
    { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "T", }, {
    "Power_Split_Device.Sensor_Carrier_Shaft.Ideal_Torque_Sensor.t",
    "HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft/Ideal Torque Sensor",
    { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Power_Split_Device.Sensor_Carrier_Shaft.Ideal_Torque_Sensor_T0",
    "HEV_SeriesParallel/Power\nSplit\nDevice/Sensor\nCarrier Shaft/PS-Simulink\nConverter",
    { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Ideal_Torque_Sensor_T0",
  }, {
    "Power_Split_Device.Sensor_Carrier_Shaft.Mechanical_Rotational_Reference.W.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft/Mechanical Rotational Reference",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Carrier_Shaft.PG.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Carrier_Shaft.Sh.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Ring_Shaft.Ideal_Rotational_Motion_Sensor.A",
    "HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "A", }, {
    "Power_Split_Device.Sensor_Ring_Shaft.Ideal_Rotational_Motion_Sensor.C.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Ring_Shaft.Ideal_Rotational_Motion_Sensor.R.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Ring_Shaft.Ideal_Rotational_Motion_Sensor.W",
    "HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "W", }, {
    "Power_Split_Device.Sensor_Ring_Shaft.Ideal_Rotational_Motion_Sensor.alpha",
    "HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad/s^2", 1.0, "1/s^2", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_NONE, TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "\\u03B1", }, {
    "Power_Split_Device.Sensor_Ring_Shaft.Ideal_Rotational_Motion_Sensor.phi",
    "HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad", 1.0, "1", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_MANDATORY, FALSE, TRUE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE,
    "Angle", }, {
    "Power_Split_Device.Sensor_Ring_Shaft.Ideal_Rotational_Motion_Sensor_W0",
    "HEV_SeriesParallel/Power\nSplit\nDevice/Sensor\nRing Shaft/PS-Simulink\nConverter1",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "Ideal_Rotational_Motion_Sensor_W0", }, {
    "Power_Split_Device.Sensor_Ring_Shaft.Ideal_Torque_Sensor.C.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft/Ideal Torque Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Ring_Shaft.Ideal_Torque_Sensor.R.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft/Ideal Torque Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Ring_Shaft.Ideal_Torque_Sensor.T",
    "HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft/Ideal Torque Sensor",
    { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "T", }, {
    "Power_Split_Device.Sensor_Ring_Shaft.Ideal_Torque_Sensor.t",
    "HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft/Ideal Torque Sensor",
    { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Power_Split_Device.Sensor_Ring_Shaft.Ideal_Torque_Sensor_T0",
    "HEV_SeriesParallel/Power\nSplit\nDevice/Sensor\nRing Shaft/PS-Simulink\nConverter",
    { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Ideal_Torque_Sensor_T0",
  }, {
    "Power_Split_Device.Sensor_Ring_Shaft.Mechanical_Rotational_Reference.W.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft/Mechanical Rotational Reference",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Ring_Shaft.PG.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Ring_Shaft.Sh.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Sun_Shaft.Ideal_Rotational_Motion_Sensor.A",
    "HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "A", }, {
    "Power_Split_Device.Sensor_Sun_Shaft.Ideal_Rotational_Motion_Sensor.C.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Sun_Shaft.Ideal_Rotational_Motion_Sensor.R.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Sun_Shaft.Ideal_Rotational_Motion_Sensor.W",
    "HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "W", }, {
    "Power_Split_Device.Sensor_Sun_Shaft.Ideal_Rotational_Motion_Sensor.alpha",
    "HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad/s^2", 1.0, "1/s^2", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_NONE, TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "\\u03B1", }, {
    "Power_Split_Device.Sensor_Sun_Shaft.Ideal_Rotational_Motion_Sensor.phi",
    "HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad", 1.0, "1", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_MANDATORY, FALSE, TRUE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE,
    "Angle", }, {
    "Power_Split_Device.Sensor_Sun_Shaft.Ideal_Rotational_Motion_Sensor_W0",
    "HEV_SeriesParallel/Power\nSplit\nDevice/Sensor\nSun Shaft/PS-Simulink\nConverter1",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "Ideal_Rotational_Motion_Sensor_W0", }, {
    "Power_Split_Device.Sensor_Sun_Shaft.Ideal_Torque_Sensor.C.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft/Ideal Torque Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Sun_Shaft.Ideal_Torque_Sensor.R.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft/Ideal Torque Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Sun_Shaft.Ideal_Torque_Sensor.T",
    "HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft/Ideal Torque Sensor",
    { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "T", }, {
    "Power_Split_Device.Sensor_Sun_Shaft.Ideal_Torque_Sensor.t",
    "HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft/Ideal Torque Sensor",
    { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Power_Split_Device.Sensor_Sun_Shaft.Ideal_Torque_Sensor_T0",
    "HEV_SeriesParallel/Power\nSplit\nDevice/Sensor\nSun Shaft/PS-Simulink\nConverter",
    { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Ideal_Torque_Sensor_T0",
  }, { "Power_Split_Device.Sensor_Sun_Shaft.Mechanical_Rotational_Reference.W.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft/Mechanical Rotational Reference",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Sun_Shaft.PG.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Power_Split_Device.Sensor_Sun_Shaft.Sh.w",
    "HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Vehicle.Final_Drive.O.w", "HEV_SeriesParallel/Vehicle/Final Drive", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Final_Drive.S.w", "HEV_SeriesParallel/Vehicle/Final Drive", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Final_Drive.t_in", "HEV_SeriesParallel/Vehicle/Final Drive", { 1,
      "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Input shaft incoming torque", },
    { "Vehicle.Final_Drive.t_out", "HEV_SeriesParallel/Vehicle/Final Drive", { 1,
      "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Output shaft incoming torque", },
  { "Vehicle.Inertia_Diff_LTire.I.w",
    "HEV_SeriesParallel/Vehicle/Inertia Diff LTire", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Inertia_Diff_LTire.J.w",
    "HEV_SeriesParallel/Vehicle/Inertia Diff LTire", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Vehicle.Inertia_Diff_LTire.t",
    "HEV_SeriesParallel/Vehicle/Inertia Diff LTire", { 1, "1x1" }, "N*m", 1.0,
    "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Vehicle.Inertia_Diff_LTire.w",
    "HEV_SeriesParallel/Vehicle/Inertia Diff LTire", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Inertia_Diff_RTire.I.w",
    "HEV_SeriesParallel/Vehicle/Inertia Diff RTire", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Inertia_Diff_RTire.J.w",
    "HEV_SeriesParallel/Vehicle/Inertia Diff RTire", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Vehicle.Inertia_Diff_RTire.t",
    "HEV_SeriesParallel/Vehicle/Inertia Diff RTire", { 1, "1x1" }, "N*m", 1.0,
    "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Vehicle.Inertia_Diff_RTire.w",
    "HEV_SeriesParallel/Vehicle/Inertia Diff RTire", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Inertia_GBox_Diff.I.w",
    "HEV_SeriesParallel/Vehicle/Inertia GBox Diff", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Inertia_GBox_Diff.J.w",
    "HEV_SeriesParallel/Vehicle/Inertia GBox Diff", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Vehicle.Inertia_GBox_Diff.t",
    "HEV_SeriesParallel/Vehicle/Inertia GBox Diff", { 1, "1x1" }, "N*m", 1.0,
    "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Vehicle.Inertia_GBox_Diff.w",
    "HEV_SeriesParallel/Vehicle/Inertia GBox Diff", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Left_Tire.A.w", "HEV_SeriesParallel/Vehicle/Left Tire", { 1, "1x1"
    }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Left_Tire.H.v", "HEV_SeriesParallel/Vehicle/Left Tire", { 1, "1x1"
    }, "m/s", 1.0, "m/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Velocity", }, {
    "Vehicle.Left_Tire.M", "HEV_SeriesParallel/Vehicle/Left Tire", { 4, "1x4" },
    "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "M", }, { "Vehicle.Left_Tire.N",
    "HEV_SeriesParallel/Vehicle/Left Tire", { 1, "1x1" }, "N", 1.0, "N",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "N", }, { "Vehicle.Left_Tire.S",
    "HEV_SeriesParallel/Vehicle/Left Tire", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "S", }, {
    "Vehicle.Left_Tire.tire_inertia.I.w", "HEV_SeriesParallel/Vehicle/Left Tire",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Left_Tire.tire_inertia.J.w", "HEV_SeriesParallel/Vehicle/Left Tire",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", },
    { "Vehicle.Left_Tire.tire_inertia.t", "HEV_SeriesParallel/Vehicle/Left Tire",
    { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Vehicle.Left_Tire.tire_inertia.w", "HEV_SeriesParallel/Vehicle/Left Tire",
      { 1, "1x1" }, "rpm", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_MANDATORY, FALSE, TRUE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE,
    "Rotational velocity", }, { "Vehicle.Left_Tire.tire_road_interaction.H.v",
    "HEV_SeriesParallel/Vehicle/Left Tire", { 1, "1x1" }, "m/s", 1.0, "m/s",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Velocity", }, {
    "Vehicle.Left_Tire.tire_road_interaction.M",
    "HEV_SeriesParallel/Vehicle/Left Tire", { 4, "1x4" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "M", }, {
    "Vehicle.Left_Tire.tire_road_interaction.N",
    "HEV_SeriesParallel/Vehicle/Left Tire", { 1, "1x1" }, "N", 1.0, "N",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "N", }, {
    "Vehicle.Left_Tire.tire_road_interaction.S",
    "HEV_SeriesParallel/Vehicle/Left Tire", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "S", }, {
    "Vehicle.Left_Tire.tire_road_interaction.T.v",
    "HEV_SeriesParallel/Vehicle/Left Tire", { 1, "1x1" }, "m/s", 1.0, "m/s",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Velocity", }, {
    "Vehicle.Left_Tire.tire_road_interaction.f_hub",
    "HEV_SeriesParallel/Vehicle/Left Tire", { 1, "1x1" }, "N", 1.0, "N",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Hub force", }, {
    "Vehicle.Left_Tire.tire_road_interaction.f_tread",
    "HEV_SeriesParallel/Vehicle/Left Tire", { 1, "1x1" }, "N", 1.0, "N",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Tread force", }, {
    "Vehicle.Left_Tire.tire_road_interaction.power_dissipated",
    "HEV_SeriesParallel/Vehicle/Left Tire", { 1, "1x1" }, "W", 1.0, "N*m/s",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Heat generated from friction", }, {
    "Vehicle.Left_Tire.wheel_axle.A.w", "HEV_SeriesParallel/Vehicle/Left Tire",
      { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_NONE, FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE,
    "Rotational velocity", }, { "Vehicle.Left_Tire.wheel_axle.N",
    "HEV_SeriesParallel/Vehicle/Left Tire", { 1, "1x1" }, "N", 1.0, "N",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "N", }, {
    "Vehicle.Left_Tire.wheel_axle.P.v", "HEV_SeriesParallel/Vehicle/Left Tire",
      { 1, "1x1" }, "m/s", 1.0, "m/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Velocity", }, {
    "Vehicle.Left_Tire.wheel_axle.f", "HEV_SeriesParallel/Vehicle/Left Tire", {
      1, "1x1" }, "N", 1.0, "N", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Force", }, {
    "Vehicle.Left_Tire.wheel_axle.t", "HEV_SeriesParallel/Vehicle/Left Tire", {
      1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Vehicle.Left_Tire_S0", "HEV_SeriesParallel/Vehicle/PS-Simulink\nConverter1",
    { 1, "1x1" }, "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Left_Tire_S0", }, {
    "Vehicle.MRRef.W.w", "HEV_SeriesParallel/Vehicle/MRRef", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.D.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.H.T",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "K", 1.0, "K",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Vehicle.Rear_Differential.S1.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.S2.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.base_gear.B.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.base_gear.F.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.base_gear.H.T",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "K", 1.0, "K",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Vehicle.Rear_Differential.base_gear.tB",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "N*m", 1.0,
    "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Base torque", }, {
    "Vehicle.Rear_Differential.base_gear.temperature",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "K", 1.0, "K",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Vehicle.Rear_Differential.base_gear.faultExtTrigger",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "External fault trigger", }, {
    "Vehicle.Rear_Differential.base_gear.damperB.C.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.base_gear.damperB.R.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.base_gear.damperB.t",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "N*m", 1.0,
    "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Vehicle.Rear_Differential.base_gear.damperB.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.base_gear.damperB.power_dissipated",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "kg*m^2/s^3",
    1.0, "kg*m^2/s^3", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "power_dissipated", }, {
    "Vehicle.Rear_Differential.base_gear.damperF.C.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.base_gear.damperF.R.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.base_gear.damperF.t",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "N*m", 1.0,
    "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Vehicle.Rear_Differential.base_gear.damperF.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.base_gear.damperF.power_dissipated",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "kg*m^2/s^3",
    1.0, "kg*m^2/s^3", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "power_dissipated", }, {
    "Vehicle.Rear_Differential.base_gear.f_hardstop",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "N", 1.0, "N",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Hard stop force", }, {
    "Vehicle.Rear_Differential.base_gear.power_dissipated",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "J/s", 1.0,
    "J/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Heat generated from friction", }, {
    "Vehicle.Rear_Differential.base_gear.tF",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "N*m", 1.0,
    "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Follower torque", }, {
    "Vehicle.Rear_Differential.base_gear.v_backlash",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "m/s", 1.0,
    "m/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Backlash velocity", }, {
    "Vehicle.Rear_Differential.base_gear.x_backlash",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "mm", 1.0, "m",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Backlash position", }, {
    "Vehicle.Rear_Differential.sun_planet_left.C.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.sun_planet_left.H.T",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "K", 1.0, "K",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Vehicle.Rear_Differential.sun_planet_left.P.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.sun_planet_left.S.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.sun_planet_left.temperature",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "K", 1.0, "K",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Vehicle.Rear_Differential.sun_planet_left.t_S",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "N*m", 1.0,
    "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Sun torque", }, {
    "Vehicle.Rear_Differential.sun_planet_left.damper.C.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.sun_planet_left.damper.R.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.sun_planet_left.damper.t",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "N*m", 1.0,
    "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Vehicle.Rear_Differential.sun_planet_left.damper.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.sun_planet_left.damper.power_dissipated",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "kg*m^2/s^3",
    1.0, "kg*m^2/s^3", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "power_dissipated", }, {
    "Vehicle.Rear_Differential.sun_planet_left.power_dissipated",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "J/s", 1.0,
    "J/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Heat generated from friction", }, {
    "Vehicle.Rear_Differential.sun_planet_left.t_C",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "N*m", 1.0,
    "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Carrier torque", }, {
    "Vehicle.Rear_Differential.sun_planet_left.t_P",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "N*m", 1.0,
    "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Planet torque", }, {
    "Vehicle.Rear_Differential.sun_planet_right.C.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.sun_planet_right.H.T",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "K", 1.0, "K",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Vehicle.Rear_Differential.sun_planet_right.P.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.sun_planet_right.S.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.sun_planet_right.temperature",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "K", 1.0, "K",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Vehicle.Rear_Differential.sun_planet_right.t_S",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "N*m", 1.0,
    "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Sun torque", }, {
    "Vehicle.Rear_Differential.sun_planet_right.damper.C.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.sun_planet_right.damper.R.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.sun_planet_right.damper.t",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "N*m", 1.0,
    "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Vehicle.Rear_Differential.sun_planet_right.damper.w",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rear_Differential.sun_planet_right.damper.power_dissipated",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "kg*m^2/s^3",
    1.0, "kg*m^2/s^3", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "power_dissipated", }, {
    "Vehicle.Rear_Differential.sun_planet_right.power_dissipated",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "J/s", 1.0,
    "J/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Heat generated from friction", }, {
    "Vehicle.Rear_Differential.sun_planet_right.t_C",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "N*m", 1.0,
    "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Carrier torque", }, {
    "Vehicle.Rear_Differential.sun_planet_right.t_P",
    "HEV_SeriesParallel/Vehicle/Rear Differential", { 1, "1x1" }, "N*m", 1.0,
    "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Planet torque", }, {
    "Vehicle.Right_Tire.A.w", "HEV_SeriesParallel/Vehicle/Right Tire", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Right_Tire.H.v", "HEV_SeriesParallel/Vehicle/Right Tire", { 1,
      "1x1" }, "m/s", 1.0, "m/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Velocity", }, {
    "Vehicle.Right_Tire.M", "HEV_SeriesParallel/Vehicle/Right Tire", { 4, "1x4"
    }, "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "M", }, { "Vehicle.Right_Tire.N",
    "HEV_SeriesParallel/Vehicle/Right Tire", { 1, "1x1" }, "N", 1.0, "N",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "N", }, { "Vehicle.Right_Tire.S",
    "HEV_SeriesParallel/Vehicle/Right Tire", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "S", }, {
    "Vehicle.Right_Tire.tire_inertia.I.w",
    "HEV_SeriesParallel/Vehicle/Right Tire", { 1, "1x1" }, "rad/s", 1.0, "1/s",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Right_Tire.tire_inertia.J.w",
    "HEV_SeriesParallel/Vehicle/Right Tire", { 1, "1x1" }, "rad/s", 1.0, "1/s",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Vehicle.Right_Tire.tire_inertia.t", "HEV_SeriesParallel/Vehicle/Right Tire",
    { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Vehicle.Right_Tire.tire_inertia.w", "HEV_SeriesParallel/Vehicle/Right Tire",
    { 1, "1x1" }, "rpm", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_MANDATORY, FALSE, TRUE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE,
    "Rotational velocity", }, { "Vehicle.Right_Tire.tire_road_interaction.H.v",
    "HEV_SeriesParallel/Vehicle/Right Tire", { 1, "1x1" }, "m/s", 1.0, "m/s",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Velocity", }, {
    "Vehicle.Right_Tire.tire_road_interaction.M",
    "HEV_SeriesParallel/Vehicle/Right Tire", { 4, "1x4" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "M", }, {
    "Vehicle.Right_Tire.tire_road_interaction.N",
    "HEV_SeriesParallel/Vehicle/Right Tire", { 1, "1x1" }, "N", 1.0, "N",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "N", }, {
    "Vehicle.Right_Tire.tire_road_interaction.S",
    "HEV_SeriesParallel/Vehicle/Right Tire", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "S", }, {
    "Vehicle.Right_Tire.tire_road_interaction.T.v",
    "HEV_SeriesParallel/Vehicle/Right Tire", { 1, "1x1" }, "m/s", 1.0, "m/s",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Velocity", }, {
    "Vehicle.Right_Tire.tire_road_interaction.f_hub",
    "HEV_SeriesParallel/Vehicle/Right Tire", { 1, "1x1" }, "N", 1.0, "N",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Hub force", }, {
    "Vehicle.Right_Tire.tire_road_interaction.f_tread",
    "HEV_SeriesParallel/Vehicle/Right Tire", { 1, "1x1" }, "N", 1.0, "N",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Tread force", }, {
    "Vehicle.Right_Tire.tire_road_interaction.power_dissipated",
    "HEV_SeriesParallel/Vehicle/Right Tire", { 1, "1x1" }, "W", 1.0, "N*m/s",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Heat generated from friction", }, {
    "Vehicle.Right_Tire.wheel_axle.A.w", "HEV_SeriesParallel/Vehicle/Right Tire",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Right_Tire.wheel_axle.N", "HEV_SeriesParallel/Vehicle/Right Tire",
      { 1, "1x1" }, "N", 1.0, "N", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "N", }, {
    "Vehicle.Right_Tire.wheel_axle.P.v", "HEV_SeriesParallel/Vehicle/Right Tire",
    { 1, "1x1" }, "m/s", 1.0, "m/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Velocity", }, {
    "Vehicle.Right_Tire.wheel_axle.f", "HEV_SeriesParallel/Vehicle/Right Tire",
      { 1, "1x1" }, "N", 1.0, "N", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Force", }, {
    "Vehicle.Right_Tire.wheel_axle.t", "HEV_SeriesParallel/Vehicle/Right Tire",
      { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Vehicle.Road_Incline.O", "HEV_SeriesParallel/Vehicle/Road Incline", { 1,
      "1x1" }, "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "O", }, {
    "Vehicle.Rotational_Damper.C.w",
    "HEV_SeriesParallel/Vehicle/Rotational Damper", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rotational_Damper.R.w",
    "HEV_SeriesParallel/Vehicle/Rotational Damper", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rotational_Damper.t",
    "HEV_SeriesParallel/Vehicle/Rotational Damper", { 1, "1x1" }, "N*m", 1.0,
    "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Vehicle.Rotational_Damper.w",
    "HEV_SeriesParallel/Vehicle/Rotational Damper", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Rotational_Damper.power_dissipated",
    "HEV_SeriesParallel/Vehicle/Rotational Damper", { 1, "1x1" }, "kg*m^2/s^3",
    1.0, "kg*m^2/s^3", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "power_dissipated", }, {
    "Vehicle.Sensor_Speed_and_Power.B.w",
    "HEV_SeriesParallel/Vehicle/Sensor Speed and  Power", { 1, "1x1" }, "rad/s",
    1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Vehicle.Sensor_Speed_and_Power.F.w",
    "HEV_SeriesParallel/Vehicle/Sensor Speed and  Power", { 1, "1x1" }, "rad/s",
    1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Vehicle.Sensor_Speed_and_Power.Ideal_Rotational_Motion_Sensor.A",
    "HEV_SeriesParallel/Vehicle/Sensor Speed and  Power/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "A", }, {
    "Vehicle.Sensor_Speed_and_Power.Ideal_Rotational_Motion_Sensor.C.w",
    "HEV_SeriesParallel/Vehicle/Sensor Speed and  Power/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Sensor_Speed_and_Power.Ideal_Rotational_Motion_Sensor.R.w",
    "HEV_SeriesParallel/Vehicle/Sensor Speed and  Power/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Sensor_Speed_and_Power.Ideal_Rotational_Motion_Sensor.W",
    "HEV_SeriesParallel/Vehicle/Sensor Speed and  Power/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "W", }, {
    "Vehicle.Sensor_Speed_and_Power.Ideal_Rotational_Motion_Sensor.alpha",
    "HEV_SeriesParallel/Vehicle/Sensor Speed and  Power/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad/s^2", 1.0, "1/s^2", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_NONE, TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "\\u03B1", }, {
    "Vehicle.Sensor_Speed_and_Power.Ideal_Rotational_Motion_Sensor.phi",
    "HEV_SeriesParallel/Vehicle/Sensor Speed and  Power/Ideal Rotational Motion Sensor",
    { 1, "1x1" }, "rad", 1.0, "1", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_MANDATORY, FALSE, TRUE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE,
    "Angle", }, {
    "Vehicle.Sensor_Speed_and_Power.Ideal_Rotational_Motion_Sensor_W0",
    "HEV_SeriesParallel/Vehicle/Sensor\nSpeed and\n Power/PS-Simulink\nConverter1",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "Ideal_Rotational_Motion_Sensor_W0", }, {
    "Vehicle.Sensor_Speed_and_Power.Ideal_Torque_Sensor.C.w",
    "HEV_SeriesParallel/Vehicle/Sensor Speed and  Power/Ideal Torque Sensor", {
      1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Sensor_Speed_and_Power.Ideal_Torque_Sensor.R.w",
    "HEV_SeriesParallel/Vehicle/Sensor Speed and  Power/Ideal Torque Sensor", {
      1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Sensor_Speed_and_Power.Ideal_Torque_Sensor.T",
    "HEV_SeriesParallel/Vehicle/Sensor Speed and  Power/Ideal Torque Sensor", {
      1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "T", }, {
    "Vehicle.Sensor_Speed_and_Power.Ideal_Torque_Sensor.t",
    "HEV_SeriesParallel/Vehicle/Sensor Speed and  Power/Ideal Torque Sensor", {
      1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Vehicle.Sensor_Speed_and_Power.Ideal_Torque_Sensor_T0",
    "HEV_SeriesParallel/Vehicle/Sensor\nSpeed and\n Power/PS-Simulink\nConverter",
    { 1, "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Ideal_Torque_Sensor_T0",
  }, { "Vehicle.Sensor_Speed_and_Power.Mechanical_Rotational_Reference.W.w",
    "HEV_SeriesParallel/Vehicle/Sensor Speed and  Power/Mechanical Rotational Reference",
    { 1, "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Sh.w", "HEV_SeriesParallel/Vehicle", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "Vehicle.Simulink_PS_Converter_output0",
    "HEV_SeriesParallel/Vehicle/Simulink-PS\nConverter", { 1, "1x1" }, "1", 1.0,
    "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Simulink_PS_Converter_output0", }, {
    "Vehicle.Torque_Source.C.w", "HEV_SeriesParallel/Vehicle/Torque Source", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Torque_Source.R.w", "HEV_SeriesParallel/Vehicle/Torque Source", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "Vehicle.Torque_Source.S", "HEV_SeriesParallel/Vehicle/Torque Source", { 1,
      "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "S", }, {
    "Vehicle.Torque_Source.t", "HEV_SeriesParallel/Vehicle/Torque Source", { 1,
      "1x1" }, "N*m", 1.0, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "Vehicle.Torque_Source.w", "HEV_SeriesParallel/Vehicle/Torque Source", { 1,
      "1x1" }, "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Angular velocity", }, {
    "Vehicle.Vehicle_Body.CD", "HEV_SeriesParallel/Vehicle/Vehicle Body", { 1,
      "1x1" }, "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "CD", }, {
    "Vehicle.Vehicle_Body.v", "HEV_SeriesParallel/Vehicle/Vehicle Body", { 1,
      "1x1" }, "m/s", 1.0, "m/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY,
    FALSE, TRUE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Velocity", }, {
    "Vehicle.Vehicle_Body.wind", "HEV_SeriesParallel/Vehicle/Vehicle Body", { 1,
      "1x1" }, "m/s", 1.0, "m/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "W", }, {
    "Vehicle.Vehicle_Body.H.v", "HEV_SeriesParallel/Vehicle/Vehicle Body", { 1,
      "1x1" }, "m/s", 1.0, "m/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Velocity", }, {
    "Vehicle.Vehicle_Body.NF", "HEV_SeriesParallel/Vehicle/Vehicle Body", { 1,
      "1x1" }, "N", 1.0, "N", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "NF", }, {
    "Vehicle.Vehicle_Body.NR", "HEV_SeriesParallel/Vehicle/Vehicle Body", { 1,
      "1x1" }, "N", 1.0, "N", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "NR", }, {
    "Vehicle.Vehicle_Body.V", "HEV_SeriesParallel/Vehicle/Vehicle Body", { 1,
      "1x1" }, "m/s", 1.0, "m/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "V", }, {
    "Vehicle.Vehicle_Body.beta", "HEV_SeriesParallel/Vehicle/Vehicle Body", { 1,
      "1x1" }, "rad", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "beta", }, {
    "Vehicle.Vehicle_Body.cg_load", "HEV_SeriesParallel/Vehicle/Vehicle Body", {
      2, "1x2" }, "m", 1.0, "m", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "CG", }, {
    "Vehicle.Vehicle_Body.elevation", "HEV_SeriesParallel/Vehicle/Vehicle Body",
    { 1, "1x1" }, "m", 1.0, "m", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_MANDATORY,
    FALSE, TRUE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Elevation change", }, {
    "Vehicle.Vehicle_Body.mass_load", "HEV_SeriesParallel/Vehicle/Vehicle Body",
    { 1, "1x1" }, "kg", 1.0, "kg", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "M", }, {
    "Vehicle.Vehicle_Body.elevation_potential_energy",
    "HEV_SeriesParallel/Vehicle/Vehicle Body", { 1, "1x1" }, "kJ", 1.0,
    "kg*m^2/s^2", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Elevation potential energy change", },
    { "Vehicle.Vehicle_Body.f", "HEV_SeriesParallel/Vehicle/Vehicle Body", { 1,
      "1x1" }, "N", 1.0, "N", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Longitudinal force", }, {
    "Vehicle.Vehicle_Body.inertia_load",
    "HEV_SeriesParallel/Vehicle/Vehicle Body", { 1, "1x1" }, "kg*m^2", 1.0,
    "kg*m^2", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "J", }, {
    "Vehicle.Vehicle_Body.power_dissipated",
    "HEV_SeriesParallel/Vehicle/Vehicle Body", { 1, "1x1" }, "W", 1.0,
    "kg*m^2/s^3", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Aerodynamic drag power", }, {
    "Vehicle.Vehicle_Body.suspension_force_f",
    "HEV_SeriesParallel/Vehicle/Vehicle Body", { 1, "1x1" }, "N", 1.0, "N",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Front suspension force", }, {
    "Vehicle.Vehicle_Body.suspension_force_r",
    "HEV_SeriesParallel/Vehicle/Vehicle Body", { 1, "1x1" }, "N", 1.0, "N",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rear suspension force", }, {
    "Vehicle.Vehicle_Body_V0",
    "HEV_SeriesParallel/Vehicle/PS-Simulink\nConverter3", { 1, "1x1" }, "km/hr",
    1.0, "m/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Vehicle_Body_V0", }, {
    "Vehicle.Wind_Velocity.O", "HEV_SeriesParallel/Vehicle/Wind Velocity", { 1,
      "1x1" }, "1", 1.0, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "O", } };

static NeModeData *s_major_mode_data = NULL;
static NeZCData s_zc_data[13] = { {
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", 1U, 0U,
    "Electrical.Generator.System.Motor_and_Drive",
    "ee.electromech.motor_and_drive_base", NE_ZC_TYPE_FALSE, }, {
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", 1U, 1U,
    "Electrical.Generator.System.Motor_and_Drive",
    "ee.electromech.motor_and_drive_base", NE_ZC_TYPE_FALSE, }, {
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", 1U, 2U,
    "Electrical.Generator.System.Motor_and_Drive",
    "ee.electromech.motor_and_drive_base", NE_ZC_TYPE_FALSE, }, {
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", 1U, 3U,
    "Electrical.Motor.System.Motor_and_Drive",
    "ee.electromech.motor_and_drive_base", NE_ZC_TYPE_FALSE, }, {
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", 1U, 4U,
    "Electrical.Motor.System.Motor_and_Drive",
    "ee.electromech.motor_and_drive_base", NE_ZC_TYPE_FALSE, }, {
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", 1U, 5U,
    "Electrical.Motor.System.Motor_and_Drive",
    "ee.electromech.motor_and_drive_base", NE_ZC_TYPE_FALSE, }, {
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 6U,
    "Electrical.Generic.Battery", "batteryecm.battery", NE_ZC_TYPE_TRUE, }, {
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 7U,
    "Electrical.Generic.Battery", "batteryecm.battery", NE_ZC_TYPE_FALSE, }, {
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 8U,
    "Electrical.Generic.Battery", "batteryecm.battery", NE_ZC_TYPE_FALSE, }, {
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 9U,
    "Electrical.Generic.Battery", "batteryecm.battery", NE_ZC_TYPE_TRUE, }, {
    "HEV_SeriesParallel/Engine/Generic Engine", 1U, 10U, "Engine.Generic_Engine",
    "sdl.engines.generic_engine", NE_ZC_TYPE_FALSE, }, {
    "HEV_SeriesParallel/Engine/Generic Engine", 1U, 11U, "Engine.Generic_Engine",
    "sdl.engines.generic_engine", NE_ZC_TYPE_TRUE, }, {
    "HEV_SeriesParallel/Vehicle/Left Tire", 2U, 12U,
    "Vehicle.Left_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", NE_ZC_TYPE_FALSE, } };

static NeRange s_range[14] = { { "ee.electromech.motor_and_drive_base", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "ee.electromech.motor_and_drive_base", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "ee.electromech.motor_and_drive_base", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "sdl.engines.generic_engine", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "sdl.engines.generic_engine", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "sdl.tires.tire_subcomponents.magic_formula",
    149U, 28U, 149U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "sdl.tires.tire_subcomponents.magic_formula", 149U, 28U, 149U, 33U,
    NE_RANGE_TYPE_NORMAL, } };

static NeAssertData s_assert_data[40] = { {
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", 1U, 0U,
    "Electrical.Generator.System.Motor_and_Drive",
    "ee.electromech.motor_and_drive_base", FALSE,
    "Servomotor DC voltage supply must be greater than zero.",
    "physmod:simscape:compiler:patterns:checks:GreaterThanZero", }, {
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 1U,
    "Electrical.Generic.Battery", "batteryecm.battery", TRUE,
    "Voltage versus state-of-charge equation coefficient, beta is not in an acceptable range. Setting to 0.",
    "physmod:battery:shared_library:batteryecm:AdjustedParameter", }, {
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 2U,
    "Electrical.Generic.Battery", "batteryecm.battery", FALSE,
    "Faded battery capacity must be greater than Charge AH1 when no-load voltage is V1.",
    "physmod:simscape:compiler:patterns:checks:GreaterThan", }, {
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 3U,
    "Electrical.Generic.Battery", "batteryecm.battery", FALSE,
    "Number of discharge cycles must be greater than or equal to zero.",
    "physmod:simscape:compiler:patterns:checks:GreaterThanOrEqualZero", }, {
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", 1U, 4U,
    "Electrical.Motor.System.Motor_and_Drive",
    "ee.electromech.motor_and_drive_base", FALSE,
    "Servomotor DC voltage supply must be greater than zero.",
    "physmod:simscape:compiler:patterns:checks:GreaterThanZero", }, {
    "HEV_SeriesParallel/Engine/Generic Engine", 1U, 5U, "Engine.Generic_Engine",
    "sdl.engines.generic_engine", FALSE,
    "Rotational velocity must be less than or equal to Maximum speed.",
    "physmod:simscape:compiler:patterns:checks:LessThanOrEqual", }, {
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 6U,
    "Electrical.Generic.Battery.R1Faded", "batteryecm.battery", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 7U,
    "Electrical.Generic.Battery.xAH", "batteryecm.battery", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 8U,
    "Electrical.Generic.Battery.x1", "batteryecm.battery", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 9U,
    "Electrical.Generic.Battery.beta", "batteryecm.battery", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 10U,
    "Electrical.Generic.Battery.beta", "batteryecm.battery", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 11U,
    "Electrical.Generic.Battery.x", "batteryecm.battery", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 12U,
    "Electrical.Generic.Battery.Vbat", "batteryecm.battery", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 13U,
    "Electrical.Generic.Battery.alpha", "batteryecm.battery", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 14U,
    "Electrical.Generic.Battery.alpha", "batteryecm.battery", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Left Tire", 1U, 15U,
    "Vehicle.Left_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", TRUE,
    "Large value inside exp, limiting the exponential to avoid nonfinite values.",
    "physmod:common:mf:expr:analyze:RequireSmallerExponentExponential", }, {
    "HEV_SeriesParallel/Vehicle/Left Tire", 1U, 16U,
    "Vehicle.Left_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Right Tire", 1U, 17U,
    "Vehicle.Right_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Right Tire", 1U, 18U,
    "Vehicle.Right_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Right Tire", 1U, 19U,
    "Vehicle.Right_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Right Tire", 1U, 20U,
    "Vehicle.Right_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Right Tire", 1U, 21U,
    "Vehicle.Right_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Right Tire", 1U, 22U,
    "Vehicle.Right_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Right Tire", 1U, 23U,
    "Vehicle.Right_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Right Tire", 1U, 24U,
    "Vehicle.Right_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Right Tire", 1U, 25U,
    "Vehicle.Right_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Right Tire", 1U, 26U,
    "Vehicle.Right_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", TRUE,
    "Large value inside exp, limiting the exponential to avoid nonfinite values.",
    "physmod:common:mf:expr:analyze:RequireSmallerExponentExponential", }, {
    "HEV_SeriesParallel/Vehicle/Right Tire", 1U, 27U,
    "Vehicle.Right_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Left Tire", 1U, 28U,
    "Vehicle.Left_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Left Tire", 1U, 29U,
    "Vehicle.Left_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Left Tire", 1U, 30U,
    "Vehicle.Left_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Left Tire", 1U, 31U,
    "Vehicle.Left_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Left Tire", 1U, 32U,
    "Vehicle.Left_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Left Tire", 1U, 33U,
    "Vehicle.Left_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Left Tire", 1U, 34U,
    "Vehicle.Left_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Left Tire", 1U, 35U,
    "Vehicle.Left_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Vehicle/Left Tire", 1U, 36U,
    "Vehicle.Left_Tire.tire_road_interaction",
    "sdl.tires.tire_subcomponents.magic_formula", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Electrical/Generic/ Battery", 1U, 37U,
    "Electrical.Generic.Battery", "batteryecm.battery", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Electrical/Generator/System/Motor and Drive", 1U, 38U,
    "Electrical.Generator.System.Motor_and_Drive",
    "ee.electromech.motor_and_drive_base", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", }, {
    "HEV_SeriesParallel/Electrical/Motor/System/Motor and Drive", 1U, 39U,
    "Electrical.Motor.System.Motor_and_Drive",
    "ee.electromech.motor_and_drive_base", FALSE,
    "In divide, the denominator must be nonzero.",
    "physmod:common:mf:expr:analyze:RequireDenominatorNonzero", } };

static NeRange s_assert_range[40] = { { "ee.electromech.motor_and_drive_base",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "sdl.engines.generic_engine", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "sdl.tires.tire_subcomponents.magic_formula",
    156U, 62U, 156U, 73U, NE_RANGE_TYPE_NORMAL, }, {
    "sdl.tires.tire_subcomponents.magic_formula", 156U, 20U, 156U, 43U,
    NE_RANGE_TYPE_NORMAL, }, { "sdl.tires.tire_subcomponents.magic_formula",
    114U, 28U, 114U, 34U, NE_RANGE_TYPE_NORMAL, }, {
    "sdl.tires.tire_subcomponents.magic_formula", 114U, 28U, 114U, 34U,
    NE_RANGE_TYPE_NORMAL, }, { "sdl.tires.tire_subcomponents.magic_formula",
    114U, 28U, 114U, 34U, NE_RANGE_TYPE_NORMAL, }, {
    "sdl.tires.tire_subcomponents.magic_formula", 332U, 10U, 332U, 34U,
    NE_RANGE_TYPE_NORMAL, }, { "sdl.tires.tire_subcomponents.magic_formula",
    114U, 28U, 114U, 34U, NE_RANGE_TYPE_NORMAL, }, {
    "sdl.tires.tire_subcomponents.magic_formula", 114U, 28U, 114U, 34U,
    NE_RANGE_TYPE_NORMAL, }, { "sdl.tires.tire_subcomponents.magic_formula",
    114U, 28U, 114U, 34U, NE_RANGE_TYPE_NORMAL, }, {
    "sdl.tires.tire_subcomponents.magic_formula", 114U, 28U, 114U, 34U,
    NE_RANGE_TYPE_NORMAL, }, { "sdl.tires.tire_subcomponents.magic_formula",
    336U, 10U, 336U, 34U, NE_RANGE_TYPE_NORMAL, }, {
    "sdl.tires.tire_subcomponents.magic_formula", 156U, 62U, 156U, 73U,
    NE_RANGE_TYPE_NORMAL, }, { "sdl.tires.tire_subcomponents.magic_formula",
    156U, 20U, 156U, 43U, NE_RANGE_TYPE_NORMAL, }, {
    "sdl.tires.tire_subcomponents.magic_formula", 114U, 28U, 114U, 34U,
    NE_RANGE_TYPE_NORMAL, }, { "sdl.tires.tire_subcomponents.magic_formula",
    114U, 28U, 114U, 34U, NE_RANGE_TYPE_NORMAL, }, {
    "sdl.tires.tire_subcomponents.magic_formula", 114U, 28U, 114U, 34U,
    NE_RANGE_TYPE_NORMAL, }, { "sdl.tires.tire_subcomponents.magic_formula",
    332U, 10U, 332U, 34U, NE_RANGE_TYPE_NORMAL, }, {
    "sdl.tires.tire_subcomponents.magic_formula", 114U, 28U, 114U, 34U,
    NE_RANGE_TYPE_NORMAL, }, { "sdl.tires.tire_subcomponents.magic_formula",
    114U, 28U, 114U, 34U, NE_RANGE_TYPE_NORMAL, }, {
    "sdl.tires.tire_subcomponents.magic_formula", 114U, 28U, 114U, 34U,
    NE_RANGE_TYPE_NORMAL, }, { "sdl.tires.tire_subcomponents.magic_formula",
    114U, 28U, 114U, 34U, NE_RANGE_TYPE_NORMAL, }, {
    "sdl.tires.tire_subcomponents.magic_formula", 336U, 10U, 336U, 34U,
    NE_RANGE_TYPE_NORMAL, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, } };

static NeAssertData s_param_assert_data[1] = { {
    "HEV_SeriesParallel/Vehicle/Vehicle Body", 1U, 0U, "Vehicle.Vehicle_Body",
    "sdl.tires.vehicle_body", FALSE, "Mass must be greater than zero.",
    "physmod:simscape:compiler:patterns:checks:GreaterThanZero", } };

static NeRange s_param_assert_range[1] = { { "sdl.tires.vehicle_body", 262U, 5U,
    262U, 11U, NE_RANGE_TYPE_NORMAL, } };

static NeAssertData *s_initial_assert_data = NULL;
static NeRange *s_initial_assert_range = NULL;
static NeRange s_equation_range[87] = { { "ee.electromech.motor_and_drive_base",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "foundation.mechanical.sensors.angular_velocity", 78U, 9U, 78U, 22U,
    NE_RANGE_TYPE_NORMAL, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "Capacitors.LossyUltraCapacitor", 38U, 13U,
    38U, 45U, NE_RANGE_TYPE_NORMAL, }, { "ee.electromech.motor_and_drive_base",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "foundation.mechanical.sensors.angular_velocity", 78U, 9U, 78U, 22U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.mechanical.sensors.angular_velocity",
    78U, 9U, 78U, 22U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.mechanical.sensors.angular_velocity", 78U, 9U, 78U, 22U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.mechanical.sensors.angular_velocity",
    78U, 9U, 78U, 22U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.mechanical.sensors.angular_velocity", 78U, 9U, 78U, 22U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.mechanical.sensors.angular_velocity",
    78U, 9U, 78U, 22U, NE_RANGE_TYPE_NORMAL, }, { "sdl.tires.vehicle_body", 273U,
    5U, 273U, 48U, NE_RANGE_TYPE_NORMAL, }, { "sdl.tires.vehicle_body", 278U, 5U,
    278U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.mechanical.rotational.inertia", 44U, 5U, 44U, 21U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.mechanical.rotational.inertia", 44U,
    20U, 44U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.mechanical.rotational.inertia", 44U, 5U, 44U, 21U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.mechanical.rotational.inertia", 44U,
    20U, 44U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.mechanical.rotational.inertia", 44U, 5U, 44U, 21U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.mechanical.rotational.inertia", 44U,
    20U, 44U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.mechanical.rotational.inertia", 44U, 5U, 44U, 21U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.mechanical.rotational.inertia", 44U,
    20U, 44U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.mechanical.rotational.inertia", 44U, 5U, 44U, 21U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.mechanical.rotational.inertia", 44U,
    20U, 44U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.mechanical.rotational.inertia", 44U, 5U, 44U, 21U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.mechanical.rotational.inertia", 44U,
    20U, 44U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.mechanical.rotational.inertia", 44U, 5U, 44U, 21U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.mechanical.rotational.inertia", 44U,
    20U, 44U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.mechanical.rotational.inertia", 44U, 5U, 44U, 21U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.mechanical.rotational.inertia", 44U,
    20U, 44U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "ee.electromech.motor_and_drive_base", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "ee.electromech.motor_and_drive_base", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "ee.electromech.motor_and_drive_base", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "batteryecm.battery", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "ee.electromech.motor_and_drive_base", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "ee.electromech.motor_and_drive_base", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "ee.electromech.motor_and_drive_base", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.electromech.motor_and_drive_base", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "sdl.engines.generic_engine", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "sdl.engines.generic_engine", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "sdl.engines.generic_engine", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "sdl.engines.generic_engine", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "sdl.engines.generic_engine", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "sdl.engines.generic_engine", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "sdl.engines.generic_engine", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "sdl.engines.generic_engine", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "sdl.engines.generic_engine", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "sdl.engines.generic_engine", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "sdl.gears.planetary_subcomponents.ring_planet", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, {
    "sdl.gears.planetary_subcomponents.ring_planet", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, {
    "sdl.gears.planetary_subcomponents.ring_planet", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "sdl.gears.planetary_subcomponents.sun_planet",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "sdl.gears.planetary_subcomponents.sun_planet", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "sdl.gears.planetary_subcomponents.sun_planet",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "foundation.mechanical.rotational.inertia", 45U, 5U, 45U, 13U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.mechanical.rotational.inertia", 45U,
    5U, 45U, 13U, NE_RANGE_TYPE_NORMAL, }, {
    "sdl.tires.tire_subcomponents.magic_formula", 114U, 5U, 114U, 64U,
    NE_RANGE_TYPE_NORMAL, }, { "sdl.tires.tire_subcomponents.magic_formula",
    160U, 13U, 160U, 27U, NE_RANGE_TYPE_NORMAL, }, {
    "sdl.tires.tire_subcomponents.magic_formula", 161U, 13U, 161U, 28U,
    NE_RANGE_TYPE_NORMAL, }, {
    "sdl.gears.planetary_subcomponents.sun_planet_bevel", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "foundation.mechanical.rotational.inertia",
    45U, 5U, 45U, 13U, NE_RANGE_TYPE_NORMAL, }, {
    "sdl.tires.tire_subcomponents.magic_formula", 114U, 5U, 114U, 64U,
    NE_RANGE_TYPE_NORMAL, }, { "sdl.tires.tire_subcomponents.magic_formula",
    160U, 13U, 160U, 27U, NE_RANGE_TYPE_NORMAL, }, {
    "sdl.tires.tire_subcomponents.magic_formula", 161U, 13U, 161U, 28U,
    NE_RANGE_TYPE_NORMAL, }, { "sdl.tires.vehicle_body", 275U, 5U, 275U, 101U,
    NE_RANGE_TYPE_NORMAL, }, { "sdl.gears.planetary_subcomponents.ring_planet",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "sdl.gears.planetary_subcomponents.sun_planet", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "foundation.mechanical.rotational.inertia",
    45U, 5U, 45U, 13U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.mechanical.rotational.inertia", 45U, 5U, 45U, 13U,
    NE_RANGE_TYPE_NORMAL, }, {
    "sdl.gears.planetary_subcomponents.sun_planet_bevel", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "foundation.mechanical.rotational.inertia",
    45U, 5U, 45U, 13U, NE_RANGE_TYPE_NORMAL, } };

static NeRange *s_cer_range = NULL;
static NeRange s_icr_range[6] = { { "batteryecm.battery", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "sdl.gears.compound_planetary_gear", 105U, 96U,
    105U, 102U, NE_RANGE_TYPE_NORMAL, }, { "sdl.gears.compound_planetary_gear",
    102U, 96U, 102U, 102U, NE_RANGE_TYPE_NORMAL, }, { "sdl.gears.differential",
    112U, 114U, 112U, 120U, NE_RANGE_TYPE_NORMAL, }, { "sdl.gears.differential",
    104U, 118U, 104U, 124U, NE_RANGE_TYPE_NORMAL, }, {
    "sdl.gears.planetary_subcomponents.sun_planet_bevel", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, } };

static NeParameterData *s_logical_parameter_data = NULL;
static NeParameterData *s_integer_parameter_data = NULL;
static NeParameterData *s_index_parameter_data = NULL;
static NeParameterData s_real_parameter_data[9] = { { "RTP_0BC1812E_w",
    "HEV_SeriesParallel/Electrical/Generator/System/Inertia", "", 0U, 1U, TRUE,
  }, { "RTP_3224FFEB_w", "HEV_SeriesParallel/Engine/Engine Shaft Inertia", "",
    0U, 1U, TRUE, }, { "RTP_1737879D_charge",
    "HEV_SeriesParallel/Electrical/Generic/ Battery", "", 0U, 1U, TRUE, }, {
    "RTP_DB87A893_w", "HEV_SeriesParallel/Electrical/Motor/System/Inertia", "",
    0U, 1U, TRUE, }, { "RTP_494A81BE_mass",
    "HEV_SeriesParallel/Vehicle/Vehicle Body", "", 0U, 1U, TRUE, }, {
    "RTP_494A81BE_v", "HEV_SeriesParallel/Vehicle/Vehicle Body", "", 0U, 1U,
    TRUE, }, { "RTP_4B685322_w", "HEV_SeriesParallel/Vehicle/Inertia Diff LTire",
    "", 0U, 1U, TRUE, }, { "RTP_ACD07E25_w",
    "HEV_SeriesParallel/Vehicle/Inertia GBox Diff", "", 0U, 1U, TRUE, }, {
    "RTP_DBD74EB3_w", "HEV_SeriesParallel/Vehicle/Inertia Diff RTire", "", 0U,
    1U, TRUE, } };

static real_T s_constant_table0[13] = { 0.0, 0.0, 110.0, 150.0, 250.0, 400.0,
  400.0, 400.0, 250.0, 150.0, 110.0, 0.0, 0.0 };

static real_T s_constant_table1[13] = { -1570.7963267948965, -1047.1975511965977,
  -418.87902047863906, -314.15926535897933, -209.43951023931953,
  -125.66370614359172, -0.0, 125.66370614359172, 209.43951023931953,
  314.15926535897933, 418.87902047863906, 1047.1975511965977, 1570.7963267948965
};

static real_T s_constant_table2[17] = { 0.0, 0.0, 70.0, 80.0, 100.0, 150.0,
  225.0, 400.0, 400.0, 400.0, 225.0, 150.0, 100.0, 80.0, 70.0, 0.0, 0.0 };

static real_T s_constant_table3[17] = { -1047.1975511965977, -680.67840827778844,
  -628.31853071795865, -523.59877559829886, -418.87902047863906,
  -314.15926535897933, -209.43951023931953, -125.66370614359172, -0.0,
  125.66370614359172, 209.43951023931953, 314.15926535897933, 418.87902047863906,
  523.59877559829886, 628.31853071795865, 680.67840827778844, 1047.1975511965977
};

static NeDsMethodOutput *ds_output_mcon_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMCON_P.mNumCol = 58;
  out->mMCON_P.mNumRow = 58;
  out->mMCON_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    59);
  out->mMCON_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    14);
  return out;
}

static NeDsMethodOutput *ds_output_mcon(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMCON.mN = 14;
  out->mMCON.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 14);
  return out;
}

static NeDsMethodOutput *ds_output_mpar_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMPAR_P.mNumCol = 58;
  out->mMPAR_P.mNumRow = 58;
  out->mMPAR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    59);
  out->mMPAR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  return out;
}

static NeDsMethodOutput *ds_output_mpar(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMPAR.mN = 1;
  out->mMPAR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 1);
  return out;
}

static NeDsMethodOutput *ds_output_mnl_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMNL_P.mNumCol = 58;
  out->mMNL_P.mNumRow = 58;
  out->mMNL_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    59);
  out->mMNL_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  return out;
}

static NeDsMethodOutput *ds_output_mnl(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMNL.mN = 2;
  out->mMNL.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 2);
  return out;
}

static NeDsMethodOutput *ds_output_vmm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVMM.mN = 17;
  out->mVMM.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    17);
  return out;
}

static NeDsMethodOutput *ds_output_dxm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXM_P.mNumCol = 58;
  out->mDXM_P.mNumRow = 17;
  out->mDXM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    59);
  out->mDXM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  return out;
}

static NeDsMethodOutput *ds_output_dxm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXM.mN = 1;
  out->mDXM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 1);
  return out;
}

static NeDsMethodOutput *ds_output_ddm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDM_P.mNumCol = 0;
  out->mDDM_P.mNumRow = 17;
  out->mDDM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  out->mDDM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_ddm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDM.mN = 0;
  out->mDDM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dum_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUM_P.mNumCol = 4;
  out->mDUM_P.mNumRow = 17;
  out->mDUM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mDUM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dum(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUM.mN = 0;
  out->mDUM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dtm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTM_P.mNumCol = 1;
  out->mDTM_P.mNumRow = 17;
  out->mDTM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mDTM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dtm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTM.mN = 0;
  out->mDTM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dpm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDPM_P.mNumCol = 9;
  out->mDPM_P.mNumRow = 17;
  out->mDPM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    10);
  out->mDPM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dpm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDPM.mN = 0;
  out->mDPM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_acon_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mACON_P.mNumCol = 58;
  out->mACON_P.mNumRow = 58;
  out->mACON_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    59);
  out->mACON_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    103);
  return out;
}

static NeDsMethodOutput *ds_output_acon(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mACON.mN = 103;
  out->mACON.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    103);
  return out;
}

static NeDsMethodOutput *ds_output_apar_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mAPAR_P.mNumCol = 58;
  out->mAPAR_P.mNumRow = 58;
  out->mAPAR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    59);
  out->mAPAR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_apar(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mAPAR.mN = 0;
  out->mAPAR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_bcon_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mBCON_P.mNumCol = 4;
  out->mBCON_P.mNumRow = 58;
  out->mBCON_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mBCON_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    3);
  return out;
}

static NeDsMethodOutput *ds_output_bcon(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mBCON.mN = 3;
  out->mBCON.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 3);
  return out;
}

static NeDsMethodOutput *ds_output_bpar_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mBPAR_P.mNumCol = 4;
  out->mBPAR_P.mNumRow = 58;
  out->mBPAR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mBPAR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_bpar(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mBPAR.mN = 0;
  out->mBPAR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ccon_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCCON_P.mNumCol = 1;
  out->mCCON_P.mNumRow = 58;
  out->mCCON_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mCCON_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_ccon(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCCON.mN = 0;
  out->mCCON.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_cpar_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCPAR_P.mNumCol = 1;
  out->mCPAR_P.mNumRow = 58;
  out->mCPAR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mCPAR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_cpar(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCPAR.mN = 0;
  out->mCPAR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_f(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mF.mN = 58;
  out->mF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 58);
  return out;
}

static NeDsMethodOutput *ds_output_vdf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVDF.mN = 58;
  out->mVDF.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    58);
  return out;
}

static NeDsMethodOutput *ds_output_vmf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVMF.mN = 58;
  out->mVMF.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    58);
  return out;
}

static NeDsMethodOutput *ds_output_vpf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVPF.mN = 58;
  out->mVPF.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    58);
  return out;
}

static NeDsMethodOutput *ds_output_vsf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVSF.mN = 58;
  out->mVSF.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    58);
  return out;
}

static NeDsMethodOutput *ds_output_slf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSLF.mN = 58;
  out->mSLF.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    58);
  return out;
}

static NeDsMethodOutput *ds_output_slf0(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSLF0.mN = 58;
  out->mSLF0.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 58);
  return out;
}

static NeDsMethodOutput *ds_output_dxf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXF_P.mNumCol = 58;
  out->mDXF_P.mNumRow = 58;
  out->mDXF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    59);
  out->mDXF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    54);
  return out;
}

static NeDsMethodOutput *ds_output_dxf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXF.mN = 54;
  out->mDXF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 54);
  return out;
}

static NeDsMethodOutput *ds_output_duf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUF_P.mNumCol = 4;
  out->mDUF_P.mNumRow = 58;
  out->mDUF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mDUF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  return out;
}

static NeDsMethodOutput *ds_output_duf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUF.mN = 1;
  out->mDUF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 1);
  return out;
}

static NeDsMethodOutput *ds_output_dtf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTF_P.mNumCol = 1;
  out->mDTF_P.mNumRow = 58;
  out->mDTF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mDTF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dtf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTF.mN = 0;
  out->mDTF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDF_P.mNumCol = 0;
  out->mDDF_P.mNumRow = 58;
  out->mDDF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  out->mDDF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_ddf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDF.mN = 0;
  out->mDDF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dpdxf_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDPDXF_P.mNumCol = 9;
  out->mDPDXF_P.mNumRow = 54;
  out->mDPDXF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 10);
  out->mDPDXF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dpdxf(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDPDXF.mN = 0;
  out->mDPDXF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dwf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDWF_P.mNumCol = 0;
  out->mDWF_P.mNumRow = 58;
  out->mDWF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  out->mDWF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dwf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDWF.mN = 0;
  out->mDWF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_tduf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDUF_P.mNumCol = 4;
  out->mTDUF_P.mNumRow = 58;
  out->mTDUF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mTDUF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    4);
  return out;
}

static NeDsMethodOutput *ds_output_tdxf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDXF_P.mNumCol = 58;
  out->mTDXF_P.mNumRow = 58;
  out->mTDXF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    59);
  out->mTDXF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    154);
  return out;
}

static NeDsMethodOutput *ds_output_dnf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDNF_P.mNumCol = 56;
  out->mDNF_P.mNumRow = 58;
  out->mDNF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    57);
  out->mDNF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    10);
  return out;
}

static NeDsMethodOutput *ds_output_dnf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDNF.mN = 10;
  out->mDNF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 10);
  return out;
}

static NeDsMethodOutput *ds_output_dnf_v_x(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDNF_V_X.mN = 58;
  out->mDNF_V_X.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 58);
  return out;
}

static NeDsMethodOutput *ds_output_cer(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCER.mN = 0;
  out->mCER.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxcer(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXCER.mN = 0;
  out->mDXCER.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxcer_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXCER_P.mNumCol = 58;
  out->mDXCER_P.mNumRow = 0;
  out->mDXCER_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 59);
  out->mDXCER_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddcer(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDCER.mN = 0;
  out->mDDCER.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddcer_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDCER_P.mNumCol = 0;
  out->mDDCER_P.mNumRow = 0;
  out->mDDCER_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 1);
  out->mDDCER_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ic(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mIC.mN = 58;
  out->mIC.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 58);
  return out;
}

static NeDsMethodOutput *ds_output_icr(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR.mN = 6;
  out->mICR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 6);
  return out;
}

static NeDsMethodOutput *ds_output_icr_im(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR_IM.mN = 6;
  out->mICR_IM.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    6);
  return out;
}

static NeDsMethodOutput *ds_output_icr_id(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR_ID.mN = 6;
  out->mICR_ID.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 6);
  return out;
}

static NeDsMethodOutput *ds_output_icr_il(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR_IL.mN = 6;
  out->mICR_IL.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 6);
  return out;
}

static NeDsMethodOutput *ds_output_dxicr(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXICR.mN = 0;
  out->mDXICR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXICR_P.mNumCol = 58;
  out->mDXICR_P.mNumRow = 6;
  out->mDXICR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 59);
  out->mDXICR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddicr(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDICR.mN = 0;
  out->mDDICR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDICR_P.mNumCol = 0;
  out->mDDICR_P.mNumRow = 6;
  out->mDDICR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 1);
  out->mDDICR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_tduicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDUICR_P.mNumCol = 4;
  out->mTDUICR_P.mNumRow = 6;
  out->mTDUICR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 5);
  out->mTDUICR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_icrm_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICRM_P.mNumCol = 58;
  out->mICRM_P.mNumRow = 6;
  out->mICRM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    59);
  out->mICRM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_icrm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICRM.mN = 0;
  out->mICRM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxicrm_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXICRM_P.mNumCol = 58;
  out->mDXICRM_P.mNumRow = 0;
  out->mDXICRM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 59);
  out->mDXICRM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxicrm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXICRM.mN = 0;
  out->mDXICRM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_ddicrm_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDICRM_P.mNumCol = 0;
  out->mDDICRM_P.mNumRow = 0;
  out->mDDICRM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 1);
  out->mDDICRM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddicrm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDICRM.mN = 0;
  out->mDDICRM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_freqs(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mFREQS.mN = 0;
  out->mFREQS.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_solverhits(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSOLVERHITS.mN = 0;
  out->mSOLVERHITS.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof
    (real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_mduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMDUY_P.mNumCol = 4;
  out->mMDUY_P.mNumRow = 27;
  out->mMDUY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mMDUY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_mdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMDXY_P.mNumCol = 58;
  out->mMDXY_P.mNumRow = 27;
  out->mMDXY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    59);
  out->mMDXY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_tduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDUY_P.mNumCol = 4;
  out->mTDUY_P.mNumRow = 27;
  out->mTDUY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mTDUY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  return out;
}

static NeDsMethodOutput *ds_output_tdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDXY_P.mNumCol = 58;
  out->mTDXY_P.mNumRow = 27;
  out->mTDXY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    59);
  out->mTDXY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    51);
  return out;
}

static NeDsMethodOutput *ds_output_y(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mY.mN = 27;
  out->mY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 27);
  return out;
}

static NeDsMethodOutput *ds_output_dxy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXY_P.mNumCol = 58;
  out->mDXY_P.mNumRow = 27;
  out->mDXY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    59);
  out->mDXY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    51);
  return out;
}

static NeDsMethodOutput *ds_output_dxy(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXY.mN = 51;
  out->mDXY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 51);
  return out;
}

static NeDsMethodOutput *ds_output_duy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUY_P.mNumCol = 4;
  out->mDUY_P.mNumRow = 27;
  out->mDUY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mDUY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  return out;
}

static NeDsMethodOutput *ds_output_duy(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUY.mN = 1;
  out->mDUY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 1);
  return out;
}

static NeDsMethodOutput *ds_output_dty_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTY_P.mNumCol = 1;
  out->mDTY_P.mNumRow = 27;
  out->mDTY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mDTY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dty(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTY.mN = 0;
  out->mDTY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_mode(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMODE.mN = 13;
  out->mMODE.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    13);
  return out;
}

static NeDsMethodOutput *ds_output_zc(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mZC.mN = 13;
  out->mZC.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 13);
  return out;
}

static NeDsMethodOutput *ds_output_cache_r(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCACHE_R.mN = 0;
  out->mCACHE_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_cache_i(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCACHE_I.mN = 0;
  out->mCACHE_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_update_r(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mUPDATE_R.mN = 0;
  out->mUPDATE_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_update_i(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mUPDATE_I.mN = 0;
  out->mUPDATE_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_update2_r(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mUPDATE2_R.mN = 0;
  out->mUPDATE2_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_update2_i(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mUPDATE2_I.mN = 0;
  out->mUPDATE2_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_lock_r(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLOCK_R.mN = 0;
  out->mLOCK_R.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_lock_i(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLOCK_I.mN = 0;
  out->mLOCK_I.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_lock2_r(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLOCK2_R.mN = 0;
  out->mLOCK2_R.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_lock2_i(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLOCK2_I.mN = 0;
  out->mLOCK2_I.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_sfo(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSFO.mN = 0;
  out->mSFO.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_sfp(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSFP.mN = 0;
  out->mSFP.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_init_r(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mINIT_R.mN = 0;
  out->mINIT_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_init_i(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mINIT_I.mN = 0;
  out->mINIT_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_log(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLOG.mN = 391;
  out->mLOG.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 391);
  return out;
}

static NeDsMethodOutput *ds_output_assert(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mASSERT.mN = 40;
  out->mASSERT.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    40);
  return out;
}

static NeDsMethodOutput *ds_output_passert(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mPASSERT.mN = 1;
  out->mPASSERT.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  return out;
}

static NeDsMethodOutput *ds_output_iassert(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mIASSERT.mN = 0;
  out->mIASSERT.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_del_t(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_T.mN = 0;
  out->mDEL_T.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_del_v(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_V.mN = 0;
  out->mDEL_V.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_del_v0(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_V0.mN = 0;
  out->mDEL_V0.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_del_tmax(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_TMAX.mN = 0;
  out->mDEL_TMAX.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dxdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXDELT_P.mNumCol = 58;
  out->mDXDELT_P.mNumRow = 0;
  out->mDXDELT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 59);
  out->mDXDELT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXDELT.mN = 0;
  out->mDXDELT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dudelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUDELT_P.mNumCol = 4;
  out->mDUDELT_P.mNumRow = 0;
  out->mDUDELT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 5);
  out->mDUDELT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dudelt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUDELT.mN = 0;
  out->mDUDELT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dtdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTDELT_P.mNumCol = 1;
  out->mDTDELT_P.mNumRow = 0;
  out->mDTDELT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 2);
  out->mDTDELT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dtdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTDELT.mN = 0;
  out->mDTDELT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_obs_exp(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_EXP.mN = 479;
  out->mOBS_EXP.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    479);
  return out;
}

static NeDsMethodOutput *ds_output_obs_act(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_ACT.mN = 479;
  out->mOBS_ACT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    479);
  return out;
}

static NeDsMethodOutput *ds_output_obs_all(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_ALL.mN = 479;
  out->mOBS_ALL.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    479);
  return out;
}

static NeDsMethodOutput *ds_output_obs_il(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_IL.mN = 479;
  out->mOBS_IL.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 479);
  return out;
}

static NeDsMethodOutput *ds_output_dp_l(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_L.mN = 0;
  out->mDP_L.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dp_i(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_I.mN = 0;
  out->mDP_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dp_j(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_J.mN = 0;
  out->mDP_J.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dp_r(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_R.mN = 3;
  out->mDP_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 3);
  return out;
}

static NeDsMethodOutput *ds_output_qx(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQX.mN = 99;
  out->mQX.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 99);
  return out;
}

static NeDsMethodOutput *ds_output_qu(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQU.mN = 5;
  out->mQU.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 5);
  return out;
}

static NeDsMethodOutput *ds_output_qt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQT.mN = 0;
  out->mQT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_q1(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQ1.mN = 23;
  out->mQ1.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 23);
  return out;
}

static NeDsMethodOutput *ds_output_qx_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQX_P.mNumCol = 58;
  out->mQX_P.mNumRow = 58;
  out->mQX_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    59);
  out->mQX_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    99);
  return out;
}

static NeDsMethodOutput *ds_output_qu_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQU_P.mNumCol = 4;
  out->mQU_P.mNumRow = 58;
  out->mQU_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mQU_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  return out;
}

static NeDsMethodOutput *ds_output_qt_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQT_P.mNumCol = 1;
  out->mQT_P.mNumRow = 58;
  out->mQT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mQT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_q1_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQ1_P.mNumCol = 1;
  out->mQ1_P.mNumRow = 58;
  out->mQ1_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mQ1_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    23);
  return out;
}

static NeDsMethodOutput *ds_output_var_tol(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVAR_TOL.mN = 58;
  out->mVAR_TOL.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    58);
  return out;
}

static NeDsMethodOutput *ds_output_eq_tol(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mEQ_TOL.mN = 58;
  out->mEQ_TOL.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    58);
  return out;
}

static NeDsMethodOutput *ds_output_lv(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLV.mN = 58;
  out->mLV.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    58);
  return out;
}

static NeDsMethodOutput *ds_output_slv(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSLV.mN = 58;
  out->mSLV.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    58);
  return out;
}

static NeDsMethodOutput *ds_output_nldv(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mNLDV.mN = 58;
  out->mNLDV.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 58);
  return out;
}

static NeDsMethodOutput *ds_output_sclv(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSCLV.mN = 58;
  out->mSCLV.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 58);
  return out;
}

static NeDsMethodOutput *ds_output_imin(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mIMIN.mN = 58;
  out->mIMIN.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 58);
  return out;
}

static NeDsMethodOutput *ds_output_imax(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mIMAX.mN = 58;
  out->mIMAX.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 58);
  return out;
}

static NeDsMethodOutput *ds_output_dimin(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDIMIN.mN = 0;
  out->mDIMIN.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dimax(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDIMAX.mN = 0;
  out->mDIMAX.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static void release_reference(NeDynamicSystem *ds)
{
  _NeDynamicSystem *_ds;
  _ds = (_NeDynamicSystem *)ds;
  if (--_ds->mRefCnt == 0) {
    _ds->mAlloc.mFreeFcn(&_ds->mAlloc, _ds);
  }
}

static void get_reference(NeDynamicSystem *ds)
{
  _NeDynamicSystem *_ds;
  _ds = (_NeDynamicSystem *)ds;
  ++_ds->mRefCnt;
}

static NeDynamicSystem *diagnostics(NeDynamicSystem *ds, boolean_T kp)
{
  _NeDynamicSystem *_ds = (_NeDynamicSystem *)ds;
  (void) kp;
  ne_ds_get_reference(&_ds->mBase);
  return &_ds->mBase;
}

static void expand(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                   PmRealVector *out, boolean_T kp)
{
  (void)ds;
  (void)kp;
  memcpy(out->mX, in->mX.mX, sizeof(real_T)*out->mN);
}

static void rtpmap(const NeDynamicSystem * ds, const PmIntVector* inl, const
                   PmIntVector* ini, const PmIntVector* inj, const PmRealVector*
                   inr, PmIntVector* outl, PmIntVector* outi, PmIntVector* outj,
                   PmRealVector* outr)
{
  (void)ds;
  memcpy(outl->mX, inl->mX, sizeof(int32_T)*inl->mN);
  memcpy(outi->mX, ini->mX, sizeof(int32_T)*ini->mN);
  memcpy(outj->mX, inj->mX, sizeof(int32_T)*inj->mN);
  memcpy(outr->mX, inr->mX, sizeof(real_T)*inr->mN);
}

NeDynamicSystem *HEV_SeriesParallel_c0f8494c_49_dae_ds(PmAllocator *allocator)
{
  NeDynamicSystem *ds;
  _NeDynamicSystem *_ds;
  static SscIoInfo input_info[4];
  static SscIoInfo output_info[27];

  /* allocate dynamic system data and extended data */
  _ds = (_NeDynamicSystem *)allocator->mCallocFcn( allocator, sizeof
    (_NeDynamicSystem), 1);
  _ds->mAlloc = *allocator;
  _ds->mRefCnt = 1;
  ds = &_ds->mBase;

  /* setup sizes */
  ds->mNumVariables = 58;
  ds->mNumDiscreteRealVariables = 0;
  ds->mNumDifferentialVariables = 17;
  ds->mNumEquations = 58;
  ds->mNumCEResiduals = 0;
  ds->mNumICResiduals = 6;
  ds->mNumFreqs = 0;
  ds->mNumSolverHits = 0;
  ds->mNumModes = 13;
  ds->mNumMajorModes = 0;
  ds->mNumRealCache = 0;
  ds->mNumIntCache = 0;
  ds->mNumObservables = 497;
  ds->mNumObservableElements = 479;
  ds->mNumZcs = 13;
  ds->mNumAsserts = 40;
  ds->mNumAssertRanges = 40;
  ds->mNumParamAsserts = 1;
  ds->mNumParamAssertRanges = 1;
  ds->mNumInitialAsserts = 0;
  ds->mNumInitialAssertRanges = 0;
  ds->mNumRanges = 14;
  ds->mNumEquationRanges = 87;
  ds->mNumCERRanges = 0;
  ds->mNumICRRanges = 6;
  ds->mNumFundamentalSamples = 0;
  ds->mNumDelays = 0;
  ds->mNumLogicalParameters = 0;
  ds->mNumIntegerParameters = 0;
  ds->mNumIndexParameters = 0;
  ds->mNumRealParameters = 9;
  ds->mNumLogicalDerivedParameters = 0;
  ds->mNumIntegerDerivedParameters = 0;
  ds->mNumIndexDerivedParameters = 0;
  ds->mNumRealDerivedParameters = 3;
  ds->mIsOutputLinear = FALSE;
  ds->mIsOutputSwitchedLinear = FALSE;
  ds->mIsScalable = FALSE;

  /* setup ios */
  ds->mNumIo[SSC_INPUT_IO_TYPE] = 4;
  input_info[0].identifier =
    "Electrical.Generator.System.GF.Simulink_PS_Converter_output0";
  input_info[0].size.numElements = 1;
  input_info[0].size.encodedDimensions = "1x1";
  input_info[0].name =
    "Electrical.Generator.System.GF.Simulink_PS_Converter_output0";
  input_info[0].unit = "1";
  input_info[1].identifier =
    "Electrical.Motor.System.GF.Simulink_PS_Converter_output0";
  input_info[1].size.numElements = 1;
  input_info[1].size.encodedDimensions = "1x1";
  input_info[1].name =
    "Electrical.Motor.System.GF.Simulink_PS_Converter_output0";
  input_info[1].unit = "1";
  input_info[2].identifier = "Engine.Simulink_PS_Converter_output0";
  input_info[2].size.numElements = 1;
  input_info[2].size.encodedDimensions = "1x1";
  input_info[2].name = "Engine.Simulink_PS_Converter_output0";
  input_info[2].unit = "1";
  input_info[3].identifier = "Vehicle.Simulink_PS_Converter_output0";
  input_info[3].size.numElements = 1;
  input_info[3].size.encodedDimensions = "1x1";
  input_info[3].name = "Vehicle.Simulink_PS_Converter_output0";
  input_info[3].unit = "1";
  ds->mIo[SSC_INPUT_IO_TYPE] = input_info;
  ds->mNumIo[SSC_OUTPUT_IO_TYPE] = 27;
  output_info[0].identifier =
    "Electrical.Generator.System.Meas_V.Voltage_Sensor_V0";
  output_info[0].size.numElements = 1;
  output_info[0].size.encodedDimensions = "1x1";
  output_info[0].name = "Electrical.Generator.System.Meas_V.Voltage_Sensor_V0";
  output_info[0].unit = "V";
  output_info[1].identifier =
    "Electrical.Generator.System.Power_Sensor.PS_Product1_O0";
  output_info[1].size.numElements = 1;
  output_info[1].size.encodedDimensions = "1x1";
  output_info[1].name =
    "Electrical.Generator.System.Power_Sensor.PS_Product1_O0";
  output_info[1].unit = "W";
  output_info[2].identifier =
    "Electrical.Generator.System.Sensor_shaft.Motion_Sensor_A0";
  output_info[2].size.numElements = 1;
  output_info[2].size.encodedDimensions = "1x1";
  output_info[2].name =
    "Electrical.Generator.System.Sensor_shaft.Motion_Sensor_A0";
  output_info[2].unit = "rad";
  output_info[3].identifier =
    "Electrical.Generator.System.Sensor_shaft.Motion_Sensor_W0";
  output_info[3].size.numElements = 1;
  output_info[3].size.encodedDimensions = "1x1";
  output_info[3].name =
    "Electrical.Generator.System.Sensor_shaft.Motion_Sensor_W0";
  output_info[3].unit = "rad/s";
  output_info[4].identifier =
    "Electrical.Generator.System.Sensor_shaft.Torque_Sensor_T0";
  output_info[4].size.numElements = 1;
  output_info[4].size.encodedDimensions = "1x1";
  output_info[4].name =
    "Electrical.Generator.System.Sensor_shaft.Torque_Sensor_T0";
  output_info[4].unit = "N*m";
  output_info[5].identifier =
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.PS_Product_O0";
  output_info[5].size.numElements = 1;
  output_info[5].size.encodedDimensions = "1x1";
  output_info[5].name =
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.PS_Product_O0";
  output_info[5].unit = "W";
  output_info[6].identifier =
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.R_O0";
  output_info[6].size.numElements = 1;
  output_info[6].size.encodedDimensions = "1x1";
  output_info[6].name =
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.R_O0";
  output_info[6].unit = "W";
  output_info[7].identifier =
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.x1_6060_O0";
  output_info[7].size.numElements = 1;
  output_info[7].size.encodedDimensions = "1x1";
  output_info[7].name =
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge.x1_6060_O0";
  output_info[7].unit = "A";
  output_info[8].identifier =
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge_I0";
  output_info[8].size.numElements = 1;
  output_info[8].size.encodedDimensions = "1x1";
  output_info[8].name =
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge_I0";
  output_info[8].unit = "A";
  output_info[9].identifier =
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge_V0";
  output_info[9].size.numElements = 1;
  output_info[9].size.encodedDimensions = "1x1";
  output_info[9].name =
    "Electrical.Generic.Measurements1.Calculate_battery_power_charge_V0";
  output_info[9].unit = "V";
  output_info[10].identifier =
    "Electrical.Motor.System.Meas_V.Voltage_Sensor_V0";
  output_info[10].size.numElements = 1;
  output_info[10].size.encodedDimensions = "1x1";
  output_info[10].name = "Electrical.Motor.System.Meas_V.Voltage_Sensor_V0";
  output_info[10].unit = "V";
  output_info[11].identifier =
    "Electrical.Motor.System.Power_Sensor.PS_Product1_O0";
  output_info[11].size.numElements = 1;
  output_info[11].size.encodedDimensions = "1x1";
  output_info[11].name = "Electrical.Motor.System.Power_Sensor.PS_Product1_O0";
  output_info[11].unit = "W";
  output_info[12].identifier =
    "Electrical.Motor.System.Sensor_shaft.Motion_Sensor_A0";
  output_info[12].size.numElements = 1;
  output_info[12].size.encodedDimensions = "1x1";
  output_info[12].name = "Electrical.Motor.System.Sensor_shaft.Motion_Sensor_A0";
  output_info[12].unit = "rad";
  output_info[13].identifier =
    "Electrical.Motor.System.Sensor_shaft.Motion_Sensor_W0";
  output_info[13].size.numElements = 1;
  output_info[13].size.encodedDimensions = "1x1";
  output_info[13].name = "Electrical.Motor.System.Sensor_shaft.Motion_Sensor_W0";
  output_info[13].unit = "rad/s";
  output_info[14].identifier =
    "Electrical.Motor.System.Sensor_shaft.Torque_Sensor_T0";
  output_info[14].size.numElements = 1;
  output_info[14].size.encodedDimensions = "1x1";
  output_info[14].name = "Electrical.Motor.System.Sensor_shaft.Torque_Sensor_T0";
  output_info[14].unit = "N*m";
  output_info[15].identifier = "Engine.Sensor.Ideal_Rotational_Motion_Sensor_W0";
  output_info[15].size.numElements = 1;
  output_info[15].size.encodedDimensions = "1x1";
  output_info[15].name = "Engine.Sensor.Ideal_Rotational_Motion_Sensor_W0";
  output_info[15].unit = "rad/s";
  output_info[16].identifier = "Engine.Sensor.Ideal_Torque_Sensor_T0";
  output_info[16].size.numElements = 1;
  output_info[16].size.encodedDimensions = "1x1";
  output_info[16].name = "Engine.Sensor.Ideal_Torque_Sensor_T0";
  output_info[16].unit = "N*m";
  output_info[17].identifier =
    "Power_Split_Device.Sensor_Carrier_Shaft.Ideal_Rotational_Motion_Sensor_W0";
  output_info[17].size.numElements = 1;
  output_info[17].size.encodedDimensions = "1x1";
  output_info[17].name =
    "Power_Split_Device.Sensor_Carrier_Shaft.Ideal_Rotational_Motion_Sensor_W0";
  output_info[17].unit = "rad/s";
  output_info[18].identifier =
    "Power_Split_Device.Sensor_Carrier_Shaft.Ideal_Torque_Sensor_T0";
  output_info[18].size.numElements = 1;
  output_info[18].size.encodedDimensions = "1x1";
  output_info[18].name =
    "Power_Split_Device.Sensor_Carrier_Shaft.Ideal_Torque_Sensor_T0";
  output_info[18].unit = "N*m";
  output_info[19].identifier =
    "Power_Split_Device.Sensor_Ring_Shaft.Ideal_Rotational_Motion_Sensor_W0";
  output_info[19].size.numElements = 1;
  output_info[19].size.encodedDimensions = "1x1";
  output_info[19].name =
    "Power_Split_Device.Sensor_Ring_Shaft.Ideal_Rotational_Motion_Sensor_W0";
  output_info[19].unit = "rad/s";
  output_info[20].identifier =
    "Power_Split_Device.Sensor_Ring_Shaft.Ideal_Torque_Sensor_T0";
  output_info[20].size.numElements = 1;
  output_info[20].size.encodedDimensions = "1x1";
  output_info[20].name =
    "Power_Split_Device.Sensor_Ring_Shaft.Ideal_Torque_Sensor_T0";
  output_info[20].unit = "N*m";
  output_info[21].identifier =
    "Power_Split_Device.Sensor_Sun_Shaft.Ideal_Rotational_Motion_Sensor_W0";
  output_info[21].size.numElements = 1;
  output_info[21].size.encodedDimensions = "1x1";
  output_info[21].name =
    "Power_Split_Device.Sensor_Sun_Shaft.Ideal_Rotational_Motion_Sensor_W0";
  output_info[21].unit = "rad/s";
  output_info[22].identifier =
    "Power_Split_Device.Sensor_Sun_Shaft.Ideal_Torque_Sensor_T0";
  output_info[22].size.numElements = 1;
  output_info[22].size.encodedDimensions = "1x1";
  output_info[22].name =
    "Power_Split_Device.Sensor_Sun_Shaft.Ideal_Torque_Sensor_T0";
  output_info[22].unit = "N*m";
  output_info[23].identifier = "Vehicle.Left_Tire_S0";
  output_info[23].size.numElements = 1;
  output_info[23].size.encodedDimensions = "1x1";
  output_info[23].name = "Vehicle.Left_Tire_S0";
  output_info[23].unit = "1";
  output_info[24].identifier =
    "Vehicle.Sensor_Speed_and_Power.Ideal_Rotational_Motion_Sensor_W0";
  output_info[24].size.numElements = 1;
  output_info[24].size.encodedDimensions = "1x1";
  output_info[24].name =
    "Vehicle.Sensor_Speed_and_Power.Ideal_Rotational_Motion_Sensor_W0";
  output_info[24].unit = "rad/s";
  output_info[25].identifier =
    "Vehicle.Sensor_Speed_and_Power.Ideal_Torque_Sensor_T0";
  output_info[25].size.numElements = 1;
  output_info[25].size.encodedDimensions = "1x1";
  output_info[25].name = "Vehicle.Sensor_Speed_and_Power.Ideal_Torque_Sensor_T0";
  output_info[25].unit = "N*m";
  output_info[26].identifier = "Vehicle.Vehicle_Body_V0";
  output_info[26].size.numElements = 1;
  output_info[26].size.encodedDimensions = "1x1";
  output_info[26].name = "Vehicle.Vehicle_Body_V0";
  output_info[26].unit = "km/hr";
  ds->mIo[SSC_OUTPUT_IO_TYPE] = output_info;

  /* setup administration methods */
  ds->mReleaseReference = release_reference;
  ds->mGetReference = get_reference;
  ds->mDiagnosticsDsFcn = diagnostics;
  ds->mExpandFcn = expand;
  ds->mRtpMapFcn = rtpmap;
  ds->mMethods[NE_DS_METHOD_MCON_P] = HEV_SeriesParallel_c0f8494c_49_ds_mcon_p;
  ds->mMakeOutput[NE_DS_METHOD_MCON_P] = ds_output_mcon_p;
  ds->mMethods[NE_DS_METHOD_MCON] = ds_mcon;
  ds->mMakeOutput[NE_DS_METHOD_MCON] = ds_output_mcon;
  ds->mMethods[NE_DS_METHOD_MPAR_P] = HEV_SeriesParallel_c0f8494c_49_ds_mpar_p;
  ds->mMakeOutput[NE_DS_METHOD_MPAR_P] = ds_output_mpar_p;
  ds->mMethods[NE_DS_METHOD_MPAR] = ds_mpar;
  ds->mMakeOutput[NE_DS_METHOD_MPAR] = ds_output_mpar;
  ds->mMethods[NE_DS_METHOD_MNL_P] = HEV_SeriesParallel_c0f8494c_49_ds_mnl_p;
  ds->mMakeOutput[NE_DS_METHOD_MNL_P] = ds_output_mnl_p;
  ds->mMethods[NE_DS_METHOD_MNL] = ds_mnl;
  ds->mMakeOutput[NE_DS_METHOD_MNL] = ds_output_mnl;
  ds->mMethods[NE_DS_METHOD_VMM] = ds_vmm;
  ds->mMakeOutput[NE_DS_METHOD_VMM] = ds_output_vmm;
  ds->mMethods[NE_DS_METHOD_DXM_P] = HEV_SeriesParallel_c0f8494c_49_ds_dxm_p;
  ds->mMakeOutput[NE_DS_METHOD_DXM_P] = ds_output_dxm_p;
  ds->mMethods[NE_DS_METHOD_DXM] = ds_dxm;
  ds->mMakeOutput[NE_DS_METHOD_DXM] = ds_output_dxm;
  ds->mMethods[NE_DS_METHOD_DDM_P] = ds_ddm_p;
  ds->mMakeOutput[NE_DS_METHOD_DDM_P] = ds_output_ddm_p;
  ds->mMethods[NE_DS_METHOD_DDM] = ds_ddm;
  ds->mMakeOutput[NE_DS_METHOD_DDM] = ds_output_ddm;
  ds->mMethods[NE_DS_METHOD_DUM_P] = ds_dum_p;
  ds->mMakeOutput[NE_DS_METHOD_DUM_P] = ds_output_dum_p;
  ds->mMethods[NE_DS_METHOD_DUM] = ds_dum;
  ds->mMakeOutput[NE_DS_METHOD_DUM] = ds_output_dum;
  ds->mMethods[NE_DS_METHOD_DTM_P] = ds_dtm_p;
  ds->mMakeOutput[NE_DS_METHOD_DTM_P] = ds_output_dtm_p;
  ds->mMethods[NE_DS_METHOD_DTM] = ds_dtm;
  ds->mMakeOutput[NE_DS_METHOD_DTM] = ds_output_dtm;
  ds->mMethods[NE_DS_METHOD_DPM_P] = ds_dpm_p;
  ds->mMakeOutput[NE_DS_METHOD_DPM_P] = ds_output_dpm_p;
  ds->mMethods[NE_DS_METHOD_DPM] = ds_dpm;
  ds->mMakeOutput[NE_DS_METHOD_DPM] = ds_output_dpm;
  ds->mMethods[NE_DS_METHOD_ACON_P] = HEV_SeriesParallel_c0f8494c_49_ds_acon_p;
  ds->mMakeOutput[NE_DS_METHOD_ACON_P] = ds_output_acon_p;
  ds->mMethods[NE_DS_METHOD_ACON] = HEV_SeriesParallel_c0f8494c_49_ds_acon;
  ds->mMakeOutput[NE_DS_METHOD_ACON] = ds_output_acon;
  ds->mMethods[NE_DS_METHOD_APAR_P] = HEV_SeriesParallel_c0f8494c_49_ds_apar_p;
  ds->mMakeOutput[NE_DS_METHOD_APAR_P] = ds_output_apar_p;
  ds->mMethods[NE_DS_METHOD_APAR] = ds_apar;
  ds->mMakeOutput[NE_DS_METHOD_APAR] = ds_output_apar;
  ds->mMethods[NE_DS_METHOD_BCON_P] = ds_bcon_p;
  ds->mMakeOutput[NE_DS_METHOD_BCON_P] = ds_output_bcon_p;
  ds->mMethods[NE_DS_METHOD_BCON] = ds_bcon;
  ds->mMakeOutput[NE_DS_METHOD_BCON] = ds_output_bcon;
  ds->mMethods[NE_DS_METHOD_BPAR_P] = ds_bpar_p;
  ds->mMakeOutput[NE_DS_METHOD_BPAR_P] = ds_output_bpar_p;
  ds->mMethods[NE_DS_METHOD_BPAR] = ds_bpar;
  ds->mMakeOutput[NE_DS_METHOD_BPAR] = ds_output_bpar;
  ds->mMethods[NE_DS_METHOD_CCON_P] = ds_ccon_p;
  ds->mMakeOutput[NE_DS_METHOD_CCON_P] = ds_output_ccon_p;
  ds->mMethods[NE_DS_METHOD_CCON] = ds_ccon;
  ds->mMakeOutput[NE_DS_METHOD_CCON] = ds_output_ccon;
  ds->mMethods[NE_DS_METHOD_CPAR_P] = ds_cpar_p;
  ds->mMakeOutput[NE_DS_METHOD_CPAR_P] = ds_output_cpar_p;
  ds->mMethods[NE_DS_METHOD_CPAR] = ds_cpar;
  ds->mMakeOutput[NE_DS_METHOD_CPAR] = ds_output_cpar;
  ds->mMethods[NE_DS_METHOD_F] = HEV_SeriesParallel_c0f8494c_49_ds_f;
  ds->mMakeOutput[NE_DS_METHOD_F] = ds_output_f;
  ds->mMethods[NE_DS_METHOD_VDF] = HEV_SeriesParallel_c0f8494c_49_ds_vdf;
  ds->mMakeOutput[NE_DS_METHOD_VDF] = ds_output_vdf;
  ds->mMethods[NE_DS_METHOD_VMF] = HEV_SeriesParallel_c0f8494c_49_ds_vmf;
  ds->mMakeOutput[NE_DS_METHOD_VMF] = ds_output_vmf;
  ds->mMethods[NE_DS_METHOD_VPF] = HEV_SeriesParallel_c0f8494c_49_ds_vpf;
  ds->mMakeOutput[NE_DS_METHOD_VPF] = ds_output_vpf;
  ds->mMethods[NE_DS_METHOD_VSF] = HEV_SeriesParallel_c0f8494c_49_ds_vsf;
  ds->mMakeOutput[NE_DS_METHOD_VSF] = ds_output_vsf;
  ds->mMethods[NE_DS_METHOD_SLF] = HEV_SeriesParallel_c0f8494c_49_ds_slf;
  ds->mMakeOutput[NE_DS_METHOD_SLF] = ds_output_slf;
  ds->mMethods[NE_DS_METHOD_SLF0] = HEV_SeriesParallel_c0f8494c_49_ds_slf0;
  ds->mMakeOutput[NE_DS_METHOD_SLF0] = ds_output_slf0;
  ds->mMethods[NE_DS_METHOD_DXF_P] = HEV_SeriesParallel_c0f8494c_49_ds_dxf_p;
  ds->mMakeOutput[NE_DS_METHOD_DXF_P] = ds_output_dxf_p;
  ds->mMethods[NE_DS_METHOD_DXF] = HEV_SeriesParallel_c0f8494c_49_ds_dxf;
  ds->mMakeOutput[NE_DS_METHOD_DXF] = ds_output_dxf;
  ds->mMethods[NE_DS_METHOD_DUF_P] = ds_duf_p;
  ds->mMakeOutput[NE_DS_METHOD_DUF_P] = ds_output_duf_p;
  ds->mMethods[NE_DS_METHOD_DUF] = ds_duf;
  ds->mMakeOutput[NE_DS_METHOD_DUF] = ds_output_duf;
  ds->mMethods[NE_DS_METHOD_DTF_P] = ds_dtf_p;
  ds->mMakeOutput[NE_DS_METHOD_DTF_P] = ds_output_dtf_p;
  ds->mMethods[NE_DS_METHOD_DTF] = ds_dtf;
  ds->mMakeOutput[NE_DS_METHOD_DTF] = ds_output_dtf;
  ds->mMethods[NE_DS_METHOD_DDF_P] = ds_ddf_p;
  ds->mMakeOutput[NE_DS_METHOD_DDF_P] = ds_output_ddf_p;
  ds->mMethods[NE_DS_METHOD_DDF] = ds_ddf;
  ds->mMakeOutput[NE_DS_METHOD_DDF] = ds_output_ddf;
  ds->mMethods[NE_DS_METHOD_DPDXF_P] = ds_dpdxf_p;
  ds->mMakeOutput[NE_DS_METHOD_DPDXF_P] = ds_output_dpdxf_p;
  ds->mMethods[NE_DS_METHOD_DPDXF] = ds_dpdxf;
  ds->mMakeOutput[NE_DS_METHOD_DPDXF] = ds_output_dpdxf;
  ds->mMethods[NE_DS_METHOD_DWF_P] = ds_dwf_p;
  ds->mMakeOutput[NE_DS_METHOD_DWF_P] = ds_output_dwf_p;
  ds->mMethods[NE_DS_METHOD_DWF] = ds_dwf;
  ds->mMakeOutput[NE_DS_METHOD_DWF] = ds_output_dwf;
  ds->mMethods[NE_DS_METHOD_TDUF_P] = ds_tduf_p;
  ds->mMakeOutput[NE_DS_METHOD_TDUF_P] = ds_output_tduf_p;
  ds->mMethods[NE_DS_METHOD_TDXF_P] = HEV_SeriesParallel_c0f8494c_49_ds_tdxf_p;
  ds->mMakeOutput[NE_DS_METHOD_TDXF_P] = ds_output_tdxf_p;
  ds->mMethods[NE_DS_METHOD_DNF_P] = HEV_SeriesParallel_c0f8494c_49_ds_dnf_p;
  ds->mMakeOutput[NE_DS_METHOD_DNF_P] = ds_output_dnf_p;
  ds->mMethods[NE_DS_METHOD_DNF] = ds_dnf;
  ds->mMakeOutput[NE_DS_METHOD_DNF] = ds_output_dnf;
  ds->mMethods[NE_DS_METHOD_DNF_V_X] = HEV_SeriesParallel_c0f8494c_49_ds_dnf_v_x;
  ds->mMakeOutput[NE_DS_METHOD_DNF_V_X] = ds_output_dnf_v_x;
  ds->mMethods[NE_DS_METHOD_CER] = ds_cer;
  ds->mMakeOutput[NE_DS_METHOD_CER] = ds_output_cer;
  ds->mMethods[NE_DS_METHOD_DXCER] = ds_dxcer;
  ds->mMakeOutput[NE_DS_METHOD_DXCER] = ds_output_dxcer;
  ds->mMethods[NE_DS_METHOD_DXCER_P] = HEV_SeriesParallel_c0f8494c_49_ds_dxcer_p;
  ds->mMakeOutput[NE_DS_METHOD_DXCER_P] = ds_output_dxcer_p;
  ds->mMethods[NE_DS_METHOD_DDCER] = ds_ddcer;
  ds->mMakeOutput[NE_DS_METHOD_DDCER] = ds_output_ddcer;
  ds->mMethods[NE_DS_METHOD_DDCER_P] = ds_ddcer_p;
  ds->mMakeOutput[NE_DS_METHOD_DDCER_P] = ds_output_ddcer_p;
  ds->mMethods[NE_DS_METHOD_IC] = HEV_SeriesParallel_c0f8494c_49_ds_ic;
  ds->mMakeOutput[NE_DS_METHOD_IC] = ds_output_ic;
  ds->mMethods[NE_DS_METHOD_ICR] = ds_icr;
  ds->mMakeOutput[NE_DS_METHOD_ICR] = ds_output_icr;
  ds->mMethods[NE_DS_METHOD_ICR_IM] = ds_icr_im;
  ds->mMakeOutput[NE_DS_METHOD_ICR_IM] = ds_output_icr_im;
  ds->mMethods[NE_DS_METHOD_ICR_ID] = ds_icr_id;
  ds->mMakeOutput[NE_DS_METHOD_ICR_ID] = ds_output_icr_id;
  ds->mMethods[NE_DS_METHOD_ICR_IL] = ds_icr_il;
  ds->mMakeOutput[NE_DS_METHOD_ICR_IL] = ds_output_icr_il;
  ds->mMethods[NE_DS_METHOD_DXICR] = ds_dxicr;
  ds->mMakeOutput[NE_DS_METHOD_DXICR] = ds_output_dxicr;
  ds->mMethods[NE_DS_METHOD_DXICR_P] = HEV_SeriesParallel_c0f8494c_49_ds_dxicr_p;
  ds->mMakeOutput[NE_DS_METHOD_DXICR_P] = ds_output_dxicr_p;
  ds->mMethods[NE_DS_METHOD_DDICR] = ds_ddicr;
  ds->mMakeOutput[NE_DS_METHOD_DDICR] = ds_output_ddicr;
  ds->mMethods[NE_DS_METHOD_DDICR_P] = ds_ddicr_p;
  ds->mMakeOutput[NE_DS_METHOD_DDICR_P] = ds_output_ddicr_p;
  ds->mMethods[NE_DS_METHOD_TDUICR_P] = ds_tduicr_p;
  ds->mMakeOutput[NE_DS_METHOD_TDUICR_P] = ds_output_tduicr_p;
  ds->mMethods[NE_DS_METHOD_ICRM_P] = HEV_SeriesParallel_c0f8494c_49_ds_icrm_p;
  ds->mMakeOutput[NE_DS_METHOD_ICRM_P] = ds_output_icrm_p;
  ds->mMethods[NE_DS_METHOD_ICRM] = ds_icrm;
  ds->mMakeOutput[NE_DS_METHOD_ICRM] = ds_output_icrm;
  ds->mMethods[NE_DS_METHOD_DXICRM_P] =
    HEV_SeriesParallel_c0f8494c_49_ds_dxicrm_p;
  ds->mMakeOutput[NE_DS_METHOD_DXICRM_P] = ds_output_dxicrm_p;
  ds->mMethods[NE_DS_METHOD_DXICRM] = ds_dxicrm;
  ds->mMakeOutput[NE_DS_METHOD_DXICRM] = ds_output_dxicrm;
  ds->mMethods[NE_DS_METHOD_DDICRM_P] = ds_ddicrm_p;
  ds->mMakeOutput[NE_DS_METHOD_DDICRM_P] = ds_output_ddicrm_p;
  ds->mMethods[NE_DS_METHOD_DDICRM] = ds_ddicrm;
  ds->mMakeOutput[NE_DS_METHOD_DDICRM] = ds_output_ddicrm;
  ds->mMethods[NE_DS_METHOD_FREQS] = ds_freqs;
  ds->mMakeOutput[NE_DS_METHOD_FREQS] = ds_output_freqs;
  ds->mMethods[NE_DS_METHOD_SOLVERHITS] = ds_solverhits;
  ds->mMakeOutput[NE_DS_METHOD_SOLVERHITS] = ds_output_solverhits;
  ds->mMethods[NE_DS_METHOD_MDUY_P] = ds_mduy_p;
  ds->mMakeOutput[NE_DS_METHOD_MDUY_P] = ds_output_mduy_p;
  ds->mMethods[NE_DS_METHOD_MDXY_P] = HEV_SeriesParallel_c0f8494c_49_ds_mdxy_p;
  ds->mMakeOutput[NE_DS_METHOD_MDXY_P] = ds_output_mdxy_p;
  ds->mMethods[NE_DS_METHOD_TDUY_P] = ds_tduy_p;
  ds->mMakeOutput[NE_DS_METHOD_TDUY_P] = ds_output_tduy_p;
  ds->mMethods[NE_DS_METHOD_TDXY_P] = HEV_SeriesParallel_c0f8494c_49_ds_tdxy_p;
  ds->mMakeOutput[NE_DS_METHOD_TDXY_P] = ds_output_tdxy_p;
  ds->mMethods[NE_DS_METHOD_Y] = HEV_SeriesParallel_c0f8494c_49_ds_y;
  ds->mMakeOutput[NE_DS_METHOD_Y] = ds_output_y;
  ds->mMethods[NE_DS_METHOD_DXY_P] = HEV_SeriesParallel_c0f8494c_49_ds_dxy_p;
  ds->mMakeOutput[NE_DS_METHOD_DXY_P] = ds_output_dxy_p;
  ds->mMethods[NE_DS_METHOD_DXY] = HEV_SeriesParallel_c0f8494c_49_ds_dxy;
  ds->mMakeOutput[NE_DS_METHOD_DXY] = ds_output_dxy;
  ds->mMethods[NE_DS_METHOD_DUY_P] = ds_duy_p;
  ds->mMakeOutput[NE_DS_METHOD_DUY_P] = ds_output_duy_p;
  ds->mMethods[NE_DS_METHOD_DUY] = ds_duy;
  ds->mMakeOutput[NE_DS_METHOD_DUY] = ds_output_duy;
  ds->mMethods[NE_DS_METHOD_DTY_P] = ds_dty_p;
  ds->mMakeOutput[NE_DS_METHOD_DTY_P] = ds_output_dty_p;
  ds->mMethods[NE_DS_METHOD_DTY] = ds_dty;
  ds->mMakeOutput[NE_DS_METHOD_DTY] = ds_output_dty;
  ds->mMethods[NE_DS_METHOD_MODE] = HEV_SeriesParallel_c0f8494c_49_ds_mode;
  ds->mMakeOutput[NE_DS_METHOD_MODE] = ds_output_mode;
  ds->mMethods[NE_DS_METHOD_ZC] = HEV_SeriesParallel_c0f8494c_49_ds_zc;
  ds->mMakeOutput[NE_DS_METHOD_ZC] = ds_output_zc;
  ds->mMethods[NE_DS_METHOD_CACHE_R] = ds_cache_r;
  ds->mMakeOutput[NE_DS_METHOD_CACHE_R] = ds_output_cache_r;
  ds->mMethods[NE_DS_METHOD_CACHE_I] = ds_cache_i;
  ds->mMakeOutput[NE_DS_METHOD_CACHE_I] = ds_output_cache_i;
  ds->mMethods[NE_DS_METHOD_UPDATE_R] = ds_update_r;
  ds->mMakeOutput[NE_DS_METHOD_UPDATE_R] = ds_output_update_r;
  ds->mMethods[NE_DS_METHOD_UPDATE_I] = ds_update_i;
  ds->mMakeOutput[NE_DS_METHOD_UPDATE_I] = ds_output_update_i;
  ds->mMethods[NE_DS_METHOD_UPDATE2_R] = ds_update2_r;
  ds->mMakeOutput[NE_DS_METHOD_UPDATE2_R] = ds_output_update2_r;
  ds->mMethods[NE_DS_METHOD_UPDATE2_I] = ds_update2_i;
  ds->mMakeOutput[NE_DS_METHOD_UPDATE2_I] = ds_output_update2_i;
  ds->mMethods[NE_DS_METHOD_LOCK_R] = ds_lock_r;
  ds->mMakeOutput[NE_DS_METHOD_LOCK_R] = ds_output_lock_r;
  ds->mMethods[NE_DS_METHOD_LOCK_I] = ds_lock_i;
  ds->mMakeOutput[NE_DS_METHOD_LOCK_I] = ds_output_lock_i;
  ds->mMethods[NE_DS_METHOD_LOCK2_R] = ds_lock2_r;
  ds->mMakeOutput[NE_DS_METHOD_LOCK2_R] = ds_output_lock2_r;
  ds->mMethods[NE_DS_METHOD_LOCK2_I] = ds_lock2_i;
  ds->mMakeOutput[NE_DS_METHOD_LOCK2_I] = ds_output_lock2_i;
  ds->mMethods[NE_DS_METHOD_SFO] = ds_sfo;
  ds->mMakeOutput[NE_DS_METHOD_SFO] = ds_output_sfo;
  ds->mMethods[NE_DS_METHOD_SFP] = ds_sfp;
  ds->mMakeOutput[NE_DS_METHOD_SFP] = ds_output_sfp;
  ds->mMethods[NE_DS_METHOD_INIT_R] = ds_init_r;
  ds->mMakeOutput[NE_DS_METHOD_INIT_R] = ds_output_init_r;
  ds->mMethods[NE_DS_METHOD_INIT_I] = ds_init_i;
  ds->mMakeOutput[NE_DS_METHOD_INIT_I] = ds_output_init_i;
  ds->mMethods[NE_DS_METHOD_LOG] = HEV_SeriesParallel_c0f8494c_49_ds_log;
  ds->mMakeOutput[NE_DS_METHOD_LOG] = ds_output_log;
  ds->mMethods[NE_DS_METHOD_ASSERT] = HEV_SeriesParallel_c0f8494c_49_ds_assert;
  ds->mMakeOutput[NE_DS_METHOD_ASSERT] = ds_output_assert;
  ds->mMethods[NE_DS_METHOD_PASSERT] = ds_passert;
  ds->mMakeOutput[NE_DS_METHOD_PASSERT] = ds_output_passert;
  ds->mMethods[NE_DS_METHOD_IASSERT] = ds_iassert;
  ds->mMakeOutput[NE_DS_METHOD_IASSERT] = ds_output_iassert;
  ds->mMethods[NE_DS_METHOD_DEL_T] = ds_del_t;
  ds->mMakeOutput[NE_DS_METHOD_DEL_T] = ds_output_del_t;
  ds->mMethods[NE_DS_METHOD_DEL_V] = ds_del_v;
  ds->mMakeOutput[NE_DS_METHOD_DEL_V] = ds_output_del_v;
  ds->mMethods[NE_DS_METHOD_DEL_V0] = ds_del_v0;
  ds->mMakeOutput[NE_DS_METHOD_DEL_V0] = ds_output_del_v0;
  ds->mMethods[NE_DS_METHOD_DEL_TMAX] = ds_del_tmax;
  ds->mMakeOutput[NE_DS_METHOD_DEL_TMAX] = ds_output_del_tmax;
  ds->mMethods[NE_DS_METHOD_DXDELT_P] =
    HEV_SeriesParallel_c0f8494c_49_ds_dxdelt_p;
  ds->mMakeOutput[NE_DS_METHOD_DXDELT_P] = ds_output_dxdelt_p;
  ds->mMethods[NE_DS_METHOD_DXDELT] = ds_dxdelt;
  ds->mMakeOutput[NE_DS_METHOD_DXDELT] = ds_output_dxdelt;
  ds->mMethods[NE_DS_METHOD_DUDELT_P] = ds_dudelt_p;
  ds->mMakeOutput[NE_DS_METHOD_DUDELT_P] = ds_output_dudelt_p;
  ds->mMethods[NE_DS_METHOD_DUDELT] = ds_dudelt;
  ds->mMakeOutput[NE_DS_METHOD_DUDELT] = ds_output_dudelt;
  ds->mMethods[NE_DS_METHOD_DTDELT_P] = ds_dtdelt_p;
  ds->mMakeOutput[NE_DS_METHOD_DTDELT_P] = ds_output_dtdelt_p;
  ds->mMethods[NE_DS_METHOD_DTDELT] = ds_dtdelt;
  ds->mMakeOutput[NE_DS_METHOD_DTDELT] = ds_output_dtdelt;
  ds->mMethods[NE_DS_METHOD_OBS_EXP] = HEV_SeriesParallel_c0f8494c_49_ds_obs_exp;
  ds->mMakeOutput[NE_DS_METHOD_OBS_EXP] = ds_output_obs_exp;
  ds->mMethods[NE_DS_METHOD_OBS_ACT] = HEV_SeriesParallel_c0f8494c_49_ds_obs_act;
  ds->mMakeOutput[NE_DS_METHOD_OBS_ACT] = ds_output_obs_act;
  ds->mMethods[NE_DS_METHOD_OBS_ALL] = HEV_SeriesParallel_c0f8494c_49_ds_obs_all;
  ds->mMakeOutput[NE_DS_METHOD_OBS_ALL] = ds_output_obs_all;
  ds->mMethods[NE_DS_METHOD_OBS_IL] = HEV_SeriesParallel_c0f8494c_49_ds_obs_il;
  ds->mMakeOutput[NE_DS_METHOD_OBS_IL] = ds_output_obs_il;
  ds->mMethods[NE_DS_METHOD_DP_L] = ds_dp_l;
  ds->mMakeOutput[NE_DS_METHOD_DP_L] = ds_output_dp_l;
  ds->mMethods[NE_DS_METHOD_DP_I] = ds_dp_i;
  ds->mMakeOutput[NE_DS_METHOD_DP_I] = ds_output_dp_i;
  ds->mMethods[NE_DS_METHOD_DP_J] = ds_dp_j;
  ds->mMakeOutput[NE_DS_METHOD_DP_J] = ds_output_dp_j;
  ds->mMethods[NE_DS_METHOD_DP_R] = ds_dp_r;
  ds->mMakeOutput[NE_DS_METHOD_DP_R] = ds_output_dp_r;
  ds->mMethods[NE_DS_METHOD_QX] = HEV_SeriesParallel_c0f8494c_49_ds_qx;
  ds->mMakeOutput[NE_DS_METHOD_QX] = ds_output_qx;
  ds->mMethods[NE_DS_METHOD_QU] = ds_qu;
  ds->mMakeOutput[NE_DS_METHOD_QU] = ds_output_qu;
  ds->mMethods[NE_DS_METHOD_QT] = ds_qt;
  ds->mMakeOutput[NE_DS_METHOD_QT] = ds_output_qt;
  ds->mMethods[NE_DS_METHOD_Q1] = ds_q1;
  ds->mMakeOutput[NE_DS_METHOD_Q1] = ds_output_q1;
  ds->mMethods[NE_DS_METHOD_QX_P] = HEV_SeriesParallel_c0f8494c_49_ds_qx_p;
  ds->mMakeOutput[NE_DS_METHOD_QX_P] = ds_output_qx_p;
  ds->mMethods[NE_DS_METHOD_QU_P] = ds_qu_p;
  ds->mMakeOutput[NE_DS_METHOD_QU_P] = ds_output_qu_p;
  ds->mMethods[NE_DS_METHOD_QT_P] = ds_qt_p;
  ds->mMakeOutput[NE_DS_METHOD_QT_P] = ds_output_qt_p;
  ds->mMethods[NE_DS_METHOD_Q1_P] = HEV_SeriesParallel_c0f8494c_49_ds_q1_p;
  ds->mMakeOutput[NE_DS_METHOD_Q1_P] = ds_output_q1_p;
  ds->mMethods[NE_DS_METHOD_VAR_TOL] = HEV_SeriesParallel_c0f8494c_49_ds_var_tol;
  ds->mMakeOutput[NE_DS_METHOD_VAR_TOL] = ds_output_var_tol;
  ds->mMethods[NE_DS_METHOD_EQ_TOL] = HEV_SeriesParallel_c0f8494c_49_ds_eq_tol;
  ds->mMakeOutput[NE_DS_METHOD_EQ_TOL] = ds_output_eq_tol;
  ds->mMethods[NE_DS_METHOD_LV] = HEV_SeriesParallel_c0f8494c_49_ds_lv;
  ds->mMakeOutput[NE_DS_METHOD_LV] = ds_output_lv;
  ds->mMethods[NE_DS_METHOD_SLV] = HEV_SeriesParallel_c0f8494c_49_ds_slv;
  ds->mMakeOutput[NE_DS_METHOD_SLV] = ds_output_slv;
  ds->mMethods[NE_DS_METHOD_NLDV] = HEV_SeriesParallel_c0f8494c_49_ds_nldv;
  ds->mMakeOutput[NE_DS_METHOD_NLDV] = ds_output_nldv;
  ds->mMethods[NE_DS_METHOD_SCLV] = HEV_SeriesParallel_c0f8494c_49_ds_sclv;
  ds->mMakeOutput[NE_DS_METHOD_SCLV] = ds_output_sclv;
  ds->mMethods[NE_DS_METHOD_IMIN] = HEV_SeriesParallel_c0f8494c_49_ds_imin;
  ds->mMakeOutput[NE_DS_METHOD_IMIN] = ds_output_imin;
  ds->mMethods[NE_DS_METHOD_IMAX] = HEV_SeriesParallel_c0f8494c_49_ds_imax;
  ds->mMakeOutput[NE_DS_METHOD_IMAX] = ds_output_imax;
  ds->mMethods[NE_DS_METHOD_DIMIN] = ds_dimin;
  ds->mMakeOutput[NE_DS_METHOD_DIMIN] = ds_output_dimin;
  ds->mMethods[NE_DS_METHOD_DIMAX] = ds_dimax;
  ds->mMakeOutput[NE_DS_METHOD_DIMAX] = ds_output_dimax;

  /* equation data */
  ds->mEquationData = s_equation_data;

  /* cer data */
  ds->mCERData = s_cer_data;

  /* icr data */
  ds->mICRData = s_icr_data;

  /* continuous variable data */
  ds->mVariableData = s_variable_data;

  /* discrete variable data */
  ds->mDiscreteData = s_discrete_data;

  /* observable data */
  ds->mObservableData = s_observable_data;

  /* major mode data */
  ds->mMajorModeData = s_major_mode_data;

  /* zc data */
  ds->mZCData = s_zc_data;

  /* ranges */
  ds->mRanges = s_range;

  /* assert data */
  ds->mAssertData = s_assert_data;

  /* assert ranges */
  ds->mAssertRanges = s_assert_range;

  /* param assert data */
  ds->mParamAssertData = s_param_assert_data;

  /* param assert ranges */
  ds->mParamAssertRanges = s_param_assert_range;

  /* initial assert data */
  ds->mInitialAssertData = s_initial_assert_data;

  /* initial assert ranges */
  ds->mInitialAssertRanges = s_initial_assert_range;

  /* equation ranges */
  ds->mEquationRanges = s_equation_range;

  /* cer ranges */
  ds->mCERRanges = s_cer_range;

  /* icr ranges */
  ds->mICRRanges = s_icr_range;

  /* parameters */
  ds->mLogicalParameters = s_logical_parameter_data;
  ds->mIntegerParameters = s_integer_parameter_data;
  ds->mIndexParameters = s_index_parameter_data;
  ds->mRealParameters = s_real_parameter_data;

  /* constant tables */
  _ds->mField0 = s_constant_table0;
  _ds->mField1 = s_constant_table1;
  _ds->mField2 = s_constant_table2;
  _ds->mField3 = s_constant_table3;
  ds->mNumLargeArray = 4;
  return (NeDynamicSystem *)_ds;
}

static int32_T ds_passert (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)LC;
  out->mPASSERT.mX[0ULL] = (int32_T)(t1->mDP_R.mX[0ULL] > 0.0);
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_iassert (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_cer (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dxcer (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddcer (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddcer_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDDCER_P.mNumCol = 0ULL;
  out->mDDCER_P.mNumRow = 0ULL;
  out->mDDCER_P.mJc[0] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_del_v (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_del_v0 (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_del_tmax (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_del_t (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dxdelt (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dudelt (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dudelt_p (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDUDELT_P.mNumCol = 4ULL;
  out->mDUDELT_P.mNumRow = 0ULL;
  out->mDUDELT_P.mJc[0] = 0;
  out->mDUDELT_P.mJc[1] = 0;
  out->mDUDELT_P.mJc[2] = 0;
  out->mDUDELT_P.mJc[3] = 0;
  out->mDUDELT_P.mJc[4] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dtdelt (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dtdelt_p (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDTDELT_P.mNumCol = 1ULL;
  out->mDTDELT_P.mNumRow = 0ULL;
  out->mDTDELT_P.mJc[0] = 0;
  out->mDTDELT_P.mJc[1] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_cache_r (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_init_r (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_update_r (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_lock_r (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_cache_i (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_init_i (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_update_i (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_lock_i (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_update2_r (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_lock2_r (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_update2_i (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_lock2_i (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_sfp (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_sfo (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_duf (const NeDynamicSystem *LC, const NeDynamicSystemInput *t2,
  NeDsMethodOutput *out)
{
  (void)LC;
  if (t2->mU.mX[2ULL] > 1.0) {
    out->mDUF.mX[0ULL] = 0.0;
  } else {
    out->mDUF.mX[0ULL] = t2->mU.mX[2ULL] >= 0.0 ? -1.0 : 0.0;
  }

  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_duf_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_1[5] = { 0, 0, 0, 1, 1 };

  (void)t1;
  (void)LC;
  out->mDUF_P.mNumCol = 4ULL;
  out->mDUF_P.mNumRow = 58ULL;
  out->mDUF_P.mJc[0] = _cg_const_1[0];
  out->mDUF_P.mJc[1] = _cg_const_1[1];
  out->mDUF_P.mJc[2] = _cg_const_1[2];
  out->mDUF_P.mJc[3] = _cg_const_1[3];
  out->mDUF_P.mJc[4] = _cg_const_1[4];
  out->mDUF_P.mIr[0] = 33;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dtf (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dtf_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDTF_P.mNumCol = 1ULL;
  out->mDTF_P.mNumRow = 58ULL;
  out->mDTF_P.mJc[0] = 0;
  out->mDTF_P.mJc[1] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddf (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddf_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDDF_P.mNumCol = 0ULL;
  out->mDDF_P.mNumRow = 58ULL;
  out->mDDF_P.mJc[0] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_apar (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_bcon (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mBCON.mX[2ULL] = 0.76923076923076916;
  out->mBCON.mX[0ULL] = 1.0;
  out->mBCON.mX[1ULL] = 1.0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_bcon_p (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_1[5] = { 0, 1, 2, 2, 3 };

  static int32_T _cg_const_2[3] = { 3, 8, 18 };

  (void)t1;
  (void)LC;
  out->mBCON_P.mNumCol = 4ULL;
  out->mBCON_P.mNumRow = 58ULL;
  out->mBCON_P.mJc[0] = _cg_const_1[0];
  out->mBCON_P.mJc[1] = _cg_const_1[1];
  out->mBCON_P.mJc[2] = _cg_const_1[2];
  out->mBCON_P.mJc[3] = _cg_const_1[3];
  out->mBCON_P.mJc[4] = _cg_const_1[4];
  out->mBCON_P.mIr[0] = _cg_const_2[0];
  out->mBCON_P.mIr[1] = _cg_const_2[1];
  out->mBCON_P.mIr[2] = _cg_const_2[2];
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_bpar (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_bpar_p (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mBPAR_P.mNumCol = 4ULL;
  out->mBPAR_P.mNumRow = 58ULL;
  out->mBPAR_P.mJc[0] = 0;
  out->mBPAR_P.mJc[1] = 0;
  out->mBPAR_P.mJc[2] = 0;
  out->mBPAR_P.mJc[3] = 0;
  out->mBPAR_P.mJc[4] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ccon (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ccon_p (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mCCON_P.mNumCol = 1ULL;
  out->mCCON_P.mNumRow = 58ULL;
  out->mCCON_P.mJc[0] = 0;
  out->mCCON_P.mJc[1] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_cpar (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_cpar_p (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mCPAR_P.mNumCol = 1ULL;
  out->mCPAR_P.mNumRow = 58ULL;
  out->mCPAR_P.mJc[0] = 0;
  out->mCPAR_P.mJc[1] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_tduf_p (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_2[4] = { 3, 8, 33, 18 };

  (void)t1;
  (void)LC;
  out->mTDUF_P.mNumCol = 4ULL;
  out->mTDUF_P.mNumRow = 58ULL;
  out->mTDUF_P.mJc[0] = 0;
  out->mTDUF_P.mJc[1] = 1;
  out->mTDUF_P.mJc[2] = 2;
  out->mTDUF_P.mJc[3] = 3;
  out->mTDUF_P.mJc[4] = 4;
  out->mTDUF_P.mIr[0] = _cg_const_2[0];
  out->mTDUF_P.mIr[1] = _cg_const_2[1];
  out->mTDUF_P.mIr[2] = _cg_const_2[2];
  out->mTDUF_P.mIr[3] = _cg_const_2[3];
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dwf (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dwf_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDWF_P.mNumCol = 0ULL;
  out->mDWF_P.mNumRow = 58ULL;
  out->mDWF_P.mJc[0] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dpdxf (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dpdxf_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDPDXF_P.mNumCol = 9ULL;
  out->mDPDXF_P.mNumRow = 54ULL;
  out->mDPDXF_P.mJc[0] = 0;
  out->mDPDXF_P.mJc[1] = 0;
  out->mDPDXF_P.mJc[2] = 0;
  out->mDPDXF_P.mJc[3] = 0;
  out->mDPDXF_P.mJc[4] = 0;
  out->mDPDXF_P.mJc[5] = 0;
  out->mDPDXF_P.mJc[6] = 0;
  out->mDPDXF_P.mJc[7] = 0;
  out->mDPDXF_P.mJc[8] = 0;
  out->mDPDXF_P.mJc[9] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dnf (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  static real_T _cg_const_1[10] = { -0.99979596000816173, 1.0, -0.8,
    0.44444444444444442, -0.1, -1.0, 1.0, -0.1, -1.0, 1.0 };

  (void)t1;
  (void)LC;
  out->mDNF.mX[0] = _cg_const_1[0];
  out->mDNF.mX[1] = _cg_const_1[1];
  out->mDNF.mX[2] = _cg_const_1[2];
  out->mDNF.mX[3] = _cg_const_1[3];
  out->mDNF.mX[4] = _cg_const_1[4];
  out->mDNF.mX[5] = _cg_const_1[5];
  out->mDNF.mX[6] = _cg_const_1[6];
  out->mDNF.mX[7] = _cg_const_1[7];
  out->mDNF.mX[8] = _cg_const_1[8];
  out->mDNF.mX[9] = _cg_const_1[9];
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_freqs (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_icr (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mICR.mX[0ULL] = 0.0;
  out->mICR.mX[1ULL] = 0.0;
  out->mICR.mX[2ULL] = 0.0;
  out->mICR.mX[3ULL] = 0.0;
  out->mICR.mX[4ULL] = 0.0;
  out->mICR.mX[5ULL] = 0.0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_icr_im (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mICR_IM.mX[0] = 3;
  out->mICR_IM.mX[1] = 3;
  out->mICR_IM.mX[2] = 3;
  out->mICR_IM.mX[3] = 3;
  out->mICR_IM.mX[4] = 3;
  out->mICR_IM.mX[5] = 3;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_icr_id (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mICR_ID.mX[0] = false;
  out->mICR_ID.mX[1] = false;
  out->mICR_ID.mX[2] = false;
  out->mICR_ID.mX[3] = false;
  out->mICR_ID.mX[4] = false;
  out->mICR_ID.mX[5] = false;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_icr_il (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mICR_IL.mX[0] = true;
  out->mICR_IL.mX[1] = true;
  out->mICR_IL.mX[2] = true;
  out->mICR_IL.mX[3] = true;
  out->mICR_IL.mX[4] = true;
  out->mICR_IL.mX[5] = true;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dxicr (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddicr (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddicr_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDDICR_P.mNumCol = 0ULL;
  out->mDDICR_P.mNumRow = 6ULL;
  out->mDDICR_P.mJc[0] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_tduicr_p (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mTDUICR_P.mNumCol = 4ULL;
  out->mTDUICR_P.mNumRow = 6ULL;
  out->mTDUICR_P.mJc[0] = 0;
  out->mTDUICR_P.mJc[1] = 0;
  out->mTDUICR_P.mJc[2] = 0;
  out->mTDUICR_P.mJc[3] = 0;
  out->mTDUICR_P.mJc[4] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_icrm (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dxicrm (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddicrm (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddicrm_p (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDDICRM_P.mNumCol = 0ULL;
  out->mDDICRM_P.mNumRow = 0ULL;
  out->mDDICRM_P.mJc[0] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dimin (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dimax (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_mcon (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  static real_T _cg_const_1[14] = { 0.02, 1.0, 1.0, 0.013333333333333334, 1.0,
    1.0, -1.0, 1.0, 1.0, 1.0, -1.0, -1.0, 1.0, 1.0 };

  (void)t1;
  (void)LC;
  out->mMCON.mX[0] = _cg_const_1[0];
  out->mMCON.mX[1] = _cg_const_1[1];
  out->mMCON.mX[2] = _cg_const_1[2];
  out->mMCON.mX[3] = _cg_const_1[3];
  out->mMCON.mX[4] = _cg_const_1[4];
  out->mMCON.mX[5] = _cg_const_1[5];
  out->mMCON.mX[6] = _cg_const_1[6];
  out->mMCON.mX[7] = _cg_const_1[7];
  out->mMCON.mX[8] = _cg_const_1[8];
  out->mMCON.mX[9] = _cg_const_1[9];
  out->mMCON.mX[10] = _cg_const_1[10];
  out->mMCON.mX[11] = _cg_const_1[11];
  out->mMCON.mX[12] = _cg_const_1[12];
  out->mMCON.mX[13] = _cg_const_1[13];
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_mpar (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)LC;
  out->mMPAR.mX[0ULL] = -t1->mDP_R.mX[0ULL];
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_mnl (const NeDynamicSystem *LC, const NeDynamicSystemInput *t2,
  NeDsMethodOutput *out)
{
  (void)LC;
  out->mMNL.mX[0ULL] = -(t2->mX.mX[0ULL] * 0.2 + 1000.0) / 1000.0;
  out->mMNL.mX[1ULL] = 1.0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dxm (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDXM.mX[0] = -0.0002;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddm (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddm_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDDM_P.mNumCol = 0ULL;
  out->mDDM_P.mNumRow = 17ULL;
  out->mDDM_P.mJc[0] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dum (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dum_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDUM_P.mNumCol = 4ULL;
  out->mDUM_P.mNumRow = 17ULL;
  out->mDUM_P.mJc[0] = 0;
  out->mDUM_P.mJc[1] = 0;
  out->mDUM_P.mJc[2] = 0;
  out->mDUM_P.mJc[3] = 0;
  out->mDUM_P.mJc[4] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dtm (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dtm_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDTM_P.mNumCol = 1ULL;
  out->mDTM_P.mNumRow = 17ULL;
  out->mDTM_P.mJc[0] = 0;
  out->mDTM_P.mJc[1] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dpm (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dpm_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDPM_P.mNumCol = 9ULL;
  out->mDPM_P.mNumRow = 17ULL;
  out->mDPM_P.mJc[0] = 0;
  out->mDPM_P.mJc[1] = 0;
  out->mDPM_P.mJc[2] = 0;
  out->mDPM_P.mJc[3] = 0;
  out->mDPM_P.mJc[4] = 0;
  out->mDPM_P.mJc[5] = 0;
  out->mDPM_P.mJc[6] = 0;
  out->mDPM_P.mJc[7] = 0;
  out->mDPM_P.mJc[8] = 0;
  out->mDPM_P.mJc[9] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_vmm (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  static boolean_T _cg_const_1[17] = { true, false, false, false, false, false,
    false, false, false, false, false, false, false, true, false, false, false };

  (void)t1;
  (void)LC;
  out->mVMM.mX[0] = _cg_const_1[0];
  out->mVMM.mX[1] = _cg_const_1[1];
  out->mVMM.mX[2] = _cg_const_1[2];
  out->mVMM.mX[3] = _cg_const_1[3];
  out->mVMM.mX[4] = _cg_const_1[4];
  out->mVMM.mX[5] = _cg_const_1[5];
  out->mVMM.mX[6] = _cg_const_1[6];
  out->mVMM.mX[7] = _cg_const_1[7];
  out->mVMM.mX[8] = _cg_const_1[8];
  out->mVMM.mX[9] = _cg_const_1[9];
  out->mVMM.mX[10] = _cg_const_1[10];
  out->mVMM.mX[11] = _cg_const_1[11];
  out->mVMM.mX[12] = _cg_const_1[12];
  out->mVMM.mX[13] = _cg_const_1[13];
  out->mVMM.mX[14] = _cg_const_1[14];
  out->mVMM.mX[15] = _cg_const_1[15];
  out->mVMM.mX[16] = _cg_const_1[16];
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dp_l (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dp_i (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dp_j (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dp_r (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)LC;
  out->mDP_R.mX[0ULL] = t1->mP_R.mX[4ULL];
  out->mDP_R.mX[1ULL] = cos(0.0) * t1->mP_R.mX[4ULL] * 9.81;
  out->mDP_R.mX[2ULL] = sin(0.0) * t1->mP_R.mX[4ULL] * 9.81;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_qu (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *out)
{
  static real_T _cg_const_1[5] = { -0.00016153846153846155, 0.76923076923076916,
    -0.76923076923076916, -2.7751479289940826, -2.7751479289940826 };

  (void)t1;
  (void)LC;
  out->mQU.mX[0] = _cg_const_1[0];
  out->mQU.mX[1] = _cg_const_1[1];
  out->mQU.mX[2] = _cg_const_1[2];
  out->mQU.mX[3] = _cg_const_1[3];
  out->mQU.mX[4] = _cg_const_1[4];
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_qt (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_q1 (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mQ1.mX[0] = 0.0;
  out->mQ1.mX[1] = 0.0;
  out->mQ1.mX[2] = 0.0;
  out->mQ1.mX[3] = 0.0;
  out->mQ1.mX[4] = 0.0;
  out->mQ1.mX[5] = 0.0;
  out->mQ1.mX[6] = 0.0;
  out->mQ1.mX[7] = 0.0;
  out->mQ1.mX[8] = 0.0;
  out->mQ1.mX[9] = 0.0;
  out->mQ1.mX[10] = 0.0;
  out->mQ1.mX[11] = 0.0;
  out->mQ1.mX[12] = 0.0;
  out->mQ1.mX[13] = 0.0;
  out->mQ1.mX[14] = 0.0;
  out->mQ1.mX[15] = 0.0;
  out->mQ1.mX[16] = 0.0;
  out->mQ1.mX[17] = 0.0;
  out->mQ1.mX[18] = 0.0;
  out->mQ1.mX[19] = 0.0;
  out->mQ1.mX[20] = 0.0;
  out->mQ1.mX[21] = 0.0;
  out->mQ1.mX[22] = 0.0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_qu_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_1[5] = { 0, 0, 0, 0, 5 };

  (void)t1;
  (void)LC;
  out->mQU_P.mNumCol = 4ULL;
  out->mQU_P.mNumRow = 58ULL;
  out->mQU_P.mJc[0] = _cg_const_1[0];
  out->mQU_P.mJc[1] = _cg_const_1[1];
  out->mQU_P.mJc[2] = _cg_const_1[2];
  out->mQU_P.mJc[3] = _cg_const_1[3];
  out->mQU_P.mJc[4] = _cg_const_1[4];
  out->mQU_P.mIr[0] = 26;
  out->mQU_P.mIr[1] = 27;
  out->mQU_P.mIr[2] = 28;
  out->mQU_P.mIr[3] = 29;
  out->mQU_P.mIr[4] = 30;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_qt_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mQT_P.mNumCol = 1ULL;
  out->mQT_P.mNumRow = 58ULL;
  out->mQT_P.mJc[0] = 0;
  out->mQT_P.mJc[1] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_solverhits (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_duy (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDUY.mX[0ULL] = -0.76923076923076916;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_duy_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_1[5] = { 0, 0, 0, 0, 1 };

  (void)t1;
  (void)LC;
  out->mDUY_P.mNumCol = 4ULL;
  out->mDUY_P.mNumRow = 27ULL;
  out->mDUY_P.mJc[0] = _cg_const_1[0];
  out->mDUY_P.mJc[1] = _cg_const_1[1];
  out->mDUY_P.mJc[2] = _cg_const_1[2];
  out->mDUY_P.mJc[3] = _cg_const_1[3];
  out->mDUY_P.mJc[4] = _cg_const_1[4];
  out->mDUY_P.mIr[0] = 25;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_mduy_p (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mMDUY_P.mNumCol = 4ULL;
  out->mMDUY_P.mNumRow = 27ULL;
  out->mMDUY_P.mJc[0] = 0;
  out->mMDUY_P.mJc[1] = 0;
  out->mMDUY_P.mJc[2] = 0;
  out->mMDUY_P.mJc[3] = 0;
  out->mMDUY_P.mJc[4] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_tduy_p (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_1[5] = { 0, 0, 0, 0, 1 };

  (void)t1;
  (void)LC;
  out->mTDUY_P.mNumCol = 4ULL;
  out->mTDUY_P.mNumRow = 27ULL;
  out->mTDUY_P.mJc[0] = _cg_const_1[0];
  out->mTDUY_P.mJc[1] = _cg_const_1[1];
  out->mTDUY_P.mJc[2] = _cg_const_1[2];
  out->mTDUY_P.mJc[3] = _cg_const_1[3];
  out->mTDUY_P.mJc[4] = _cg_const_1[4];
  out->mTDUY_P.mIr[0] = 25;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dty (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dty_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDTY_P.mNumCol = 1ULL;
  out->mDTY_P.mNumRow = 27ULL;
  out->mDTY_P.mJc[0] = 0;
  out->mDTY_P.mJc[1] = 0;
  (void)LC;
  (void)out;
  return 0;
}
