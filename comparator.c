#include <stdio.h>
#include "house.h"

int house_comp_year(house *a, house *b) {
    if (a->construction_year > b->construction_year) return  1;
    if (a->construction_year < b->construction_year) return -1;
    return 0;
}