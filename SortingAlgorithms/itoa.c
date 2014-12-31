//
//  itoa.c
//  SortingAlgorithms
//
//  Created by Takahiro on 2014/12/31.
//  Copyright (c) 2014 Takahiro Ishikawa. All rights reserved.
//

#include "itoa.h"

/* reverse: reverse string s in place */
void reverse(char *s)
{
    int c, i, j;
    
    for (i = 0, j = (int)strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa: convert n to characters in s */
void itoa(int n, char *s)
{
    int i;
    
    i = 0;
    do { /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    s[i] = '\0';
    
    reverse(s);
}
