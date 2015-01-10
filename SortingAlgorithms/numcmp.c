//
//  comp.c
//  SortingAlgorithms
//
//  Created by Takahiro on 2014/12/27.
//  Copyright (c) 2014 Takahiro Ishikawa. All rights reserved.
//
//  Reference "C Programming Language (2nd Edition)", Brian Kernighan and Dennis Ritchie.
//

#include "numcmp.h"

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}
