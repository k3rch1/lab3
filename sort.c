#include <stdio.h>
#include "vector.h"
#include "comparator.h"
#include <stdint.h>

void f_sort(vector *vec, comparator comp) {
    uint32_t step = (uint32_t)((float)get_vector_size(vec) / 1.247f);

    while (step >= 1) {
        

        step = (uint32_t)((float)step / 1.247f);
    }
}