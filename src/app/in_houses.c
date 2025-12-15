#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "house.h"
#include "vector.h"

static house_type str_to_type(const char *s) {
    if (strcmp(s, "PANEL") == 0) return PANEL;
    if (strcmp(s, "BRICK") == 0) return BRICK;
    if (strcmp(s, "MONOLITHIC") == 0) return MONOLITHIC;
    return PANEL;
}

static int parse_u32(const char *s, uint32_t *out) {
    char *end = NULL;
    unsigned long vec = strtoul(s, &end, 10);
    if (!s[0] || (end && *end != '\0')) return 0;
    *out = (uint32_t)vec;
    return 1;
}

static int parse_float(const char *s, float *out) {
    char *end = NULL;
    float vec = strtof(s, &end);
    if (!s[0] || (end && *end != '\0')) return 0;
    *out = vec;
    return 1;
}

vector *read_houses_csv(FILE *in) {
    vector *vec = init_vector(sizeof(house));
    if (!vec) return NULL;

    char line[512];

    if (!fgets(line, sizeof line, in)) return vec;

    while (fgets(line, sizeof line, in)) {
        line[strcspn(line, "\r\n")] = '\0';

        char *save = NULL;
        char *t0 = strtok_r(line, ",", &save);
        char *t1 = strtok_r(NULL, ",", &save);
        char *t2 = strtok_r(NULL, ",", &save);
        char *t3 = strtok_r(NULL, ",", &save);
        char *t4 = strtok_r(NULL, ",", &save);
        char *t5 = strtok_r(NULL, ",", &save);
        char *t6 = strtok_r(NULL, ",", &save);
        char *t7 = strtok_r(NULL, ",", &save);
        char *t8 = strtok_r(NULL, ",", &save);

        if (!t0 || !t1 || !t2 || !t3 || !t4 || !t5 || !t6 || !t7 || !t8) {
            continue;
        }

        house h = {0};
        snprintf(h.developer_name, sizeof h.developer_name, "%s", t0);
        snprintf(h.microdistrict_name, sizeof h.microdistrict_name, "%s", t1);
        h.type = str_to_type(t2);

        if (!parse_u32(t3, &h.construction_year)) continue;
        h.has_lift = (atoi(t4) ? TRUE : FALSE);
        h.has_garbage_lift = (atoi(t5) ? TRUE : FALSE);
        if (!parse_u32(t6, &h.flats_count)) continue;
        if (!parse_u32(t7, &h.floors_count)) continue;
        if (!parse_float(t8, &h.avg_flat_square)) continue;

        push_element(vec, get_vector_size(vec), &h);
    }

    return vec;
}

vector *read_houses_from_stdin() {
    vector *vec = init_vector(sizeof(house));
    if (!vec) return NULL;

    char line[512];

    if (!fgets(line, sizeof line, stdin)) {
        return vec;
    }

    while (fgets(line, sizeof line, stdin)) {
        line[strcspn(line, "\r\n")] = '\0';

        house h;

        char *save = NULL;
        char *tok = strtok_r(line, ",", &save);
        if (!tok) continue;
        snprintf(h.developer_name, sizeof h.developer_name, "%s", tok);

        tok = strtok_r(NULL, ",", &save);
        if (!tok) continue;
        snprintf(h.microdistrict_name, sizeof h.microdistrict_name, "%s", tok);

        tok = strtok_r(NULL, ",", &save);
        if (!tok) continue;
        if (strcmp(tok, "PANEL") == 0) h.type = PANEL;
        else if (strcmp(tok, "BRICK") == 0) h.type = BRICK;
        else h.type = MONOLITHIC;

        tok = strtok_r(NULL, ",", &save);
        h.construction_year = atoi(tok);

        tok = strtok_r(NULL, ",", &save);
        h.has_lift = atoi(tok);

        tok = strtok_r(NULL, ",", &save);
        h.has_garbage_lift = atoi(tok);

        tok = strtok_r(NULL, ",", &save);
        h.flats_count = atoi(tok);

        tok = strtok_r(NULL, ",", &save);
        h.floors_count = atoi(tok);

        tok = strtok_r(NULL, ",", &save);
        h.avg_flat_square = atof(tok);

        push_element(vec, get_vector_size(vec), &h);
    }

    return vec;
}