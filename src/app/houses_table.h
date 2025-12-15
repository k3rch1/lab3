#pragma once
#include <stdio.h>
#include "vector.h"

void print_houses_table_csv(FILE *out, vector *houses);
void print_houses_table_stdout(vector *houses);