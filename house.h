#pragma once
#include <stdint.h>

typedef enum house_type {
    PANEL,
    BRICK,
    MONOLITHIC,
} house_type;

typedef enum boolean {
    FALSE,
    TRUE,
} boolean;

typedef struct house {
    char *developer_name;
    char *microdistrict_name;
    house_type type;
    uint32_t construction_year;
    boolean has_lift;
    boolean has_garbage_lift;
    uint32_t flats_count;
    uint32_t floors_count;
    uint32_t avg_flat_square;
} house;