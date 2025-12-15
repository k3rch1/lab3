#pragma once
#include "boolean.h"
#include "stdint.h"

typedef enum program_mode {
    MODE_NONE,
    MODE_GENERATE,
    MODE_SORT,
    MODE_PRINT
} program_mode;

typedef enum sort_alg {
    SORT_COMB,
    SORT_QUICK
} sort_alg;

typedef struct args_t {
    program_mode mode;
    sort_direction dir;
    sort_alg alg;

    const char *in_file;
    const char *out_file;

    uint32_t generate_n;
} args_t;