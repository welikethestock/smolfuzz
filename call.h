#ifndef __HEADER_FUZZ_CALL__
#define __HEADER_FUZZ_CALL__

#include "common.h"
#include "arg.h"
#include "ret.h"

EXTERN_C_START

typedef struct
{
    fuzz_call_arg_type_t    type;
    struct
    {
        u8                      as_ptr : 1;
    };
    fuzz_arg_options_t      options;
    fuzz_arg_state_t        state;
} fuzz_call_arg_t;

#define fuzz_call_arg(_type, _as_ptr, _options) \
    { .type = _type, .as_ptr = _as_ptr, .options = _options, .state = fuzz_arg_state(0, 0) }

typedef enum
{
    FUZZ_CALL_CDECL = 0,
    FUZZ_CALL_STDCALL,
    FUZZ_CALL_FASTCALL,
    FUZZ_CALL_THISCALL
} fuzz_call_convention;

typedef void(*fuzz_callback_fn)(fuzz_call_return_value_t return_value, struct fuzz_call_description_t *call_description);

typedef struct fuzz_call_description_t
{
    void                                    *func;
    const char                              *func_name;
    u32                                     arg_count;
    u32                                     repetitons;
    fuzz_call_arg_t                         args[0x10];
    struct
    {
        u8                                      calling_con : 2;
    };
    fuzz_call_return_value_description_t    return_val_description;
    fuzz_callback_fn                        callback;
    size                                    last_args[8];
} fuzz_call_description_t;

#define fuzz_call_description(_func, _repetitons, _calling_con, _return_val_description, _callback, _arg_count, ...) \
    { \
        .func = _cast(void *, _func), \
        .func_name = #_func, \
        .arg_count = _arg_count, \
        .repetitons = _repetitons, \
        .args = { __VA_ARGS__ }, \
        .calling_con = _calling_con, \
        .return_val_description = _return_val_description, \
        .callback = _callback, \
        .last_args = { 0 } \
    }

extern
fuzz_call_return_value_t fuzz_perform_call(void *function, fuzz_call_description_t *description);

extern
bool_c fuzz_call_check_result(fuzz_call_description_t *call_description, fuzz_call_return_value_t result);

#define fuzz_perform_calls(description) \
    for(; (description)->repetitons != 0; --(description)->repetitons) \
    { \
        fuzz_call_return_value_t ret_value = fuzz_perform_call((description)->func, description); \
        if(fuzz_call_check_result(description, ret_value) && (description)->callback != NULL) \
        { \
            (description)->callback(ret_value, (description)); \
        } \
    }

EXTERN_C_END

#endif