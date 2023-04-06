/*
 * triu.c
 *
 * Code generation for function 'triu'
 *
 */

/* Include files */
#include "triu.h"
#include "bLUSGS_naive.h"
#include "bLUSGS_naive_data.h"
#include "bLUSGS_naive_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sparse.h"

/* Variable Definitions */
static emlrtRSInfo gc_emlrtRSI = { 28, /* lineNo */
  "sparse/triu",                       /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\triu.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 31, /* lineNo */
  "sparse/triu",                       /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\triu.m"/* pathName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 28,/* lineNo */
  1,                                   /* colNo */
  "triu",                              /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\triu.m"/* pName */
};

/* Function Definitions */
void sparse_triu(const emlrtStack *sp, const emxArray_real_T *A_d, const
                 emxArray_int32_T *A_colidx, const emxArray_int32_T *A_rowidx,
                 int32_T A_m, int32_T A_n, emxArray_real_T *U_d,
                 emxArray_int32_T *U_colidx, emxArray_int32_T *U_rowidx, int32_T
                 *U_m, int32_T *U_n)
{
  coder_internal_sparse expl_temp;
  int32_T ridx;
  int32_T didx;
  int32_T col;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  d_emxInitStruct_coder_internal_(sp, &expl_temp, &vb_emlrtRTEI, true);
  st.site = &gc_emlrtRSI;
  sparse_spallocLike(&st, A_m, A_n, A_colidx->data[A_colidx->size[0] - 1] - 1,
                     &expl_temp);
  ridx = U_d->size[0];
  U_d->size[0] = expl_temp.d->size[0];
  emxEnsureCapacity_real_T(sp, U_d, ridx, &vb_emlrtRTEI);
  didx = expl_temp.d->size[0];
  for (ridx = 0; ridx < didx; ridx++) {
    U_d->data[ridx] = expl_temp.d->data[ridx];
  }

  ridx = U_colidx->size[0];
  U_colidx->size[0] = expl_temp.colidx->size[0];
  emxEnsureCapacity_int32_T(sp, U_colidx, ridx, &vb_emlrtRTEI);
  didx = expl_temp.colidx->size[0];
  for (ridx = 0; ridx < didx; ridx++) {
    U_colidx->data[ridx] = expl_temp.colidx->data[ridx];
  }

  ridx = U_rowidx->size[0];
  U_rowidx->size[0] = expl_temp.rowidx->size[0];
  emxEnsureCapacity_int32_T(sp, U_rowidx, ridx, &vb_emlrtRTEI);
  didx = expl_temp.rowidx->size[0];
  for (ridx = 0; ridx < didx; ridx++) {
    U_rowidx->data[ridx] = expl_temp.rowidx->data[ridx];
  }

  *U_m = expl_temp.m;
  *U_n = expl_temp.n;
  U_colidx->data[0] = 1;
  didx = 0;
  st.site = &hc_emlrtRSI;
  d_emxFreeStruct_coder_internal_(&expl_temp);
  if ((1 <= A_n) && (A_n > 2147483646)) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (col = 0; col < A_n; col++) {
    ridx = A_colidx->data[col] - 1;
    while ((ridx + 1 < A_colidx->data[col + 1]) && (A_rowidx->data[ridx] <= col))
    {
      U_rowidx->data[didx] = A_rowidx->data[ridx];
      U_d->data[didx] = A_d->data[ridx];
      didx++;
      ridx++;
    }

    U_colidx->data[col + 1] = didx + 1;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (triu.c) */
