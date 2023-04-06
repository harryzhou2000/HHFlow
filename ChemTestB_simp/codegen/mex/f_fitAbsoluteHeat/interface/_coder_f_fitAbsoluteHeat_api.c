/*
 * _coder_f_fitAbsoluteHeat_api.c
 *
 * Code generation for function '_coder_f_fitAbsoluteHeat_api'
 *
 */

/* Include files */
#include "_coder_f_fitAbsoluteHeat_api.h"
#include "f_fitAbsoluteHeat.h"
#include "f_fitAbsoluteHeat_data.h"
#include "f_fitAbsoluteHeat_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo v_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_f_fitAbsoluteHeat_api",      /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *T, const
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

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *T, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(T), &thisId, y);
  emlrtDestroyArray(&T);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 0, 0 };

  y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u->data[0]);
  emlrtSetDimensions((mxArray *)m, u->size, 2);
  emlrtAssign(&y, m);
  return y;
}

void f_fitAbsoluteHeat_api(const mxArray * const prhs[3], int32_T nlhs, const
  mxArray *plhs[1])
{
  emxArray_real_T *T;
  emxArray_real_T *asA;
  emxArray_real_T *asB;
  emxArray_real_T *hs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &T, 2, &v_emlrtRTEI, true);
  emxInit_real_T(&st, &asA, 2, &v_emlrtRTEI, true);
  emxInit_real_T(&st, &asB, 2, &v_emlrtRTEI, true);
  emxInit_real_T(&st, &hs, 2, &v_emlrtRTEI, true);

  /* Marshall function inputs */
  T->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "T", T);
  asA->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "asA", asA);
  asB->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "asB", asB);

  /* Invoke the target function */
  f_fitAbsoluteHeat(&st, T, asA, asB, hs);

  /* Marshall function outputs */
  hs->canFreeData = false;
  plhs[0] = emlrt_marshallOut(hs);
  emxFree_real_T(&hs);
  emxFree_real_T(&asB);
  emxFree_real_T(&asA);
  emxFree_real_T(&T);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_f_fitAbsoluteHeat_api.c) */
