#pragma once
#include <stdint.h>

typedef struct vector vector;

vector *init_vector(size_t element_size);
void free_vector(vector *vec);
void extend_vector(vector *vec);

uint32_t get_vector_size(vector *vec);

void *vector_begin(vector *vec);
void *vector_end(vector *vec);
void *get_vector_element(vector *vec, uint32_t i);

void push_element(vector *vec, uint32_t i, void *value);
void delete_element(vector *vec, uint32_t i);
void swap_elements(vector *vec, uint32_t i, uint32_t j);

vector *array_to_vector(void *array, uint32_t count, size_t element_size);
void *vector_to_array(vector *vec);