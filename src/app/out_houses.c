#include <stdio.h>
#include "house.h"
#include "vector.h"

static const char *type_to_str(house_type t) {
    switch (t) {
        case PANEL: return "PANEL";
        case BRICK: return "BRICK";
        case MONOLITHIC: return "MONOLITHIC";
        default: return "UNKNOWN";
    }
}

void write_houses_csv(FILE *out, vector *houses) {
    fprintf(out,
        "developer_name,microdistrict_name,type,construction_year,"
        "has_lift,has_garbage_lift,flats_count,floors_count,avg_flat_square\n"
    );

    uint32_t n = get_vector_size(houses);
    for (uint32_t i = 0; i < n; i++) {
        house *h = (house*)get_vector_element(houses, i);
        fprintf(out, "%s,%s,%s,%u,%d,%d,%u,%u,%.2f\n",
            h->developer_name,
            h->microdistrict_name,
            type_to_str(h->type),
            h->construction_year,
            h->has_lift,
            h->has_garbage_lift,
            h->flats_count,
            h->floors_count,
            h->avg_flat_square
        );
    }
}

void print_houses(vector *houses) {
    printf("developer_name,microdistrict_name,type,construction_year,has_lift,has_garbage_lift,flats_count,floors_count,avg_flat_square\n");

    uint32_t n = get_vector_size(houses);
    for (uint32_t i = 0; i < n; i++) {
        house *h = (house*)get_vector_element(houses, i);
        printf("%s,%s,%s,%u,%d,%d,%u,%u,%.2f\n",
            h->developer_name,
            h->microdistrict_name,
            type_to_str(h->type),
            h->construction_year,
            h->has_lift,
            h->has_garbage_lift,
            h->flats_count,
            h->floors_count,
            h->avg_flat_square
        );
    }
}