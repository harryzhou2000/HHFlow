/*
 * bLUSGS_naive_data.c
 *
 * Code generation for function 'bLUSGS_naive_data'
 *
 */

/* Include files */
#include "bLUSGS_naive_data.h"
#include "bLUSGS_naive.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131594U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "bLUSGS_naive",                      /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo o_emlrtRSI = { 21,         /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo s_emlrtRSI = { 306,        /* lineNo */
  "eml_float_colon",                   /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

emlrtRSInfo ob_emlrtRSI = { 1508,      /* lineNo */
  "sparse/spallocLike",                /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

emlrtRSInfo rb_emlrtRSI = { 178,       /* lineNo */
  "sparse/sparse",                     /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

emlrtRSInfo sb_emlrtRSI = { 145,       /* lineNo */
  "sparse/sparse",                     /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

emlrtRSInfo tb_emlrtRSI = { 144,       /* lineNo */
  "sparse/sparse",                     /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

emlrtRSInfo vc_emlrtRSI = { 451,       /* lineNo */
  "CXSparseAPI/makeCX",                /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

emlrtRSInfo wc_emlrtRSI = { 453,       /* lineNo */
  "CXSparseAPI/makeCX",                /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

emlrtRSInfo xc_emlrtRSI = { 382,       /* lineNo */
  "sparse/ctranspose",                 /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

emlrtRSInfo yc_emlrtRSI = { 24,        /* lineNo */
  "sparse/locTranspose",               /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\locTranspose.m"/* pathName */
};

emlrtRSInfo ad_emlrtRSI = { 29,        /* lineNo */
  "sparse/locTranspose",               /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\locTranspose.m"/* pathName */
};

emlrtRSInfo bd_emlrtRSI = { 33,        /* lineNo */
  "sparse/locTranspose",               /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\locTranspose.m"/* pathName */
};

emlrtRSInfo cd_emlrtRSI = { 17,        /* lineNo */
  "sparse/locTranspose",               /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\locTranspose.m"/* pathName */
};

emlrtRSInfo dd_emlrtRSI = { 417,       /* lineNo */
  "CXSparseAPI/iteratedQR",            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

emlrtRSInfo ed_emlrtRSI = { 351,       /* lineNo */
  "CXSparseAPI/iteratedQR",            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

emlrtRTEInfo f_emlrtRTEI = { 1641,     /* lineNo */
  31,                                  /* colNo */
  "assertValidSize",                   /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pName */
};

emlrtRTEInfo m_emlrtRTEI = { 1638,     /* lineNo */
  9,                                   /* colNo */
  "assertValidSize",                   /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pName */
};

emlrtRTEInfo tb_emlrtRTEI = { 1508,    /* lineNo */
  17,                                  /* colNo */
  "sparse",                            /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pName */
};

emlrtRTEInfo yb_emlrtRTEI = { 451,     /* lineNo */
  63,                                  /* colNo */
  "CXSparseAPI",                       /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pName */
};

emlrtRTEInfo bc_emlrtRTEI = { 32,      /* lineNo */
  1,                                   /* colNo */
  "locTranspose",                      /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\locTranspose.m"/* pName */
};

emlrtRTEInfo cc_emlrtRTEI = { 388,     /* lineNo */
  25,                                  /* colNo */
  "CXSparseAPI",                       /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pName */
};

/* End of code generation (bLUSGS_naive_data.c) */
