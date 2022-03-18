#ifndef SELECTION_SORT
#define SELECTION_SORT

#include "algorithmsUtils.h"

void selectionSort(int *list, int n);

void selectionSort(int *list, int n)
{
    int i, j;

    for(i = 0; i < n - 1; i++)
    {
        int min = i;

        for (j = i + 1; j < n; j++)
        {
            if (list[min] > list[j])
            {
                min = j;
            }
        }

        if (min != i)
        {
            swap(list + i, list + min);
        }
    }
}

#endif