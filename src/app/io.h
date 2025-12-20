#pragma once
#include <stdio.h>
#include "vector.h"

vector *in_houses(FILE *in);
void out_houses(FILE *out, vector *houses);
void out_houses_table(FILE *out, vector *houses);