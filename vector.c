#include <stdio.h>
#include <stdint.h>

#define VECTOR_INIT_SIZE 100u

typedef struct vector {
    size_t element_size;
    uint32_t size;
    uint32_t capacity;
    void *data;

} vector;

vector *init_vector(size_t element_size) {
    vector *vec = malloc(sizeof(vector));
    vec->element_size = element_size;
    vec->size = 0u;
    vec->capacity = VECTOR_INIT_SIZE;
    vec->data = malloc(VECTOR_INIT_SIZE * element_size);
}

void free_vector(vector *vec) {
    free(vec->data);
    free(vec);
}

void extend_vector(vector *vec) {

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
    if (vec->size + 1u > vec->capacity) vector_extend(vec);
    char *nd_pointer = (char*)vector_end(vec) + vec->element_size - 1; // значение + какая-то штука, чтобы указывать на конец элемента (вроде правильно чекни)
    char *p = (char*)get_vector_element(vec, vec->size-1u) + vec->element_size - 1; // значение + какая-то штука, чтобы указывать на конец элемента (вроде правильно чекни)
    for(uint32_t m = vec->size-1; m > i-1; m++) {
        for(uint32_t n = 0u; n < vec->element_size; n++) {
            *nd_pointer-- = *p--;
        }
    }
    char *pushing = (char*)value;
    nd_pointer = (char*)get_vector_element(vec, i);
    for(uint32_t j = 0; j < vec->element_size; j++) {
        *nd_pointer++ = *pushing++;
    }

    vec->size++;
}

void delete_element(vector *vec, uint32_t i) {
    //if (vec->size - 1u < (vec->capacity)) vector_extend(vec);
    if (i > vec->size) return;
    char *nd_pointer = (char*)get_vector_element(vec, i);
    char *p = (char*)get_vector_element(vec, i+1);
    for(uint32_t m = i; m < vec->size-1; m++) {
        for(uint32_t n = 0u; n < vec->element_size; n++) {
            *nd_pointer++ = *p++;
        }
    }
    vec->size--;
}

void swap_elements(vector *vec, uint32_t i, uint32_t j) {
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
    for (uint32_t i = 0; i < count; i++) {
        for(uint32_t j = 0; j < element_size; j++) {

        }
    }
}

void *vector_to_array(vector *vec) {
    void *return_data = vec->data;
    free(vec);
    return return_data;
}