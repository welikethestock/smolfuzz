#ifndef __HEADER_SMOLFUZZ_FUZZ__
#define __HEADER_SMOLFUZZ_FUZZ__

#include "common.h"
#include "arg.h"
#include "call.h"

#define DEFINE_FUZZ_TARGETS(targets_name, ...) \
    static fuzz_call_description_t targets_name[] = \
    { \
       __VA_ARGS__ \
    }

#define DEFINE_FUZZ_TARGET fuzz_call_description

#define FUZZ_TARGETS(targets_name) \
    for(size index = 0; index < sizeof(targets_name) / sizeof(targets_name[0]); ++index) \
    { \
        fuzz_perform_calls(&targets_name[index]); \
    }

#endif