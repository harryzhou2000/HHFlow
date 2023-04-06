/*
 * tril.h
 *
 * Code generation for function 'tril'
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
void sparse_tril(const emlrtStack *sp, const emxArray_real_T *A_d, const
                 emxArray_int32_T *A_colidx, const emxArray_int32_T *A_rowidx,
                 int32_T A_m, int32_T A_n, emxArray_real_T *L_d,
                 emxArray_int32_T *L_colidx, emxArray_int32_T *L_rowidx, int32_T
                 *L_m, int32_T *L_n);

/* End of code generation (tril.h) */
