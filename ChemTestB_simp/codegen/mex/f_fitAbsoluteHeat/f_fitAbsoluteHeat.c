/*
 * f_fitAbsoluteHeat.c
 *
 * Code generation for function 'f_fitAbsoluteHeat'
 *
 */

/* Include files */
#include "f_fitAbsoluteHeat.h"
#include "eml_int_forloop_overflow_check.h"
#include "f_fitAbsoluteHeat_data.h"
#include "f_fitAbsoluteHeat_emxutil.h"
#include "mtimes.h"
#include "mwmathutil.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "useConstantDim.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 3,     /* lineNo */
  "f_fitAbsoluteHeat",                 /* fcnName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 4,   /* lineNo */
  "f_fitAbsoluteHeat",                 /* fcnName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 6,   /* lineNo */
  "f_fitAbsoluteHeat",                 /* fcnName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 12,  /* lineNo */
  "f_fitAbsoluteHeat",                 /* fcnName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 13,  /* lineNo */
  "f_fitAbsoluteHeat",                 /* fcnName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 14,  /* lineNo */
  "f_fitAbsoluteHeat",                 /* fcnName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 15,  /* lineNo */
  "f_fitAbsoluteHeat",                 /* fcnName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 15,  /* lineNo */
  "sum",                               /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 42,  /* lineNo */
  "sumprod",                           /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 106, /* lineNo */
  "applyToMultipleDims",               /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\applyToMultipleDims.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 39,  /* lineNo */
  "function_handle/parenReference",    /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\function_handle.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 38,  /* lineNo */
  "@(x)sumprod(op,x,coder.internal.indexInt(1),varargin{2:end})",/* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 99,  /* lineNo */
  "sumprod",                           /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 125, /* lineNo */
  "combineVectorElements",             /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 185, /* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 29,  /* lineNo */
  "reshapeSizeChecks",                 /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 14,  /* lineNo */
  "cumprod",                           /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\cumprod.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 16,  /* lineNo */
  "cumop",                             /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 27, /* lineNo */
  "cat",                               /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 102,/* lineNo */
  "cat_impl",                          /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 79, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 48, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 27,    /* lineNo */
  5,                                   /* colNo */
  "error",                             /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\lang\\error.m"/* pName */
};

static emlrtRTEInfo emlrtRTEI = { 118, /* lineNo */
  23,                                  /* colNo */
  "dynamic_size_checks",               /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 123,/* lineNo */
  23,                                  /* colNo */
  "dynamic_size_checks",               /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 283,/* lineNo */
  27,                                  /* colNo */
  "check_non_axis_size",               /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 52,/* lineNo */
  13,                                  /* colNo */
  "reshapeSizeChecks",                 /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pName */
};

static emlrtECInfo emlrtECI = { 2,     /* nDims */
  15,                                  /* lineNo */
  6,                                   /* colNo */
  "f_fitAbsoluteHeat",                 /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { 2,   /* nDims */
  15,                                  /* lineNo */
  11,                                  /* colNo */
  "f_fitAbsoluteHeat",                 /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { 2,   /* nDims */
  15,                                  /* lineNo */
  16,                                  /* colNo */
  "f_fitAbsoluteHeat",                 /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pName */
};

static emlrtECInfo d_emlrtECI = { 2,   /* nDims */
  14,                                  /* lineNo */
  6,                                   /* colNo */
  "f_fitAbsoluteHeat",                 /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pName */
};

static emlrtECInfo e_emlrtECI = { 2,   /* nDims */
  14,                                  /* lineNo */
  11,                                  /* colNo */
  "f_fitAbsoluteHeat",                 /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pName */
};

static emlrtECInfo f_emlrtECI = { 2,   /* nDims */
  14,                                  /* lineNo */
  16,                                  /* colNo */
  "f_fitAbsoluteHeat",                 /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 3, /* lineNo */
  8,                                   /* colNo */
  "f_fitAbsoluteHeat",                 /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 12,/* lineNo */
  1,                                   /* colNo */
  "f_fitAbsoluteHeat",                 /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 28,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 47,/* lineNo */
  9,                                   /* colNo */
  "div",                               /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\div.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "f_fitAbsoluteHeat",                 /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 14,/* lineNo */
  16,                                  /* colNo */
  "f_fitAbsoluteHeat",                 /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 14,/* lineNo */
  40,                                  /* colNo */
  "f_fitAbsoluteHeat",                 /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 14,/* lineNo */
  1,                                   /* colNo */
  "f_fitAbsoluteHeat",                 /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 15,/* lineNo */
  40,                                  /* colNo */
  "f_fitAbsoluteHeat",                 /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 12,/* lineNo */
  29,                                  /* colNo */
  "f_fitAbsoluteHeat",                 /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 13,/* lineNo */
  32,                                  /* colNo */
  "f_fitAbsoluteHeat",                 /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_fitAbsoluteHeat.m"/* pName */
};

static emlrtRSInfo kb_emlrtRSI = { 27, /* lineNo */
  "error",                             /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\lang\\error.m"/* pathName */
};

/* Function Declarations */
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);

/* Function Definitions */
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

void f_fitAbsoluteHeat(const emlrtStack *sp, const emxArray_real_T *T, const
  emxArray_real_T *asA, const emxArray_real_T *asB, emxArray_real_T *hs)
{
  emxArray_boolean_T *x;
  int32_T i;
  int32_T vlen;
  real_T y;
  int32_T k;
  int32_T nx;
  const mxArray *b_y;
  const mxArray *m;
  static const int32_T iv[2] = { 1, 4 };

  static const char_T varargin_1[4] = { 'T', '<', '0', '!' };

  emxArray_real_T *b_x;
  emxArray_real_T b_T;
  int32_T input_sizes[2];
  boolean_T empty_non_axis_sizes;
  int8_T input_sizes_idx_0;
  int32_T sizes_idx_0;
  emxArray_real_T *Tprod;
  int32_T i1;
  emxArray_int32_T *c_y;
  emxArray_real_T *r;
  emxArray_real_T *coefs;
  emxArray_real_T *b_tmp;
  emxArray_boolean_T *c_T;
  int32_T b_input_sizes[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &x, 2, &h_emlrtRTEI, true);

  /*  asA = [as6,as1,as2,as3,as4,as5] */
  st.site = &emlrtRSI;
  b_st.site = &h_emlrtRSI;
  c_st.site = &i_emlrtRSI;
  i = x->size[0] * x->size[1];
  x->size[0] = T->size[0];
  x->size[1] = T->size[1];
  emxEnsureCapacity_boolean_T(&c_st, x, i, &h_emlrtRTEI);
  vlen = T->size[0] * T->size[1];
  for (i = 0; i < vlen; i++) {
    x->data[i] = (T->data[i] < 1.0E-10);
  }

  d_st.site = &j_emlrtRSI;
  e_st.site = &k_emlrtRSI;
  f_st.site = &l_emlrtRSI;
  g_st.site = &m_emlrtRSI;
  vlen = x->size[0] * x->size[1];
  if (x->size[0] * x->size[1] == 0) {
    y = 0.0;
  } else {
    h_st.site = &n_emlrtRSI;
    y = x->data[0];
    i_st.site = &o_emlrtRSI;
    if ((2 <= x->size[0] * x->size[1]) && (x->size[0] * x->size[1] > 2147483646))
    {
      j_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&j_st);
    }

    for (k = 2; k <= vlen; k++) {
      y += (real_T)x->data[k - 1];
    }
  }

  if (y > 0.0) {
    st.site = &b_emlrtRSI;
    b_y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&st, 4, m, &varargin_1[0]);
    emlrtAssign(&b_y, m);
    b_st.site = &kb_emlrtRSI;
    error(&b_st, b_y, &emlrtMCI);
  }

  st.site = &c_emlrtRSI;
  nx = T->size[0] * T->size[1];
  b_st.site = &q_emlrtRSI;
  vlen = T->size[0];
  if (T->size[1] > T->size[0]) {
    vlen = T->size[1];
  }

  vlen = muIntScalarMax_sint32(nx, vlen);
  if (1 > vlen) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (nx > vlen) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  emxInit_real_T(&st, &b_x, 2, &q_emlrtRTEI, true);
  st.site = &d_emlrtRSI;
  b_T = *T;
  input_sizes[0] = 1;
  input_sizes[1] = nx;
  b_T.size = &input_sizes[0];
  b_T.numDimensions = 2;
  b_st.site = &d_emlrtRSI;
  repmat(&b_st, &b_T, (real_T)asA->size[1] - 1.0, b_x);
  b_st.site = &u_emlrtRSI;
  c_st.site = &v_emlrtRSI;
  useConstantDim(&c_st, b_x);
  st.site = &d_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  if (nx != 0) {
    k = nx;
  } else if ((b_x->size[0] != 0) && (b_x->size[1] != 0)) {
    k = b_x->size[1];
  } else {
    k = 0;
    if (b_x->size[1] > 0) {
      k = b_x->size[1];
    }
  }

  c_st.site = &db_emlrtRSI;
  if ((nx != k) && (nx != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((b_x->size[1] != k) && ((b_x->size[0] != 0) && (b_x->size[1] != 0))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  empty_non_axis_sizes = (k == 0);
  if (empty_non_axis_sizes || (nx != 0)) {
    input_sizes_idx_0 = 1;
  } else {
    input_sizes_idx_0 = 0;
  }

  if (empty_non_axis_sizes || ((b_x->size[0] != 0) && (b_x->size[1] != 0))) {
    sizes_idx_0 = b_x->size[0];
  } else {
    sizes_idx_0 = 0;
  }

  emxInit_real_T(&b_st, &Tprod, 2, &i_emlrtRTEI, true);
  i = Tprod->size[0] * Tprod->size[1];
  Tprod->size[0] = input_sizes_idx_0 + sizes_idx_0;
  Tprod->size[1] = k;
  emxEnsureCapacity_real_T(&b_st, Tprod, i, &i_emlrtRTEI);
  for (i = 0; i < k; i++) {
    vlen = input_sizes_idx_0;
    for (i1 = 0; i1 < vlen; i1++) {
      Tprod->data[Tprod->size[0] * i] = 1.0;
    }
  }

  for (i = 0; i < k; i++) {
    for (i1 = 0; i1 < sizes_idx_0; i1++) {
      Tprod->data[(i1 + input_sizes_idx_0) + Tprod->size[0] * i] = b_x->data[i1
        + sizes_idx_0 * i];
    }
  }

  emxInit_int32_T(&b_st, &c_y, 2, &r_emlrtRTEI, true);
  if (asA->size[1] - 1 < 1) {
    c_y->size[0] = 1;
    c_y->size[1] = 0;
  } else {
    vlen = asA->size[1] - 2;
    i = c_y->size[0] * c_y->size[1];
    c_y->size[0] = 1;
    c_y->size[1] = asA->size[1] - 1;
    emxEnsureCapacity_int32_T(sp, c_y, i, &j_emlrtRTEI);
    for (i = 0; i <= vlen; i++) {
      c_y->data[i] = i + 1;
    }
  }

  emxInit_real_T(sp, &r, 1, &k_emlrtRTEI, true);
  st.site = &e_emlrtRSI;
  i = r->size[0];
  r->size[0] = c_y->size[1];
  emxEnsureCapacity_real_T(&st, r, i, &k_emlrtRTEI);
  vlen = c_y->size[1];
  for (i = 0; i < vlen; i++) {
    r->data[i] = 1.0 / (real_T)c_y->data[i];
  }

  emxFree_int32_T(&c_y);
  b_st.site = &e_emlrtRSI;
  b_repmat(&b_st, r, nx, b_x);
  b_st.site = &cb_emlrtRSI;
  emxFree_real_T(&r);
  if (nx != 0) {
    k = nx;
  } else if ((b_x->size[0] != 0) && (b_x->size[1] != 0)) {
    k = b_x->size[1];
  } else {
    k = 0;
    if (b_x->size[1] > 0) {
      k = b_x->size[1];
    }
  }

  c_st.site = &db_emlrtRSI;
  if ((nx != k) && (nx != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((b_x->size[1] != k) && ((b_x->size[0] != 0) && (b_x->size[1] != 0))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  empty_non_axis_sizes = (k == 0);
  if (empty_non_axis_sizes || (nx != 0)) {
    input_sizes_idx_0 = 1;
  } else {
    input_sizes_idx_0 = 0;
  }

  if (empty_non_axis_sizes || ((b_x->size[0] != 0) && (b_x->size[1] != 0))) {
    sizes_idx_0 = b_x->size[0];
  } else {
    sizes_idx_0 = 0;
  }

  emxInit_real_T(&b_st, &coefs, 2, &l_emlrtRTEI, true);
  i = coefs->size[0] * coefs->size[1];
  coefs->size[0] = input_sizes_idx_0 + sizes_idx_0;
  coefs->size[1] = k;
  emxEnsureCapacity_real_T(&b_st, coefs, i, &l_emlrtRTEI);
  for (i = 0; i < k; i++) {
    vlen = input_sizes_idx_0;
    for (i1 = 0; i1 < vlen; i1++) {
      coefs->data[coefs->size[0] * i] = 1.0;
    }
  }

  for (i = 0; i < k; i++) {
    for (i1 = 0; i1 < sizes_idx_0; i1++) {
      coefs->data[(i1 + input_sizes_idx_0) + coefs->size[0] * i] = b_x->data[i1
        + sizes_idx_0 * i];
    }
  }

  emxFree_real_T(&b_x);
  emxInit_real_T(&b_st, &b_tmp, 2, &m_emlrtRTEI, true);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])Tprod->size, *(int32_T (*)[2])
    coefs->size, &f_emlrtECI, sp);
  st.site = &f_emlrtRSI;
  i = b_tmp->size[0] * b_tmp->size[1];
  b_tmp->size[0] = Tprod->size[0];
  b_tmp->size[1] = Tprod->size[1];
  emxEnsureCapacity_real_T(&st, b_tmp, i, &m_emlrtRTEI);
  vlen = Tprod->size[0] * Tprod->size[1];
  for (i = 0; i < vlen; i++) {
    b_tmp->data[i] = Tprod->data[i] * coefs->data[i];
  }

  b_st.site = &hb_emlrtRSI;
  if (asA->size[1] != b_tmp->size[0]) {
    if (((asA->size[0] == 1) && (asA->size[1] == 1)) || ((b_tmp->size[0] == 1) &&
         (b_tmp->size[1] == 1))) {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
        "MATLAB:innerdim", 0);
    }
  }

  emxInit_boolean_T(&b_st, &c_T, 2, &n_emlrtRTEI, true);
  b_st.site = &gb_emlrtRSI;
  mtimes(&b_st, asA, b_tmp, hs);
  i = c_T->size[0] * c_T->size[1];
  c_T->size[0] = 1;
  c_T->size[1] = nx;
  emxEnsureCapacity_boolean_T(sp, c_T, i, &n_emlrtRTEI);
  for (i = 0; i < nx; i++) {
    c_T->data[i] = (T->data[i] < 1000.0);
  }

  st.site = &f_emlrtRSI;
  c_repmat(&st, c_T, asA->size[0], x);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])hs->size, *(int32_T (*)[2])x->size,
    &e_emlrtECI, sp);
  vlen = hs->size[0] * hs->size[1];
  for (i = 0; i < vlen; i++) {
    hs->data[i] *= (real_T)x->data[i];
  }

  b_input_sizes[0] = asA->size[0];
  b_input_sizes[1] = nx;
  emlrtSizeEqCheckNDR2012b(b_input_sizes, *(int32_T (*)[2])hs->size, &d_emlrtECI,
    sp);
  i = hs->size[0] * hs->size[1];
  hs->size[0] = asA->size[0];
  hs->size[1] = nx;
  emxEnsureCapacity_real_T(sp, hs, i, &o_emlrtRTEI);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])Tprod->size, *(int32_T (*)[2])
    coefs->size, &c_emlrtECI, sp);
  st.site = &g_emlrtRSI;
  b_st.site = &hb_emlrtRSI;
  emxFree_real_T(&coefs);
  if (asB->size[1] != b_tmp->size[0]) {
    if (((asB->size[0] == 1) && (asB->size[1] == 1)) || ((b_tmp->size[0] == 1) &&
         (b_tmp->size[1] == 1))) {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
        "MATLAB:innerdim", 0);
    }
  }

  b_st.site = &gb_emlrtRSI;
  mtimes(&b_st, asB, b_tmp, Tprod);
  i = c_T->size[0] * c_T->size[1];
  c_T->size[0] = 1;
  c_T->size[1] = nx;
  emxEnsureCapacity_boolean_T(sp, c_T, i, &p_emlrtRTEI);
  emxFree_real_T(&b_tmp);
  for (i = 0; i < nx; i++) {
    c_T->data[i] = (T->data[i] >= 1000.0);
  }

  st.site = &g_emlrtRSI;
  c_repmat(&st, c_T, asA->size[0], x);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])Tprod->size, *(int32_T (*)[2])
    x->size, &b_emlrtECI, sp);
  vlen = Tprod->size[0] * Tprod->size[1];
  emxFree_boolean_T(&c_T);
  for (i = 0; i < vlen; i++) {
    Tprod->data[i] *= (real_T)x->data[i];
  }

  emxFree_boolean_T(&x);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])hs->size, *(int32_T (*)[2])
    Tprod->size, &emlrtECI, sp);
  vlen = hs->size[0] * hs->size[1];
  for (i = 0; i < vlen; i++) {
    hs->data[i] += Tprod->data[i];
  }

  emxFree_real_T(&Tprod);

  /*  for i = 1:size(asA,2) */
  /*      hs = hs + ((asA(:,i) * (T).^(i-1)) / max(1, i-1)) .* (T < 1000); */
  /*      hs = hs + ((asB(:,i) * (T).^(i-1)) / max(1, i-1)) .* (T >= 1000); */
  /*      % warning: i don't know if this T is good */
  /*  end */
  vlen = hs->size[0] * hs->size[1];
  for (i = 0; i < vlen; i++) {
    hs->data[i] *= 8.314;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (f_fitAbsoluteHeat.c) */
