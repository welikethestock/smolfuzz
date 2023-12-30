#include "call.h"

typedef size(*fuzz_call_args0_cdecl)();
typedef size(*fuzz_call_args1_cdecl)(size a1);
typedef size(*fuzz_call_args2_cdecl)(size a1, size a2);
typedef size(*fuzz_call_args3_cdecl)(size a1, size a2, size a3);
typedef size(*fuzz_call_args4_cdecl)(size a1, size a2, size a3, size a4);
typedef size(*fuzz_call_args5_cdecl)(size a1, size a2, size a3, size a4, size a5);
typedef size(*fuzz_call_args6_cdecl)(size a1, size a2, size a3, size a4, size a5, size a6);
typedef size(*fuzz_call_args7_cdecl)(size a1, size a2, size a3, size a4, size a5, size a6, size a7);
typedef size(*fuzz_call_args8_cdecl)(size a1, size a2, size a3, size a4, size a5, size a6, size a7, size a8);

#define _arg(arg, options) \
    (options.as_ptr) ? _cast(size, &arg) : _cast(size, ((arg) & ((size)(-1))))

fuzz_call_return_value_t fuzz_perform_call(void *function, fuzz_call_description_t *description)
{
    switch(description->arg_count)
    {
        case 0:
        {
            fuzz_call_return_value_t ret;
            ret._64 = _cast(
                u64, 
                _cast(fuzz_call_args0_cdecl, function)()
            ) & _cast(u64, -1);

            return ret;
        }

        case 1:
        {
            u64 a1 = fuzz_arg_u64(&description->args[0].state, description->args[0].options);

            fuzz_call_return_value_t ret;
            ret._64 = _cast(
                u64, 
                _cast(fuzz_call_args1_cdecl, function)(
                    _arg(a1, description->args[0].options)
                )
            ) & _cast(u64, -1);

            return ret;
        }

        case 2:
        {
            u64 a1 = fuzz_arg_u64(&description->args[0].state, description->args[0].options);
            u64 a2 = fuzz_arg_u64(&description->args[1].state, description->args[1].options);

            fuzz_call_return_value_t ret;
            ret._64 = _cast(
                u64, 
                _cast(fuzz_call_args2_cdecl, function)(
                    _arg(a1, description->args[0].options), 
                    _arg(a2, description->args[1].options)
                )
            ) & _cast(u64, -1);

            return ret;
        }

        case 3:
        {
            u64 a1 = fuzz_arg_u64(&description->args[0].state, description->args[0].options);
            u64 a2 = fuzz_arg_u64(&description->args[1].state, description->args[1].options);
            u64 a3 = fuzz_arg_u64(&description->args[2].state, description->args[2].options);

            fuzz_call_return_value_t ret;
            ret._64 = _cast(
                u64, 
                _cast(fuzz_call_args3_cdecl, function)(
                    _arg(a1, description->args[0].options), 
                    _arg(a2, description->args[1].options), 
                    _arg(a3, description->args[2].options)
                )
            ) & _cast(u64, -1);

            return ret;
        }

        case 4:
        {
            u64 a1 = fuzz_arg_u64(&description->args[0].state, description->args[0].options);
            u64 a2 = fuzz_arg_u64(&description->args[1].state, description->args[1].options);
            u64 a3 = fuzz_arg_u64(&description->args[2].state, description->args[2].options);
            u64 a4 = fuzz_arg_u64(&description->args[3].state, description->args[3].options);

            fuzz_call_return_value_t ret;
            ret._64 = _cast(
                u64, 
                _cast(fuzz_call_args4_cdecl, function)(
                    _arg(a1, description->args[0].options), 
                    _arg(a2, description->args[1].options), 
                    _arg(a3, description->args[2].options),
                    _arg(a4, description->args[3].options)
                )
            ) & _cast(u64, -1);

            return ret;
        }

        case 5:
        {
            u64 a1 = fuzz_arg_u64(&description->args[0].state, description->args[0].options);
            u64 a2 = fuzz_arg_u64(&description->args[1].state, description->args[1].options);
            u64 a3 = fuzz_arg_u64(&description->args[2].state, description->args[2].options);
            u64 a4 = fuzz_arg_u64(&description->args[3].state, description->args[3].options);
            u64 a5 = fuzz_arg_u64(&description->args[4].state, description->args[4].options);

            fuzz_call_return_value_t ret;
            ret._64 = _cast(
                u64, 
                _cast(fuzz_call_args5_cdecl, function)(
                    _arg(a1, description->args[0].options), 
                    _arg(a2, description->args[1].options), 
                    _arg(a3, description->args[2].options),
                    _arg(a4, description->args[3].options),
                    _arg(a5, description->args[4].options)
                )
            ) & _cast(u64, -1);

            return ret;
        }

        case 6:
        {
            u64 a1 = fuzz_arg_u64(&description->args[0].state, description->args[0].options);
            u64 a2 = fuzz_arg_u64(&description->args[1].state, description->args[1].options);
            u64 a3 = fuzz_arg_u64(&description->args[2].state, description->args[2].options);
            u64 a4 = fuzz_arg_u64(&description->args[3].state, description->args[3].options);
            u64 a5 = fuzz_arg_u64(&description->args[4].state, description->args[4].options);
            u64 a6 = fuzz_arg_u64(&description->args[5].state, description->args[5].options);

            fuzz_call_return_value_t ret;
            ret._64 = _cast(
                u64, 
                _cast(fuzz_call_args6_cdecl, function)(
                    _arg(a1, description->args[0].options), 
                    _arg(a2, description->args[1].options), 
                    _arg(a3, description->args[2].options),
                    _arg(a4, description->args[3].options),
                    _arg(a5, description->args[4].options),
                    _arg(a6, description->args[5].options)
                )
            ) & _cast(u64, -1);

            return ret;
        }

        case 7:
        {
            u64 a1 = fuzz_arg_u64(&description->args[0].state, description->args[0].options);
            u64 a2 = fuzz_arg_u64(&description->args[1].state, description->args[1].options);
            u64 a3 = fuzz_arg_u64(&description->args[2].state, description->args[2].options);
            u64 a4 = fuzz_arg_u64(&description->args[3].state, description->args[3].options);
            u64 a5 = fuzz_arg_u64(&description->args[4].state, description->args[4].options);
            u64 a6 = fuzz_arg_u64(&description->args[5].state, description->args[5].options);
            u64 a7 = fuzz_arg_u64(&description->args[6].state, description->args[6].options);

            fuzz_call_return_value_t ret;
            ret._64 = _cast(
                u64, 
                _cast(fuzz_call_args7_cdecl, function)(
                    _arg(a1, description->args[0].options), 
                    _arg(a2, description->args[1].options), 
                    _arg(a3, description->args[2].options),
                    _arg(a4, description->args[3].options),
                    _arg(a5, description->args[4].options),
                    _arg(a6, description->args[5].options),
                    _arg(a7, description->args[6].options)
                )
            ) & _cast(u64, -1);

            return ret;
        }

        case 8:
        {
            u64 a1 = fuzz_arg_u64(&description->args[0].state, description->args[0].options);
            u64 a2 = fuzz_arg_u64(&description->args[1].state, description->args[1].options);
            u64 a3 = fuzz_arg_u64(&description->args[2].state, description->args[2].options);
            u64 a4 = fuzz_arg_u64(&description->args[3].state, description->args[3].options);
            u64 a5 = fuzz_arg_u64(&description->args[4].state, description->args[4].options);
            u64 a6 = fuzz_arg_u64(&description->args[5].state, description->args[5].options);
            u64 a7 = fuzz_arg_u64(&description->args[6].state, description->args[6].options);
            u64 a8 = fuzz_arg_u64(&description->args[7].state, description->args[7].options);

            fuzz_call_return_value_t ret;
            ret._64 = _cast(
                u64, 
                _cast(fuzz_call_args8_cdecl, function)(
                    _arg(a1, description->args[0].options), 
                    _arg(a2, description->args[1].options), 
                    _arg(a3, description->args[2].options),
                    _arg(a4, description->args[3].options),
                    _arg(a5, description->args[4].options),
                    _arg(a6, description->args[5].options),
                    _arg(a7, description->args[6].options),
                    _arg(a8, description->args[7].options)
                )
            ) & _cast(u64, -1);

            return ret;
        }
    }
}