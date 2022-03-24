#include "random_data.h"
#include <stdio.h>
#include <stdlib.h>

short testRandomSequence(int *list, int n);
short testConstantSequence(int *list, int n);
short testIncreasingSequence(int *list, int n);
short testDescendingSequence(int *list, int n);
short testAShapedSequence(int *list, int n);
short testVShapedSequence(int *list, int n);

int main()
{

    enum sequenceType types[] =
        {
            Random,
            Constant,
            Increasing,
            Descending,
            AShaped,
            VShaped};

    short (*testFunctions[6])(int *list, int n) = {
        testRandomSequence,
        testConstantSequence,
        testIncreasingSequence,
        testDescendingSequence,
        testAShapedSequence,
        testVShapedSequence};

    int i, n = sizeof(types) / sizeof(enum sequenceType);
    int *testList = calloc(1000000, sizeof(int));

    for (i = 0; i < n; i++)
    {
        enum sequenceType currentType = types[i];

        printf("Testing %s type sequence generator\n\n", getSequenceTypeName(currentType));

        int j;

        for (j = 1; j <= 10; j++)
        {
            int m = 100000 * j;
            printf("Testing for n=%d: ", m);

            getSequence(testList, m, currentType);

            if (testFunctions[i](testList, m))
            {
                printf("Passed! \n");
            }
            else
            {
                printf("Failed! \n");
            }
        }

        printf("\n");
    }

    free(testList);
}

short testRandomSequence(int *list, int n)
{
    return 1;
}

short testConstantSequence(int *list, int n)
{

    int i;

    for (i = 0; i < n; i++)
    {
        if (list[0] != list[i])
        {
            return 0;
        }
    }

    return 1;
}

short testIncreasingSequence(int *list, int n)
{

    int i;

    for (i = 1; i < n; i++)
    {
        if (list[i - 1] + 1 != list[i])
        {
            return 0;
        }
    }

    return 1;
}

short testDescendingSequence(int *list, int n)
{

    int i;

    for (i = 1; i < n; i++)
    {
        if (list[i - 1] - 1 != list[i])
        {
            return 0;
        }
    }

    return 1;
}

short testAShapedSequence(int *list, int n)
{
    return 1;
}

short testVShapedSequence(int *list, int n)
{
    return 1;
}