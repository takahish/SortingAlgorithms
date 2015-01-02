//
//  heap_sort.h
//  SortingAlgorithms
//
//  Created by Takahiro on 2014/12/30.
//  Copyright (c) 2014 Takahiro Ishikawa. All rights reserved.
//
//  Reference "Algorithms in a Nutshell", George T. Heineman, Gary Pollice, and Stanley Selkow.
//

#ifndef __SortingAlgorithms__heap_sort__
#define __SortingAlgorithms__heap_sort__

void heap_sort(void **ar, int n, int(*cmp)(const void *, const void *));

#endif /* defined(__SortingAlgorithms__heap_sort__) */
