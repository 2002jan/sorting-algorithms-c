#ifndef HEAP_SORT
#define HEAP_SORT

#include "algorithmsUtils.h"

void heapSort(int *list, int n);
void heapify(int *list, int n, int i);

void heapSort(int *list, int n)
{
    
    int m;

    for (m = n/2 - 1; m >= 0; m--) heapify(list, n, m);

    for (m = n - 1; m >= 0; m--)
    {
        swap(list, list+m);

        heapify(list, m, 0);
    }
    

}

void heapify(int *list, int n, int i)
{

    int biggest = i;
    int l = 2 * i + 1;
    int r = l + 1;

    if (l < n && list[l] > list[biggest])
    {
        biggest = l;
    }

    if (r < n && list[r] > list[biggest])
    {
        biggest = r;
    }
    
    if (biggest != i)
    {
        swap(list + i, list + biggest);
        heapify(list, n, biggest);
    }
}

#endif