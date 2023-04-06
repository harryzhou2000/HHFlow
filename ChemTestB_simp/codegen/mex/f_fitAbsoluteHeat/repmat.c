/*
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "repmat.h"
#include "eml_int_forloop_overflow_check.h"
#include "f_fitAbsoluteHeat.h"
#include "f_fitAbsoluteHeat_data.h"
#include "f_fitAbsoluteHeat_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo r_emlrtRSI = { 28,  /* lineNo */
  "repmat",                            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 66,  /* lineNo */
  "repmat",                            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 69,  /* lineNo */
  "repmat",                            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 64, /* lineNo */
  "repmat",                            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 71, /* lineNo */
  "repmat",                            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtDCInfo emlrtDCI = { 31,    /* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m",/* pName */
  4                                    /* checkKind */
};

static emlrtRTEInfo f_emlrtRTEI = { 64,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 58,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

/* Function Definitions */
void b_repmat(const emlrtStack *sp, const emxArray_real_T *a, real_T varargin_2,
              emxArray_real_T *b)
{
  real_T b_varargin_2;
  int32_T nrows;
  int32_T i;
  int32_T jtilecol;
  int32_T ibtile;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &r_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (varargin_2 != varargin_2) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  if (varargin_2 <= 0.0) {
    b_varargin_2 = 0.0;
  } else {
    b_varargin_2 = varargin_2;
  }

  if (!(b_varargin_2 <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      "Coder:MATLAB:pmaxsize", 0);
  }

  nrows = b->size[0] * b->size[1];
  b->size[0] = a->size[0];
  i = (int32_T)varargin_2;
  b->size[1] = i;
  emxEnsureCapacity_real_T(sp, b, nrows, &s_emlrtRTEI);
  nrows = a->size[0];
  st.site = &eb_emlrtRSI;
  if ((1 <= i) && (i > 2147483646)) {
    b_st.site = &p_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (jtilecol = 0; jtilecol < i; jtilecol++) {
    ibtile = jtilecol * nrows;
    st.site = &fb_emlrtRSI;
    if ((1 <= nrows) && (nrows > 2147483646)) {
      b_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (k = 0; k < nrows; k++) {
      b->data[ibtile + k] = a->data[k];
    }
  }
}

void c_repmat(const emlrtStack *sp, const emxArray_boolean_T *a, real_T
              varargin_1, emxArray_boolean_T *b)
{
  real_T b_varargin_1;
  int32_T i;
  int32_T ncols;
  int32_T jcol;
  int32_T ibmat;
  int32_T itilerow;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &r_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (varargin_1 != varargin_1) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  if (varargin_1 <= 0.0) {
    b_varargin_1 = 0.0;
  } else {
    b_varargin_1 = varargin_1;
  }

  if (!(b_varargin_1 <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      "Coder:MATLAB:pmaxsize", 0);
  }

  i = (int32_T)varargin_1;
  ncols = b->size[0] * b->size[1];
  b->size[0] = i;
  b->size[1] = a->size[1];
  emxEnsureCapacity_boolean_T(sp, b, ncols, &s_emlrtRTEI);
  ncols = a->size[1];
  st.site = &s_emlrtRSI;
  if ((1 <= a->size[1]) && (a->size[1] > 2147483646)) {
    b_st.site = &p_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (jcol = 0; jcol < ncols; jcol++) {
    ibmat = jcol * i;
    st.site = &t_emlrtRSI;
    if ((1 <= i) && (i > 2147483646)) {
      b_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (itilerow = 0; itilerow < i; itilerow++) {
      b->data[ibmat + itilerow] = a->data[jcol];
    }
  }
}

void repmat(const emlrtStack *sp, const emxArray_real_T *a, real_T varargin_1,
            emxArray_real_T *b)
{
  real_T b_varargin_1;
  int32_T i;
  int32_T ncols;
  int32_T jcol;
  int32_T ibmat;
  int32_T itilerow;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &r_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (varargin_1 != varargin_1) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  if (varargin_1 <= 0.0) {
    b_varargin_1 = 0.0;
  } else {
    b_varargin_1 = varargin_1;
  }

  if (!(b_varargin_1 <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      "Coder:MATLAB:pmaxsize", 0);
  }

  if (!(varargin_1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1, &emlrtDCI, sp);
  }

  i = (int32_T)varargin_1;
  ncols = b->size[0] * b->size[1];
  b->size[0] = i;
  b->size[1] = a->size[1];
  emxEnsureCapacity_real_T(sp, b, ncols, &s_emlrtRTEI);
  ncols = a->size[1];
  st.site = &s_emlrtRSI;
  if ((1 <= a->size[1]) && (a->size[1] > 2147483646)) {
    b_st.site = &p_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (jcol = 0; jcol < ncols; jcol++) {
    ibmat = jcol * i;
    st.site = &t_emlrtRSI;
    if ((1 <= i) && (i > 2147483646)) {
      b_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (itilerow = 0; itilerow < i; itilerow++) {
      b->data[ibmat + itilerow] = a->data[jcol];
    }
  }
}

/* End of code generation (repmat.c) */
