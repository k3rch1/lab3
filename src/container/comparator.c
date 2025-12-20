#include <stdio.h>
#include "house.h"
#include <string.h>

int house_comp(void *pa, void *pb) {
    house *a = (house*)pa;
    house *b = (house*)pb;
    if (strcmp(a->developer_name, b->developer_name) != 0) return strcmp(a->developer_name, b->developer_name);
    if (strcmp(a->microdistrict_name, b->microdistrict_name) != 0) return strcmp(a->microdistrict_name, b->microdistrict_name);
    if (a->type != b->type) return a->type - b->type;
    if (a->construction_year != b->construction_year) return (int)a->construction_year - (int)b->construction_year;
    if (a->has_lift != b->has_lift) return a->has_lift - b->has_lift;
    if (a->has_garbage_lift != b->has_garbage_lift) return a->has_garbage_lift - b->has_garbage_lift;
    if (a->flats_count != b->flats_count) return (int)a->flats_count - (int)b->flats_count;
    if (a->floors_count != b->floors_count) return (int)a->floors_count - (int)b->floors_count;
    if (a->avg_flat_square != b->avg_flat_square) return a->avg_flat_square - b->avg_flat_square;
    return 0;
}