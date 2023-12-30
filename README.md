noteworthy:

0 dependencies (including any c runtime libs) aslong as you define fuzz_random_func
 

ai gen summary:

# Overview

## Fuzz targets

A fuzz target is a function that you want to test. In test.c, two fuzz targets are provided as examples:

- `check_code`: This function takes a u32 input and returns it if it equals 79285, otherwise it returns 0.
- `check_char`: This function takes a char input and returns '+' if it equals '?', otherwise it returns '-'.

### How to create a fuzz target

[Here](https://github.com/welikethestock/smolfuzz/blob/master/test.c#L24), two fuzzing targets are defined using the DEFINE_FUZZ_TARGET macro:

1. check_code: This function is tested with a range of inputs. The second argument 100000 is the number of tests to run. The FUZZ_CALL_CDECL is the calling convention of the function. The [fuzz_call_return_value_eq(79285)](https://github.com/welikethestock/smolfuzz/blob/master/test.c#L30) is the condition for a successful test (the function should return 79285). If the condition is met, the code_bruteforced function is called. The 1 is the number of arguments the function takes, and the fuzz_call_arg macro defines the type and range of the argument.

2. check_char: Similar to check_code, but this function checks a character. The condition for a successful test is that the function should not return -. If the condition is met, the plus_encountered function is called.

The DEFINE_FUZZ_TARGETS macro is used to group these fuzzing targets together under the name fuzz_test.

In the main function, FUZZ_TARGETS(fuzz_test) is called to start the fuzzing process for the defined targets.

### Specifying argument characteristics when creating a fuzz target

See [here](https://github.com/welikethestock/smolfuzz/blob/master/test.c#L32)

1. fuzz_arg_random(_as_ptr): This macro creates a fuzz_arg_options_t structure where the type field is set to 0, indicating that the argument should be generated randomly. The _as_ptr parameter determines whether the argument should be treated as a pointer.

2. fuzz_arg_min_max(min, max, _as_ptr): This macro creates a fuzz_arg_options_t structure where the type field is set to 1, indicating that the argument should be a random value between min and max. The _as_ptr parameter determines whether the argument should be treated as a pointer.

3. fuzz_arg_step(_step_size, _max, _as_ptr): This macro creates a fuzz_arg_options_t structure where the type field is set to 2, indicating that the argument should be generated by incrementing a counter by _step_size. The _max parameter is used as the initial value of the counter. The _as_ptr parameter determines whether the argument should be treated as a pointer.