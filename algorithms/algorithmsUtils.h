#ifndef ALGORITHMS_UTILS
#define ALGORITHMS_UTILS

void swap(int *i, int *j);

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}
#endif