//
//  selection_sort.c
//  SortingAlgorithms
//
//  Created by Takahiro on 2014/12/28.
//  Copyright (c) 2014 Takahiro ishikawa. All rights reserved.
//

#include "selection_sort.h"
#include "swap.h"

static int select_max(void **ar, int left, int right, int (*cmp)(const void *, const void *))
{
    int max_pos = left;
    int i = left;
    while (++i <= right) {
        if ((*cmp)(ar[i], ar[max_pos]) > 0) {
            max_pos = i;
        }
    }

    return max_pos;
}

void selection_sort(void **ar, int n, int (*cmp)(const void *, const void *))
{
    int i;

    /* repeatedly select max in A[0,i] and swap with proper position */
    for (i = n-1; i >= 1; i--) {
        int max_pos = select_max(ar, 0, i, cmp);
        if (max_pos != i) {
            swap(ar, max_pos, i);
        }
    }
}