#include <stdlib.h>

void getRandomData(int *array, int n);

void getRandomData(int *array, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        array[i] = rand() % 10000;
    }
}