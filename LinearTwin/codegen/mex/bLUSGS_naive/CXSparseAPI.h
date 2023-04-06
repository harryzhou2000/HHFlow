/*
 * CXSparseAPI.h
 *
 * Code generation for function 'CXSparseAPI'
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
void CXSparseAPI_iteratedLU(const emlrtStack *sp, const emxArray_real_T *A_d,
  const emxArray_int32_T *A_colidx, const emxArray_int32_T *A_rowidx, int32_T
  A_m, int32_T A_n, const emxArray_real_T *b, emxArray_real_T *out);

/* End of code generation (CXSparseAPI.h) */
