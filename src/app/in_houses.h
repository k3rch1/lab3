#pragma once
#include <stdio.h>
#include "vector.h"

vector *read_houses_csv(FILE *in);
vector *read_houses_from_stdin();