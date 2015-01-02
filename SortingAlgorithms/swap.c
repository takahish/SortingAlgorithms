//
//  swap.c
//  SortingAlgorithms
//
//  Created by Takahiro on 2014/12/29.
//  Copyright (c) 2014 Takahiro Ishikawa. All rights reserved.
//
//  Reference "C Programming Language (2nd Edition)", Brian Kernighan and Dennis Ritchie.
//

#include "swap.h"

void swap(void **v, int i, int j)
{
    void *temp = v[i];

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}