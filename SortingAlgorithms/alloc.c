//
//  alloc.c
//  SortingAlgorithms
//
//  Created by Takahiro on 2014/12/24.
//  Copyright (c) 2014 Takahiro Ishikawa. All rights reserved.
//

#include "alloc.h"

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n; /* old p */
    } else      /* not enough room */
        return 0;
}

void afree(char *p) /* free strage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}