#ifndef INSERTION_SORT
#define INSERTION_SORT

#include "algorithmsUtils.h"

void insertionSort(int *list, int n);

void insertionSort(int *list, int n)
{
    int i;

    for(i = 1; i < n; i++)
    {
        int j = i - 1;

        while (list[j] > list[j + 1] && j >= 0)
        {
            swap(list + j, list + j + 1);
            j -= 1;
        }
        
    }
}

#endif