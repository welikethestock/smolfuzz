#include "fuzz.h"
#include <stdio.h>  

u32 check_code(u32 code)
{
    return (code == 79285) ? code : 0;
}

void code_bruteforced(fuzz_call_return_value_t return_value, fuzz_call_description_t *call_description)
{
    printf("code bruteforced: %d (%d)\n", return_value._32, call_description->last_args[0]);
}

u8 check_char(char c)
{
    return c == '?' ? '+' : '-';  
}

void plus_encountered(fuzz_call_return_value_t return_value, fuzz_call_description_t *call_description)
{
    printf("plus encountered (%d)\n", call_description->last_args[0]);
}

DEFINE_FUZZ_TARGETS(
    fuzz_test,
    DEFINE_FUZZ_TARGET(
        check_code,
        100000,
        FUZZ_CALL_CDECL,
        fuzz_call_return_value_eq(79285),
        code_bruteforced,
        1,
        fuzz_call_arg(
            FUZZ_CALL_ARG_U32,
            FALSE_C,
            fuzz_arg_step(1, -1, FALSE_C)
        )
    ),
    DEFINE_FUZZ_TARGET(
        check_char,
        1000,
        FUZZ_CALL_CDECL,
        fuzz_call_return_value_neq('-'),
        plus_encountered,
        1,
        fuzz_call_arg(
            FUZZ_CALL_ARG_U8,
            FALSE_C,
            fuzz_arg_min_max(0, 255, FALSE_C)
        )
    )
);

int main()
{
    FUZZ_TARGETS(fuzz_test);

    return 0;
}