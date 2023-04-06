/*
 * CXSparseAPI.c
 *
 * Code generation for function 'CXSparseAPI'
 *
 */

/* Include files */
#include "CXSparseAPI.h"
#include "bLUSGS_naive.h"
#include "bLUSGS_naive_data.h"
#include "bLUSGS_naive_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "makeCXSparseMatrix.h"
#include "rt_nonfinite.h"
#include "solve_from_lu.h"
#include "solve_from_qr.h"
#include "sparse.h"
#include "warning.h"

/* Variable Definitions */
static emlrtRSInfo sc_emlrtRSI = { 287,/* lineNo */
  "CXSparseAPI/iteratedLU",            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 307,/* lineNo */
  "CXSparseAPI/iteratedLU",            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 310,/* lineNo */
  "CXSparseAPI/iteratedLU",            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRTEInfo dc_emlrtRTEI = { 324,/* lineNo */
  17,                                  /* colNo */
  "CXSparseAPI",                       /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = { 310,/* lineNo */
  23,                                  /* colNo */
  "CXSparseAPI",                       /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pName */
};

/* Function Definitions */
void CXSparseAPI_iteratedLU(const emlrtStack *sp, const emxArray_real_T *A_d,
  const emxArray_int32_T *A_colidx, const emxArray_int32_T *A_rowidx, int32_T
  A_m, int32_T A_n, const emxArray_real_T *b, emxArray_real_T *out)
{
  emxArray_int32_T *in_colidx;
  emxArray_int32_T *in_rowidx;
  emxArray_int32_T *counts;
  emxArray_real_T *outBuff;
  coder_internal_sparse expl_temp;
  cs_di* cxA;
  int32_T k;
  cs_dis * S;
  cs_din * N;
  int32_T idx;
  real_T tol;
  boolean_T overflow;
  int32_T iv[2];
  int32_T c;
  int32_T outridx;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &sc_emlrtRSI;
  emxInit_int32_T(&st, &in_colidx, 1, &yb_emlrtRTEI, true);
  emxInit_int32_T(&st, &in_rowidx, 1, &yb_emlrtRTEI, true);
  emxInit_int32_T(&st, &counts, 1, &bc_emlrtRTEI, true);
  emxInit_real_T(&st, &outBuff, 1, &cc_emlrtRTEI, true);
  d_emxInitStruct_coder_internal_(&st, &expl_temp, &yb_emlrtRTEI, true);
  if (A_m < A_n) {
    b_st.site = &vc_emlrtRSI;
    c_st.site = &vc_emlrtRSI;
    d_st.site = &xc_emlrtRSI;
    e_st.site = &cd_emlrtRSI;
    sparse_sparse(&e_st, A_n, A_m, A_colidx->data[A_colidx->size[0] - 1] - 1,
                  &expl_temp);
    k = outBuff->size[0];
    outBuff->size[0] = expl_temp.d->size[0];
    emxEnsureCapacity_real_T(&d_st, outBuff, k, &yb_emlrtRTEI);
    idx = expl_temp.d->size[0];
    for (k = 0; k < idx; k++) {
      outBuff->data[k] = expl_temp.d->data[k];
    }

    k = in_colidx->size[0];
    in_colidx->size[0] = expl_temp.colidx->size[0];
    emxEnsureCapacity_int32_T(&d_st, in_colidx, k, &yb_emlrtRTEI);
    idx = expl_temp.colidx->size[0];
    for (k = 0; k < idx; k++) {
      in_colidx->data[k] = expl_temp.colidx->data[k];
    }

    k = in_rowidx->size[0];
    in_rowidx->size[0] = expl_temp.rowidx->size[0];
    emxEnsureCapacity_int32_T(&d_st, in_rowidx, k, &yb_emlrtRTEI);
    idx = expl_temp.rowidx->size[0];
    for (k = 0; k < idx; k++) {
      in_rowidx->data[k] = expl_temp.rowidx->data[k];
    }

    if ((A_m != 0) && (A_n != 0)) {
      idx = in_colidx->size[0];
      k = in_colidx->size[0];
      in_colidx->size[0] = idx;
      emxEnsureCapacity_int32_T(&d_st, in_colidx, k, &yb_emlrtRTEI);
      for (k = 0; k < idx; k++) {
        in_colidx->data[k] = 0;
      }

      idx = A_colidx->data[A_colidx->size[0] - 1];
      e_st.site = &yc_emlrtRSI;
      overflow = ((1 <= A_colidx->data[A_colidx->size[0] - 1] - 1) &&
                  (A_colidx->data[A_colidx->size[0] - 1] - 1 > 2147483646));
      if (overflow) {
        f_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (k = 0; k <= idx - 2; k++) {
        in_colidx->data[A_rowidx->data[k]]++;
      }

      in_colidx->data[0] = 1;
      idx = A_m + 1;
      e_st.site = &ad_emlrtRSI;
      if ((2 <= A_m + 1) && (A_m + 1 > 2147483646)) {
        f_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (k = 2; k <= idx; k++) {
        in_colidx->data[k - 1] += in_colidx->data[k - 2];
      }

      k = counts->size[0];
      counts->size[0] = A_m;
      emxEnsureCapacity_int32_T(&d_st, counts, k, &bc_emlrtRTEI);
      for (k = 0; k < A_m; k++) {
        counts->data[k] = 0;
      }

      e_st.site = &bd_emlrtRSI;
      if ((1 <= A_n) && (A_n > 2147483646)) {
        f_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (c = 0; c < A_n; c++) {
        for (idx = A_colidx->data[c] - 1; idx + 1 < A_colidx->data[c + 1]; idx++)
        {
          k = counts->data[A_rowidx->data[idx] - 1];
          outridx = (k + in_colidx->data[A_rowidx->data[idx] - 1]) - 1;
          outBuff->data[outridx] = A_d->data[idx];
          in_rowidx->data[outridx] = c + 1;
          counts->data[A_rowidx->data[idx] - 1] = k + 1;
        }
      }
    }

    cxA = makeCXSparseMatrix(in_colidx->data[in_colidx->size[0] - 1] - 1,
      expl_temp.n, expl_temp.m, &in_colidx->data[0], &in_rowidx->data[0],
      &outBuff->data[0]);
  } else {
    b_st.site = &wc_emlrtRSI;
    cxA = makeCXSparseMatrix(A_colidx->data[A_colidx->size[0] - 1] - 1, A_n, A_m,
      &A_colidx->data[0], &A_rowidx->data[0], &A_d->data[0]);
  }

  S = cs_di_sqr(2, cxA, 0);
  N = cs_di_lu(cxA, S, 1);
  cs_di_spfree(cxA);
  if (N == NULL) {
    st.site = &tc_emlrtRSI;
    warning(&st);
    cs_di_sfree(S);
    cs_di_nfree(N);
    st.site = &uc_emlrtRSI;
    b_st.site = &ed_emlrtRSI;
    if (A_m < A_n) {
      c_st.site = &vc_emlrtRSI;
      d_st.site = &vc_emlrtRSI;
      e_st.site = &xc_emlrtRSI;
      f_st.site = &cd_emlrtRSI;
      sparse_sparse(&f_st, A_n, A_m, A_colidx->data[A_colidx->size[0] - 1] - 1,
                    &expl_temp);
      k = outBuff->size[0];
      outBuff->size[0] = expl_temp.d->size[0];
      emxEnsureCapacity_real_T(&e_st, outBuff, k, &yb_emlrtRTEI);
      idx = expl_temp.d->size[0];
      for (k = 0; k < idx; k++) {
        outBuff->data[k] = expl_temp.d->data[k];
      }

      k = in_colidx->size[0];
      in_colidx->size[0] = expl_temp.colidx->size[0];
      emxEnsureCapacity_int32_T(&e_st, in_colidx, k, &yb_emlrtRTEI);
      idx = expl_temp.colidx->size[0];
      for (k = 0; k < idx; k++) {
        in_colidx->data[k] = expl_temp.colidx->data[k];
      }

      k = in_rowidx->size[0];
      in_rowidx->size[0] = expl_temp.rowidx->size[0];
      emxEnsureCapacity_int32_T(&e_st, in_rowidx, k, &yb_emlrtRTEI);
      idx = expl_temp.rowidx->size[0];
      for (k = 0; k < idx; k++) {
        in_rowidx->data[k] = expl_temp.rowidx->data[k];
      }

      if ((A_m != 0) && (A_n != 0)) {
        idx = in_colidx->size[0];
        k = in_colidx->size[0];
        in_colidx->size[0] = idx;
        emxEnsureCapacity_int32_T(&e_st, in_colidx, k, &yb_emlrtRTEI);
        for (k = 0; k < idx; k++) {
          in_colidx->data[k] = 0;
        }

        idx = A_colidx->data[A_colidx->size[0] - 1];
        f_st.site = &yc_emlrtRSI;
        overflow = ((1 <= A_colidx->data[A_colidx->size[0] - 1] - 1) &&
                    (A_colidx->data[A_colidx->size[0] - 1] - 1 > 2147483646));
        if (overflow) {
          g_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        for (k = 0; k <= idx - 2; k++) {
          in_colidx->data[A_rowidx->data[k]]++;
        }

        in_colidx->data[0] = 1;
        idx = A_m + 1;
        f_st.site = &ad_emlrtRSI;
        if ((2 <= A_m + 1) && (A_m + 1 > 2147483646)) {
          g_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        for (k = 2; k <= idx; k++) {
          in_colidx->data[k - 1] += in_colidx->data[k - 2];
        }

        k = counts->size[0];
        counts->size[0] = A_m;
        emxEnsureCapacity_int32_T(&e_st, counts, k, &bc_emlrtRTEI);
        for (k = 0; k < A_m; k++) {
          counts->data[k] = 0;
        }

        f_st.site = &bd_emlrtRSI;
        if ((1 <= A_n) && (A_n > 2147483646)) {
          g_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        for (c = 0; c < A_n; c++) {
          for (idx = A_colidx->data[c] - 1; idx + 1 < A_colidx->data[c + 1]; idx
               ++) {
            k = counts->data[A_rowidx->data[idx] - 1];
            outridx = (k + in_colidx->data[A_rowidx->data[idx] - 1]) - 1;
            outBuff->data[outridx] = A_d->data[idx];
            in_rowidx->data[outridx] = c + 1;
            counts->data[A_rowidx->data[idx] - 1] = k + 1;
          }
        }
      }

      cxA = makeCXSparseMatrix(in_colidx->data[in_colidx->size[0] - 1] - 1,
        expl_temp.n, expl_temp.m, &in_colidx->data[0], &in_rowidx->data[0],
        &outBuff->data[0]);
    } else {
      c_st.site = &wc_emlrtRSI;
      cxA = makeCXSparseMatrix(A_colidx->data[A_colidx->size[0] - 1] - 1, A_n,
        A_m, &A_colidx->data[0], &A_rowidx->data[0], &A_d->data[0]);
    }

    S = cs_di_sqr(2, cxA, 1);
    N = cs_di_qr(cxA, S);
    cs_di_spfree(cxA);
    qr_rank_di(N, &tol);
    k = out->size[0];
    out->size[0] = A_n;
    emxEnsureCapacity_real_T(&st, out, k, &ec_emlrtRTEI);
    if (b->size[0] < A_n) {
      k = outBuff->size[0];
      outBuff->size[0] = A_n;
      emxEnsureCapacity_real_T(&st, outBuff, k, &ec_emlrtRTEI);
    } else {
      k = outBuff->size[0];
      outBuff->size[0] = b->size[0];
      emxEnsureCapacity_real_T(&st, outBuff, k, &ec_emlrtRTEI);
    }

    idx = b->size[0];
    for (k = 0; k < idx; k++) {
      outBuff->data[k] = b->data[k];
    }

    solve_from_qr_di(N, S, (double *)&outBuff->data[0], b->size[0], A_n);
    if (1 > A_n) {
      idx = 0;
    } else {
      idx = A_n;
    }

    iv[0] = 1;
    iv[1] = idx;
    b_st.site = &dd_emlrtRSI;
    indexShapeCheck(&b_st, outBuff->size[0], iv);
    for (k = 0; k < idx; k++) {
      out->data[k] = outBuff->data[k];
    }

    cs_di_sfree(S);
    cs_di_nfree(N);
  } else {
    k = out->size[0];
    out->size[0] = b->size[0];
    emxEnsureCapacity_real_T(sp, out, k, &dc_emlrtRTEI);
    idx = b->size[0];
    for (k = 0; k < idx; k++) {
      out->data[k] = b->data[k];
    }

    solve_from_lu_di(N, S, (double *)&out->data[0], b->size[0]);
    cs_di_sfree(S);
    cs_di_nfree(N);
  }

  d_emxFreeStruct_coder_internal_(&expl_temp);
  emxFree_real_T(&outBuff);
  emxFree_int32_T(&counts);
  emxFree_int32_T(&in_rowidx);
  emxFree_int32_T(&in_colidx);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (CXSparseAPI.c) */
