#pragma once
#include "house.h"

typedef int (*comparator)(void*, void*);
int house_comp_year(void *pa, void *pb);
int int_comp(void *pa, void *pb);