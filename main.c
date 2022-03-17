#include <stdio.h>
#include <time.h>
#include "random_data.h"
#include "algorithms/IS.h"
#include "sortingUtils.h"

int main()
{

    int *array;
    int sorted, n;
    clock_t begin, end;

    for (int i = 0; i < 100; i++)
    {
        n = 10 + 100 * i;
        printf("Run %d:", i + 1);

        double timepassed = 0;

        int j;

        for (j = 0; j < 5; j++)
        {
            array = (int *)malloc(n * sizeof(int));

            getRandomData(array, n);

            begin = clock();
            insertionSort(array, n);
            end = clock();

            sorted = checkIfSorted(array, n);

            if (sorted == 0)
            {
                printf(" Failed: \n");
                printArray(array, n);
                free(array);
                break;
            }

            timepassed += (double)(end - begin) * 1000 / CLOCKS_PER_SEC;

            free(array);
        }
        
        timepassed /= 5;

        if (sorted == 1)
        {
            printf(" Passed in %fms\n", timepassed);
        }
    }

    return 0;

}