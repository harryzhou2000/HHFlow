/*
 * f_doNChem.h
 *
 * Code generation for function 'f_doNChem'
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
#include "f_doNChem_types.h"

/* Function Declarations */
void f_doNChem(const emlrtStack *sp, const emxArray_real_T *n, const
               emxArray_real_T *kf, const emxArray_real_T *kb, const
               emxArray_real_T *nuf, const emxArray_real_T *nub, const
               emxArray_real_T *C, const emxArray_real_T *L, emxArray_real_T
               *doN);

/* End of code generation (f_doNChem.h) */
