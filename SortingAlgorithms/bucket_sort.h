//
//  bucket_sort.h
//  SortingAlgorithms
//
//  Created by Takahiro on 2015/01/01.
//  Copyright (c) 2015 Takahiro Ishikawa. All rights reserved.
//
//  Reference "Algorithms in a Nutshell", George T. Heineman, Gary Pollice, and Stanley Selkow.
//

#ifndef __SortingAlgorithms__bucket_sort__
#define __SortingAlgorithms__bucket_sort__

#include <stdlib.h>

int hash(char *elt);
int num_buckets(int num_elements);

/* lined list of elements in bucket. */
typedef struct {
    void         *element;
    struct ENTRY *next;
} ENTRY;

/* maintain count of entries in each bucket and pointer to its first entry */
typedef struct {
    int    size;
    ENTRY  *head;
} BUCKET;

/* Allocation of buckets and the number of buckets allocated */
static BUCKET *buckets = 0;
static int num = 0;

/* One by one remove and overwrite ar */
void extract (BUCKET *buckets, int(*cmp)(const void *, const void *), void **ar, int n);

void bucket_sort(void **ar, int n, int(*cmp)(const void *, const void *));

#endif /* defined(__SortingAlgorithms__bucket_sort__) */
