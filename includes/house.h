#pragma once
#include <stdint.h>
#include "boolean.h"

typedef enum house_type {
    PANEL,
    BRICK,
    MONOLITHIC,
} house_type;

typedef struct house {
    char developer_name[32];
    char microdistrict_name[32];
    house_type type;
    uint32_t construction_year;
    boolean has_lift;
    boolean has_garbage_lift;
    uint32_t flats_count;
    uint32_t floors_count;
    float avg_flat_square;
} house;