#include <stdio.h>
#include "house.h"

int house_comp_year(void *pa, void *pb) {
    house *a = (house*)pa;
    house *b = (house*)pb;
    if (a->construction_year > b->construction_year) return  1;
    if (a->construction_year < b->construction_year) return -1;
    return 0;
}

int int_comp(void *pa, void *pb) {
    int *a = (int*)pa;
    int *b = (int*)pb;
    if (*a > *b) return  1;
    if (*a < *b) return -1;
    return 0;
}