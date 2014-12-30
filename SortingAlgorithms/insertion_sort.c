//
//  insertion_sort.c
//  SortingAlgorithms
//
//  Created by Takahiro on 2014/12/27.
//  Copyright (c) 2014 Takahiro Ishikawa. All rights reserved.
//

#include "insertion_sort.h"

void insertion_sort(void **ar, int n, int(*cmp)(const void *, const void *))
{
    int i, j;
    for (j = 1; j < n; j++) {
        i = j-1;
        void *value = ar[j];
        while (i >= 0 && (*cmp)(ar[i], value) > 0) {
            ar[i+1] = ar[i];
            i--;
        }
        ar[i+1] = value;
    }
}