#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "boolean.h"

#define VECTOR_INIT_SIZE 128u

typedef struct vector {
    size_t element_size;
    uint32_t size;
    uint32_t capacity;
    float capacity_multiplier;
    void *data;

} vector;

vector *init_vector(size_t element_size) {
    vector *vec = malloc(sizeof(vector));
    vec->element_size = element_size;
    vec->size = 0u;
    vec->capacity = VECTOR_INIT_SIZE;
    vec->capacity_multiplier = 2.0f;
    vec->data = malloc(VECTOR_INIT_SIZE * element_size);
    return vec;
}

void free_vector(vector *vec) {
    free(vec->data);
    free(vec);
}

void extend_vector(vector *vec, boolean extending) {
    uint32_t new_capacity = vec->capacity;

    if (extending) {
        float new_capacity_fl = (float)new_capacity * (float)vec->capacity_multiplier;
        new_capacity = (uint32_t)new_capacity_fl;
        if(new_capacity_fl - (float)new_capacity > 0) new_capacity++;
        if (vec->capacity_multiplier > 1.2f) vec->capacity_multiplier -= 0.1f;
    } else {
        if (vec->capacity_multiplier < 2.0f) vec->capacity_multiplier += 0.1f;
        new_capacity = (uint32_t)((float)new_capacity / (float)vec->capacity_multiplier);
        if (new_capacity < VECTOR_INIT_SIZE) new_capacity = VECTOR_INIT_SIZE;
    }

    vec->data = realloc(vec->data, new_capacity * vec->element_size);
    vec->capacity = new_capacity;
}

vector *copy_vector(vector *vec) {
    vector *new_vec = init_vector(vec->element_size);
    new_vec->capacity = vec->capacity;
    new_vec->capacity_multiplier = vec->capacity_multiplier;
    new_vec->size = vec->size;
    memcpy(new_vec->data, vec->data, vec->capacity * vec->element_size);
    return new_vec;
}

uint32_t get_vector_size(vector *vec) {
    return vec->size; 
}

void *vector_begin(vector *vec) {
    return vec->data;
}

void *vector_end(vector *vec) {
    return (void*)((char*)vector_begin(vec) + vec->size * vec->element_size);
}

void *get_vector_element(vector *vec, uint32_t i) {
    if (i < vec->size) return (void*)((char*)vector_begin(vec) + i * vec->element_size);
    else return NULL;
}

void push_element(vector *vec, uint32_t i, void *value) {
    if (i > vec->size) return;
    if (vec->size + 1u > vec->capacity) extend_vector(vec, 1);

    char *nd_pointer, *p;
    if (vec->size > 0) {
        nd_pointer = (char*)vector_end(vec) + vec->element_size - 1;
        p = (char*)get_vector_element(vec, vec->size-1u) + vec->element_size - 1;

        for(uint32_t m = i; m < vec->size; m++) {
            for(uint32_t n = 0u; n < vec->element_size; n++) {
                *nd_pointer-- = *p--;
            }
        }
    }
    
    char *pushing = (char*)value;
    if (vec->size == 0) nd_pointer = (char*)vector_begin(vec);
    else if (i == vec->size) nd_pointer = (char*)vector_end(vec);
    else nd_pointer = (char*)get_vector_element(vec, i);
    
    for(uint32_t j = 0; j < vec->element_size; j++) {
        *nd_pointer++ = *pushing++;
    }

    vec->size++;
}

void delete_element(vector *vec, uint32_t i) {
    if (i >= vec->size || vec->size == 0) return;

    char *nd_pointer = (char*)get_vector_element(vec, i);
    char *p = (char*)get_vector_element(vec, i+1);
    for(uint32_t m = i+1; m < vec->size; m++) {
        for(uint32_t n = 0u; n < vec->element_size; n++) {
            *nd_pointer++ = *p++;
        }
    }
    vec->size--;

    if(vec->size < (float)(vec->capacity)/(float)(vec->capacity_multiplier + 0.1f*(vec->capacity_multiplier < 2.0f))) extend_vector(vec, 0);
}

void swap_elements(vector *vec, uint32_t i, uint32_t j) {
    if (i >= vec->size || j >= vec->size) return;
    char *a = (char*)get_vector_element(vec, i);
    char *b = (char*)get_vector_element(vec, j);
    char *c = malloc(vec->element_size);

    for(uint32_t m = 0u; m < vec->element_size; m++)
        *c++ = *a++;
    
    a -= vec->element_size;
    c -= vec->element_size;

    for(uint32_t m = 0u; m < vec->element_size; m++)
        *a++ = *b++;

    b -= vec->element_size;

    for(uint32_t m = 0u; m < vec->element_size; m++)
        *b++ = *c++;

    c -= vec->element_size;
    free(c);
}

vector *array_to_vector(void *array, uint32_t count, size_t element_size) {
    if (count == 0) return NULL;
    vector *vec = init_vector(element_size);
    char *array_data = (char*)array;
    for (uint32_t i = 0; i < count; i++) {
        push_element(vec, i, array_data);
        array_data += element_size;
    }

    return vec;
}

void *vector_to_array(vector *vec) {
    void *return_data = vec->data;
    free(vec);
    return return_data;
}