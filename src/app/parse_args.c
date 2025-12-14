#include <stdio.h>
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
                fprintf(stderr, "Missing N after %s\n", argv[i]);
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
        else if (strcmp(argv[i], "--asc") == 0) {
            args.dir = ASC;
        }
        else if (strcmp(argv[i], "--desc") == 0) {
            args.dir = DESC;
        }
        else if (strcmp(argv[i], "--quick") == 0) {
            args.alg = SORT_QUICK;
        }
        else if (strcmp(argv[i], "--comb") == 0) {
            args.alg = SORT_COMB;
        }
        else if (strcmp(argv[i], "--in") == 0 || strcmp(argv[i], "-i") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "Missing filename after %s\n", argv[i]);
                exit(1);
            }
            args.in_file = argv[++i];
        }
        else if (strcmp(argv[i], "--out") == 0 || strcmp(argv[i], "-o") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "Missing filename after %s\n", argv[i]);
                exit(1);
            }
            args.out_file = argv[++i];
        }
        else {
            fprintf(stderr, "Unknown argument: %s\n", argv[i]);
            exit(1);
        }
    }

    if (args.mode == MODE_NONE) {
        fprintf(stderr, "No mode specified (--generate / --sort / --print)\n");
        exit(1);
    }

    return args;
}