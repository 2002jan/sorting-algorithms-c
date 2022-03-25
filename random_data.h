#ifndef RANDOM_DATA
#define RANDOM_DATA

#include <stdlib.h>

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

int uniform_distribution(int max);

void getSequence(int *array, int n, enum sequenceType type)
{
    int i, middlePoint = n / 2;

    for (i = 0; i < n; i++)
    {

        if (type == Random)
        {
            array[i] = uniform_distribution(i);
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
            else if (i == middlePoint)
            {
                array[i] = n;
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
                array[i] = (n - middlePoint - i) * 2 - 1;
            }
            else if (i == middlePoint)
            {
                if (n % 2 == 1)
                    array[i] = 1;
                else {
                    array[i] = 2;
                    middlePoint -= 1;
                    }
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

int uniform_distribution(int max)
{
    double randNum = rand() / (1.0 + RAND_MAX);
    return (randNum * (max + 1));
}

#endif