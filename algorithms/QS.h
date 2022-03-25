#ifndef QUICK_SORT
#define QUICK_SORT

#include "algorithmsUtils.h"
#include <stdio.h>

void quickSort(int *list, int n);

void quickSort(int *list, int n)
{

    int pivot = list[n / 2];

    int i = -1, j = n;

    while (1)
    {
        while (list[++i] < pivot && i <= j);

        while (list[--j] > pivot && i <= j);

        if (i > j)
        {
            break;
        }

        swap(list + j, list + i);
    }

    if (j > 0)
    {
        quickSort(list, j + 1);
    }

    if (i < n - 1)
    {
        quickSort(list + i, n - i);
    }
}

#endif