/*
 * sparse.c
 *
 * Code generation for function 'sparse'
 *
 */

/* Include files */
#include "sparse.h"
#include "CXSparseAPI.h"
#include "bLUSGS_naive.h"
#include "bLUSGS_naive_data.h"
#include "bLUSGS_naive_emxutil.h"
#include "bigProduct.h"
#include "eml_int_forloop_overflow_check.h"
#include "fillIn.h"
#include "indexShapeCheck.h"
#include "makeCXSparseMatrix.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "solve_from_qr.h"
#include "warning.h"

/* Variable Definitions */
static emlrtRSInfo n_emlrtRSI = { 1636,/* lineNo */
  "assertValidSize",                   /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 299,/* lineNo */
  "sparse/times",                      /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 95, /* lineNo */
  "sparse/binOp",                      /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\binOp.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 99, /* lineNo */
  "sparse/binOp",                      /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\binOp.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 292,/* lineNo */
  "allocEqsizeBinop",                  /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\binOp.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 221,/* lineNo */
  "sparse/sparse",                     /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 199,/* lineNo */
  "sparse/sparse",                     /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 168,/* lineNo */
  "sparseSparseEqsizeBinOp",           /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\binOp.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 291,/* lineNo */
  "sparse/plus",                       /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 1482,/* lineNo */
  "sparse/mldivide",                   /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 156,/* lineNo */
  "CXSparseAPI/iteratedSolve",         /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 158,/* lineNo */
  "CXSparseAPI/iteratedSolve",         /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo gd_emlrtRSI = { 373,/* lineNo */
  "CXSparseAPI/iteratedQR",            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo hd_emlrtRSI = { 374,/* lineNo */
  "CXSparseAPI/iteratedQR",            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtMCInfo c_emlrtMCI = { 53,  /* lineNo */
  19,                                  /* colNo */
  "flt2str",                           /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 286,/* lineNo */
  9,                                   /* colNo */
  "allocEqsizeBinop",                  /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\binOp.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 55,/* lineNo */
  27,                                  /* colNo */
  "sparse/binOp",                      /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\binOp.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 53,/* lineNo */
  27,                                  /* colNo */
  "sparse/binOp",                      /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\binOp.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 180,/* lineNo */
  39,                                  /* colNo */
  "sparse/sparse",                     /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 58,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 1508,  /* lineNo */
  13,                                  /* colNo */
  "sparse/spallocLike",                /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m",/* pName */
  4                                    /* checkKind */
};

static emlrtRTEInfo r_emlrtRTEI = { 135,/* lineNo */
  35,                                  /* colNo */
  "CXSparseAPI/iteratedSolve",         /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 95,/* lineNo */
  5,                                   /* colNo */
  "binOp",                             /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\binOp.m"/* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 193,/* lineNo */
  13,                                  /* colNo */
  "sparse",                            /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 195,/* lineNo */
  42,                                  /* colNo */
  "sparse",                            /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 197,/* lineNo */
  13,                                  /* colNo */
  "sparse",                            /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 1508,/* lineNo */
  13,                                  /* colNo */
  "sparse",                            /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = { 1482,/* lineNo */
  13,                                  /* colNo */
  "sparse",                            /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 158,/* lineNo */
  23,                                  /* colNo */
  "CXSparseAPI",                       /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pName */
};

static emlrtRSInfo kd_emlrtRSI = { 53, /* lineNo */
  "flt2str",                           /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m"/* pathName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14]);
static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_sprintf_, const char_T *identifier, char_T y[14]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14])
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m, 2, pArrays, "sprintf", true, location);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_sprintf_, const char_T *identifier, char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(a__output_of_sprintf_), &thisId, y);
  emlrtDestroyArray(&a__output_of_sprintf_);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2] = { 1, 14 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 14);
  emlrtDestroyArray(&src);
}

void sparse_mldivide(const emlrtStack *sp, const emxArray_real_T *A_d, const
                     emxArray_int32_T *A_colidx, const emxArray_int32_T
                     *A_rowidx, int32_T A_m, int32_T A_n, const emxArray_real_T *
                     b, emxArray_real_T *y)
{
  boolean_T overflow;
  emxArray_real_T *outBuff;
  emxArray_int32_T *in_colidx;
  emxArray_int32_T *in_rowidx;
  emxArray_int32_T *counts;
  coder_internal_sparse expl_temp;
  int32_T k;
  cs_di* cxA;
  cs_dis * S;
  cs_din * N;
  int32_T idx;
  real_T tol;
  int32_T outridx;
  const mxArray *b_y;
  const mxArray *m;
  static const int32_T iv[2] = { 1, 6 };

  static const char_T rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  const mxArray *c_y;
  const mxArray *m1;
  char_T str[14];
  int32_T iv1[2];
  int32_T c;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &pc_emlrtRSI;
  if ((A_m == 0) || (A_n == 0)) {
    overflow = true;
  } else {
    overflow = false;
  }

  emxInit_real_T(&st, &outBuff, 1, &cc_emlrtRTEI, true);
  emxInit_int32_T(&st, &in_colidx, 1, &yb_emlrtRTEI, true);
  emxInit_int32_T(&st, &in_rowidx, 1, &yb_emlrtRTEI, true);
  emxInit_int32_T(&st, &counts, 1, &bc_emlrtRTEI, true);
  d_emxInitStruct_coder_internal_(&st, &expl_temp, &yb_emlrtRTEI, true);
  if (overflow || (b->size[0] == 0)) {
    k = y->size[0];
    y->size[0] = A_n;
    emxEnsureCapacity_real_T(&st, y, k, &xb_emlrtRTEI);
    for (k = 0; k < A_n; k++) {
      y->data[k] = 0.0;
    }
  } else {
    if (A_m != b->size[0]) {
      emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI, "MATLAB:dimagree",
        "MATLAB:dimagree", 0);
    }

    if (b->size[0] == A_n) {
      b_st.site = &qc_emlrtRSI;
      CXSparseAPI_iteratedLU(&b_st, A_d, A_colidx, A_rowidx, A_m, A_n, b, y);
    } else {
      b_st.site = &rc_emlrtRSI;
      c_st.site = &ed_emlrtRSI;
      if (A_m < A_n) {
        d_st.site = &vc_emlrtRSI;
        e_st.site = &vc_emlrtRSI;
        f_st.site = &xc_emlrtRSI;
        g_st.site = &cd_emlrtRSI;
        sparse_sparse(&g_st, A_n, A_m, A_colidx->data[A_colidx->size[0] - 1] - 1,
                      &expl_temp);
        k = outBuff->size[0];
        outBuff->size[0] = expl_temp.d->size[0];
        emxEnsureCapacity_real_T(&f_st, outBuff, k, &yb_emlrtRTEI);
        idx = expl_temp.d->size[0];
        for (k = 0; k < idx; k++) {
          outBuff->data[k] = expl_temp.d->data[k];
        }

        k = in_colidx->size[0];
        in_colidx->size[0] = expl_temp.colidx->size[0];
        emxEnsureCapacity_int32_T(&f_st, in_colidx, k, &yb_emlrtRTEI);
        idx = expl_temp.colidx->size[0];
        for (k = 0; k < idx; k++) {
          in_colidx->data[k] = expl_temp.colidx->data[k];
        }

        k = in_rowidx->size[0];
        in_rowidx->size[0] = expl_temp.rowidx->size[0];
        emxEnsureCapacity_int32_T(&f_st, in_rowidx, k, &yb_emlrtRTEI);
        idx = expl_temp.rowidx->size[0];
        for (k = 0; k < idx; k++) {
          in_rowidx->data[k] = expl_temp.rowidx->data[k];
        }

        idx = in_colidx->size[0];
        k = in_colidx->size[0];
        in_colidx->size[0] = idx;
        emxEnsureCapacity_int32_T(&f_st, in_colidx, k, &yb_emlrtRTEI);
        for (k = 0; k < idx; k++) {
          in_colidx->data[k] = 0;
        }

        idx = A_colidx->data[A_colidx->size[0] - 1];
        g_st.site = &yc_emlrtRSI;
        overflow = ((1 <= A_colidx->data[A_colidx->size[0] - 1] - 1) &&
                    (A_colidx->data[A_colidx->size[0] - 1] - 1 > 2147483646));
        if (overflow) {
          h_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }

        for (k = 0; k <= idx - 2; k++) {
          in_colidx->data[A_rowidx->data[k]]++;
        }

        in_colidx->data[0] = 1;
        idx = A_m + 1;
        g_st.site = &ad_emlrtRSI;
        if (A_m + 1 > 2147483646) {
          h_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }

        for (k = 2; k <= idx; k++) {
          in_colidx->data[k - 1] += in_colidx->data[k - 2];
        }

        k = counts->size[0];
        counts->size[0] = A_m;
        emxEnsureCapacity_int32_T(&f_st, counts, k, &bc_emlrtRTEI);
        for (k = 0; k < A_m; k++) {
          counts->data[k] = 0;
        }

        g_st.site = &bd_emlrtRSI;
        if (A_n > 2147483646) {
          h_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&h_st);
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

        cxA = makeCXSparseMatrix(in_colidx->data[in_colidx->size[0] - 1] - 1,
          expl_temp.n, expl_temp.m, &in_colidx->data[0], &in_rowidx->data[0],
          &outBuff->data[0]);
      } else {
        d_st.site = &wc_emlrtRSI;
        cxA = makeCXSparseMatrix(A_colidx->data[A_colidx->size[0] - 1] - 1, A_n,
          A_m, &A_colidx->data[0], &A_rowidx->data[0], &A_d->data[0]);
      }

      S = cs_di_sqr(2, cxA, 1);
      N = cs_di_qr(cxA, S);
      cs_di_spfree(cxA);
      idx = qr_rank_di(N, &tol);
      if (A_m > A_n) {
        outridx = A_n;
      } else {
        outridx = A_m;
      }

      if (idx < outridx) {
        c_st.site = &hd_emlrtRSI;
        b_y = NULL;
        m = emlrtCreateCharArray(2, &iv[0]);
        emlrtInitCharArrayR2013a(&c_st, 6, m, &rfmt[0]);
        emlrtAssign(&b_y, m);
        c_y = NULL;
        m1 = emlrtCreateDoubleScalar(tol);
        emlrtAssign(&c_y, m1);
        d_st.site = &kd_emlrtRSI;
        emlrt_marshallIn(&d_st, b_sprintf(&d_st, b_y, c_y, &c_emlrtMCI),
                         "<output of sprintf>", str);
        c_st.site = &gd_emlrtRSI;
        b_warning(&c_st, idx, str);
      }

      k = y->size[0];
      y->size[0] = A_n;
      emxEnsureCapacity_real_T(&b_st, y, k, &ac_emlrtRTEI);
      if (b->size[0] < A_n) {
        k = outBuff->size[0];
        outBuff->size[0] = A_n;
        emxEnsureCapacity_real_T(&b_st, outBuff, k, &ac_emlrtRTEI);
      } else {
        k = outBuff->size[0];
        outBuff->size[0] = b->size[0];
        emxEnsureCapacity_real_T(&b_st, outBuff, k, &ac_emlrtRTEI);
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

      iv1[0] = 1;
      iv1[1] = idx;
      c_st.site = &dd_emlrtRSI;
      indexShapeCheck(&c_st, outBuff->size[0], iv1);
      for (k = 0; k < idx; k++) {
        y->data[k] = outBuff->data[k];
      }

      cs_di_sfree(S);
      cs_di_nfree(N);
    }
  }

  d_emxFreeStruct_coder_internal_(&expl_temp);
  emxFree_int32_T(&counts);
  emxFree_int32_T(&in_rowidx);
  emxFree_int32_T(&in_colidx);
  emxFree_real_T(&outBuff);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void sparse_plus(const emlrtStack *sp, const emxArray_real_T *a_d, const
                 emxArray_int32_T *a_colidx, const emxArray_int32_T *a_rowidx,
                 int32_T a_m, int32_T a_n, const emxArray_real_T *b_d, const
                 emxArray_int32_T *b_colidx, const emxArray_int32_T *b_rowidx,
                 int32_T b_m, int32_T b_n, emxArray_real_T *s_d,
                 emxArray_int32_T *s_colidx, emxArray_int32_T *s_rowidx, int32_T
                 *s_m, int32_T *s_n)
{
  int32_T numalloc;
  int32_T overflow;
  coder_internal_sparse expl_temp;
  int32_T c;
  int32_T aidx_tmp;
  int32_T aidx;
  int32_T bidx_tmp;
  int32_T bidx;
  boolean_T moreAToDo;
  boolean_T moreBToDo;
  real_T val;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &ic_emlrtRSI;
  if (a_m != b_m) {
    emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  if (a_n != b_n) {
    emlrtErrorWithMessageIdR2018a(&st, &k_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  b_st.site = &lb_emlrtRSI;
  if (a_colidx->data[a_colidx->size[0] - 1] - 1 > -(b_colidx->data
       [b_colidx->size[0] - 1] + MIN_int32_T)) {
    bigProduct(b_n, b_m, &numalloc, &overflow);
    if (overflow != 0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:SparseFuncAlmostFull",
        "Coder:toolbox:SparseFuncAlmostFull", 0);
    }
  }

  numalloc = (a_colidx->data[a_colidx->size[0] - 1] + b_colidx->data
              [b_colidx->size[0] - 1]) - 2;
  overflow = b_n * b_m;
  numalloc = muIntScalarMin_sint32(numalloc, overflow);
  if (numalloc < 1) {
    numalloc = 1;
  }

  d_emxInitStruct_coder_internal_(&b_st, &expl_temp, &nb_emlrtRTEI, true);
  c_st.site = &nb_emlrtRSI;
  d_st.site = &ob_emlrtRSI;
  sparse_sparse(&d_st, b_m, b_n, numalloc, &expl_temp);
  overflow = s_d->size[0];
  s_d->size[0] = expl_temp.d->size[0];
  emxEnsureCapacity_real_T(&c_st, s_d, overflow, &nb_emlrtRTEI);
  numalloc = expl_temp.d->size[0];
  for (overflow = 0; overflow < numalloc; overflow++) {
    s_d->data[overflow] = expl_temp.d->data[overflow];
  }

  overflow = s_colidx->size[0];
  s_colidx->size[0] = expl_temp.colidx->size[0];
  emxEnsureCapacity_int32_T(&c_st, s_colidx, overflow, &nb_emlrtRTEI);
  numalloc = expl_temp.colidx->size[0];
  for (overflow = 0; overflow < numalloc; overflow++) {
    s_colidx->data[overflow] = expl_temp.colidx->data[overflow];
  }

  overflow = s_rowidx->size[0];
  s_rowidx->size[0] = expl_temp.rowidx->size[0];
  emxEnsureCapacity_int32_T(&c_st, s_rowidx, overflow, &nb_emlrtRTEI);
  numalloc = expl_temp.rowidx->size[0];
  for (overflow = 0; overflow < numalloc; overflow++) {
    s_rowidx->data[overflow] = expl_temp.rowidx->data[overflow];
  }

  *s_m = expl_temp.m;
  *s_n = expl_temp.n;
  b_st.site = &mb_emlrtRSI;
  numalloc = 1;
  s_colidx->data[0] = 1;
  c_st.site = &vb_emlrtRSI;
  if ((1 <= expl_temp.n) && (expl_temp.n > 2147483646)) {
    d_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  d_emxFreeStruct_coder_internal_(&expl_temp);
  for (c = 0; c < *s_n; c++) {
    overflow = c + 1;
    aidx_tmp = a_colidx->data[overflow - 1];
    aidx = aidx_tmp - 1;
    bidx_tmp = b_colidx->data[overflow - 1];
    bidx = bidx_tmp - 1;
    moreAToDo = (aidx_tmp < a_colidx->data[overflow]);
    moreBToDo = (bidx_tmp < b_colidx->data[overflow]);
    while (moreAToDo || moreBToDo) {
      while ((aidx + 1 < a_colidx->data[overflow]) && ((!moreBToDo) ||
              (a_rowidx->data[aidx] < b_rowidx->data[bidx]))) {
        if (a_d->data[aidx] != 0.0) {
          s_d->data[numalloc - 1] = a_d->data[aidx];
          s_rowidx->data[numalloc - 1] = a_rowidx->data[aidx];
          numalloc++;
        }

        aidx++;
      }

      moreAToDo = (aidx + 1 < a_colidx->data[overflow]);
      while ((bidx + 1 < b_colidx->data[overflow]) && ((!moreAToDo) ||
              (b_rowidx->data[bidx] < a_rowidx->data[aidx]))) {
        if (b_d->data[bidx] != 0.0) {
          s_d->data[numalloc - 1] = b_d->data[bidx];
          s_rowidx->data[numalloc - 1] = b_rowidx->data[bidx];
          numalloc++;
        }

        bidx++;
      }

      while ((aidx + 1 < a_colidx->data[overflow]) && (bidx + 1 < b_colidx->
              data[overflow]) && (a_rowidx->data[aidx] == b_rowidx->data[bidx]))
      {
        val = a_d->data[aidx] + b_d->data[bidx];
        if (val != 0.0) {
          s_d->data[numalloc - 1] = val;
          s_rowidx->data[numalloc - 1] = b_rowidx->data[bidx];
          numalloc++;
        }

        bidx++;
        aidx++;
      }

      moreAToDo = (aidx + 1 < a_colidx->data[overflow]);
      moreBToDo = (bidx + 1 < b_colidx->data[overflow]);
    }

    s_colidx->data[overflow] = numalloc;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void sparse_spallocLike(const emlrtStack *sp, int32_T m, int32_T n, real_T nzmax,
  coder_internal_sparse *s)
{
  int32_T numalloc;
  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ob_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &tb_emlrtRSI;
  if (m < 0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &m_emlrtRTEI,
      "Coder:toolbox:SparseNegativeSize", "Coder:toolbox:SparseNegativeSize", 0);
  }

  if (m >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
      "Coder:toolbox:SparseMaxSize", "Coder:toolbox:SparseMaxSize", 2, 12,
      MAX_int32_T);
  }

  b_st.site = &sb_emlrtRSI;
  if (n < 0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &m_emlrtRTEI,
      "Coder:toolbox:SparseNegativeSize", "Coder:toolbox:SparseNegativeSize", 0);
  }

  if (n >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
      "Coder:toolbox:SparseMaxSize", "Coder:toolbox:SparseMaxSize", 2, 12,
      MAX_int32_T);
  }

  s->m = m;
  s->n = n;
  b_st.site = &rb_emlrtRSI;
  c_st.site = &n_emlrtRSI;
  if ((nzmax != nzmax) || muDoubleScalarIsInf(nzmax)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &o_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  if (nzmax < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &m_emlrtRTEI,
      "Coder:toolbox:SparseNegativeSize", "Coder:toolbox:SparseNegativeSize", 0);
  }

  if (!(0.0 <= nzmax)) {
    emlrtErrorWithMessageIdR2018a(&st, &n_emlrtRTEI,
      "Coder:toolbox:SparseNzmaxTooSmall", "Coder:toolbox:SparseNzmaxTooSmall",
      0);
  }

  if ((int32_T)nzmax >= 1) {
    numalloc = (int32_T)nzmax;
  } else {
    numalloc = 1;
  }

  if (numalloc < 0) {
    emlrtNonNegativeCheckR2012b(numalloc, &emlrtDCI, &st);
  }

  i = s->d->size[0];
  s->d->size[0] = numalloc;
  emxEnsureCapacity_real_T(&st, s->d, i, &sb_emlrtRTEI);
  for (i = 0; i < numalloc; i++) {
    s->d->data[i] = 0.0;
  }

  s->maxnz = numalloc;
  i = s->colidx->size[0];
  s->colidx->size[0] = n + 1;
  emxEnsureCapacity_int32_T(&st, s->colidx, i, &tb_emlrtRTEI);
  s->colidx->data[0] = 1;
  i = s->rowidx->size[0];
  s->rowidx->size[0] = numalloc;
  emxEnsureCapacity_int32_T(&st, s->rowidx, i, &sb_emlrtRTEI);
  for (i = 0; i < numalloc; i++) {
    s->rowidx->data[i] = 0;
  }

  b_st.site = &qb_emlrtRSI;
  for (numalloc = 0; numalloc < n; numalloc++) {
    s->colidx->data[numalloc + 1] = 1;
  }

  b_st.site = &pb_emlrtRSI;
  sparse_fillIn(&b_st, s);
}

void sparse_sparse(const emlrtStack *sp, int32_T m, int32_T n, int32_T nzmaxval,
                   coder_internal_sparse *this)
{
  int32_T numalloc;
  int32_T i;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &tb_emlrtRSI;
  if (m < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
      "Coder:toolbox:SparseNegativeSize", "Coder:toolbox:SparseNegativeSize", 0);
  }

  if (m >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
      "Coder:toolbox:SparseMaxSize", "Coder:toolbox:SparseMaxSize", 2, 12,
      MAX_int32_T);
  }

  st.site = &sb_emlrtRSI;
  if (n < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
      "Coder:toolbox:SparseNegativeSize", "Coder:toolbox:SparseNegativeSize", 0);
  }

  if (n >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
      "Coder:toolbox:SparseMaxSize", "Coder:toolbox:SparseMaxSize", 2, 12,
      MAX_int32_T);
  }

  this->m = m;
  this->n = n;
  st.site = &rb_emlrtRSI;
  if (nzmaxval < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
      "Coder:toolbox:SparseNegativeSize", "Coder:toolbox:SparseNegativeSize", 0);
  }

  if (nzmaxval >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
      "Coder:toolbox:SparseMaxSize", "Coder:toolbox:SparseMaxSize", 2, 12,
      MAX_int32_T);
  }

  if (nzmaxval >= 1) {
    numalloc = nzmaxval;
  } else {
    numalloc = 1;
  }

  i = this->d->size[0];
  this->d->size[0] = numalloc;
  emxEnsureCapacity_real_T(sp, this->d, i, &ob_emlrtRTEI);
  for (i = 0; i < numalloc; i++) {
    this->d->data[i] = 0.0;
  }

  this->maxnz = numalloc;
  i = this->colidx->size[0];
  this->colidx->size[0] = n + 1;
  emxEnsureCapacity_int32_T(sp, this->colidx, i, &pb_emlrtRTEI);
  this->colidx->data[0] = 1;
  i = this->rowidx->size[0];
  this->rowidx->size[0] = numalloc;
  emxEnsureCapacity_int32_T(sp, this->rowidx, i, &qb_emlrtRTEI);
  for (i = 0; i < numalloc; i++) {
    this->rowidx->data[i] = 0;
  }

  for (numalloc = 0; numalloc < n; numalloc++) {
    this->colidx->data[numalloc + 1] = 1;
  }

  st.site = &pb_emlrtRSI;
  sparse_fillIn(&st, this);
}

void sparse_times(const emlrtStack *sp, const emxArray_real_T *a_d, const
                  emxArray_int32_T *a_colidx, const emxArray_int32_T *a_rowidx,
                  int32_T a_m, int32_T a_n, const emxArray_boolean_T *b_d, const
                  emxArray_int32_T *b_colidx, const emxArray_int32_T *b_rowidx,
                  int32_T b_m, int32_T b_n, emxArray_real_T *s_d,
                  emxArray_int32_T *s_colidx, emxArray_int32_T *s_rowidx,
                  int32_T *s_m, int32_T *s_n)
{
  int32_T numalloc;
  int32_T overflow;
  coder_internal_sparse expl_temp;
  int32_T c;
  int32_T aidx_tmp;
  int32_T aidx;
  int32_T bidx_tmp;
  int32_T bidx;
  boolean_T moreAToDo;
  boolean_T moreBToDo;
  real_T val;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &kb_emlrtRSI;
  if (a_m != b_m) {
    emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  if (a_n != b_n) {
    emlrtErrorWithMessageIdR2018a(&st, &k_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  b_st.site = &lb_emlrtRSI;
  if (a_colidx->data[a_colidx->size[0] - 1] - 1 > -(b_colidx->data
       [b_colidx->size[0] - 1] + MIN_int32_T)) {
    bigProduct(b_n, b_m, &numalloc, &overflow);
    if (overflow != 0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:SparseFuncAlmostFull",
        "Coder:toolbox:SparseFuncAlmostFull", 0);
    }
  }

  numalloc = (a_colidx->data[a_colidx->size[0] - 1] + b_colidx->data
              [b_colidx->size[0] - 1]) - 2;
  overflow = b_n * b_m;
  numalloc = muIntScalarMin_sint32(numalloc, overflow);
  if (numalloc < 1) {
    numalloc = 1;
  }

  d_emxInitStruct_coder_internal_(&b_st, &expl_temp, &nb_emlrtRTEI, true);
  c_st.site = &nb_emlrtRSI;
  d_st.site = &ob_emlrtRSI;
  sparse_sparse(&d_st, b_m, b_n, numalloc, &expl_temp);
  overflow = s_d->size[0];
  s_d->size[0] = expl_temp.d->size[0];
  emxEnsureCapacity_real_T(&c_st, s_d, overflow, &nb_emlrtRTEI);
  numalloc = expl_temp.d->size[0];
  for (overflow = 0; overflow < numalloc; overflow++) {
    s_d->data[overflow] = expl_temp.d->data[overflow];
  }

  overflow = s_colidx->size[0];
  s_colidx->size[0] = expl_temp.colidx->size[0];
  emxEnsureCapacity_int32_T(&c_st, s_colidx, overflow, &nb_emlrtRTEI);
  numalloc = expl_temp.colidx->size[0];
  for (overflow = 0; overflow < numalloc; overflow++) {
    s_colidx->data[overflow] = expl_temp.colidx->data[overflow];
  }

  overflow = s_rowidx->size[0];
  s_rowidx->size[0] = expl_temp.rowidx->size[0];
  emxEnsureCapacity_int32_T(&c_st, s_rowidx, overflow, &nb_emlrtRTEI);
  numalloc = expl_temp.rowidx->size[0];
  for (overflow = 0; overflow < numalloc; overflow++) {
    s_rowidx->data[overflow] = expl_temp.rowidx->data[overflow];
  }

  *s_m = expl_temp.m;
  *s_n = expl_temp.n;
  b_st.site = &mb_emlrtRSI;
  numalloc = 1;
  s_colidx->data[0] = 1;
  c_st.site = &vb_emlrtRSI;
  if ((1 <= expl_temp.n) && (expl_temp.n > 2147483646)) {
    d_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  d_emxFreeStruct_coder_internal_(&expl_temp);
  for (c = 0; c < *s_n; c++) {
    overflow = c + 1;
    aidx_tmp = a_colidx->data[overflow - 1];
    aidx = aidx_tmp - 1;
    bidx_tmp = b_colidx->data[overflow - 1];
    bidx = bidx_tmp - 1;
    moreAToDo = (aidx_tmp < a_colidx->data[overflow]);
    moreBToDo = (bidx_tmp < b_colidx->data[overflow]);
    while (moreAToDo || moreBToDo) {
      while ((aidx + 1 < a_colidx->data[overflow]) && ((!moreBToDo) ||
              (a_rowidx->data[aidx] < b_rowidx->data[bidx]))) {
        if (a_d->data[aidx] * 0.0 != 0.0) {
          s_d->data[numalloc - 1] = rtNaN;
          s_rowidx->data[numalloc - 1] = a_rowidx->data[aidx];
          numalloc++;
        }

        aidx++;
      }

      moreAToDo = (aidx + 1 < a_colidx->data[overflow]);
      while ((bidx + 1 < b_colidx->data[overflow]) && ((!moreAToDo) ||
              (b_rowidx->data[bidx] < a_rowidx->data[aidx]))) {
        bidx++;
      }

      while ((aidx + 1 < a_colidx->data[overflow]) && (bidx + 1 < b_colidx->
              data[overflow]) && (a_rowidx->data[aidx] == b_rowidx->data[bidx]))
      {
        val = a_d->data[aidx] * (real_T)b_d->data[bidx];
        if (val != 0.0) {
          s_d->data[numalloc - 1] = val;
          s_rowidx->data[numalloc - 1] = b_rowidx->data[bidx];
          numalloc++;
        }

        bidx++;
        aidx++;
      }

      moreAToDo = (aidx + 1 < a_colidx->data[overflow]);
      moreBToDo = (bidx + 1 < b_colidx->data[overflow]);
    }

    s_colidx->data[overflow] = numalloc;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (sparse.c) */
