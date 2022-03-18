#ifndef SHELL_SORT
#define SHELL_SORT

#include "../sortingUtils.h"

void shellSort(int *list, int n);

void shellSort(int *list, int n)
{
    int i;

    for (i = n / 2; i > 0; i /= 2)
    {
        int p;

        for (p = 0; p < n - i; p++)
        {
            int j = p + i;
            int temp = list[j];

            while (j >= i && temp < list[j - i])
            {
                list[j] = list[j - i];
                j -= i;
            }

            list[j] = temp;
        }
    }
    
}

#endif