#include "arg.h"

u8 fuzz_arg_u8(fuzz_arg_state_t *state, fuzz_arg_options_t options)
{
    return fuzz_arg_u16(state, options) & 0xFF;
}

u16 fuzz_arg_u16(fuzz_arg_state_t *state, fuzz_arg_options_t options)
{
    return fuzz_arg_u32(state, options) & 0xFFFF;
}

u32 fuzz_arg_u32(fuzz_arg_state_t *state, fuzz_arg_options_t options)
{
    return fuzz_arg_u64(state, options) & 0xFFFFFFFF;
}

#ifndef fuzz_random_func
#include <immintrin.h>
#define fuzz_random_func _rdrand64_step
#else
extern
int fuzz_random_func(unsigned long long *);
#endif

u64 fuzz_arg_u64(fuzz_arg_state_t *state, fuzz_arg_options_t options)
{
    u64 rand;
    for(; fuzz_random_func(&rand) != 1;);

    switch(options.type)
    {
        case 1: // min, max
        {
            u64 min, max;
            min = options.min_max._64[0];
            max = options.min_max._64[1];

            return min + (rand % ((max + 1) - min));
        }

        case 2:
        {
            u64 ret = state->counter & 0xFFFFFFFFFFFFFFFF;
            state->counter += options.step_size;

            return ret;
        }

        case 3:
        {
            u64 ret = state->counter & 0xFFFFFFFFFFFFFFFF;
            state->counter += options.step_size;

            return ret % options.min_max._64[0];
        }
        
        default:
        {
            break;
        }
    }

    return rand;
}