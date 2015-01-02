//
//  comp.c
//  SortingAlgorithms
//
//  Created by Takahiro on 2014/12/27.
//  Copyright (c) 2014 Takahiro Ishikawa. All rights reserved.
//
//  Reference "C Programming Language (2nd Edition)", Brian Kernighan and Dennis Ritchie.
//

#include "comp.h"

/* string_comp: return <0 if s<t, 0 if s==t, >0 if s>t */
int string_comp(char *s1, char *s2)
{
    for ( ; *s1 == *s2; s1++, s2++)
        if (*s1 == '\0')
            return 0;
    return *s1 - *s2;
}

/* number_comp: compare s1 and s2 numerically */
int number_comp(char *s1, char *s2)
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
