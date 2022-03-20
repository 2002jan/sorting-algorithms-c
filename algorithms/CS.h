#ifndef COUNTING_SORT
#define COUNTING_SORT

#include <stdlib.h>
#include <stdio.h>
#include "../sortingUtils.h"

void countingSort(int *list, int n);

void countingSort(int *list, int n)
{
    int i, max = 0;

    for (i = 0; i < n; i++)
    {
        if (list[i] > max)
        {
            max = list[i];
        }
    }

    int *temp = (int*)malloc(++max * sizeof(int));

    for (i = 0; i < max; i++)
    {
        temp[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        int val = list[i];
        temp[val] += 1;
    }

    for (i = 0; i < max; i++)
    {
        int j, count = temp[i];

        if (i > 0)
        {
            temp[i] += temp[i - 1];
        }
        
        for(j = 1; j <= count; j++){
            list[temp[i] - j] = i;
        }
    }

    free(temp);
}


#endif