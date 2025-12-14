#include <stdio.h>
#include "vector.h"
#include "comparator.h"
#include <stdint.h>

void f_sort(vector *vec, comparator comp, sort_direction dir) {
    uint32_t vec_size = get_vector_size(vec);

    float stepf = (float)vec_size / 1.247f;
    uint32_t step;
    while (stepf >= 1.0f) {
        step = (uint32_t)stepf;
        if (stepf - (float)step >= 0.5f) step++;

        for (uint32_t i = step; i < vec_size; i++) {
            if (comp(get_vector_element(vec, i-step), get_vector_element(vec, i)) * dir > 0) swap_elements(vec, i-step, i);
        }

        stepf = (float)stepf / 1.247f;
    }
}