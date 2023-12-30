#ifndef __HEADER_SMOLFUZZ_COMMON__
#define __HEADER_SMOLFUZZ_COMMON__

#ifdef __cplusplus
    #define EXTERN_C_START extern "C" {
    #define EXTERN_C_END }
#else
    #define EXTERN_C_START
    #define EXTERN_C_END
#endif

#ifndef SMOLLFUZ_NO_TYPES
#define i8      char
#define u8      unsigned char
#define i16     short 
#define u16     unsigned short
#define i32     int
#define u32     unsigned int
#define i64     long long
#define u64     unsigned long long
#define bool_c  i32
#define size    unsigned long
#define ssize   long

#define FALSE_C 0
#define TRUE_C  1
#endif

#define _cast(type, value) \
    ((type)(value))

#endif