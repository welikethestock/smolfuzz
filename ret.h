#ifndef __HEADER_FUZZ_RET__
#define __HEADER_FUZZ_RET__

#include "common.h"

EXTERN_C_START

typedef union
{
    u8  _8;
    u16 _16;
    u32 _32;
    u64 _64;
} fuzz_call_return_value_t;

typedef enum
{
    FUZZ_CALL_RETURN_VAL_NO_CHECK = 0,
    FUZZ_CALL_RETURN_VAL_EQ,
    FUZZ_CALL_RETURN_VAL_NEQ,
    FUZZ_CALL_RETURN_VAL_LESS_THAN,
    FUZZ_CALL_RETURN_VAL_GREATER_THAN,
    FUZZ_CALL_RETURN_VAL_LESS_THAN_EQ,
    FUZZ_CALL_RETURN_VAL_GREATER_THAN_EQ,
    FUZZ_CALL_RETURN_VAL_MIN_MAX,
    FUZZ_CALL_RETURN_VAL_CUSTOM
} fuzz_call_return_value_type_t;

typedef bool_c(*fuzz_call_return_value_check_fn)(fuzz_call_return_value_t return_value, struct fuzz_call_description_t *call_description);
typedef struct fuzz_call_return_value_description_t
{
    union
    {
        fuzz_call_return_value_t        eq;
        fuzz_call_return_value_t        neq;
        fuzz_call_return_value_t        less_than;
        fuzz_call_return_value_t        greater_than;
        fuzz_call_return_value_t        less_eq;
        fuzz_call_return_value_t        greater_eq;
        fuzz_call_return_value_check_fn custom;

        union
        {
            u64         _64[2];
        } min_max;
    };
    struct
    {
        u8              type : 4;
    };
} fuzz_call_return_value_description_t;

#define fuzz_call_return_value_eq(val) \
    { .eq = { ._64 = _cast(u64, val) & 0xFFFFFFFFFFFFFFFF }, .type = FUZZ_CALL_RETURN_VAL_EQ }

#define fuzz_call_return_value_neq(val) \
    { .neq = { ._64 = _cast(u64, val) & 0xFFFFFFFFFFFFFFFF }, .type = FUZZ_CALL_RETURN_VAL_NEQ }

#define fuzz_call_return_value_less_than(val) \
    { .less_than = { ._64 = _cast(u64, val) & 0xFFFFFFFFFFFFFFFF }, .type = FUZZ_CALL_RETURN_VAL_LESS_THAN }

#define fuzz_call_return_value_greater_than(val) \
    { .greater_than = { ._64 = _cast(u64, val) & 0xFFFFFFFFFFFFFFFF }, .type = FUZZ_CALL_RETURN_VAL_GREATER_THAN }

#define fuzz_call_return_value_less_than_eq(val) \
    { .less_than = { ._64 = _cast(u64, val) & 0xFFFFFFFFFFFFFFFF }, .type = FUZZ_CALL_RETURN_VAL_LESS_THAN_EQ }

#define fuzz_call_return_value_greater_than_eq(val) \
    { .greater_than = { ._64 = _cast(u64, val) & 0xFFFFFFFFFFFFFFFF }, .type = FUZZ_CALL_RETURN_VAL_GREATER_THAN_EQ }

#define fuzz_call_return_value_min_max(min, max) \
    { .min_max = { ._64 = { _cast(u64, min) & 0xFFFFFFFFFFFFFFFF, _cast(u64, max) & 0xFFFFFFFFFFFFFFFF } }, .type = FUZZ_CALL_RETURN_VAL_MIN_MAX }

#define fuzz_call_return_value_custom(func) \
    { .custom = func, .type = FUZZ_CALL_RETURN_VAL_CUSTOM }

EXTERN_C_END

#endif