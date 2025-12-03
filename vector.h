#pragma once
#include <stdint.h>

typedef struct vector {
    vector_element* start;
} vector;

typedef struct vector_element
{
    uint32_t value;
    vector_element *previous;
    vector_element *next;
} vector_element;
