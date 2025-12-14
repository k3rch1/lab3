#pragma once
#include "house.h"

typedef enum sort_direction {
    desc = -1,
    asc = 1,
} sort_direction;

typedef int (*comparator)(void*, void*);
int house_comp_year(void *pa, void *pb);