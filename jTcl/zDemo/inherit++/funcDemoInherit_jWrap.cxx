
/*  ----------------------------------------------------------
 *   This file was automatically generated with
 *   jWrap (C)FRIDU a Free Software Company 97-98
 *   File: funcDemoInherit_jWrap.cxx small C++ example
 *   Date: Thu Apr 30 17:06:31 2020


 *   jWrap --cc2jTcl /home/fulup/Workspace/Fridu/Exe/linux86/etc/funcDemoInherit.h.cpp
 *
 *   WARNING: Except if you really know what you are doing
 *   you should not edit this file by hand.
 *
 *   In order finding jWrap check: http://www.fridu.bzh
 + ------------------------------------------------------------ */

#ifndef EASYC_PROTO_ONLY
#define EASYC_PROTO_ONLY
#endif
#define JWRAP_CC2JTCL

#include "libRuntimeJwrap.h"
#include "funcDemoInherit.h"

#ifndef DemoInherit_CUSTOM_STAMP
 #ifdef FRIDU
 #define DemoInherit_CUSTOM_STAMP &vStamp_libDemoInherit[12]
 #else
 #define DemoInherit_CUSTOM_STAMP NULL
 #endif
#endif

#define JWRAP_CREATE_FUNC jWrapTypeTcl2Cc
#define JWRAP_FREE_FUNC   jWrapTypeFree
#define JWRAP_CGET_FUNC   jWrapTypeCget

 // Build module static informations
 static JWRAP_modules module;
 static int initDone=0;
 static char *errTypeFmt="param:%d type [%s] not equivalent to [%s]\n";
 static JWRAP_types usedType [4];

 // Build used type enumeration
 enum enumType {
   JTYPE_Define_DemoInherit        = 0,
   JTYPE_char_Ptr                  = 1,
   JTYPE_double                    = 2,
   JTYPE_int                       = 3
 }; // end of usedType enumeration

 // Build used commands help array
 static char *helpCmd[] = {
   "double = mag ();",
   "double = mag1 ();",
   "double = mag ();",
   "double = mag2 ();",
   "double = mag ();",
   "double = mag3 ();",
 NULL
 }; // end of helpCmd array


/* *** Define Section *** */


 // build define enumeration
 typedef long Define_DemoInherit;
 static char *Define_DemoInherit_slotNames [] = {
   "__STDC__",
   "__STDC_VERSION__",
   "__STDC_UTF_16__",
   "__STDC_UTF_32__",
   "__STDC_HOSTED__",
   "__GNUC__",
   "__GNUC_MINOR__",
   "__GNUC_PATCHLEVEL__",
   "__ATOMIC_RELAXED",
   "__ATOMIC_SEQ_CST",
   "__ATOMIC_ACQUIRE",
   "__ATOMIC_RELEASE",
   "__ATOMIC_ACQ_REL",
   "__ATOMIC_CONSUME",
   "__FINITE_MATH_ONLY__",
   "_LP64",
   "__LP64__",
   "__SIZEOF_INT__",
   "__SIZEOF_LONG__",
   "__SIZEOF_LONG_LONG__",
   "__SIZEOF_SHORT__",
   "__SIZEOF_FLOAT__",
   "__SIZEOF_DOUBLE__",
   "__SIZEOF_LONG_DOUBLE__",
   "__SIZEOF_SIZE_T__",
   "__CHAR_BIT__",
   "__BIGGEST_ALIGNMENT__",
   "__ORDER_LITTLE_ENDIAN__",
   "__ORDER_BIG_ENDIAN__",
   "__ORDER_PDP_ENDIAN__",
   "__SIZEOF_POINTER__",
   "__GXX_ABI_VERSION",
   "__SCHAR_MAX__",
   "__SHRT_MAX__",
   "__INT_MAX__",
   "__LONG_MAX__",
   "__LONG_LONG_MAX__",
   "__WCHAR_MAX__",
   "__WINT_MAX__",
   "__WINT_MIN__",
   "__PTRDIFF_MAX__",
   "__SIZE_MAX__",
   "__SCHAR_WIDTH__",
   "__SHRT_WIDTH__",
   "__INT_WIDTH__",
   "__LONG_WIDTH__",
   "__LONG_LONG_WIDTH__",
   "__WCHAR_WIDTH__",
   "__WINT_WIDTH__",
   "__PTRDIFF_WIDTH__",
   "__SIZE_WIDTH__",
   "__INTMAX_MAX__",
   "__UINTMAX_MAX__",
   "__INTMAX_WIDTH__",
   "__SIG_ATOMIC_MAX__",
   "__SIG_ATOMIC_WIDTH__",
   "__INT8_MAX__",
   "__INT16_MAX__",
   "__INT32_MAX__",
   "__INT64_MAX__",
   "__UINT8_MAX__",
   "__UINT16_MAX__",
   "__UINT32_MAX__",
   "__UINT64_MAX__",
   "__INT_LEAST8_MAX__",
   "__INT_LEAST8_WIDTH__",
   "__INT_LEAST16_MAX__",
   "__INT_LEAST16_WIDTH__",
   "__INT_LEAST32_MAX__",
   "__INT_LEAST32_WIDTH__",
   "__INT_LEAST64_MAX__",
   "__INT_LEAST64_WIDTH__",
   "__UINT_LEAST8_MAX__",
   "__UINT_LEAST16_MAX__",
   "__UINT_LEAST32_MAX__",
   "__UINT_LEAST64_MAX__",
   "__INT_FAST8_MAX__",
   "__INT_FAST8_WIDTH__",
   "__INT_FAST16_MAX__",
   "__INT_FAST16_WIDTH__",
   "__INT_FAST32_MAX__",
   "__INT_FAST32_WIDTH__",
   "__INT_FAST64_MAX__",
   "__INT_FAST64_WIDTH__",
   "__UINT_FAST8_MAX__",
   "__UINT_FAST16_MAX__",
   "__UINT_FAST32_MAX__",
   "__UINT_FAST64_MAX__",
   "__INTPTR_MAX__",
   "__INTPTR_WIDTH__",
   "__UINTPTR_MAX__",
   "__GCC_IEC_559",
   "__GCC_IEC_559_COMPLEX",
   "__FLT_EVAL_METHOD__",
   "__FLT_EVAL_METHOD_TS_18661_3__",
   "__DEC_EVAL_METHOD__",
   "__FLT_RADIX__",
   "__FLT_MANT_DIG__",
   "__FLT_DIG__",
   "__FLT_MAX_EXP__",
   "__FLT_MAX_10_EXP__",
   "__FLT_DECIMAL_DIG__",
   "__FLT_MAX__",
   "__FLT_MIN__",
   "__FLT_EPSILON__",
   "__FLT_DENORM_MIN__",
   "__FLT_HAS_DENORM__",
   "__FLT_HAS_INFINITY__",
   "__FLT_HAS_QUIET_NAN__",
   "__DBL_MANT_DIG__",
   "__DBL_DIG__",
   "__DBL_MAX_EXP__",
   "__DBL_MAX_10_EXP__",
   "__DBL_DECIMAL_DIG__",
   "__DBL_HAS_DENORM__",
   "__DBL_HAS_INFINITY__",
   "__DBL_HAS_QUIET_NAN__",
   "__LDBL_MANT_DIG__",
   "__LDBL_DIG__",
   "__LDBL_MAX_EXP__",
   "__LDBL_MAX_10_EXP__",
   "__DECIMAL_DIG__",
   "__LDBL_DECIMAL_DIG__",
   "__LDBL_MAX__",
   "__LDBL_MIN__",
   "__LDBL_EPSILON__",
   "__LDBL_DENORM_MIN__",
   "__LDBL_HAS_DENORM__",
   "__LDBL_HAS_INFINITY__",
   "__LDBL_HAS_QUIET_NAN__",
   "__FLT32_MANT_DIG__",
   "__FLT32_DIG__",
   "__FLT32_MAX_EXP__",
   "__FLT32_MAX_10_EXP__",
   "__FLT32_DECIMAL_DIG__",
   "__FLT32_MAX__",
   "__FLT32_MIN__",
   "__FLT32_EPSILON__",
   "__FLT32_DENORM_MIN__",
   "__FLT32_HAS_DENORM__",
   "__FLT32_HAS_INFINITY__",
   "__FLT32_HAS_QUIET_NAN__",
   "__FLT64_MANT_DIG__",
   "__FLT64_DIG__",
   "__FLT64_MAX_EXP__",
   "__FLT64_MAX_10_EXP__",
   "__FLT64_DECIMAL_DIG__",
   "__FLT64_MAX__",
   "__FLT64_MIN__",
   "__FLT64_EPSILON__",
   "__FLT64_DENORM_MIN__",
   "__FLT64_HAS_DENORM__",
   "__FLT64_HAS_INFINITY__",
   "__FLT64_HAS_QUIET_NAN__",
   "__FLT128_MANT_DIG__",
   "__FLT128_DIG__",
   "__FLT128_MAX_EXP__",
   "__FLT128_MAX_10_EXP__",
   "__FLT128_DECIMAL_DIG__",
   "__FLT128_MAX__",
   "__FLT128_MIN__",
   "__FLT128_EPSILON__",
   "__FLT128_DENORM_MIN__",
   "__FLT128_HAS_DENORM__",
   "__FLT128_HAS_INFINITY__",
   "__FLT128_HAS_QUIET_NAN__",
   "__FLT32X_MANT_DIG__",
   "__FLT32X_DIG__",
   "__FLT32X_MAX_EXP__",
   "__FLT32X_MAX_10_EXP__",
   "__FLT32X_DECIMAL_DIG__",
   "__FLT32X_MAX__",
   "__FLT32X_MIN__",
   "__FLT32X_EPSILON__",
   "__FLT32X_DENORM_MIN__",
   "__FLT32X_HAS_DENORM__",
   "__FLT32X_HAS_INFINITY__",
   "__FLT32X_HAS_QUIET_NAN__",
   "__FLT64X_MANT_DIG__",
   "__FLT64X_DIG__",
   "__FLT64X_MAX_EXP__",
   "__FLT64X_MAX_10_EXP__",
   "__FLT64X_DECIMAL_DIG__",
   "__FLT64X_MAX__",
   "__FLT64X_MIN__",
   "__FLT64X_EPSILON__",
   "__FLT64X_DENORM_MIN__",
   "__FLT64X_HAS_DENORM__",
   "__FLT64X_HAS_INFINITY__",
   "__FLT64X_HAS_QUIET_NAN__",
   "__DEC32_MANT_DIG__",
   "__DEC32_MAX_EXP__",
   "__DEC32_MIN__",
   "__DEC32_MAX__",
   "__DEC32_EPSILON__",
   "__DEC32_SUBNORMAL_MIN__",
   "__DEC64_MANT_DIG__",
   "__DEC64_MAX_EXP__",
   "__DEC64_MIN__",
   "__DEC64_MAX__",
   "__DEC64_EPSILON__",
   "__DEC64_SUBNORMAL_MIN__",
   "__DEC128_MANT_DIG__",
   "__DEC128_MAX_EXP__",
   "__DEC128_MIN__",
   "__DEC128_MAX__",
   "__DEC128_EPSILON__",
   "__DEC128_SUBNORMAL_MIN__",
   "__GNUC_STDC_INLINE__",
   "__NO_INLINE__",
   "__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1",
   "__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2",
   "__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4",
   "__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8",
   "__GCC_ATOMIC_BOOL_LOCK_FREE",
   "__GCC_ATOMIC_CHAR_LOCK_FREE",
   "__GCC_ATOMIC_CHAR16_T_LOCK_FREE",
   "__GCC_ATOMIC_CHAR32_T_LOCK_FREE",
   "__GCC_ATOMIC_WCHAR_T_LOCK_FREE",
   "__GCC_ATOMIC_SHORT_LOCK_FREE",
   "__GCC_ATOMIC_INT_LOCK_FREE",
   "__GCC_ATOMIC_LONG_LOCK_FREE",
   "__GCC_ATOMIC_LLONG_LOCK_FREE",
   "__GCC_ATOMIC_TEST_AND_SET_TRUEVAL",
   "__GCC_ATOMIC_POINTER_LOCK_FREE",
   "__GCC_HAVE_DWARF2_CFI_ASM",
   "__PRAGMA_REDEFINE_EXTNAME",
   "__SIZEOF_INT128__",
   "__SIZEOF_WCHAR_T__",
   "__SIZEOF_WINT_T__",
   "__SIZEOF_PTRDIFF_T__",
   "__amd64",
   "__amd64__",
   "__x86_64",
   "__x86_64__",
   "__SIZEOF_FLOAT80__",
   "__SIZEOF_FLOAT128__",
   "__ATOMIC_HLE_ACQUIRE",
   "__ATOMIC_HLE_RELEASE",
   "__GCC_ASM_FLAG_OUTPUTS__",
   "__k8",
   "__k8__",
   "__code_model_small__",
   "__MMX__",
   "__SSE__",
   "__SSE2__",
   "__FXSR__",
   "__SSE_MATH__",
   "__SSE2_MATH__",
   "__SEG_FS",
   "__SEG_GS",
   "__gnu_linux__",
   "__linux",
   "__linux__",
   "linux",
   "__unix",
   "__unix__",
   "unix",
   "__ELF__",
   "__DECIMAL_BID_FORMAT__",
   "__STDC__",
   "JWRAP",
   "JWRAP_JTCL",
   NULL
 };
 static long Define_DemoInherit_slotValues [] = {
   (long)__STDC__,
   (long)__STDC_VERSION__,
   (long)__STDC_UTF_16__,
   (long)__STDC_UTF_32__,
   (long)__STDC_HOSTED__,
   (long)__GNUC__,
   (long)__GNUC_MINOR__,
   (long)__GNUC_PATCHLEVEL__,
   (long)__ATOMIC_RELAXED,
   (long)__ATOMIC_SEQ_CST,
   (long)__ATOMIC_ACQUIRE,
   (long)__ATOMIC_RELEASE,
   (long)__ATOMIC_ACQ_REL,
   (long)__ATOMIC_CONSUME,
   (long)__FINITE_MATH_ONLY__,
   (long)_LP64,
   (long)__LP64__,
   (long)__SIZEOF_INT__,
   (long)__SIZEOF_LONG__,
   (long)__SIZEOF_LONG_LONG__,
   (long)__SIZEOF_SHORT__,
   (long)__SIZEOF_FLOAT__,
   (long)__SIZEOF_DOUBLE__,
   (long)__SIZEOF_LONG_DOUBLE__,
   (long)__SIZEOF_SIZE_T__,
   (long)__CHAR_BIT__,
   (long)__BIGGEST_ALIGNMENT__,
   (long)__ORDER_LITTLE_ENDIAN__,
   (long)__ORDER_BIG_ENDIAN__,
   (long)__ORDER_PDP_ENDIAN__,
   (long)__SIZEOF_POINTER__,
   (long)__GXX_ABI_VERSION,
   (long)__SCHAR_MAX__,
   (long)__SHRT_MAX__,
   (long)__INT_MAX__,
   (long)__LONG_MAX__,
   (long)__LONG_LONG_MAX__,
   (long)__WCHAR_MAX__,
   (long)__WINT_MAX__,
   (long)__WINT_MIN__,
   (long)__PTRDIFF_MAX__,
   (long)__SIZE_MAX__,
   (long)__SCHAR_WIDTH__,
   (long)__SHRT_WIDTH__,
   (long)__INT_WIDTH__,
   (long)__LONG_WIDTH__,
   (long)__LONG_LONG_WIDTH__,
   (long)__WCHAR_WIDTH__,
   (long)__WINT_WIDTH__,
   (long)__PTRDIFF_WIDTH__,
   (long)__SIZE_WIDTH__,
   (long)__INTMAX_MAX__,
   (long)__UINTMAX_MAX__,
   (long)__INTMAX_WIDTH__,
   (long)__SIG_ATOMIC_MAX__,
   (long)__SIG_ATOMIC_WIDTH__,
   (long)__INT8_MAX__,
   (long)__INT16_MAX__,
   (long)__INT32_MAX__,
   (long)__INT64_MAX__,
   (long)__UINT8_MAX__,
   (long)__UINT16_MAX__,
   (long)__UINT32_MAX__,
   (long)__UINT64_MAX__,
   (long)__INT_LEAST8_MAX__,
   (long)__INT_LEAST8_WIDTH__,
   (long)__INT_LEAST16_MAX__,
   (long)__INT_LEAST16_WIDTH__,
   (long)__INT_LEAST32_MAX__,
   (long)__INT_LEAST32_WIDTH__,
   (long)__INT_LEAST64_MAX__,
   (long)__INT_LEAST64_WIDTH__,
   (long)__UINT_LEAST8_MAX__,
   (long)__UINT_LEAST16_MAX__,
   (long)__UINT_LEAST32_MAX__,
   (long)__UINT_LEAST64_MAX__,
   (long)__INT_FAST8_MAX__,
   (long)__INT_FAST8_WIDTH__,
   (long)__INT_FAST16_MAX__,
   (long)__INT_FAST16_WIDTH__,
   (long)__INT_FAST32_MAX__,
   (long)__INT_FAST32_WIDTH__,
   (long)__INT_FAST64_MAX__,
   (long)__INT_FAST64_WIDTH__,
   (long)__UINT_FAST8_MAX__,
   (long)__UINT_FAST16_MAX__,
   (long)__UINT_FAST32_MAX__,
   (long)__UINT_FAST64_MAX__,
   (long)__INTPTR_MAX__,
   (long)__INTPTR_WIDTH__,
   (long)__UINTPTR_MAX__,
   (long)__GCC_IEC_559,
   (long)__GCC_IEC_559_COMPLEX,
   (long)__FLT_EVAL_METHOD__,
   (long)__FLT_EVAL_METHOD_TS_18661_3__,
   (long)__DEC_EVAL_METHOD__,
   (long)__FLT_RADIX__,
   (long)__FLT_MANT_DIG__,
   (long)__FLT_DIG__,
   (long)__FLT_MAX_EXP__,
   (long)__FLT_MAX_10_EXP__,
   (long)__FLT_DECIMAL_DIG__,
   (long)__FLT_MAX__,
   (long)__FLT_MIN__,
   (long)__FLT_EPSILON__,
   (long)__FLT_DENORM_MIN__,
   (long)__FLT_HAS_DENORM__,
   (long)__FLT_HAS_INFINITY__,
   (long)__FLT_HAS_QUIET_NAN__,
   (long)__DBL_MANT_DIG__,
   (long)__DBL_DIG__,
   (long)__DBL_MAX_EXP__,
   (long)__DBL_MAX_10_EXP__,
   (long)__DBL_DECIMAL_DIG__,
   (long)__DBL_HAS_DENORM__,
   (long)__DBL_HAS_INFINITY__,
   (long)__DBL_HAS_QUIET_NAN__,
   (long)__LDBL_MANT_DIG__,
   (long)__LDBL_DIG__,
   (long)__LDBL_MAX_EXP__,
   (long)__LDBL_MAX_10_EXP__,
   (long)__DECIMAL_DIG__,
   (long)__LDBL_DECIMAL_DIG__,
   (long)__LDBL_MAX__,
   (long)__LDBL_MIN__,
   (long)__LDBL_EPSILON__,
   (long)__LDBL_DENORM_MIN__,
   (long)__LDBL_HAS_DENORM__,
   (long)__LDBL_HAS_INFINITY__,
   (long)__LDBL_HAS_QUIET_NAN__,
   (long)__FLT32_MANT_DIG__,
   (long)__FLT32_DIG__,
   (long)__FLT32_MAX_EXP__,
   (long)__FLT32_MAX_10_EXP__,
   (long)__FLT32_DECIMAL_DIG__,
   (long)__FLT32_MAX__,
   (long)__FLT32_MIN__,
   (long)__FLT32_EPSILON__,
   (long)__FLT32_DENORM_MIN__,
   (long)__FLT32_HAS_DENORM__,
   (long)__FLT32_HAS_INFINITY__,
   (long)__FLT32_HAS_QUIET_NAN__,
   (long)__FLT64_MANT_DIG__,
   (long)__FLT64_DIG__,
   (long)__FLT64_MAX_EXP__,
   (long)__FLT64_MAX_10_EXP__,
   (long)__FLT64_DECIMAL_DIG__,
   (long)__FLT64_MAX__,
   (long)__FLT64_MIN__,
   (long)__FLT64_EPSILON__,
   (long)__FLT64_DENORM_MIN__,
   (long)__FLT64_HAS_DENORM__,
   (long)__FLT64_HAS_INFINITY__,
   (long)__FLT64_HAS_QUIET_NAN__,
   (long)__FLT128_MANT_DIG__,
   (long)__FLT128_DIG__,
   (long)__FLT128_MAX_EXP__,
   (long)__FLT128_MAX_10_EXP__,
   (long)__FLT128_DECIMAL_DIG__,
   (long)__FLT128_MAX__,
   (long)__FLT128_MIN__,
   (long)__FLT128_EPSILON__,
   (long)__FLT128_DENORM_MIN__,
   (long)__FLT128_HAS_DENORM__,
   (long)__FLT128_HAS_INFINITY__,
   (long)__FLT128_HAS_QUIET_NAN__,
   (long)__FLT32X_MANT_DIG__,
   (long)__FLT32X_DIG__,
   (long)__FLT32X_MAX_EXP__,
   (long)__FLT32X_MAX_10_EXP__,
   (long)__FLT32X_DECIMAL_DIG__,
   (long)__FLT32X_MAX__,
   (long)__FLT32X_MIN__,
   (long)__FLT32X_EPSILON__,
   (long)__FLT32X_DENORM_MIN__,
   (long)__FLT32X_HAS_DENORM__,
   (long)__FLT32X_HAS_INFINITY__,
   (long)__FLT32X_HAS_QUIET_NAN__,
   (long)__FLT64X_MANT_DIG__,
   (long)__FLT64X_DIG__,
   (long)__FLT64X_MAX_EXP__,
   (long)__FLT64X_MAX_10_EXP__,
   (long)__FLT64X_DECIMAL_DIG__,
   (long)__FLT64X_MAX__,
   (long)__FLT64X_MIN__,
   (long)__FLT64X_EPSILON__,
   (long)__FLT64X_DENORM_MIN__,
   (long)__FLT64X_HAS_DENORM__,
   (long)__FLT64X_HAS_INFINITY__,
   (long)__FLT64X_HAS_QUIET_NAN__,
   (long)__DEC32_MANT_DIG__,
   (long)__DEC32_MAX_EXP__,
   (long)__DEC32_MIN__,
   (long)__DEC32_MAX__,
   (long)__DEC32_EPSILON__,
   (long)__DEC32_SUBNORMAL_MIN__,
   (long)__DEC64_MANT_DIG__,
   (long)__DEC64_MAX_EXP__,
   (long)__DEC64_MIN__,
   (long)__DEC64_MAX__,
   (long)__DEC64_EPSILON__,
   (long)__DEC64_SUBNORMAL_MIN__,
   (long)__DEC128_MANT_DIG__,
   (long)__DEC128_MAX_EXP__,
   (long)__DEC128_MIN__,
   (long)__DEC128_MAX__,
   (long)__DEC128_EPSILON__,
   (long)__DEC128_SUBNORMAL_MIN__,
   (long)__GNUC_STDC_INLINE__,
   (long)__NO_INLINE__,
   (long)__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1,
   (long)__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2,
   (long)__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4,
   (long)__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8,
   (long)__GCC_ATOMIC_BOOL_LOCK_FREE,
   (long)__GCC_ATOMIC_CHAR_LOCK_FREE,
   (long)__GCC_ATOMIC_CHAR16_T_LOCK_FREE,
   (long)__GCC_ATOMIC_CHAR32_T_LOCK_FREE,
   (long)__GCC_ATOMIC_WCHAR_T_LOCK_FREE,
   (long)__GCC_ATOMIC_SHORT_LOCK_FREE,
   (long)__GCC_ATOMIC_INT_LOCK_FREE,
   (long)__GCC_ATOMIC_LONG_LOCK_FREE,
   (long)__GCC_ATOMIC_LLONG_LOCK_FREE,
   (long)__GCC_ATOMIC_TEST_AND_SET_TRUEVAL,
   (long)__GCC_ATOMIC_POINTER_LOCK_FREE,
   (long)__GCC_HAVE_DWARF2_CFI_ASM,
   (long)__PRAGMA_REDEFINE_EXTNAME,
   (long)__SIZEOF_INT128__,
   (long)__SIZEOF_WCHAR_T__,
   (long)__SIZEOF_WINT_T__,
   (long)__SIZEOF_PTRDIFF_T__,
   (long)__amd64,
   (long)__amd64__,
   (long)__x86_64,
   (long)__x86_64__,
   (long)__SIZEOF_FLOAT80__,
   (long)__SIZEOF_FLOAT128__,
   (long)__ATOMIC_HLE_ACQUIRE,
   (long)__ATOMIC_HLE_RELEASE,
   (long)__GCC_ASM_FLAG_OUTPUTS__,
   (long)__k8,
   (long)__k8__,
   (long)__code_model_small__,
   (long)__MMX__,
   (long)__SSE__,
   (long)__SSE2__,
   (long)__FXSR__,
   (long)__SSE_MATH__,
   (long)__SSE2_MATH__,
   (long)__SEG_FS,
   (long)__SEG_GS,
   (long)__gnu_linux__,
   (long)__linux,
   (long)__linux__,
   (long)linux,
   (long)__unix,
   (long)__unix__,
   (long)unix,
   (long)__ELF__,
   (long)__DECIMAL_BID_FORMAT__,
   (long)__STDC__,
   (long)JWRAP,
   (long)JWRAP_JTCL,
   0
 };
 static JWRAP_enums Define_DemoInherit_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_Define_DemoInherit],
  263,
  Define_DemoInherit_slotNames,
  (long*)Define_DemoInherit_slotValues
 };
LOCAL int Put_Define_DemoInherit (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &Define_DemoInherit_enum, tclObj));
}
LOCAL void Get_Define_DemoInherit (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&Define_DemoInherit_enum, tclObj);
}
// Build Define_DemoInherit jointure as a Tcl type
static Tcl_ObjType Define_DemoInherit_type = {
  "Define_DemoInherit",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Define_DemoInherit,
  (Tcl_SetFromAnyProc*)      Put_Define_DemoInherit
  };

 // Hold Defines & Enum reference for jWrap struct help cmd
 static JWRAP_enums *enumerations[]={
  &Define_DemoInherit_enum,
  NULL
 };

/* *** Functions Section *** */


/* *** Classes Section *** */
static Tcl_Obj *tclStr_Point1_mag1 = jWrapStringNew ("mag1",4);
class jWrap_Point1 : public Point1
{
 private:
 Tcl_Obj    *jTclHandle;  // store jTcl instance object name
 Tcl_Interp *interp;      // Save Interp in order call jTcl from C++

 public: // everything else is public

 // Interface jTcl to C++ for public mag C/C++ function/method
 static int jTcl_mag_0 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_HashEntry *entryPtr;
 jWrap_Point1 *objHandle;
 Tcl_Obj *resultPtr;
 struct { union {
   double   appli;
   void *ptr;
 } shared; }result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 2) goto errorNumArg;

 // get cc object handle from jTcl object name
 entryPtr = Tcl_FindHashEntry (module.hashTable
          , TCL_STRING (objv[1]));
 if (entryPtr == NULL) {
  Tcl_AppendResult (interp,"Unknown C++ Object in Hashtable index="
                   ,TCL_STRING (objv[1]),NULL);
  return (TCL_ERROR);
 }
 objHandle= (jWrap_Point1*)Tcl_GetHashValue (entryPtr);


 // Check param number
 if (objc != 2) goto  errorNumArg;

 // effectively call C++ function/method
 result.shared.appli =  objHandle->Point1::mag ();

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(double*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_double].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[0]);
  return TCL_ERROR;
 } // end method jWrap_mag0

 // Interface jTcl to C++ for public mag1 C/C++ function/method
 static int jTcl_mag1_1 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_HashEntry *entryPtr;
 jWrap_Point1 *objHandle;
 Tcl_Obj *resultPtr;
 struct { union {
   double   appli;
   void *ptr;
 } shared; }result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 2) goto errorNumArg;

 // get cc object handle from jTcl object name
 entryPtr = Tcl_FindHashEntry (module.hashTable
          , TCL_STRING (objv[1]));
 if (entryPtr == NULL) {
  Tcl_AppendResult (interp,"Unknown C++ Object in Hashtable index="
                   ,TCL_STRING (objv[1]),NULL);
  return (TCL_ERROR);
 }
 objHandle= (jWrap_Point1*)Tcl_GetHashValue (entryPtr);


 // Check param number
 if (objc != 2) goto  errorNumArg;

 // effectively call C++ function/method
 result.shared.appli =  objHandle->Point1::mag1 ();

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(double*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_double].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[1]);
  return TCL_ERROR;
 } // end method jWrap_mag11

 // Interface C++ -> jTcl for mag1 C++ method
 virtual double mag1 ()
 {
 Tcl_Obj tmpCgetObj;
 Tcl_Obj *currentObj;
double result;
 Tcl_CmdInfo infoCmd;
 Tcl_Obj *objv[2],*resultObj;
 int     status;
 // Build jTcl cmd start with proc_name + jtcl_obj + method_name
 objv[0] = jTclHandle;
 objv[1] = tclStr_Point1_mag1;

 // Translate params from C++ native to Tcl object
  // call jTcl free method
  if (!Tcl_GetCommandInfo (interp, TCL_STRING (jTclHandle), &infoCmd)) {
     jWrapPanic (NULL,"Unknown jTcl  object",TCL_STRING (jTclHandle));
  }
  status = (*infoCmd.objProc) (infoCmd.objClientData, interp,2,objv);

  if (status != TCL_OK) jWrapPanic (NULL,"jTcl Method mag1 failed");

 resultObj = Tcl_GetObjResult(interp);
 // convert to our wanted application type
 if (resultObj->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)resultObj->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = resultObj->bytes;
   tmpCgetObj.length  = resultObj->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = resultObj;
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_double].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_double].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_double].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_double].obj->name);
 }
  result = *(double*)&currentObj->internalRep;

 return result;
 } // end method mag1

 // jWrap need a constructor to register jTcl obj reference
 static jTcl_new (ClientData clData, Tcl_Interp *interp
           ,int objc,Tcl_Obj *CONST objv[]) {
 // tempry data for registration of CC obj handle in hashtable
 int isnew; Tcl_HashEntry *entryPtr;


 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 2) goto errorNumArg;

 // Store cc handle in hashtable with jTcl handle as key
 entryPtr = Tcl_CreateHashEntry (&jWrapHashTable ,TCL_STRING (objv[1]), &isnew);
 if (!isnew) goto errorMultiInherit; // Effectively build C++ object and store it in hashtable
 Tcl_SetHashValue (entryPtr, (ClientData) new jWrap_Point1 (interp,objv[1]));
 return TCL_OK;


 errorNumArg:
  Tcl_WrongNumArgs (interp, 1, objv, "Syntax: new Point1");
  return TCL_ERROR;

 errorMultiInherit:
  Tcl_AppendResult (interp,"jWrap cannot multi-inherit: class Point1 handle="
                   ,TCL_STRING(objv[1]),NULL);
  return TCL_ERROR;
 } // end default jTcl->C++ Point1 constructor

 // Destructor clean up c++ object
 ~jWrap_Point1 () {
   int status;
   Tcl_CmdInfo infoCmd;
   Tcl_Obj *resultPtr;
   Tcl_Obj *objv[2];

   // if called from jTcl just return
   if (jTclHandle == NULL) return;

   // Build jTcl free cmd
   objv[0] = jWrapFreeMethod;
   objv[1] = jTclHandle;

  // call jTcl free method
  if (!Tcl_GetCommandInfo (interp, TCL_STRING (jTclHandle), &infoCmd)) {
     jWrapPanic (NULL,"Unknown jTcl  object",TCL_STRING (jTclHandle));
  }
   status    = (*infoCmd.objProc) (infoCmd.objClientData, interp,2,objv);

   if (status != TCL_OK) {
     resultPtr = Tcl_GetObjResult(interp);
     jWrapPanic (NULL,TCL_STRING(resultPtr));   }

 } // end C++ destructor

 // jTcl destructor call C++ cleanup
 static int jTcl_free
 (ClientData clData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_HashEntry *entryPtr;
 jWrap_Point1 *cxxHandle;
  // prepare emergency panic return
  if (setjmp (jWrapCheckPoint)) {
     return TCL_ERROR;
  }
 // get cc object handle from jTcl object name
 entryPtr = Tcl_FindHashEntry (&jWrapHashTable
          , TCL_STRING (objv[1]));
 if (entryPtr == NULL) {
  Tcl_AppendResult (interp,"Unknown C++ Object in Hashtable handle="
                   ,TCL_STRING (objv[1]),NULL);
  return (TCL_ERROR);
 }
 cxxHandle= (jWrap_Point1*)Tcl_GetHashValue (entryPtr);

  // Clean up the place and make C++ destructor not to recall jTcl
  Tcl_DecrRefCount(cxxHandle->jTclHandle);
  cxxHandle->jTclHandle = NULL;

  //effectively destroy C++ object and jTcl reference
  delete (cxxHandle);

  return TCL_OK;
 } // end jTcl destructor

 // internal constructor register C++ handle in jTcl object
 jWrap_Point1 (Tcl_Interp *objInterp, Tcl_Obj *jTclObj)
 {
   // Store jTcl object string in C++ object
   Tcl_IncrRefCount (jTclObj);
   jTclHandle = jTclObj;
   interp     = objInterp;

   // register instance variable in Tcl interp
   jWrapVarRegister (interp, jTclHandle, "x", (long*)&x, 1 
                  , &usedType[JTYPE_double]);
 } // end internal constructor
}; // end class jWrap_Point1

class jWrap_Point2 : public Point2
{
 private:
 Tcl_Obj    *jTclHandle;  // store jTcl instance object name
 Tcl_Interp *interp;      // Save Interp in order call jTcl from C++

 public: // everything else is public

 // Interface jTcl to C++ for public mag C/C++ function/method
 static int jTcl_mag_2 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_HashEntry *entryPtr;
 jWrap_Point2 *objHandle;
 Tcl_Obj *resultPtr;
 struct { union {
   double   appli;
   void *ptr;
 } shared; }result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 2) goto errorNumArg;

 // get cc object handle from jTcl object name
 entryPtr = Tcl_FindHashEntry (module.hashTable
          , TCL_STRING (objv[1]));
 if (entryPtr == NULL) {
  Tcl_AppendResult (interp,"Unknown C++ Object in Hashtable index="
                   ,TCL_STRING (objv[1]),NULL);
  return (TCL_ERROR);
 }
 objHandle= (jWrap_Point2*)Tcl_GetHashValue (entryPtr);


 // Check param number
 if (objc != 2) goto  errorNumArg;

 // effectively call C++ function/method
 result.shared.appli =  objHandle->Point2::mag ();

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(double*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_double].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[2]);
  return TCL_ERROR;
 } // end method jWrap_mag2

 // Interface jTcl to C++ for public mag2 C/C++ function/method
 static int jTcl_mag2_3 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_HashEntry *entryPtr;
 jWrap_Point2 *objHandle;
 Tcl_Obj *resultPtr;
 struct { union {
   double   appli;
   void *ptr;
 } shared; }result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 2) goto errorNumArg;

 // get cc object handle from jTcl object name
 entryPtr = Tcl_FindHashEntry (module.hashTable
          , TCL_STRING (objv[1]));
 if (entryPtr == NULL) {
  Tcl_AppendResult (interp,"Unknown C++ Object in Hashtable index="
                   ,TCL_STRING (objv[1]),NULL);
  return (TCL_ERROR);
 }
 objHandle= (jWrap_Point2*)Tcl_GetHashValue (entryPtr);


 // Check param number
 if (objc != 2) goto  errorNumArg;

 // effectively call C++ function/method
 result.shared.appli =  objHandle->Point2::mag2 ();

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(double*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_double].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[3]);
  return TCL_ERROR;
 } // end method jWrap_mag23

 // jWrap need a constructor to register jTcl obj reference
 static jTcl_new (ClientData clData, Tcl_Interp *interp
           ,int objc,Tcl_Obj *CONST objv[]) {
 // tempry data for registration of CC obj handle in hashtable
 int isnew; Tcl_HashEntry *entryPtr;


 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 2) goto errorNumArg;

 // Store cc handle in hashtable with jTcl handle as key
 entryPtr = Tcl_CreateHashEntry (&jWrapHashTable ,TCL_STRING (objv[1]), &isnew);
 if (!isnew) goto errorMultiInherit; // Effectively build C++ object and store it in hashtable
 Tcl_SetHashValue (entryPtr, (ClientData) new jWrap_Point2 (interp,objv[1]));
 return TCL_OK;


 errorNumArg:
  Tcl_WrongNumArgs (interp, 1, objv, "Syntax: new Point2");
  return TCL_ERROR;

 errorMultiInherit:
  Tcl_AppendResult (interp,"jWrap cannot multi-inherit: class Point2 handle="
                   ,TCL_STRING(objv[1]),NULL);
  return TCL_ERROR;
 } // end default jTcl->C++ Point2 constructor

 // Destructor clean up c++ object
 ~jWrap_Point2 () {
   int status;
   Tcl_CmdInfo infoCmd;
   Tcl_Obj *resultPtr;
   Tcl_Obj *objv[2];

   // if called from jTcl just return
   if (jTclHandle == NULL) return;

   // Build jTcl free cmd
   objv[0] = jWrapFreeMethod;
   objv[1] = jTclHandle;

  // call jTcl free method
  if (!Tcl_GetCommandInfo (interp, TCL_STRING (jTclHandle), &infoCmd)) {
     jWrapPanic (NULL,"Unknown jTcl  object",TCL_STRING (jTclHandle));
  }
   status    = (*infoCmd.objProc) (infoCmd.objClientData, interp,2,objv);

   if (status != TCL_OK) {
     resultPtr = Tcl_GetObjResult(interp);
     jWrapPanic (NULL,TCL_STRING(resultPtr));   }

 } // end C++ destructor

 // jTcl destructor call C++ cleanup
 static int jTcl_free
 (ClientData clData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_HashEntry *entryPtr;
 jWrap_Point2 *cxxHandle;
  // prepare emergency panic return
  if (setjmp (jWrapCheckPoint)) {
     return TCL_ERROR;
  }
 // get cc object handle from jTcl object name
 entryPtr = Tcl_FindHashEntry (&jWrapHashTable
          , TCL_STRING (objv[1]));
 if (entryPtr == NULL) {
  Tcl_AppendResult (interp,"Unknown C++ Object in Hashtable handle="
                   ,TCL_STRING (objv[1]),NULL);
  return (TCL_ERROR);
 }
 cxxHandle= (jWrap_Point2*)Tcl_GetHashValue (entryPtr);

  // Clean up the place and make C++ destructor not to recall jTcl
  Tcl_DecrRefCount(cxxHandle->jTclHandle);
  cxxHandle->jTclHandle = NULL;

  //effectively destroy C++ object and jTcl reference
  delete (cxxHandle);

  return TCL_OK;
 } // end jTcl destructor

 // internal constructor register C++ handle in jTcl object
 jWrap_Point2 (Tcl_Interp *objInterp, Tcl_Obj *jTclObj)
 {
   // Store jTcl object string in C++ object
   Tcl_IncrRefCount (jTclObj);
   jTclHandle = jTclObj;
   interp     = objInterp;

   // register instance variable in Tcl interp
   jWrapVarRegister (interp, jTclHandle, "y", (long*)&y, 1 
                  , &usedType[JTYPE_double]);
 } // end internal constructor
}; // end class jWrap_Point2

class jWrap_Point3 : public Point3
{
 private:
 Tcl_Obj    *jTclHandle;  // store jTcl instance object name
 Tcl_Interp *interp;      // Save Interp in order call jTcl from C++

 public: // everything else is public

 // Interface jTcl to C++ for public mag C/C++ function/method
 static int jTcl_mag_4 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_HashEntry *entryPtr;
 jWrap_Point3 *objHandle;
 Tcl_Obj *resultPtr;
 struct { union {
   double   appli;
   void *ptr;
 } shared; }result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 2) goto errorNumArg;

 // get cc object handle from jTcl object name
 entryPtr = Tcl_FindHashEntry (module.hashTable
          , TCL_STRING (objv[1]));
 if (entryPtr == NULL) {
  Tcl_AppendResult (interp,"Unknown C++ Object in Hashtable index="
                   ,TCL_STRING (objv[1]),NULL);
  return (TCL_ERROR);
 }
 objHandle= (jWrap_Point3*)Tcl_GetHashValue (entryPtr);


 // Check param number
 if (objc != 2) goto  errorNumArg;

 // effectively call C++ function/method
 result.shared.appli =  objHandle->Point3::mag ();

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(double*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_double].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[4]);
  return TCL_ERROR;
 } // end method jWrap_mag4

 // Interface jTcl to C++ for public mag3 C/C++ function/method
 static int jTcl_mag3_5 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_HashEntry *entryPtr;
 jWrap_Point3 *objHandle;
 Tcl_Obj *resultPtr;
 struct { union {
   double   appli;
   void *ptr;
 } shared; }result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 2) goto errorNumArg;

 // get cc object handle from jTcl object name
 entryPtr = Tcl_FindHashEntry (module.hashTable
          , TCL_STRING (objv[1]));
 if (entryPtr == NULL) {
  Tcl_AppendResult (interp,"Unknown C++ Object in Hashtable index="
                   ,TCL_STRING (objv[1]),NULL);
  return (TCL_ERROR);
 }
 objHandle= (jWrap_Point3*)Tcl_GetHashValue (entryPtr);


 // Check param number
 if (objc != 2) goto  errorNumArg;

 // effectively call C++ function/method
 result.shared.appli =  objHandle->Point3::mag3 ();

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(double*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_double].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[5]);
  return TCL_ERROR;
 } // end method jWrap_mag35

 // jWrap need a constructor to register jTcl obj reference
 static jTcl_new (ClientData clData, Tcl_Interp *interp
           ,int objc,Tcl_Obj *CONST objv[]) {
 // tempry data for registration of CC obj handle in hashtable
 int isnew; Tcl_HashEntry *entryPtr;


 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 2) goto errorNumArg;

 // Store cc handle in hashtable with jTcl handle as key
 entryPtr = Tcl_CreateHashEntry (&jWrapHashTable ,TCL_STRING (objv[1]), &isnew);
 if (!isnew) goto errorMultiInherit; // Effectively build C++ object and store it in hashtable
 Tcl_SetHashValue (entryPtr, (ClientData) new jWrap_Point3 (interp,objv[1]));
 return TCL_OK;


 errorNumArg:
  Tcl_WrongNumArgs (interp, 1, objv, "Syntax: new Point3");
  return TCL_ERROR;

 errorMultiInherit:
  Tcl_AppendResult (interp,"jWrap cannot multi-inherit: class Point3 handle="
                   ,TCL_STRING(objv[1]),NULL);
  return TCL_ERROR;
 } // end default jTcl->C++ Point3 constructor

 // Destructor clean up c++ object
 ~jWrap_Point3 () {
   int status;
   Tcl_CmdInfo infoCmd;
   Tcl_Obj *resultPtr;
   Tcl_Obj *objv[2];

   // if called from jTcl just return
   if (jTclHandle == NULL) return;

   // Build jTcl free cmd
   objv[0] = jWrapFreeMethod;
   objv[1] = jTclHandle;

  // call jTcl free method
  if (!Tcl_GetCommandInfo (interp, TCL_STRING (jTclHandle), &infoCmd)) {
     jWrapPanic (NULL,"Unknown jTcl  object",TCL_STRING (jTclHandle));
  }
   status    = (*infoCmd.objProc) (infoCmd.objClientData, interp,2,objv);

   if (status != TCL_OK) {
     resultPtr = Tcl_GetObjResult(interp);
     jWrapPanic (NULL,TCL_STRING(resultPtr));   }

 } // end C++ destructor

 // jTcl destructor call C++ cleanup
 static int jTcl_free
 (ClientData clData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_HashEntry *entryPtr;
 jWrap_Point3 *cxxHandle;
  // prepare emergency panic return
  if (setjmp (jWrapCheckPoint)) {
     return TCL_ERROR;
  }
 // get cc object handle from jTcl object name
 entryPtr = Tcl_FindHashEntry (&jWrapHashTable
          , TCL_STRING (objv[1]));
 if (entryPtr == NULL) {
  Tcl_AppendResult (interp,"Unknown C++ Object in Hashtable handle="
                   ,TCL_STRING (objv[1]),NULL);
  return (TCL_ERROR);
 }
 cxxHandle= (jWrap_Point3*)Tcl_GetHashValue (entryPtr);

  // Clean up the place and make C++ destructor not to recall jTcl
  Tcl_DecrRefCount(cxxHandle->jTclHandle);
  cxxHandle->jTclHandle = NULL;

  //effectively destroy C++ object and jTcl reference
  delete (cxxHandle);

  return TCL_OK;
 } // end jTcl destructor

 // internal constructor register C++ handle in jTcl object
 jWrap_Point3 (Tcl_Interp *objInterp, Tcl_Obj *jTclObj)
 {
   // Store jTcl object string in C++ object
   Tcl_IncrRefCount (jTclObj);
   jTclHandle = jTclObj;
   interp     = objInterp;

   // register instance variable in Tcl interp
   jWrapVarRegister (interp, jTclHandle, "z", (long*)&z, 1 
                  , &usedType[JTYPE_double]);
 } // end internal constructor
}; // end class jWrap_Point3


/* ***  Tcl Register Section *** */
#ifdef __cplusplus
extern "C" {
#endif
RESTRICTED int Demoinherit_Init (Tcl_Interp *interp) {
 // Dont init twice
 if (initDone) return TCL_OK;
 initDone = 1;

 /* --- Build module handle & register it in jWrap --- */

 module.magic       =JWRAP_MODULE;
 module.name        ="DemoInherit";
 module.help        ="small C++ example";
 module.helpCmd     = helpCmd;
 module.nbCmd       = 6;
 module.hashTable   = NULL;
 module.version     = DemoInherit_CUSTOM_STAMP;
 module.structures  = NULL;
 module.enumerations= enumerations;
 module.info        = NULL;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   return TCL_ERROR;
 }

 // init routines user or default
#ifdef DemoInherit_CUSTOM_INIT
 DemoInherit_CUSTOM_INIT;
#else
 if (Jwrap_Init (interp) != TCL_OK) return TCL_ERROR;
#endif
 jWrapModuleRegister (interp,&module);
 jWrapEnumRegister (&module,&Define_DemoInherit_enum,&Define_DemoInherit_type);

 /* --- Used Type Section --- */

 jWrapTypeCheck (&usedType [0],"Define_DemoInherit",sizeof(Define_DemoInherit));
 jWrapTypeCheck (&usedType [1],"char_Ptr",sizeof(char *));
 jWrapTypeCheck (&usedType [2],"double",sizeof(double));
 jWrapTypeCheck (&usedType [3],"int",sizeof(int));

 /* --- Static Variable registration --- */

 jWrapVarRegister (interp, NULL, "Inherit_help", (long*)&Inherit_help, 12 
                  , &usedType[JTYPE_char_Ptr]);
 jWrapVarRegister (interp, NULL, "Inherit_help", (long*)&Inherit_help, 12 
                  , &usedType[JTYPE_char_Ptr]);

 /* --- Functions sub-section --- */

 /* --- Class sub-section --- */

 { // registering class Point1 in Tcl
 Tcl_Obj *tclClassIndex;
 Tcl_Obj *tclClassValue= Tcl_NewStringObj ("Point1",6);Tcl_IncrRefCount(tclClassValue);
 Tcl_Obj *tclCountValue= Tcl_NewIntObj(0); Tcl_IncrRefCount(tclCountValue);
 Tcl_Obj *tclClassArray= Tcl_NewStringObj ("_C_Point1",9);Tcl_IncrRefCount(tclClassArray);
 Tcl_ObjSetVar2(interp,tclClassArray,jWrapMyString,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_ObjSetVar2(interp,tclClassArray,jWrapExtendsString,tclClassValue,TCL_GLOBAL_ONLY);
 // build a reference Count mandatory for jTcl
 Tcl_ObjSetVar2 (interp,tclClassArray,jWrapInsCountString,tclCountValue,TCL_GLOBAL_ONLY);

 /* --- Static Variable registration --- */
 jWrapVarRegister (interp, tclClassArray, "count", (long*)&Point1::count, 5 
                  , &usedType[JTYPE_int]);

 // register mag C/C++ entry point as  Tcl command
 tclClassIndex= Tcl_NewStringObj ("mag",3);Tcl_IncrRefCount(tclClassIndex);
 tclClassValue= Tcl_NewStringObj ("Point1.mag",10);Tcl_IncrRefCount(tclClassValue);
 Tcl_ObjSetVar2 (interp,tclClassArray,tclClassIndex,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_CreateObjCommand (interp,TCL_STRING(tclClassValue),jWrap_Point1::jTcl_mag_0, (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);


 // register mag1 C/C++ entry point as  Tcl command
 tclClassIndex= Tcl_NewStringObj ("mag1",4);Tcl_IncrRefCount(tclClassIndex);
 tclClassValue= Tcl_NewStringObj ("Point1.mag1",11);Tcl_IncrRefCount(tclClassValue);
 Tcl_ObjSetVar2 (interp,tclClassArray,tclClassIndex,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_CreateObjCommand (interp,TCL_STRING(tclClassValue),jWrap_Point1::jTcl_mag1_1, (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);


 // registrate constructor/destructor
 Tcl_CreateObjCommand (interp,"Point1.new", jWrap_Point1::jTcl_new   , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 Tcl_CreateObjCommand (interp,"Point1.free", jWrap_Point1::jTcl_free   , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 } // end class Point1 registration

 { // registering class Point2 in Tcl
 Tcl_Obj *tclClassIndex;
 Tcl_Obj *tclClassValue= Tcl_NewStringObj ("Point2",6);Tcl_IncrRefCount(tclClassValue);
 Tcl_Obj *tclCountValue= Tcl_NewIntObj(0); Tcl_IncrRefCount(tclCountValue);
 Tcl_Obj *tclClassArray= Tcl_NewStringObj ("_C_Point2",9);Tcl_IncrRefCount(tclClassArray);
 Tcl_ObjSetVar2(interp,tclClassArray,jWrapMyString,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_ObjSetVar2(interp,tclClassArray,jWrapExtendsString,tclClassValue,TCL_GLOBAL_ONLY);
 // build a reference Count mandatory for jTcl
 Tcl_ObjSetVar2 (interp,tclClassArray,jWrapInsCountString,tclCountValue,TCL_GLOBAL_ONLY);

 /* --- Extend Class from suppers --- */
 jWrapExtendClass (interp,TCL_STRING(tclClassArray), "_C_Point1");

 /* --- Static Variable registration --- */

 // register mag C/C++ entry point as  Tcl command
 tclClassIndex= Tcl_NewStringObj ("mag",3);Tcl_IncrRefCount(tclClassIndex);
 tclClassValue= Tcl_NewStringObj ("Point2.mag",10);Tcl_IncrRefCount(tclClassValue);
 Tcl_ObjSetVar2 (interp,tclClassArray,tclClassIndex,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_CreateObjCommand (interp,TCL_STRING(tclClassValue),jWrap_Point2::jTcl_mag_2, (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);


 // register mag2 C/C++ entry point as  Tcl command
 tclClassIndex= Tcl_NewStringObj ("mag2",4);Tcl_IncrRefCount(tclClassIndex);
 tclClassValue= Tcl_NewStringObj ("Point2.mag2",11);Tcl_IncrRefCount(tclClassValue);
 Tcl_ObjSetVar2 (interp,tclClassArray,tclClassIndex,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_CreateObjCommand (interp,TCL_STRING(tclClassValue),jWrap_Point2::jTcl_mag2_3, (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);


 // registrate constructor/destructor
 Tcl_CreateObjCommand (interp,"Point2.new", jWrap_Point2::jTcl_new   , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 Tcl_CreateObjCommand (interp,"Point2.free", jWrap_Point2::jTcl_free   , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 } // end class Point2 registration

 { // registering class Point3 in Tcl
 Tcl_Obj *tclClassIndex;
 Tcl_Obj *tclClassValue= Tcl_NewStringObj ("Point3",6);Tcl_IncrRefCount(tclClassValue);
 Tcl_Obj *tclCountValue= Tcl_NewIntObj(0); Tcl_IncrRefCount(tclCountValue);
 Tcl_Obj *tclClassArray= Tcl_NewStringObj ("_C_Point3",9);Tcl_IncrRefCount(tclClassArray);
 Tcl_ObjSetVar2(interp,tclClassArray,jWrapMyString,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_ObjSetVar2(interp,tclClassArray,jWrapExtendsString,tclClassValue,TCL_GLOBAL_ONLY);
 // build a reference Count mandatory for jTcl
 Tcl_ObjSetVar2 (interp,tclClassArray,jWrapInsCountString,tclCountValue,TCL_GLOBAL_ONLY);

 /* --- Extend Class from suppers --- */
 jWrapExtendClass (interp,TCL_STRING(tclClassArray), "_C_Point2");

 /* --- Static Variable registration --- */

 // register mag C/C++ entry point as  Tcl command
 tclClassIndex= Tcl_NewStringObj ("mag",3);Tcl_IncrRefCount(tclClassIndex);
 tclClassValue= Tcl_NewStringObj ("Point3.mag",10);Tcl_IncrRefCount(tclClassValue);
 Tcl_ObjSetVar2 (interp,tclClassArray,tclClassIndex,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_CreateObjCommand (interp,TCL_STRING(tclClassValue),jWrap_Point3::jTcl_mag_4, (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);


 // register mag3 C/C++ entry point as  Tcl command
 tclClassIndex= Tcl_NewStringObj ("mag3",4);Tcl_IncrRefCount(tclClassIndex);
 tclClassValue= Tcl_NewStringObj ("Point3.mag3",11);Tcl_IncrRefCount(tclClassValue);
 Tcl_ObjSetVar2 (interp,tclClassArray,tclClassIndex,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_CreateObjCommand (interp,TCL_STRING(tclClassValue),jWrap_Point3::jTcl_mag3_5, (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);


 // registrate constructor/destructor
 Tcl_CreateObjCommand (interp,"Point3.new", jWrap_Point3::jTcl_new   , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 Tcl_CreateObjCommand (interp,"Point3.free", jWrap_Point3::jTcl_free   , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 } // end class Point3 registration
 return TCL_OK;
} // end function DemoInherit_Init
#ifdef __cplusplus
}
#endif

// ------------------ end funcDemoInherit_jWrap.cxx ----------------------
