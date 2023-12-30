#include "ret.h"

bool_c fuzz_call_check_result(fuzz_call_return_value_description_t *ret_val_desc, fuzz_call_return_value_t result)
{
    switch(ret_val_desc->type)
    {
        case FUZZ_CALL_RETURN_VAL_EQ:
        {
            return (result._64 == ret_val_desc->eq._64);
        }

        case FUZZ_CALL_RETURN_VAL_NEQ:
        {
            return (result._64 != ret_val_desc->neq._64);
        }

        case FUZZ_CALL_RETURN_VAL_LESS_THAN:
        {
            return (result._64 < ret_val_desc->less_than._64);
        }

        case FUZZ_CALL_RETURN_VAL_GREATER_THAN:
        {
            return (result._64 > ret_val_desc->greater_than._64);
        }

        case FUZZ_CALL_RETURN_VAL_LESS_THAN_EQ:
        {
            return (result._64 <= ret_val_desc->less_eq._64);
        }

        case FUZZ_CALL_RETURN_VAL_GREATER_THAN_EQ:
        {
            return (result._64 >= ret_val_desc->greater_eq._64);
        }

        case FUZZ_CALL_RETURN_VAL_MIN_MAX:
        {
            if(result._64 < ret_val_desc->min_max._64[0] || result._64 > ret_val_desc->min_max._64[1])
            {
                return FALSE_C;
            }

            return TRUE_C;
        }

        case FUZZ_CALL_RETURN_VAL_CUSTOM:
        {
            return ret_val_desc->custom(result, ret_val_desc);
        }
    }
    
    return FALSE_C;
}