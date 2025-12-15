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

static const char *bool_to_str(boolean b) {
    return (b == TRUE) ? "YES" : "NO";
}

void print_houses_table_csv(FILE *out, vector *houses) {
    fprintf(out,
        "%-3s | %-16s | %-14s | %-10s | %-4s | %-4s | %-4s | %-5s | %-5s | %-8s\n",
        "#", "developer", "microdistrict", "type",
        "year", "lift", "gbg", "flats", "floors", "avg_sq"
    );

    uint32_t n = get_vector_size(houses);
    for (uint32_t i = 0; i < n; i++) {
        house *h = (house*)get_vector_element(houses, i);

        fprintf(out,
            "%-3u | %-16s | %-14s | %-10s | %-4u | %-4s | %-4s | %-5u | %-6u | %-8.2f\n",
            (unsigned)(i + 1),
            h->developer_name,
            h->microdistrict_name,
            type_to_str(h->type),
            (unsigned)h->construction_year,
            bool_to_str(h->has_lift),
            bool_to_str(h->has_garbage_lift),
            (unsigned)h->flats_count,
            (unsigned)h->floors_count,
            (float)h->avg_flat_square
        );
    }
}

void print_houses_table_stdout(vector *houses) {
    printf("%-3s | %-16s | %-14s | %-10s | %-4s | %-4s | %-4s | %-5s | %-5s | %-8s\n",
        "#", "developer", "microdistrict", "type",
        "year", "lift", "gbg", "flats", "floors", "avg_sq"
    );

    uint32_t n = get_vector_size(houses);
    for (uint32_t i = 0; i < n; i++) {
        house *h = (house*)get_vector_element(houses, i);

        printf("%-3u | %-16s | %-14s | %-10s | %-4u | %-4s | %-4s | %-5u | %-6u | %-8.2f\n",
            (unsigned)(i + 1),
            h->developer_name,
            h->microdistrict_name,
            type_to_str(h->type),
            (unsigned)h->construction_year,
            bool_to_str(h->has_lift),
            bool_to_str(h->has_garbage_lift),
            (unsigned)h->flats_count,
            (unsigned)h->floors_count,
            (float)h->avg_flat_square
        );
    }
}