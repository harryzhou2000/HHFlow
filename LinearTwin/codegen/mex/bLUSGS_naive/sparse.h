/*
 * sparse.h
 *
 * Code generation for function 'sparse'
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
void sparse_mldivide(const emlrtStack *sp, const emxArray_real_T *A_d, const
                     emxArray_int32_T *A_colidx, const emxArray_int32_T
                     *A_rowidx, int32_T A_m, int32_T A_n, const emxArray_real_T *
                     b, emxArray_real_T *y);
void sparse_plus(const emlrtStack *sp, const emxArray_real_T *a_d, const
                 emxArray_int32_T *a_colidx, const emxArray_int32_T *a_rowidx,
                 int32_T a_m, int32_T a_n, const emxArray_real_T *b_d, const
                 emxArray_int32_T *b_colidx, const emxArray_int32_T *b_rowidx,
                 int32_T b_m, int32_T b_n, emxArray_real_T *s_d,
                 emxArray_int32_T *s_colidx, emxArray_int32_T *s_rowidx, int32_T
                 *s_m, int32_T *s_n);
void sparse_spallocLike(const emlrtStack *sp, int32_T m, int32_T n, real_T nzmax,
  coder_internal_sparse *s);
void sparse_sparse(const emlrtStack *sp, int32_T m, int32_T n, int32_T nzmaxval,
                   coder_internal_sparse *this);
void sparse_times(const emlrtStack *sp, const emxArray_real_T *a_d, const
                  emxArray_int32_T *a_colidx, const emxArray_int32_T *a_rowidx,
                  int32_T a_m, int32_T a_n, const emxArray_boolean_T *b_d, const
                  emxArray_int32_T *b_colidx, const emxArray_int32_T *b_rowidx,
                  int32_T b_m, int32_T b_n, emxArray_real_T *s_d,
                  emxArray_int32_T *s_colidx, emxArray_int32_T *s_rowidx,
                  int32_T *s_m, int32_T *s_n);

/* End of code generation (sparse.h) */
