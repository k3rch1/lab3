#include <stdio.h>

FILE *open_in(const char *path) {
    if (!path) return stdin;
    return fopen(path, "r");
}

FILE *open_out(const char *path) {
    if (!path) return stdout;
    return fopen(path, "w");
}

void close_file(FILE *f) {
    if(f && (f != stdin || f != stdout)) fclose(f);
}