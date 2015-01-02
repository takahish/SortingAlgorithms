//
//  bucket_sort.c
//  SortingAlgorithms
//
//  Created by Takahiro on 2015/01/01.
//  Copyright (c) 2015 Takahiro Ishikawa. All rights reserved.
//
//  Reference "Algorithms in a Nutshell", George T. Heineman, Gary Pollice, and Stanley Selkow.
//

#include "bucket_sort.h"

/* One by one remove and overwrite ar */
void extract (BUCKET *buckets, int(*cmp)(const void *, const void *), void **ar, int n)
{
    int i, low;
    int idx = 0;
    for (i = 0; i < num; i++) {
        ENTRY *ptr, *tmp;
        if (buckets[i].size == 0) continue; /* empty bucket */
        ptr = buckets[i].head;
        if (buckets[i].size == 1) {
            ar[idx++] = ptr->element;
            free(ptr);
            buckets[i].size = 0;
            continue;
        }

        /* insersion sort where elements are drawn from linked list and
         * inserted into array. Linked lists are released. */
        low = idx;
        ar[idx++] = ptr->element;
        tmp = ptr;
        ptr = (ENTRY *)ptr->next;
        free(tmp);
        while (ptr != NULL) {
            int i = idx-1;
            while(i >= low && (*cmp)(ar[i], ptr->element) > 0) {
                ar[i+1] = ar[i];
                i--;
            }
            ar[i+1] = ptr->element;
            tmp = ptr;
            ptr = (ENTRY *)ptr->next;
            free(tmp);
            idx++;
        }
        buckets[i].size = 0;
    }
}

void bucket_sort(void **ar, int n, int(*cmp)(const void *, const void *))
{
    int i;
    num = num_buckets(n);
    buckets = (BUCKET *) calloc (num, sizeof(BUCKET));
    for (i = 0; i < n; i++) {
        int k = hash(ar[i]);

        /* Insert each element and ncrement counts */
        ENTRY *e = (ENTRY *) calloc(1, sizeof(ENTRY));
        e->element = ar[i];

        if (buckets[k].head == NULL) {
            buckets[k].head = e;
        } else {
            e->next = (struct ENTRY *)buckets[k].head;
            buckets[k].head = e;
        }

        buckets[k].size++;
    }

    /* now read out and overwrite ar. */
    extract(buckets, cmp, ar, n);

    free(buckets);
}

/** Number of buckets to use is the same as the number of elements. */
int num_buckets(int num_elements) {
    num = num_elements;
    return num_elements;
}

/**
 * Hash function to identify bucket number from element. Customized
 * to properly encode elements in order within the buckets. Range of
 * numbers is from [0,1), so we subdivide into buckets of size 1/num;
 */
int hash(char *s) {
    double d = atof(s);
    int bucket = num*d;
    return bucket;
}