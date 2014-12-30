//
//  swap.c
//  SortingAlgorithms
//
//  Created by Takahiro on 2014/12/29.
//  Copyright (c) 2014年 石川 貴大. All rights reserved.
//

#include "swap.h"

void swap(void **v, int i, int j)
{
    void *temp = v[i];

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}