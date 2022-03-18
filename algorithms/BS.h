#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include "algorithmsUtils.h"

void bubbleSort(int *list, int n);

void bubbleSort(int *list, int n)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for (j = 1; j < n - i; j++)
        {
            if (list[j - 1] > list[j])
            {
                swap(list + j - 1, list + j);
            }            
        }
        
    }
}

#endif