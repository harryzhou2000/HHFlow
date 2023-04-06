/*
 * bLUSGS_naive_emxutil.h
 *
 * Code generation for function 'bLUSGS_naive_emxutil'
 *
 */

#pragma once

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "bLUSGS_naive_types.h"

/* Function Declarations */
void c_emxFreeStruct_coder_internal_(coder_internal_sparse_1 *pStruct);
void c_emxInitStruct_coder_internal_(const emlrtStack *sp,
  coder_internal_sparse_1 *pStruct, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);
void d_emxFreeStruct_coder_internal_(coder_internal_sparse *pStruct);
void d_emxInitStruct_coder_internal_(const emlrtStack *sp, coder_internal_sparse
  *pStruct, const emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxEnsureCapacity_boolean_T(const emlrtStack *sp, emxArray_boolean_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_int32_T(const emlrtStack *sp, emxArray_int32_T *emxArray,
  int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
  int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
void emxFree_int32_T(emxArray_int32_T **pEmxArray);
void emxFree_real_T(emxArray_real_T **pEmxArray);
void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray, int32_T
                     numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                     doPush);
void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray, int32_T
                    numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                    doPush);

/* End of code generation (bLUSGS_naive_emxutil.h) */
