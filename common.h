#ifndef __HEADER_SMOLFUZZ_COMMON__
#define __HEADER_SMOLFUZZ_COMMON__

#ifdef __cplusplus
    #define EXTERN_C_START extern "C" {
    #define EXTERN_C_END }
#else
    #define EXTERN_C_START
    #define EXTERN_C_END
#endif

typedef char                i8;
typedef unsigned char       u8;
typedef short               i16;
typedef unsigned short      u16;
typedef int                 i32, bool_c;
typedef unsigned int        u32;
typedef long long           i64;
typedef unsigned long long  u64;

typedef unsigned long       size;
typedef long                ssize;

#define _cast(type, value) \
    ((type)(value))

#define FALSE_C 0
#define TRUE_C  1

#endif