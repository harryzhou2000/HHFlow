/*
 * triu.h
 *
 * Code generation for function 'triu'
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
void sparse_triu(const emlrtStack *sp, const emxArray_real_T *A_d, const
                 emxArray_int32_T *A_colidx, const emxArray_int32_T *A_rowidx,
                 int32_T A_m, int32_T A_n, emxArray_real_T *U_d,
                 emxArray_int32_T *U_colidx, emxArray_int32_T *U_rowidx, int32_T
                 *U_m, int32_T *U_n);

/* End of code generation (triu.h) */
