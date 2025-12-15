#pragma once
#include <stdio.h>

FILE *open_out(const char *path);
void close_out(FILE *f);