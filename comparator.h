#pragma once
#include "house.h"

typedef int (*comparator)(const void*, const void*);
int house_comp_year(house *a, house *b);