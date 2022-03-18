#ifndef RANDOM_DATA
#define RANDOM_DATA

#include <stdlib.h>
#define RANDOM_MODULO 15000;

enum sequenceType
{
    Random,
    Constant,
    Increasing,
    Descending,
    AShaped,
    VShaped
};

void getSequence(int *array, int n, enum sequenceType type);

void getSequence(int *array, int n, enum sequenceType type)
{
    int i, middlePoint = n / 2;

    for (i = 0; i < n; i++)
    {

        if (type == Random)
        {
            array[i] = rand() % RANDOM_MODULO;
        }
        else if (type == Constant)
        {
            array[i] = 0;
        }
        else if (type == Increasing)
        {
            array[i] = i;
        }
        else if (type == Descending)
        {
            array[i] = n - i;
        }
        else if (type == AShaped)
        {
            if (i < middlePoint)
            {
                array[i] = i * 2 + 1;
            }
            else
            {
                array[i] = (n - i) * 2;
            }
        }
        else if (type == VShaped)
        {
            if (i < middlePoint)
            {
                array[i] = (middlePoint - i) * 2 + 1;
            }
            else
            {
                array[i] = (i - middlePoint) * 2;
            }
        }
    }
}

#endif