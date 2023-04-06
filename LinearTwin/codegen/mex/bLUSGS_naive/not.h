/*
 * not.h
 *
 * Code generation for function 'not'
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
void sparse_not(const emlrtStack *sp, const emxArray_int32_T *S_colidx, const
                emxArray_int32_T *S_rowidx, int32_T S_m, int32_T S_n,
                emxArray_boolean_T *out_d, emxArray_int32_T *out_colidx,
                emxArray_int32_T *out_rowidx, int32_T *out_m, int32_T *out_n,
                int32_T *out_maxnz);

/* End of code generation (not.h) */
