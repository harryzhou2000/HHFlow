/*
 * _coder_f_doNChem_api.c
 *
 * Code generation for function '_coder_f_doNChem_api'
 *
 */

/* Include files */
#include "_coder_f_doNChem_api.h"
#include "f_doNChem.h"
#include "f_doNChem_data.h"
#include "f_doNChem_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo qb_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "_coder_f_doNChem_api",              /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *n, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { -1, -1 };

  const boolean_T bv[2] = { true, true };

  int32_T iv[2];
  int32_T i;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *n, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(n), &thisId, y);
  emlrtDestroyArray(&n);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[3] = { 0, 0, 0 };

  y = NULL;
  m = emlrtCreateNumericArray(3, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u->data[0]);
  emlrtSetDimensions((mxArray *)m, u->size, 3);
  emlrtAssign(&y, m);
  return y;
}

void f_doNChem_api(const mxArray * const prhs[7], int32_T nlhs, const mxArray
                   *plhs[1])
{
  emxArray_real_T *n;
  emxArray_real_T *kf;
  emxArray_real_T *kb;
  emxArray_real_T *nuf;
  emxArray_real_T *nub;
  emxArray_real_T *C;
  emxArray_real_T *L;
  emxArray_real_T *doN;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &n, 2, &qb_emlrtRTEI, true);
  emxInit_real_T(&st, &kf, 2, &qb_emlrtRTEI, true);
  emxInit_real_T(&st, &kb, 2, &qb_emlrtRTEI, true);
  emxInit_real_T(&st, &nuf, 2, &qb_emlrtRTEI, true);
  emxInit_real_T(&st, &nub, 2, &qb_emlrtRTEI, true);
  emxInit_real_T(&st, &C, 2, &qb_emlrtRTEI, true);
  emxInit_real_T(&st, &L, 2, &qb_emlrtRTEI, true);
  emxInit_real_T(&st, &doN, 3, &qb_emlrtRTEI, true);

  /* Marshall function inputs */
  n->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "n", n);
  kf->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "kf", kf);
  kb->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "kb", kb);
  nuf->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "nuf", nuf);
  nub->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "nub", nub);
  C->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "C", C);
  L->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "L", L);

  /* Invoke the target function */
  f_doNChem(&st, n, kf, kb, nuf, nub, C, L, doN);

  /* Marshall function outputs */
  doN->canFreeData = false;
  plhs[0] = emlrt_marshallOut(doN);
  emxFree_real_T(&doN);
  emxFree_real_T(&L);
  emxFree_real_T(&C);
  emxFree_real_T(&nub);
  emxFree_real_T(&nuf);
  emxFree_real_T(&kb);
  emxFree_real_T(&kf);
  emxFree_real_T(&n);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_f_doNChem_api.c) */
