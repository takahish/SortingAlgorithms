//
//  heap_sort.c
//  SortingAlgorithms
//
//  Created by Takahiro on 2014/12/30.
//  Copyright (c) 2014 Takahiro Ishikawa. All rights reserved.
//
//  Reference "Algorithms in a Nutshell", George T. Heineman, Gary Pollice, and Stanley Selkow.
//

#include "heap_sort.h"
#include "swap.h"

static void heapify(void **ar, int(*cmp)(const void *, const void *), int idx, int max)
{
    int left = 2*idx + 1;
    int right = 2*idx +2;
    int largest;

    /* Find largest element of A[idx], A[left], and A[right]. */
    if (left < max && (*cmp)(ar[left], ar[idx]) > 0) {
        largest = left;
    } else {
        largest = idx;
    }

    if (right < max && (*cmp)(ar[right], ar[largest]) > 0) {
        largest = right;
    }

    /* If largest is not already the parent then swap and propagate. */
    if (largest != idx) {
        swap(ar, largest, idx);
        heapify(ar, cmp, largest, max);
    }
}

static void build_heap(void **ar, int(*cmp)(const void *, const void *), int n)
{
    int i;
    for (i = n/2-1; i>=0; i--) {
        heapify(ar, cmp, i, n);
    }
}

void heap_sort(void **ar, int n, int(*cmp)(const void *, const void *))
{
    int i;
    build_heap(ar, cmp, n);
    for (i = n-1; i >= 1; i--) {
        swap(ar, 0, i);

        heapify(ar, cmp, 0, i);
    }
}