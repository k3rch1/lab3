#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "house.h"
#include "vector.h"

static const char *DEVS[] = {
    "PIK", "LSR", "A101", "MRGroup", "1DSK", "Samolyot"
};

static const char *MDS[] = {
    "Central", "North", "South", "Park", "River", "Green"
};

static int rnd_int(int l, int r) {
    return l + rand() % (r - l + 1);
}

static float rnd_float(float l, float r) {
    return l + (float)rand() / RAND_MAX * (r - l);
}

house gen_house(void) {
    house h;

    snprintf(h.developer_name, sizeof h.developer_name, "%s", DEVS[rnd_int(0, 5)]);
    snprintf(h.microdistrict_name, sizeof h.microdistrict_name, "%s", MDS[rnd_int(0, 5)]);
    h.type = (house_type)rnd_int(0, 2);
    h.construction_year = rnd_int(1900, 2025);
    h.has_lift = rnd_int(0, 1);
    h.has_garbage_lift = rnd_int(0, 1);
    h.floors_count = rnd_int(1, 40);
    h.flats_count = rnd_int(10, 1200);
    h.avg_flat_square = rnd_float(18.0f, 120.0f);

    return h;
}

vector *generate(uint32_t n) {
    srand((unsigned)time(NULL));

    vector *vec = init_vector(sizeof(house));

    for (uint32_t i = 0; i < n; i++) {
        house h = gen_house();
        push_element(vec, get_vector_size(vec), &h);
    }

    return vec;
}