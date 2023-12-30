#include "ret.h"
#include "call.h"

bool_c fuzz_call_check_result(struct fuzz_call_description_t *call_description, fuzz_call_return_value_t result)
{
    switch(call_description->return_val_description.type)
    {
        case FUZZ_CALL_RETURN_VAL_EQ:
        {
            return (result._64 == call_description->return_val_description.eq._64);
        }

        case FUZZ_CALL_RETURN_VAL_NEQ:
        {
            return (result._64 != call_description->return_val_description.neq._64);
        }

        case FUZZ_CALL_RETURN_VAL_LESS_THAN:
        {
            return (result._64 < call_description->return_val_description.less_than._64);
        }

        case FUZZ_CALL_RETURN_VAL_GREATER_THAN:
        {
            return (result._64 > call_description->return_val_description.greater_than._64);
        }

        case FUZZ_CALL_RETURN_VAL_LESS_THAN_EQ:
        {
            return (result._64 <= call_description->return_val_description.less_eq._64);
        }

        case FUZZ_CALL_RETURN_VAL_GREATER_THAN_EQ:
        {
            return (result._64 >= call_description->return_val_description.greater_eq._64);
        }

        case FUZZ_CALL_RETURN_VAL_MIN_MAX:
        {
            if(
                result._64 < call_description->return_val_description.min_max._64[0] || 
                result._64 > call_description->return_val_description.min_max._64[1]
            )
            {
                return FALSE_C;
            }

            return TRUE_C;
        }

        case FUZZ_CALL_RETURN_VAL_CUSTOM:
        {
            return call_description->return_val_description.custom(result, call_description);
        }
    }
    
    return FALSE_C;
}