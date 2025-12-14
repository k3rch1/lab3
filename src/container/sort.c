#include <stdio.h>
#include "vector.h"
#include "comparator.h"
#include "boolean.h"
#include <stdint.h>

void comb_sort(vector *vec, comparator comp, sort_direction dir) {
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

void q_sort(vector *vec, comparator comp, sort_direction dir) {
    if (get_vector_size(vec) < 2u) return;
    q_sort_body(vec, comp, dir, 0u, get_vector_size(vec)-1u);
}

void q_sort_body(vector *vec, comparator comp, sort_direction dir, uint32_t l, uint32_t r) {
    if (l >= r) return;
    else if (r == l + 1u) {
        if (comp(get_vector_element(vec, l), get_vector_element(vec, r)) * dir > 0) swap_elements(vec, l, r);
        return;
    }

    void *pivot = get_vector_element(vec, (l+r)/2u);

    uint32_t left_count = 0u;
    for(uint32_t i = l; i < r+1u; i++) {
        if (i == (l+r)/2u) continue;

        if (comp(get_vector_element(vec, i), pivot) * dir <= 0) left_count++;
    }
    uint32_t pivot_pos = (l+r)/2u;
    if (l + left_count != (l+r)/2u) {
        pivot_pos = l + left_count;
        swap_elements(vec, pivot_pos, (l+r)/2);
        pivot = get_vector_element(vec, pivot_pos);
    }
    
    if (left_count == 0u) q_sort_body(vec, comp, dir, l + 1u, r);
    else if (pivot_pos == r) q_sort_body(vec, comp, dir, l, r-1u);
    else {
        uint32_t i = l, j = pivot_pos + 1u;
        while (i < pivot_pos) {
            if (comp(get_vector_element(vec, i), pivot) * dir > 0) {
                swap_elements(vec, i, j);
                j++;
            } else i++;
        }

        q_sort_body(vec, comp, dir, l, pivot_pos - 1u);
        q_sort_body(vec, comp, dir, pivot_pos + 1u, r);
    }
}