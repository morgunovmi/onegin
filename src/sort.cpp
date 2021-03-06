#include <stdlib.h>
#include <string.h>

#include "sort.h"

void swap(void *a, void *b, size_t size) {
    void *temp = calloc(1, size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

void heapify(void *array, size_t n, size_t i, size_t size, int (*cmp)(const void *, const void *)) {
    char *arr = (char *)array;
    size_t largest = i;
    size_t l = 2 * i + 1;
    size_t r = 2 * i + 2;

    if (l < n && cmp(arr + l * size, arr + largest * size) > 0) {
        largest = l;
    }
    if (r < n && cmp(arr + r * size, arr + largest * size) > 0) {
        largest = r;
    }
    if (largest != i) {
        swap(arr + i * size, arr + largest * size, size);
        heapify(arr, n, largest, size, cmp);
    }
}

void myHeapSort(void *base, size_t nmemb, size_t size, int (*cmp)(const void *, const void *)) {
    for (int i = (int)nmemb / 2 - 1; i >= 0; --i) {
        heapify(base, nmemb, i, size, cmp);
    }

    for (int i = (int)nmemb - 1; i > 0; --i) {
        swap(base, (char *)base + i * size, size);
        heapify(base, i, 0, size, cmp);
    }
}
