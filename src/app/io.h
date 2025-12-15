#pragma once
#include <stdio.h>

FILE *open_in(const char *path);
FILE *open_out(const char *path);
void close_file(FILE *f);