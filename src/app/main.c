#include <stdio.h>
#include <stdlib.h>
#include "parse_args.h"
#include "generate.h"
#include <stdint.h>
#include "out_houses.h"
#include "io.h"

int main(int argc, char** argv) {
    args_t args = parse_args(argc, argv);

    if (args.mode == 1) {
        vector *vec = generate(args.generate_n);

        if(args.out_file != NULL) {
            FILE *out = open_out(args.out_file);
            if (!out) exit(1);

            write_houses_csv(out, vec);

            close_out(out);
            free_vector(vec);
        } else {
            print_houses(vec);
        }
    }

    return 0;
}