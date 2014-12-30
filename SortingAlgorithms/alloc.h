//
//  alloc.h
//  SortingAlgorithms
//
//  Created by Takahiro on 2014/12/24.
//  Copyright (c) 2014 Takahiro Ishikawa. All rights reserved.
//

#ifndef __SortingAlgorithms__alloc__
#define __SortingAlgorithms__alloc__

#define ALLOCSIZE 5000000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* strage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n);  /* return pointer to n characters */
void afree(char *p); /* free strage pointed to by p */

#endif /* defined(__SortingAlgorithms__alloc__) */
