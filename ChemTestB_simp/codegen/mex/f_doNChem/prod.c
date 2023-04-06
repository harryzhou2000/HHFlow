/*
 * prod.c
 *
 * Code generation for function 'prod'
 *
 */

/* Include files */
#include "prod.h"
#include "eml_int_forloop_overflow_check.h"
#include "f_doNChem.h"
#include "f_doNChem_data.h"
#include "f_doNChem_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo db_emlrtRSI = { 11, /* lineNo */
  "prod",                              /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\prod.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 99, /* lineNo */
  "sumprod",                           /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 125,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 164,/* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 185,/* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRTEInfo j_emlrtRTEI = { 76,/* lineNo */
  9,                                   /* colNo */
  "sumprod",                           /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 46,/* lineNo */
  23,                                  /* colNo */
  "sumprod",                           /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 11,/* lineNo */
  1,                                   /* colNo */
  "prod",                              /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\prod.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 125,/* lineNo */
  13,                                  /* colNo */
  "combineVectorElements",             /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pName */
};

/* Function Definitions */
void prod(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  boolean_T p;
  int32_T vlen;
  uint32_T sz_idx_1;
  int32_T npages;
  int32_T i;
  int32_T xpageoffset;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &db_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  if (((x->size[0] != 1) || (x->size[1] != 1)) && (x->size[0] == 1)) {
    emlrtErrorWithMessageIdR2018a(&st, &k_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility",
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  p = false;
  if ((x->size[0] == 0) && (x->size[1] == 0)) {
    p = true;
  }

  if (p) {
    emlrtErrorWithMessageIdR2018a(&st, &j_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty",
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b_st.site = &eb_emlrtRSI;
  vlen = x->size[0];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    sz_idx_1 = (uint32_T)x->size[1];
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int32_T)sz_idx_1;
    emxEnsureCapacity_real_T(&b_st, y, i, &ob_emlrtRTEI);
    xpageoffset = (int32_T)sz_idx_1;
    for (i = 0; i < xpageoffset; i++) {
      y->data[i] = 1.0;
    }
  } else {
    c_st.site = &fb_emlrtRSI;
    npages = x->size[1];
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = x->size[1];
    emxEnsureCapacity_real_T(&c_st, y, i, &pb_emlrtRTEI);
    d_st.site = &gb_emlrtRSI;
    if (x->size[1] > 2147483646) {
      e_st.site = &n_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (i = 0; i < npages; i++) {
      xpageoffset = i * x->size[0];
      y->data[i] = x->data[xpageoffset];
      d_st.site = &hb_emlrtRSI;
      if ((2 <= vlen) && (vlen > 2147483646)) {
        e_st.site = &n_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      for (k = 2; k <= vlen; k++) {
        y->data[i] *= x->data[(xpageoffset + k) - 1];
      }
    }
  }
}

/* End of code generation (prod.c) */
