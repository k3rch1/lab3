#include <stdio.h>
#include <stdint.h>

#define VECTOR_INIT_SIZE 100

typedef struct vector {
    size_t element_size;
    uint32_t vector_size;
    void *data;

} vector;

vector *init_vector(size_t element_size) {
    vector *vec = malloc(sizeof(vector));
    vec->element_size = element_size;
    vec->data = malloc(VECTOR_INIT_SIZE * element_size);
}

void free_vector(vector *vec) {
    free(vec->data);
    free(vec);
}

void vector_extend(vector *vec) {

}

uint32_t get_vector_size(vector *vec) {
    return vec->vector_size; 
}

void *vector_begin(vector *vec) {
    return vec->data;
}

void *vector_end(vector *vec) {
    return (void*)((char*)vector_begin(vec) + vec->vector_size * vec->element_size);
}

void *get_vector_element(vector *vec, uint32_t i) {
    if (i < vec->vector_size) return (void*)((char*)vector_begin(vec) + i * vec->element_size);
    else return NULL;
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