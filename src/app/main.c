#include <stdio.h>
#include <stdlib.h>
#include "parse_args.h"
#include "generate.h"
#include <stdint.h>
#include "io.h"
#include "comparator.h"
#include "sort.h"

int main(int argc, char** argv) {
    args_t args = parse_args(argc, argv);

    if (args.mode == 1) {
        vector *vec = generate(args.generate_n);

        if(args.out_file != NULL) {
            FILE *out = fopen(args.out_file, "w");
            if (!out) exit(1);

            out_houses(out, vec);

            fclose(out);
        } else {
            out_houses(stdout, vec);
        }
        free_vector(vec);
    } else if(args.mode == 2) {
        vector *vec = NULL;
        if(args.in_file != NULL) {
            FILE *in = fopen(args.in_file, "r");
            if (!in) {
                exit(1);
            }

            vec = in_houses(in);
            fclose(in);
        } else {
            vec = in_houses(stdin);
        }

        if (!vec || get_vector_size(vec) == 0) {
            exit(1);
        }

        if (args.alg == SORT_COMB) {
            comb_sort(vec, house_comp, args.dir);
        } else {
            q_sort(vec, house_comp, args.dir);
        }

        if(args.out_file != NULL) {
            FILE *out = fopen(args.out_file, "w");
            if (!out) exit(1);

            out_houses(out, vec);

            fclose(out);
        } else {
            out_houses(stdout, vec);
        }

        free_vector(vec);
    } else if(args.mode == 3) {
        vector *vec = NULL;
        if(args.in_file != NULL) {
            FILE *in = fopen(args.in_file, "r");
            if (!in) {
                exit(1);
            }

            vec = in_houses(in);
            fclose(in);
        } else {
            vec = in_houses(stdin);
        }

        if (!vec || get_vector_size(vec) == 0) {
            exit(1);
        }

        if(args.out_file != NULL) {
            FILE *out = fopen(args.out_file, "w");
            if (!out) exit(1);

            out_houses_table(out, vec);

            fclose(out);
        } else {
            out_houses_table(stdout, vec);
        }
        free_vector(vec);
    }

    return 0;
}