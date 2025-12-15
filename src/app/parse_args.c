#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "modes.h"

args_t parse_args(int argc, char **argv) {
    args_t args = {
        .mode = MODE_NONE,
        .dir = ASC,
        .alg = SORT_QUICK,
        .in_file = NULL,
        .out_file = NULL,
        .generate_n = 0
    };

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--generate") == 0 || strcmp(argv[i], "-g") == 0) {
            if (i + 1 >= argc) {
                exit(1);
            }
            args.mode = MODE_GENERATE;
            args.generate_n = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "--sort") == 0 || strcmp(argv[i], "-s") == 0) {
            args.mode = MODE_SORT;
        }
        else if (strcmp(argv[i], "--print") == 0 || strcmp(argv[i], "-P") == 0) {
            args.mode = MODE_PRINT;
        }
        else if (strcmp(argv[i], "--type=asc") == 0) {
            args.dir = ASC;
        }
        else if (strcmp(argv[i], "--type=desc") == 0) {
            args.dir = DESC;
        }
        else if (strcmp(argv[i], "--quick") == 0) {
            args.alg = SORT_QUICK;
        }
        else if (strcmp(argv[i], "--comb") == 0) {
            args.alg = SORT_COMB;
        }
        else if (strcmp(argv[i], "-i") == 0) {
            if (i + 1 >= argc) {
                exit(1);
            }
            args.in_file = argv[++i];
        }
        else if (strncmp(argv[i], "--in=", 5) == 0) {
            args.in_file = argv[i] + 5;
        }
        else if (strcmp(argv[i], "-o") == 0) {
            if (i + 1 >= argc) {
                exit(1);
            }
            args.out_file = argv[++i];
        }
        else if (strncmp(argv[i], "--out=", 6) == 0) {
            args.out_file = argv[i] + 6;
        }
        else {
            exit(1);
        }
    }

    if (args.mode == MODE_NONE) {
        exit(1);
    }

    return args;
}