#include <stdio.h>
#include <stdlib.h>
#include "parse_args.h"
#include "generate.h"
#include <stdint.h>
#include "in_houses.h"
#include "out_houses.h"
#include "houses_table.h"
#include "io.h"
#include "comparator.h"
#include "sort.h"

int main(int argc, char** argv) {
    args_t args = parse_args(argc, argv);

    if (args.mode == 1) {
        vector *vec = generate(args.generate_n);

        if(args.out_file != NULL) {
            FILE *out = open_out(args.out_file);
            if (!out) exit(1);

            write_houses_csv(out, vec);

            close_file(out);
        } else {
            print_houses(vec);
        }
        free_vector(vec);
    } else if(args.mode == 2) {
        vector *vec = NULL;
        if(args.in_file != NULL) {
            FILE *in = open_in(args.in_file);
            if (!in) {
                exit(1);
            }

            vec = read_houses_csv(in);
            close_file(in);
        } else {
            vec = read_houses_from_stdin();
        }

        if (!vec || get_vector_size(vec) == 0) {
            exit(1);
        }

        if (args.alg == SORT_COMB) {
            comb_sort(vec, house_comp_year, args.dir);
        } else {
            q_sort(vec, house_comp_year, args.dir);
        }

        if(args.out_file != NULL) {
            FILE *out = open_out(args.out_file);
            if (!out) exit(1);

            write_houses_csv(out, vec);

            close_file(out);
        } else {
            print_houses(vec);
        }

        free_vector(vec);
    } else if(args.mode == 3) {
        vector *vec = NULL;
        if(args.in_file != NULL) {
            FILE *in = fopen(args.in_file, "r");
            if (!in) {
                exit(1);
            }

            vec = read_houses_csv(in);
            close_file(in);
        } else {
            vec = read_houses_from_stdin();
        }

        if (!vec || get_vector_size(vec) == 0) {
            exit(1);
        }

        if(args.out_file != NULL) {
            FILE *out = open_out(args.out_file);
            if (!out) exit(1);

            print_houses_table_csv(out, vec);

            close_file(out);
        } else {
            print_houses_table_stdout(vec);
        }
        free_vector(vec);
    }

    return 0;
}