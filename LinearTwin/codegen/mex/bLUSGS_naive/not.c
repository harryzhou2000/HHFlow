/*
 * not.c
 *
 * Code generation for function 'not'
 *
 */

/* Include files */
#include "not.h"
#include "bLUSGS_naive.h"
#include "bLUSGS_naive_data.h"
#include "bLUSGS_naive_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo yb_emlrtRSI = { 7,  /* lineNo */
  "sparse/not",                        /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\not.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 8,  /* lineNo */
  "sparse/not",                        /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\not.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 11, /* lineNo */
  "sparse/not",                        /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\not.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 14, /* lineNo */
  "sparse/not",                        /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\not.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 20, /* lineNo */
  "sparse/not",                        /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\not.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 30, /* lineNo */
  "sparse/not",                        /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\not.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 40, /* lineNo */
  "sparse/not",                        /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\not.m"/* pathName */
};

static emlrtRTEInfo p_emlrtRTEI = { 83,/* lineNo */
  27,                                  /* colNo */
  "notnnz",                            /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\not.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 8,/* lineNo */
  1,                                   /* colNo */
  "not",                               /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\not.m"/* pName */
};

static emlrtRSInfo ld_emlrtRSI = { 18, /* lineNo */
  "indexDivide",                       /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\indexDivide.m"/* pathName */
};

/* Function Declarations */
static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator);

/* Function Definitions */
static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator)
{
  int32_T quotient;
  uint32_T b_numerator;
  uint32_T b_denominator;
  if (denominator == 0) {
    emlrtDivisionByZeroErrorR2012b(NULL, sp);
  } else {
    if (numerator < 0) {
      b_numerator = ~(uint32_T)numerator + 1U;
    } else {
      b_numerator = (uint32_T)numerator;
    }

    if (denominator < 0) {
      b_denominator = ~(uint32_T)denominator + 1U;
    } else {
      b_denominator = (uint32_T)denominator;
    }

    b_numerator /= b_denominator;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(int32_T)b_numerator;
    } else {
      quotient = (int32_T)b_numerator;
    }
  }

  return quotient;
}

void sparse_not(const emlrtStack *sp, const emxArray_int32_T *S_colidx, const
                emxArray_int32_T *S_rowidx, int32_T S_m, int32_T S_n,
                emxArray_boolean_T *out_d, emxArray_int32_T *out_colidx,
                emxArray_int32_T *out_rowidx, int32_T *out_m, int32_T *out_n,
                int32_T *out_maxnz)
{
  int32_T smaller;
  int32_T larger;
  int32_T q;
  int32_T numalloc;
  int32_T c;
  int32_T curPosition;
  int32_T i;
  boolean_T overflow;
  int32_T writeRow;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (S_m > S_n) {
    smaller = S_n;
    larger = S_m;
  } else {
    smaller = S_m;
    larger = S_n;
  }

  if (smaller == 0) {
    larger = 0;
  } else {
    b_st.site = &ld_emlrtRSI;
    q = div_s32(&b_st, S_colidx->data[S_colidx->size[0] - 1] - 1, smaller);
    larger -= q;
    if (larger == 0) {
      larger = 0;
    } else {
      b_st.site = &ld_emlrtRSI;
      if ((larger > div_s32(&b_st, MAX_int32_T, smaller)) || (smaller > div_s32(
            &b_st, MAX_int32_T, larger))) {
        emlrtErrorWithMessageIdR2018a(&st, &p_emlrtRTEI,
          "Coder:toolbox:SparseNot", "Coder:toolbox:SparseNot", 0);
      }

      larger = ((smaller * larger - S_colidx->data[S_colidx->size[0] - 1]) + q *
                smaller) + 1;
    }
  }

  st.site = &ac_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  c_st.site = &tb_emlrtRSI;
  if (S_m < 0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &m_emlrtRTEI,
      "Coder:toolbox:SparseNegativeSize", "Coder:toolbox:SparseNegativeSize", 0);
  }

  if (S_m >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(&c_st, &f_emlrtRTEI,
      "Coder:toolbox:SparseMaxSize", "Coder:toolbox:SparseMaxSize", 2, 12,
      MAX_int32_T);
  }

  c_st.site = &sb_emlrtRSI;
  if (S_n < 0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &m_emlrtRTEI,
      "Coder:toolbox:SparseNegativeSize", "Coder:toolbox:SparseNegativeSize", 0);
  }

  if (S_n >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(&c_st, &f_emlrtRTEI,
      "Coder:toolbox:SparseMaxSize", "Coder:toolbox:SparseMaxSize", 2, 12,
      MAX_int32_T);
  }

  c_st.site = &rb_emlrtRSI;
  if (larger < 0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &m_emlrtRTEI,
      "Coder:toolbox:SparseNegativeSize", "Coder:toolbox:SparseNegativeSize", 0);
  }

  if (larger >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(&c_st, &f_emlrtRTEI,
      "Coder:toolbox:SparseMaxSize", "Coder:toolbox:SparseMaxSize", 2, 12,
      MAX_int32_T);
  }

  if (larger >= 1) {
    numalloc = larger;
  } else {
    numalloc = 1;
  }

  q = out_d->size[0];
  out_d->size[0] = numalloc;
  emxEnsureCapacity_boolean_T(&b_st, out_d, q, &ub_emlrtRTEI);
  for (q = 0; q < numalloc; q++) {
    out_d->data[q] = false;
  }

  q = out_colidx->size[0];
  out_colidx->size[0] = S_n + 1;
  emxEnsureCapacity_int32_T(&b_st, out_colidx, q, &tb_emlrtRTEI);
  out_colidx->data[0] = 1;
  q = out_rowidx->size[0];
  out_rowidx->size[0] = numalloc;
  emxEnsureCapacity_int32_T(&b_st, out_rowidx, q, &ub_emlrtRTEI);
  for (q = 0; q < numalloc; q++) {
    out_rowidx->data[q] = 0;
  }

  for (c = 0; c < S_n; c++) {
    out_colidx->data[c + 1] = 1;
  }

  smaller = out_colidx->size[0];
  for (c = 0; c <= smaller - 2; c++) {
    out_colidx->data[c] = 1;
  }

  out_colidx->data[out_colidx->size[0] - 1] = 1;
  if (1 > larger) {
    smaller = 0;
  } else {
    smaller = larger;
  }

  for (q = 0; q < smaller; q++) {
    out_d->data[q] = true;
  }

  curPosition = 0;
  st.site = &bc_emlrtRSI;
  for (c = 0; c < S_n; c++) {
    out_colidx->data[c] = curPosition + 1;
    q = S_colidx->data[c + 1];
    if (S_colidx->data[c] == q) {
      st.site = &cc_emlrtRSI;
      for (i = 0; i < S_m; i++) {
        out_rowidx->data[curPosition + i] = i + 1;
      }

      curPosition += S_m;
    } else {
      larger = S_rowidx->data[S_colidx->data[c] - 1];
      st.site = &dc_emlrtRSI;
      smaller = larger - 1;
      overflow = ((1 <= smaller) && (smaller > 2147483646));
      if (overflow) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (writeRow = 0; writeRow <= larger - 2; writeRow++) {
        out_rowidx->data[curPosition] = writeRow + 1;
        curPosition++;
      }

      larger = (q - S_colidx->data[c]) - 2;
      for (i = 0; i <= larger; i++) {
        smaller = S_colidx->data[c] + i;
        q = S_rowidx->data[smaller - 1] + 1;
        smaller = S_rowidx->data[smaller] - 1;
        st.site = &ec_emlrtRSI;
        if ((q <= smaller) && (smaller > 2147483646)) {
          b_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (writeRow = q; writeRow <= smaller; writeRow++) {
          out_rowidx->data[curPosition] = writeRow;
          curPosition++;
        }
      }

      q = S_rowidx->data[S_colidx->data[c] + larger] + 1;
      st.site = &fc_emlrtRSI;
      for (writeRow = q; writeRow <= S_m; writeRow++) {
        out_rowidx->data[curPosition] = writeRow;
        curPosition++;
      }
    }
  }

  out_colidx->data[S_n] = curPosition + 1;
  *out_m = S_m;
  *out_n = S_n;
  *out_maxnz = numalloc;
}

/* End of code generation (not.c) */
