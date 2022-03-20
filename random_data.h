#ifndef RANDOM_DATA
#define RANDOM_DATA

#include <stdlib.h>
#define RANDOM_MODULO 32767;

enum sequenceType
{
    Random,
    Constant,
    Increasing,
    Descending,
    AShaped,
    VShaped
};

char *getSequenceTypeName(enum sequenceType type);

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

char *getSequenceTypeName(enum sequenceType type)
{

    switch (type)
    {
    case Random:
        return "Random";
        break;
    case Constant:
        return "Constant";
        break;
    case Increasing:
        return "Increasing";
        break;
    case Descending:
        return "Descending";
        break;
    case AShaped:
        return "AShaped";
        break;
    case VShaped:
        return "VShaped";
        break;
    default:
        return "";
        break;
    }

}

#endif