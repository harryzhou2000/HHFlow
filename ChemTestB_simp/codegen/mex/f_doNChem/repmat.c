/*
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "repmat.h"
#include "eml_int_forloop_overflow_check.h"
#include "f_doNChem.h"
#include "f_doNChem_data.h"
#include "f_doNChem_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo o_emlrtRSI = { 28,  /* lineNo */
  "repmat",                            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 64,  /* lineNo */
  "repmat",                            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 66,  /* lineNo */
  "repmat",                            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 71,  /* lineNo */
  "repmat",                            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 83, /* lineNo */
  "repmat",                            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 268,/* lineNo */
  "repmatLooper",                      /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 272,/* lineNo */
  "repmatLooper",                      /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 63, /* lineNo */
  "repmat",                            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 47,    /* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 64,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRSInfo pb_emlrtRSI = { 47, /* lineNo */
  "repmat",                            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
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

void b_repmat(const emlrtStack *sp, const emxArray_real_T *a, real_T varargin_2,
              emxArray_real_T *b)
{
  int32_T nrows;
  int32_T i;
  int32_T jtilecol;
  int32_T ibtile;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &o_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (varargin_2 != varargin_2) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  nrows = b->size[0] * b->size[1];
  b->size[0] = a->size[0];
  i = (int32_T)varargin_2;
  b->size[1] = i;
  emxEnsureCapacity_real_T(sp, b, nrows, &lb_emlrtRTEI);
  nrows = a->size[0];
  st.site = &p_emlrtRSI;
  if ((1 <= i) && (i > 2147483646)) {
    b_st.site = &n_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (jtilecol = 0; jtilecol < i; jtilecol++) {
    ibtile = jtilecol * nrows;
    st.site = &r_emlrtRSI;
    if ((1 <= nrows) && (nrows > 2147483646)) {
      b_st.site = &n_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (k = 0; k < nrows; k++) {
      b->data[ibtile + k] = a->data[k];
    }
  }
}

void c_repmat(const emlrtStack *sp, const emxArray_real_T *a, real_T varargin_1,
              emxArray_real_T *b)
{
  int32_T i;
  int32_T i1;
  int32_T na;
  int32_T k;
  int32_T b_k;
  int32_T i2;
  int32_T t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &o_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (varargin_1 != varargin_1) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  i = (int32_T)varargin_1;
  i1 = b->size[0] * b->size[1] * b->size[2];
  b->size[0] = i;
  b->size[1] = a->size[1];
  b->size[2] = a->size[2];
  emxEnsureCapacity_real_T(sp, b, i1, &lb_emlrtRTEI);
  if ((i != 0) && (a->size[1] != 0) && (a->size[2] != 0)) {
    st.site = &kb_emlrtRSI;
    na = a->size[2];
    b_st.site = &lb_emlrtRSI;
    if ((1 <= a->size[2]) && (a->size[2] > 2147483646)) {
      c_st.site = &n_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (k = 0; k < na; k++) {
      b_st.site = &mb_emlrtRSI;
      i1 = a->size[1];
      c_st.site = &lb_emlrtRSI;
      if ((1 <= a->size[1]) && (a->size[1] > 2147483646)) {
        d_st.site = &n_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (b_k = 0; b_k < i1; b_k++) {
        i2 = i - 1;
        for (t = 0; t <= i2; t++) {
          b->data[(t + b->size[0] * b_k) + b->size[0] * b->size[1] * k] =
            a->data[b_k + a->size[1] * k];
        }
      }
    }
  }
}

void d_repmat(const emlrtStack *sp, const emxArray_real_T *a, real_T varargin_3,
              emxArray_real_T *b)
{
  real_T b_varargin_3;
  int32_T tile_size[3];
  int32_T tile_size_tmp;
  int32_T ibtile;
  int32_T nrows;
  int32_T ncols;
  int32_T ntilecols;
  int32_T k;
  int32_T jtilecol;
  int32_T jcol;
  int32_T ibmat;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &o_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (varargin_3 != varargin_3) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  if (varargin_3 <= 0.0) {
    b_varargin_3 = 0.0;
  } else {
    b_varargin_3 = varargin_3;
  }

  if (!(b_varargin_3 <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      "Coder:MATLAB:pmaxsize", 0);
  }

  tile_size[0] = 1;
  tile_size[1] = 1;
  tile_size_tmp = (int32_T)varargin_3;
  tile_size[2] = tile_size_tmp;
  ibtile = b->size[0] * b->size[1] * b->size[2];
  b->size[0] = a->size[0];
  b->size[1] = a->size[1];
  b->size[2] = tile_size_tmp;
  emxEnsureCapacity_real_T(sp, b, ibtile, &lb_emlrtRTEI);
  nrows = a->size[0];
  ncols = a->size[1];
  st.site = &nb_emlrtRSI;
  ntilecols = 1;
  k = 3;
  if (tile_size_tmp == 1) {
    k = 2;
  }

  for (tile_size_tmp = 2; tile_size_tmp <= k; tile_size_tmp++) {
    ntilecols *= tile_size[tile_size_tmp - 1];
  }

  st.site = &p_emlrtRSI;
  if ((1 <= ntilecols) && (ntilecols > 2147483646)) {
    b_st.site = &n_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (jtilecol = 0; jtilecol < ntilecols; jtilecol++) {
    ibtile = jtilecol * (nrows * ncols) - 1;
    st.site = &q_emlrtRSI;
    if ((1 <= ncols) && (ncols > 2147483646)) {
      b_st.site = &n_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (jcol = 0; jcol < ncols; jcol++) {
      tile_size_tmp = jcol * nrows;
      ibmat = ibtile + tile_size_tmp;
      st.site = &r_emlrtRSI;
      if ((1 <= nrows) && (nrows > 2147483646)) {
        b_st.site = &n_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (k = 0; k < nrows; k++) {
        b->data[(ibmat + k) + 1] = a->data[tile_size_tmp + k];
      }
    }
  }
}

void e_repmat(const emlrtStack *sp, const emxArray_real_T *a, real_T varargin_2,
              emxArray_real_T *b)
{
  real_T b_varargin_2;
  int32_T i;
  int32_T i1;
  int32_T na;
  int32_T k;
  int32_T t;
  int32_T i2;
  int32_T b_k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &o_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
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
    emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      "Coder:MATLAB:pmaxsize", 0);
  }

  i = b->size[0] * b->size[1] * b->size[2];
  b->size[0] = a->size[0];
  i1 = (int32_T)varargin_2;
  b->size[1] = i1;
  b->size[2] = a->size[2];
  emxEnsureCapacity_real_T(sp, b, i, &lb_emlrtRTEI);
  if ((a->size[0] != 0) && (i1 != 0) && (a->size[2] != 0)) {
    st.site = &kb_emlrtRSI;
    na = a->size[2];
    b_st.site = &lb_emlrtRSI;
    if ((1 <= a->size[2]) && (a->size[2] > 2147483646)) {
      c_st.site = &n_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (k = 0; k < na; k++) {
      b_st.site = &mb_emlrtRSI;
      i = i1 - 1;
      for (t = 0; t <= i; t++) {
        c_st.site = &mb_emlrtRSI;
        i2 = a->size[0];
        d_st.site = &lb_emlrtRSI;
        if ((1 <= a->size[0]) && (a->size[0] > 2147483646)) {
          e_st.site = &n_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }

        for (b_k = 0; b_k < i2; b_k++) {
          b->data[(b_k + b->size[0] * t) + b->size[0] * b->size[1] * k] =
            a->data[b_k + a->size[0] * k];
        }
      }
    }
  }
}

void repmat(const emlrtStack *sp, const emxArray_real_T *a, real_T varargin_2,
            emxArray_real_T *b)
{
  int32_T outsize_idx_1_tmp;
  int32_T outsize_idx_1;
  int32_T ncols;
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 1, 15 };

  static const char_T u[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a',
    'x', 's', 'i', 'z', 'e' };

  int32_T jtilecol;
  int32_T ibtile;
  int32_T jcol;
  int32_T iacol_tmp;
  int32_T ibmat;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &o_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (varargin_2 != varargin_2) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  outsize_idx_1_tmp = (int32_T)varargin_2;
  outsize_idx_1 = a->size[1] * outsize_idx_1_tmp;
  if (!(outsize_idx_1 == (real_T)a->size[1] * (real_T)outsize_idx_1_tmp)) {
    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(sp, 15, m, &u[0]);
    emlrtAssign(&y, m);
    st.site = &pb_emlrtRSI;
    error(&st, y, &emlrtMCI);
  }

  ncols = b->size[0] * b->size[1];
  b->size[0] = a->size[0];
  b->size[1] = outsize_idx_1;
  emxEnsureCapacity_real_T(sp, b, ncols, &lb_emlrtRTEI);
  outsize_idx_1 = a->size[0];
  ncols = a->size[1];
  st.site = &p_emlrtRSI;
  if ((1 <= outsize_idx_1_tmp) && (outsize_idx_1_tmp > 2147483646)) {
    b_st.site = &n_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (jtilecol = 0; jtilecol < outsize_idx_1_tmp; jtilecol++) {
    ibtile = jtilecol * (outsize_idx_1 * ncols) - 1;
    st.site = &q_emlrtRSI;
    if ((1 <= ncols) && (ncols > 2147483646)) {
      b_st.site = &n_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (jcol = 0; jcol < ncols; jcol++) {
      iacol_tmp = jcol * outsize_idx_1;
      ibmat = ibtile + iacol_tmp;
      st.site = &r_emlrtRSI;
      if ((1 <= outsize_idx_1) && (outsize_idx_1 > 2147483646)) {
        b_st.site = &n_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (k = 0; k < outsize_idx_1; k++) {
        b->data[(ibmat + k) + 1] = a->data[iacol_tmp + k];
      }
    }
  }
}

/* End of code generation (repmat.c) */
