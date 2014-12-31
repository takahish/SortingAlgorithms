//
//  counting_sort.c
//  SortingAlgorithms
//
//  Created by Takahiro on 2014/12/30.
//  Copyright (c) 2014 Takahiro Ishikawa. All rights reserved.
//

#include "counting_sort.h"

/* Sort the n elements in ar, drawn from the values [0,k). */
void counting_sort(void **ar, int n)
{
    int i, idx = 0, k = COUNTING_SORT_K;
    int *B = calloc(k, sizeof(int));

    for (i = 0; i < n; i++) {
        B[atoi(ar[i])]++;
    }

    for (i = 0; i < k; i++) {
        while (B[i]-- > 0) {
            itoa(i, (char *)ar[idx++]);
        }
    }

    free(B);
}