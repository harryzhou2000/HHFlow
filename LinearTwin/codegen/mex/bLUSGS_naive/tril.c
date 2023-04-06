/*
 * tril.c
 *
 * Code generation for function 'tril'
 *
 */

/* Include files */
#include "tril.h"
#include "bLUSGS_naive.h"
#include "bLUSGS_naive_data.h"
#include "bLUSGS_naive_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sparse.h"

/* Variable Definitions */
static emlrtRSInfo wb_emlrtRSI = { 28, /* lineNo */
  "sparse/tril",                       /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\tril.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 31, /* lineNo */
  "sparse/tril",                       /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\tril.m"/* pathName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 28,/* lineNo */
  1,                                   /* colNo */
  "tril",                              /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\tril.m"/* pName */
};

/* Function Definitions */
void sparse_tril(const emlrtStack *sp, const emxArray_real_T *A_d, const
                 emxArray_int32_T *A_colidx, const emxArray_int32_T *A_rowidx,
                 int32_T A_m, int32_T A_n, emxArray_real_T *L_d,
                 emxArray_int32_T *L_colidx, emxArray_int32_T *L_rowidx, int32_T
                 *L_m, int32_T *L_n)
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
  d_emxInitStruct_coder_internal_(sp, &expl_temp, &rb_emlrtRTEI, true);
  st.site = &wb_emlrtRSI;
  sparse_spallocLike(&st, A_m, A_n, A_colidx->data[A_colidx->size[0] - 1] - 1,
                     &expl_temp);
  ridx = L_d->size[0];
  L_d->size[0] = expl_temp.d->size[0];
  emxEnsureCapacity_real_T(sp, L_d, ridx, &rb_emlrtRTEI);
  didx = expl_temp.d->size[0];
  for (ridx = 0; ridx < didx; ridx++) {
    L_d->data[ridx] = expl_temp.d->data[ridx];
  }

  ridx = L_colidx->size[0];
  L_colidx->size[0] = expl_temp.colidx->size[0];
  emxEnsureCapacity_int32_T(sp, L_colidx, ridx, &rb_emlrtRTEI);
  didx = expl_temp.colidx->size[0];
  for (ridx = 0; ridx < didx; ridx++) {
    L_colidx->data[ridx] = expl_temp.colidx->data[ridx];
  }

  ridx = L_rowidx->size[0];
  L_rowidx->size[0] = expl_temp.rowidx->size[0];
  emxEnsureCapacity_int32_T(sp, L_rowidx, ridx, &rb_emlrtRTEI);
  didx = expl_temp.rowidx->size[0];
  for (ridx = 0; ridx < didx; ridx++) {
    L_rowidx->data[ridx] = expl_temp.rowidx->data[ridx];
  }

  *L_m = expl_temp.m;
  *L_n = expl_temp.n;
  L_colidx->data[0] = 1;
  didx = 0;
  st.site = &xb_emlrtRSI;
  d_emxFreeStruct_coder_internal_(&expl_temp);
  if ((1 <= A_n) && (A_n > 2147483646)) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (col = 0; col < A_n; col++) {
    for (ridx = A_colidx->data[col] - 1; ridx + 1 < A_colidx->data[col + 1];
         ridx++) {
      if (A_rowidx->data[ridx] >= col + 2) {
        L_rowidx->data[didx] = A_rowidx->data[ridx];
        L_d->data[didx] = A_d->data[ridx];
        didx++;
      }
    }

    L_colidx->data[col + 1] = didx + 1;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (tril.c) */
