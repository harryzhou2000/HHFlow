/*
 * f_doNChem.c
 *
 * Code generation for function 'f_doNChem'
 *
 */

/* Include files */
#include "f_doNChem.h"
#include "f_doNChem_data.h"
#include "f_doNChem_emxutil.h"
#include "mtimes.h"
#include "mwmathutil.h"
#include "power.h"
#include "prod.h"
#include "repmat.h"
#include "reshapeSizeChecks.h"
#include "rt_nonfinite.h"
#include "scalexpCompatible.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 9,     /* lineNo */
  "f_doNChem",                         /* fcnName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 13,  /* lineNo */
  "f_doNChem",                         /* fcnName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 14,  /* lineNo */
  "f_doNChem",                         /* fcnName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 23,  /* lineNo */
  "f_doNChem",                         /* fcnName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 27,  /* lineNo */
  "f_doNChem",                         /* fcnName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 28,  /* lineNo */
  "f_doNChem",                         /* fcnName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 29,  /* lineNo */
  "f_doNChem",                         /* fcnName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 30,  /* lineNo */
  "f_doNChem",                         /* fcnName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 31,  /* lineNo */
  "f_doNChem",                         /* fcnName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 79,  /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 48,  /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 29, /* lineNo */
  "reshapeSizeChecks",                 /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pathName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  37,                                  /* colNo */
  "nuf",                               /* aName */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  59,                                  /* colNo */
  "kf",                                /* aName */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { 2,     /* nDims */
  13,                                  /* lineNo */
  15,                                  /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  37,                                  /* colNo */
  "nub",                               /* aName */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  59,                                  /* colNo */
  "kb",                                /* aName */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo b_emlrtECI = { 2,   /* nDims */
  14,                                  /* lineNo */
  15,                                  /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  8,                                   /* colNo */
  "Rf",                                /* aName */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  13,                                  /* lineNo */
  5,                                   /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtECInfo d_emlrtECI = { 2,   /* nDims */
  16,                                  /* lineNo */
  6,                                   /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  8,                                   /* colNo */
  "Rb",                                /* aName */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo e_emlrtECI = { -1,  /* nDims */
  14,                                  /* lineNo */
  5,                                   /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtECInfo f_emlrtECI = { 2,   /* nDims */
  17,                                  /* lineNo */
  6,                                   /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtECInfo g_emlrtECI = { 3,   /* nDims */
  27,                                  /* lineNo */
  6,                                   /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtECInfo h_emlrtECI = { 3,   /* nDims */
  28,                                  /* lineNo */
  7,                                   /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtECInfo i_emlrtECI = { 2,   /* nDims */
  29,                                  /* lineNo */
  12,                                  /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtECInfo j_emlrtECI = { 2,   /* nDims */
  30,                                  /* lineNo */
  8,                                   /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo emlrtRTEI = { 52,  /* lineNo */
  13,                                  /* colNo */
  "reshapeSizeChecks",                 /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 59,/* lineNo */
  23,                                  /* colNo */
  "reshapeSizeChecks",                 /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 20,/* lineNo */
  15,                                  /* colNo */
  "rdivide_helper",                    /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\rdivide_helper.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 123,/* lineNo */
  23,                                  /* colNo */
  "dynamic_size_checks",               /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 118,/* lineNo */
  23,                                  /* colNo */
  "dynamic_size_checks",               /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 5, /* lineNo */
  1,                                   /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 6, /* lineNo */
  1,                                   /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 13,/* lineNo */
  33,                                  /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 13,/* lineNo */
  56,                                  /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 13,/* lineNo */
  15,                                  /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 23,/* lineNo */
  15,                                  /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 14,/* lineNo */
  33,                                  /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 14,/* lineNo */
  56,                                  /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 14,/* lineNo */
  15,                                  /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 29,/* lineNo */
  12,                                  /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 29,/* lineNo */
  52,                                  /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 30,/* lineNo */
  8,                                   /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 31,/* lineNo */
  1,                                   /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 9,/* lineNo */
  1,                                   /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 23,/* lineNo */
  1,                                   /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 27,/* lineNo */
  1,                                   /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 1,/* lineNo */
  10,                                  /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 1,/* lineNo */
  16,                                  /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 28,/* lineNo */
  7,                                   /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 29,/* lineNo */
  44,                                  /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 9,/* lineNo */
  21,                                  /* colNo */
  "f_doNChem",                         /* fName */
  "E:\\projects\\HHFlow\\ChemTestB\\f_doNChem.m"/* pName */
};

/* Function Declarations */
static void dynamic_size_checks(const emlrtStack *sp, const emxArray_real_T *a,
  const emxArray_real_T *b, int32_T innerDimA, int32_T innerDimB);

/* Function Definitions */
static void dynamic_size_checks(const emlrtStack *sp, const emxArray_real_T *a,
  const emxArray_real_T *b, int32_T innerDimA, int32_T innerDimB)
{
  if (innerDimA != innerDimB) {
    if (((a->size[0] == 1) && (a->size[1] == 1)) || ((b->size[0] == 1) &&
         (b->size[1] == 1))) {
      emlrtErrorWithMessageIdR2018a(sp, &e_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(sp, &d_emlrtRTEI, "MATLAB:innerdim",
        "MATLAB:innerdim", 0);
    }
  }
}

void f_doNChem(const emlrtStack *sp, const emxArray_real_T *n, const
               emxArray_real_T *kf, const emxArray_real_T *kb, const
               emxArray_real_T *nuf, const emxArray_real_T *nub, const
               emxArray_real_T *C, const emxArray_real_T *L, emxArray_real_T
               *doN)
{
  emxArray_real_T *Rf;
  int32_T nE;
  int32_T i;
  int32_T maxdimlen;
  emxArray_real_T *Rb;
  emxArray_real_T *tbFactors;
  emxArray_real_T *b_doN;
  emxArray_real_T *r;
  emxArray_real_T *r1;
  emxArray_real_T *b_nuf;
  emxArray_real_T *b_kf;
  int32_T nx;
  int32_T sz_idx_1;
  emxArray_real_T *b_n;
  int32_T c_kf[2];
  emxArray_real_T *ndiv;
  emxArray_real_T *dR;
  emxArray_real_T *y;
  emxArray_real_T b_Rf;
  int32_T d_kf[3];
  emxArray_real_T *x;
  int32_T e_kf[3];
  emxArray_real_T *b_tbFactors;
  int32_T f_kf[2];
  int32_T g_kf[2];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &Rf, 2, &n_emlrtRTEI, true);
  nE = kf->size[1];
  i = Rf->size[0] * Rf->size[1];
  Rf->size[0] = kf->size[0];
  Rf->size[1] = kf->size[1];
  emxEnsureCapacity_real_T(sp, Rf, i, &n_emlrtRTEI);
  maxdimlen = kf->size[0] * kf->size[1];
  for (i = 0; i < maxdimlen; i++) {
    Rf->data[i] = rtNaN;
  }

  emxInit_real_T(sp, &Rb, 2, &o_emlrtRTEI, true);
  i = Rb->size[0] * Rb->size[1];
  Rb->size[0] = kf->size[0];
  Rb->size[1] = kf->size[1];
  emxEnsureCapacity_real_T(sp, Rb, i, &o_emlrtRTEI);
  maxdimlen = kf->size[0] * kf->size[1];
  for (i = 0; i < maxdimlen; i++) {
    Rb->data[i] = rtNaN;
  }

  emxInit_real_T(sp, &tbFactors, 2, &bb_emlrtRTEI, true);
  emxInit_real_T(sp, &b_doN, 2, &eb_emlrtRTEI, true);
  emxInit_real_T(sp, &r, 2, &ib_emlrtRTEI, true);
  st.site = &emlrtRSI;
  b_st.site = &k_emlrtRSI;
  dynamic_size_checks(&b_st, C, n, C->size[1], n->size[0]);
  b_st.site = &j_emlrtRSI;
  mtimes(&b_st, C, n, b_doN);
  st.site = &emlrtRSI;
  repmat(&st, L, kf->size[1], r);
  st.site = &emlrtRSI;
  power(&st, b_doN, r, tbFactors);
  i = kf->size[0];
  emxInit_real_T(sp, &r1, 2, &fb_emlrtRTEI, true);
  emxInit_real_T(sp, &b_nuf, 1, &p_emlrtRTEI, true);
  emxInit_real_T(sp, &b_kf, 2, &q_emlrtRTEI, true);
  for (nx = 0; nx < i; nx++) {
    sz_idx_1 = nx + 1;
    if ((sz_idx_1 < 1) || (sz_idx_1 > nuf->size[0])) {
      emlrtDynamicBoundsCheckR2012b(sz_idx_1, 1, nuf->size[0], &emlrtBCI, sp);
    }

    maxdimlen = nuf->size[1];
    sz_idx_1 = b_nuf->size[0];
    b_nuf->size[0] = nuf->size[1];
    emxEnsureCapacity_real_T(sp, b_nuf, sz_idx_1, &p_emlrtRTEI);
    for (sz_idx_1 = 0; sz_idx_1 < maxdimlen; sz_idx_1++) {
      b_nuf->data[sz_idx_1] = nuf->data[nx + nuf->size[0] * sz_idx_1];
    }

    st.site = &b_emlrtRSI;
    b_repmat(&st, b_nuf, nE, r);
    st.site = &b_emlrtRSI;
    power(&st, n, r, b_doN);
    st.site = &b_emlrtRSI;
    prod(&st, b_doN, r1);
    sz_idx_1 = nx + 1;
    if ((sz_idx_1 < 1) || (sz_idx_1 > kf->size[0])) {
      emlrtDynamicBoundsCheckR2012b(sz_idx_1, 1, kf->size[0], &b_emlrtBCI, sp);
    }

    maxdimlen = kf->size[1];
    sz_idx_1 = b_kf->size[0] * b_kf->size[1];
    b_kf->size[0] = 1;
    b_kf->size[1] = kf->size[1];
    emxEnsureCapacity_real_T(sp, b_kf, sz_idx_1, &q_emlrtRTEI);
    for (sz_idx_1 = 0; sz_idx_1 < maxdimlen; sz_idx_1++) {
      b_kf->data[sz_idx_1] = kf->data[nx + kf->size[0] * sz_idx_1];
    }

    emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])r1->size, *(int32_T (*)[2])
      b_kf->size, &emlrtECI, sp);
    sz_idx_1 = nx + 1;
    if ((sz_idx_1 < 1) || (sz_idx_1 > Rf->size[0])) {
      emlrtDynamicBoundsCheckR2012b(sz_idx_1, 1, Rf->size[0], &e_emlrtBCI, sp);
    }

    sz_idx_1 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity_real_T(sp, r1, sz_idx_1, &r_emlrtRTEI);
    maxdimlen = r1->size[1];
    for (sz_idx_1 = 0; sz_idx_1 < maxdimlen; sz_idx_1++) {
      r1->data[sz_idx_1] *= kf->data[nx + kf->size[0] * sz_idx_1];
    }

    c_kf[0] = 1;
    c_kf[1] = Rf->size[1];
    emlrtSubAssignSizeCheckR2012b(&c_kf[0], 2, &r1->size[0], 2, &c_emlrtECI, sp);
    maxdimlen = r1->size[1];
    for (sz_idx_1 = 0; sz_idx_1 < maxdimlen; sz_idx_1++) {
      Rf->data[nx + Rf->size[0] * sz_idx_1] = r1->data[sz_idx_1];
    }

    sz_idx_1 = nx + 1;
    if ((sz_idx_1 < 1) || (sz_idx_1 > nub->size[0])) {
      emlrtDynamicBoundsCheckR2012b(sz_idx_1, 1, nub->size[0], &c_emlrtBCI, sp);
    }

    maxdimlen = nub->size[1];
    sz_idx_1 = b_nuf->size[0];
    b_nuf->size[0] = nub->size[1];
    emxEnsureCapacity_real_T(sp, b_nuf, sz_idx_1, &t_emlrtRTEI);
    for (sz_idx_1 = 0; sz_idx_1 < maxdimlen; sz_idx_1++) {
      b_nuf->data[sz_idx_1] = nub->data[nx + nub->size[0] * sz_idx_1];
    }

    st.site = &c_emlrtRSI;
    b_repmat(&st, b_nuf, nE, r);
    st.site = &c_emlrtRSI;
    power(&st, n, r, b_doN);
    st.site = &c_emlrtRSI;
    prod(&st, b_doN, r1);
    sz_idx_1 = nx + 1;
    if ((sz_idx_1 < 1) || (sz_idx_1 > kb->size[0])) {
      emlrtDynamicBoundsCheckR2012b(sz_idx_1, 1, kb->size[0], &d_emlrtBCI, sp);
    }

    maxdimlen = kb->size[1];
    sz_idx_1 = b_kf->size[0] * b_kf->size[1];
    b_kf->size[0] = 1;
    b_kf->size[1] = kb->size[1];
    emxEnsureCapacity_real_T(sp, b_kf, sz_idx_1, &u_emlrtRTEI);
    for (sz_idx_1 = 0; sz_idx_1 < maxdimlen; sz_idx_1++) {
      b_kf->data[sz_idx_1] = kb->data[nx + kb->size[0] * sz_idx_1];
    }

    emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])r1->size, *(int32_T (*)[2])
      b_kf->size, &b_emlrtECI, sp);
    sz_idx_1 = nx + 1;
    if ((sz_idx_1 < 1) || (sz_idx_1 > Rb->size[0])) {
      emlrtDynamicBoundsCheckR2012b(sz_idx_1, 1, Rb->size[0], &f_emlrtBCI, sp);
    }

    sz_idx_1 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity_real_T(sp, r1, sz_idx_1, &v_emlrtRTEI);
    maxdimlen = r1->size[1];
    for (sz_idx_1 = 0; sz_idx_1 < maxdimlen; sz_idx_1++) {
      r1->data[sz_idx_1] *= kb->data[nx + kb->size[0] * sz_idx_1];
    }

    c_kf[0] = 1;
    c_kf[1] = Rb->size[1];
    emlrtSubAssignSizeCheckR2012b(&c_kf[0], 2, &r1->size[0], 2, &e_emlrtECI, sp);
    maxdimlen = r1->size[1];
    for (sz_idx_1 = 0; sz_idx_1 < maxdimlen; sz_idx_1++) {
      Rb->data[nx + Rb->size[0] * sz_idx_1] = r1->data[sz_idx_1];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_kf);
  emxFree_real_T(&b_nuf);
  emxFree_real_T(&r1);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])Rf->size, *(int32_T (*)[2])
    tbFactors->size, &d_emlrtECI, sp);
  maxdimlen = Rf->size[0] * Rf->size[1];
  for (i = 0; i < maxdimlen; i++) {
    Rf->data[i] *= tbFactors->data[i];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])Rb->size, *(int32_T (*)[2])
    tbFactors->size, &f_emlrtECI, sp);
  maxdimlen = Rb->size[0] * Rb->size[1];
  for (i = 0; i < maxdimlen; i++) {
    Rb->data[i] *= tbFactors->data[i];
  }

  /*  R = Rf - Rb; */
  /*  oN = ((nub - nuf)') * R; */
  st.site = &d_emlrtRSI;
  nx = n->size[0] * n->size[1];
  b_st.site = &ib_emlrtRSI;
  computeDimsData(&b_st, n->size[0], kf->size[1]);
  nE = n->size[0];
  if (n->size[1] > n->size[0]) {
    nE = n->size[1];
  }

  maxdimlen = muIntScalarMax_sint32(nx, nE);
  if (1 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (n->size[0] > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (kf->size[1] > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (n->size[0] * kf->size[1] != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  emxInit_real_T(&st, &b_n, 3, &s_emlrtRTEI, true);
  i = b_n->size[0] * b_n->size[1] * b_n->size[2];
  b_n->size[0] = 1;
  b_n->size[1] = n->size[0];
  b_n->size[2] = kf->size[1];
  emxEnsureCapacity_real_T(sp, b_n, i, &s_emlrtRTEI);
  maxdimlen = n->size[0] * kf->size[1];
  for (i = 0; i < maxdimlen; i++) {
    b_n->data[i] = n->data[i] + 1.0E-200;
  }

  emxInit_real_T(sp, &ndiv, 3, &cb_emlrtRTEI, true);
  st.site = &d_emlrtRSI;
  c_repmat(&st, b_n, kf->size[0], ndiv);

  /*  dR = repmat(nuf,1,1,nE) ./ ndiv .* reshape(Rf,nReaction,1,nE)... */
  /*      - repmat(nub,1,1,nE) ./ ndiv .* reshape(Rb,nReaction,1,nE) +... */
  /*      reshape(C.*L, nReaction, nS, 1) ./ (reshape(tbFactors,nReaction,1,nE) + 1e-200); */
  st.site = &e_emlrtRSI;
  nx = Rf->size[0] * Rf->size[1];
  b_st.site = &ib_emlrtRSI;
  computeDimsData(&b_st, kf->size[0], kf->size[1]);
  nE = Rf->size[0];
  emxFree_real_T(&b_n);
  if (Rf->size[1] > Rf->size[0]) {
    nE = Rf->size[1];
  }

  maxdimlen = muIntScalarMax_sint32(nx, nE);
  if (kf->size[0] > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (1 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (kf->size[1] > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (kf->size[0] * kf->size[1] != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  emxInit_real_T(&st, &dR, 3, &db_emlrtRTEI, true);
  st.site = &e_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  d_repmat(&b_st, nuf, kf->size[1], dR);
  if (!scalexpCompatible(dR, ndiv)) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  maxdimlen = dR->size[0] * dR->size[1] * dR->size[2];
  for (i = 0; i < maxdimlen; i++) {
    dR->data[i] /= ndiv->data[i];
  }

  emxInit_real_T(&st, &y, 3, &hb_emlrtRTEI, true);
  nE = kf->size[0];
  maxdimlen = kf->size[1];
  b_Rf = *Rf;
  d_kf[0] = nE;
  d_kf[1] = 1;
  d_kf[2] = maxdimlen;
  b_Rf.size = &d_kf[0];
  b_Rf.numDimensions = 3;
  st.site = &e_emlrtRSI;
  e_repmat(&st, &b_Rf, n->size[0], y);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[3])dR->size, *(int32_T (*)[3])y->size,
    &g_emlrtECI, sp);
  st.site = &f_emlrtRSI;
  nx = Rb->size[0] * Rb->size[1];
  b_st.site = &ib_emlrtRSI;
  computeDimsData(&b_st, kf->size[0], kf->size[1]);
  nE = Rb->size[0];
  if (Rb->size[1] > Rb->size[0]) {
    nE = Rb->size[1];
  }

  maxdimlen = muIntScalarMax_sint32(nx, nE);
  if (kf->size[0] > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (1 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (kf->size[1] > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (kf->size[0] * kf->size[1] != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  emxInit_real_T(&st, &x, 3, &gb_emlrtRTEI, true);
  st.site = &f_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  d_repmat(&b_st, nub, kf->size[1], x);
  if (!scalexpCompatible(x, ndiv)) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  maxdimlen = x->size[0] * x->size[1] * x->size[2];
  for (i = 0; i < maxdimlen; i++) {
    x->data[i] /= ndiv->data[i];
  }

  nE = kf->size[0];
  maxdimlen = kf->size[1];
  b_Rf = *Rb;
  e_kf[0] = nE;
  e_kf[1] = 1;
  e_kf[2] = maxdimlen;
  b_Rf.size = &e_kf[0];
  b_Rf.numDimensions = 3;
  st.site = &f_emlrtRSI;
  e_repmat(&st, &b_Rf, n->size[0], ndiv);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[3])x->size, *(int32_T (*)[3])ndiv->size,
    &h_emlrtECI, sp);
  maxdimlen = dR->size[0] * dR->size[1] * dR->size[2];
  emxFree_real_T(&Rb);
  for (i = 0; i < maxdimlen; i++) {
    dR->data[i] *= y->data[i];
  }

  maxdimlen = x->size[0] * x->size[1] * x->size[2];
  for (i = 0; i < maxdimlen; i++) {
    x->data[i] *= ndiv->data[i];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[3])dR->size, *(int32_T (*)[3])x->size,
    &g_emlrtECI, sp);
  st.site = &g_emlrtRSI;
  repmat(&st, L, n->size[0], r);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])C->size, *(int32_T (*)[2])r->size,
    &i_emlrtECI, sp);
  st.site = &g_emlrtRSI;
  nx = tbFactors->size[0] * tbFactors->size[1];
  b_st.site = &ib_emlrtRSI;
  computeDimsData(&b_st, kf->size[0], kf->size[1]);
  nE = tbFactors->size[0];
  if (tbFactors->size[1] > tbFactors->size[0]) {
    nE = tbFactors->size[1];
  }

  maxdimlen = muIntScalarMax_sint32(nx, nE);
  if (kf->size[0] > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (1 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (kf->size[1] > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (kf->size[0] * kf->size[1] != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &g_emlrtRSI;
  i = Rf->size[0] * Rf->size[1];
  Rf->size[0] = C->size[0];
  Rf->size[1] = C->size[1];
  emxEnsureCapacity_real_T(&st, Rf, i, &w_emlrtRTEI);
  maxdimlen = C->size[0] * C->size[1];
  for (i = 0; i < maxdimlen; i++) {
    Rf->data[i] = C->data[i] * r->data[i];
  }

  emxInit_real_T(&st, &b_tbFactors, 3, &x_emlrtRTEI, true);
  b_st.site = &g_emlrtRSI;
  d_repmat(&b_st, Rf, kf->size[1], ndiv);
  i = b_tbFactors->size[0] * b_tbFactors->size[1] * b_tbFactors->size[2];
  b_tbFactors->size[0] = kf->size[0];
  b_tbFactors->size[1] = 1;
  b_tbFactors->size[2] = kf->size[1];
  emxEnsureCapacity_real_T(&st, b_tbFactors, i, &x_emlrtRTEI);
  maxdimlen = kf->size[0] * kf->size[1];
  emxFree_real_T(&Rf);
  for (i = 0; i < maxdimlen; i++) {
    b_tbFactors->data[i] = tbFactors->data[i] + 1.0E-200;
  }

  emxFree_real_T(&tbFactors);
  b_st.site = &g_emlrtRSI;
  e_repmat(&b_st, b_tbFactors, n->size[0], y);
  emxFree_real_T(&b_tbFactors);
  if (!scalexpCompatible(ndiv, y)) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  maxdimlen = ndiv->size[0] * ndiv->size[1] * ndiv->size[2];
  for (i = 0; i < maxdimlen; i++) {
    ndiv->data[i] /= y->data[i];
  }

  emxFree_real_T(&y);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[3])dR->size, *(int32_T (*)[3])
    ndiv->size, &g_emlrtECI, sp);
  maxdimlen = dR->size[0] * dR->size[1] * dR->size[2];
  for (i = 0; i < maxdimlen; i++) {
    dR->data[i] = (dR->data[i] - x->data[i]) + ndiv->data[i];
  }

  emxFree_real_T(&x);
  emxFree_real_T(&ndiv);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])nub->size, *(int32_T (*)[2])
    nuf->size, &j_emlrtECI, sp);
  st.site = &h_emlrtRSI;
  nx = dR->size[0] * dR->size[1] * dR->size[2];
  b_st.site = &ib_emlrtRSI;
  sz_idx_1 = b_computeDimsData(&b_st, nx, kf->size[0]);
  nE = dR->size[0];
  if (dR->size[1] > dR->size[0]) {
    nE = dR->size[1];
  }

  if (dR->size[2] > nE) {
    nE = dR->size[2];
  }

  maxdimlen = muIntScalarMax_sint32(nx, nE);
  if (kf->size[0] > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (sz_idx_1 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (kf->size[0] * sz_idx_1 != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  i = r->size[0] * r->size[1];
  r->size[0] = nub->size[0];
  r->size[1] = nub->size[1];
  emxEnsureCapacity_real_T(sp, r, i, &y_emlrtRTEI);
  maxdimlen = nub->size[0] * nub->size[1];
  for (i = 0; i < maxdimlen; i++) {
    r->data[i] = nub->data[i] - nuf->data[i];
  }

  st.site = &h_emlrtRSI;
  c_kf[0] = kf->size[0];
  b_Rf = *dR;
  f_kf[0] = c_kf[0];
  f_kf[1] = sz_idx_1;
  b_Rf.size = &f_kf[0];
  b_Rf.numDimensions = 2;
  b_st.site = &k_emlrtRSI;
  dynamic_size_checks(&b_st, r, &b_Rf, r->size[0], kf->size[0]);
  c_kf[0] = kf->size[0];
  b_Rf = *dR;
  g_kf[0] = c_kf[0];
  g_kf[1] = sz_idx_1;
  b_Rf.size = &g_kf[0];
  b_Rf.numDimensions = 2;
  b_st.site = &j_emlrtRSI;
  b_mtimes(&b_st, r, &b_Rf, b_doN);
  st.site = &i_emlrtRSI;
  nx = b_doN->size[0] * b_doN->size[1];
  b_st.site = &ib_emlrtRSI;
  c_computeDimsData(&b_st, n->size[0], n->size[0], kf->size[1]);
  nE = b_doN->size[0];
  emxFree_real_T(&r);
  emxFree_real_T(&dR);
  if (b_doN->size[1] > b_doN->size[0]) {
    nE = b_doN->size[1];
  }

  maxdimlen = muIntScalarMax_sint32(nx, nE);
  if (n->size[0] > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (kf->size[1] > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (n->size[0] * n->size[0] * kf->size[1] != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  i = doN->size[0] * doN->size[1] * doN->size[2];
  doN->size[0] = n->size[0];
  doN->size[1] = n->size[0];
  doN->size[2] = kf->size[1];
  emxEnsureCapacity_real_T(sp, doN, i, &ab_emlrtRTEI);
  maxdimlen = n->size[0] * n->size[0] * kf->size[1];
  for (i = 0; i < maxdimlen; i++) {
    doN->data[i] = b_doN->data[i];
  }

  emxFree_real_T(&b_doN);

  /*  doN = zeros(nS,nS,nE); */
  /*  for i = 1:nE */
  /*      dR = nuf ./ (n(:,i)'+1e-200) .* Rf(:,i) - nub ./ (n(:,i)'+1e-200) .* Rb(:,i) + ... */
  /*          C.*L .* R(:,i) ./(tbFactors(:,i)+1e-200); */
  /*       */
  /*      doN(:,:,i) = ((nub - nuf)') * dR; */
  /*       */
  /*  end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (f_doNChem.c) */
