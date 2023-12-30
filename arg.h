#ifndef __HEADER_FUZZ_ARG__
#define __HEADER_FUZZ_ARG__

#include "common.h"

EXTERN_C_START

typedef struct
{
    u64     counter;
    u32     random_seed;
} fuzz_arg_state_t;

#define fuzz_arg_state(_counter, _random_seed) \
    { .counter = _counter, .random_seed = _random_seed }

typedef struct
{
    union
    {
        u64         _64[2];
    } min_max;
    size    step_size;
    struct
    {
        u8      type    : 2; // 0 = random, 1 = random (min, max), 2 = counter + step_size, 3 = (counter + step_size) % max
        u8      as_ptr  : 1;
    };
} fuzz_arg_options_t;

#define fuzz_arg_random(_as_ptr) \
    { .min_max = { ._64 = { 0, 0 } }, .step_size = 0, .type = 0, .as_ptr = _as_ptr }

#define fuzz_arg_min_max(min, max, _as_ptr) \
    { .min_max = { ._64 = { (min) & 0xFFFFFFFFFFFFFFFF, (max) & 0xFFFFFFFFFFFFFFFF } }, .type = 1, .as_ptr = _as_ptr }

#define fuzz_arg_step(_step_size, _max, _as_ptr) \
    { .min_max = { ._64 = { (_max) & 0xFFFFFFFFFFFFFFFF, 0 } }, .step_size = _step_size, .type = 2, .as_ptr = _as_ptr }

extern
u8  fuzz_arg_u8(fuzz_arg_state_t *state, fuzz_arg_options_t options);

extern
u16 fuzz_arg_u16(fuzz_arg_state_t *state, fuzz_arg_options_t options);

extern
u32 fuzz_arg_u32(fuzz_arg_state_t *state, fuzz_arg_options_t options);

extern
u64 fuzz_arg_u64(fuzz_arg_state_t *state, fuzz_arg_options_t options);

EXTERN_C_END

#endif