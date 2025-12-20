#include <stdio.h>
#include "house.h"
#include "boolean.h"
#include "vector.h"

static const char *type_to_str(house_type t) {
    switch (t) {
        case PANEL: return "PANEL";
        case BRICK: return "BRICK";
        case MONOLITHIC: return "MONOLITHIC";
        default: return "PANEL";
    }
}

static const char *bool_to_str(boolean b) {
    return (b == TRUE) ? "YES" : "NO";
}

vector *in_houses(FILE *in) {
    vector *vec = init_vector(sizeof(house));

    char line[512];
    if (!fgets(line, sizeof line, in)) return vec;

    while (fgets(line, sizeof line, in)) {
        house h;
        int res = sscanf(line, "%31[^,],%31[^,],%u,%u,%u,%u,%u,%u,%f", h.developer_name, h.microdistrict_name, &h.type, &h.construction_year, &h.has_lift, &h.has_garbage_lift, &h.flats_count, &h.floors_count, &h.avg_flat_square);
        push_element(vec, get_vector_size(vec), &h);
    }

    return vec;
}

void out_houses(FILE *out, vector *houses) {
    fprintf(out,
        "developer_name,microdistrict_name,type,construction_year,"
        "has_lift,has_garbage_lift,flats_count,floors_count,avg_flat_square\n"
    );

    uint32_t n = get_vector_size(houses);
    for (uint32_t i = 0; i < n; i++) {
        house *h = (house*)get_vector_element(houses, i);
        fprintf(out, "%s,%s,%s,%u,%s,%s,%u,%u,%.2f\n",
            h->developer_name,
            h->microdistrict_name,
            type_to_str(h->type),
            h->construction_year,
            bool_to_str(h->has_lift),
            bool_to_str(h->has_garbage_lift),
            h->flats_count,
            h->floors_count,
            h->avg_flat_square
        );
    }
}

void out_houses_table(FILE *out, vector *houses) {
    fprintf(out,
        "%-3s | %-16s | %-14s | %-10s | %-4s | %-4s | %-4s | %-5s | %-5s | %-8s\n",
        "#", "developer", "microdistrict", "type",
        "construction_year", "has_lift", "has_garbage_lift", "flats_count", "floors_count", "avg_flat_square"
    );

    uint32_t n = get_vector_size(houses);
    for (uint32_t i = 0; i < n; i++) {
        house *h = (house*)get_vector_element(houses, i);
        fprintf(out,
            "%-3u | %-16s | %-14s | %-10s | %-4u | %-4s | %-4s | %-5u | %-6u | %-8.2f\n",
            i + 1u,
            h->developer_name,
            h->microdistrict_name,
            type_to_str(h->type),
            h->construction_year,
            bool_to_str(h->has_lift),
            bool_to_str(h->has_garbage_lift),
            h->flats_count,
            h->floors_count,
            h->avg_flat_square
        );
    }
}