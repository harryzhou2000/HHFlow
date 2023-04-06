/*
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "power.h"
#include "eml_int_forloop_overflow_check.h"
#include "f_doNChem.h"
#include "f_doNChem_data.h"
#include "f_doNChem_emxutil.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "scalexpAlloc.h"

/* Variable Definitions */
static emlrtRSInfo s_emlrtRSI = { 70,  /* lineNo */
  "power",                             /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 79,  /* lineNo */
  "fltpower",                          /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 81,  /* lineNo */
  "fltpower",                          /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 46,  /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 66,  /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 202, /* lineNo */
  "flatIter",                          /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 94,  /* lineNo */
  "fltpower_domain_error",             /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 101,/* lineNo */
  "fltpower_domain_error",             /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 44, /* lineNo */
  "vAllOrAny",                         /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\vAllOrAny.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 103,/* lineNo */
  "flatVectorAllOrAny",                /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\vAllOrAny.m"/* pathName */
};

static emlrtRTEInfo h_emlrtRTEI = { 82,/* lineNo */
  5,                                   /* colNo */
  "fltpower",                          /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 19,/* lineNo */
  23,                                  /* colNo */
  "scalexpAlloc",                      /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 46,/* lineNo */
  6,                                   /* colNo */
  "applyBinaryScalarFunction",         /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

/* Function Definitions */
void power(const emlrtStack *sp, const emxArray_real_T *a, const emxArray_real_T
           *b, emxArray_real_T *y)
{
  emxArray_real_T *z;
  int32_T csz_idx_0;
  int32_T csz_idx_1;
  int32_T i;
  boolean_T p;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &z, 2, &mb_emlrtRTEI, true);
  st.site = &s_emlrtRSI;
  b_st.site = &t_emlrtRSI;
  c_st.site = &v_emlrtRSI;
  if (a->size[0] <= b->size[0]) {
    csz_idx_0 = a->size[0];
  } else {
    csz_idx_0 = b->size[0];
  }

  if (a->size[1] <= b->size[1]) {
    csz_idx_1 = a->size[1];
  } else {
    csz_idx_1 = b->size[1];
  }

  i = z->size[0] * z->size[1];
  if (a->size[0] <= b->size[0]) {
    z->size[0] = a->size[0];
  } else {
    z->size[0] = b->size[0];
  }

  if (a->size[1] <= b->size[1]) {
    z->size[1] = a->size[1];
  } else {
    z->size[1] = b->size[1];
  }

  emxEnsureCapacity_real_T(&c_st, z, i, &mb_emlrtRTEI);
  if (!dimagree(z, a, b)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  emxFree_real_T(&z);
  i = y->size[0] * y->size[1];
  y->size[0] = csz_idx_0;
  y->size[1] = csz_idx_1;
  emxEnsureCapacity_real_T(&b_st, y, i, &nb_emlrtRTEI);
  c_st.site = &w_emlrtRSI;
  csz_idx_0 *= csz_idx_1;
  d_st.site = &x_emlrtRSI;
  if ((1 <= csz_idx_0) && (csz_idx_0 > 2147483646)) {
    e_st.site = &n_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (csz_idx_1 = 0; csz_idx_1 < csz_idx_0; csz_idx_1++) {
    y->data[csz_idx_1] = muDoubleScalarPower(a->data[csz_idx_1], b->
      data[csz_idx_1]);
  }

  b_st.site = &u_emlrtRSI;
  if ((a->size[0] == 1) && (a->size[1] == 1)) {
    if (a->data[0] < 0.0) {
      c_st.site = &y_emlrtRSI;
      d_st.site = &bb_emlrtRSI;
      csz_idx_0 = b->size[0] * b->size[1];
      p = false;
      e_st.site = &cb_emlrtRSI;
      if ((1 <= csz_idx_0) && (csz_idx_0 > 2147483646)) {
        f_st.site = &n_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (csz_idx_1 = 0; csz_idx_1 < csz_idx_0; csz_idx_1++) {
        if (p || ((!muDoubleScalarIsNaN(b->data[csz_idx_1])) &&
                  (muDoubleScalarFloor(b->data[csz_idx_1]) != b->data[csz_idx_1])))
        {
          p = true;
        }
      }
    } else {
      p = false;
    }
  } else if ((b->size[0] == 1) && (b->size[1] == 1)) {
    if ((!muDoubleScalarIsNaN(b->data[0])) && (muDoubleScalarFloor(b->data[0])
         != b->data[0])) {
      c_st.site = &ab_emlrtRSI;
      d_st.site = &bb_emlrtRSI;
      csz_idx_0 = a->size[0] * a->size[1];
      p = false;
      e_st.site = &cb_emlrtRSI;
      if ((1 <= csz_idx_0) && (csz_idx_0 > 2147483646)) {
        f_st.site = &n_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (csz_idx_1 = 0; csz_idx_1 < csz_idx_0; csz_idx_1++) {
        if (p || (a->data[csz_idx_1] < 0.0)) {
          p = true;
        }
      }
    } else {
      p = false;
    }
  } else {
    p = false;
    i = a->size[0] * a->size[1];
    for (csz_idx_1 = 0; csz_idx_1 < i; csz_idx_1++) {
      if (p || ((a->data[csz_idx_1] < 0.0) && (!muDoubleScalarIsNaN(b->
             data[csz_idx_1])) && (muDoubleScalarFloor(b->data[csz_idx_1]) !=
            b->data[csz_idx_1]))) {
        p = true;
      }
    }
  }

  if (p) {
    emlrtErrorWithMessageIdR2018a(&st, &h_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (power.c) */
