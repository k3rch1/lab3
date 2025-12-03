#include <stdio.h>
#include <stdint.h>

typedef struct vector_element {
    void *value;

} vector_element;

typedef struct vector {
    size_t element_size;
    uint32_t vector_size;
} vector;

vector *init_vector() {

}

void free_vector(vector *vec) {

}

uint32_t get_vector_size(vector *vec) {

}

vector_element *get_vector_element(vector *vec, uint32_t i) {

}

void push_element(vector *vec, uint32_t i, void *value) {

}

void delete_element(vector *vec, uint32_t i) {

}

void swap_elements(vector *vec, uint32_t i, uint32_t j) {

}

vector *array_to_vector(void *array) {

}

void *vector_to_array(vector *vec) {

}