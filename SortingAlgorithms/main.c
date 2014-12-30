//
//  main.c
//  SortingAlgorithms
//
//  Created by Takahiro on 2014/12/24.
//  Copyright (c) 2014 Takahiro Ishikawa. All rights reserved.
//

#include <stdio.h>

#include "alloc.h"
#include "comp.h"
#include "copy.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "heap_sort.h"

#define MAXLINE 1000 /* maximum input line size */
#define MAXLINES 5000 /* max #lines to bo sorted */

char *lineptr[MAXLINES]; /* pointer to text lines */

int get_line(char *line, int maxline);
int readlines(char **lineptr, int nlines);
void writelines(char **lineptr, int nlines);

/* sort input lines */
int main(int argc, const char * argv[])
{
    int nlines; /* number of input lines read */

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        //insertion_sort((void *)lineptr, nlines, (int (*)(const void *, const void *))string_comp);
        //selection_sort((void *)lineptr, nlines, (int (*)(const void  *, const void *))string_comp);
        heap_sort((void *)lineptr, nlines, (int (*)(const void *, const void *))string_comp);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines */
int readlines(char **lineptr, int maxlines)
{
    int len, nlines;
    char *p, line[MAXLINE];

    nlines = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (nlines > maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            copy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* get_line: read a line into s, return lenght */
int get_line(char *s, int lim)
{
    int c, i;
    
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* writelines: write output lines */
void writelines(char **lineptr, int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
