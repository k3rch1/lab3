#include <stdio.h>

FILE *open_out(const char *path) {FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen(--out)");
        return NULL;
    }
    return f;
}

void close_out(FILE *f) {
    if(f) fclose(f);
}