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

        for (j = 1; j <= 9; j++)
        {
            int m = 111111 * j + 1;
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
    int m = 1000000 + 1;
    int i,*count = calloc(m, sizeof(int));

    int maxCount = 0;

    for (i = 0; i < n; i++)
    {
        int num = list[i];
        count[num] += 1;

        if (count[num] > maxCount)
        {
            maxCount = count[num];
        }
        
    }

    float avg = 0.0f;
    int elements = 0;

    for (i = 0; i < m; i++)
    {
        if(count[i] > 0){
            avg += count[i];
            elements++;
        }
    }

    free(count);

    if (avg / elements > 2.1)
    {
        return 0;
    }
    

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
    
    if(n % 2 == 1 && list[n / 2] != n){
        return 0;
    }

    if (n % 2 == 0 && (list[n / 2] != n || list[n / 2 + 1] != n - 2 || list[n / 2 - 1] != n - 1))
    {
        return 0;
    }

    int i, mp = n / 2;

    for (i = 1; i < n; i++)
    {
        if (i < mp && list[i - 1] + 2 != list[i])
        {
            return 0;
        }
        else if (i > mp + 1 && list[i - 1] - 2 != list[i])
        {
            return 0;
        }
    }
    
    return 1;

}

short testVShapedSequence(int *list, int n)
{
    
    if(n % 2 == 1 && list[n / 2] != 1){
        return 0;
    }

    if (n % 2 == 0 && (list[n / 2] != 2 || list[n / 2 - 1] != 1 || list[n / 2 + 1] != 4))
    {
        return 0;
    }

    int i, mp = n / 2;

    for (i = 1; i < n; i++)
    {
        if (i < mp && list[i - 1] - 2 != list[i])
        {
            return 0;
        }
        else if (i > mp + 1&& list[i - 1] + 2 != list[i])
        {
            return 0;
        }
    }
    
    return 1;
}