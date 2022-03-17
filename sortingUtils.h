#include <stdio.h>
#include <time.h>
#include "random_data.h"


void printArray(int *list, int n);

int checkIfSorted(int *list, int n);

void testAlgorithm(void (*alg)(int *list, int n), int start, int step, int steps, int runs);

/**
 * @brief Prints whole list into console
 * 
 * @param list 
 * @param n 
 */
void printArray(int *list, int n)
{
    printf("{");

    int i;

    for (i = 0; i < n; i++)
    {
        
        printf(" %d", list[i]);

        if (i < n -1)
        {
            printf(",");
        }
    }

    printf("}\n");
    
}

/**
 * @brief Checkes if list on given pointer is sorted
 * 
 * @param list 
 * @param n 
 * @return int 
 */
int checkIfSorted(int *list, int n)
{

    int i, sorted = 1;

    for (i = 1; i < n; i++)
    {
        if (list[i - 1] > list[i])
        {
            sorted = 0;
            break;
        }
        
    }
    
    return sorted;
}

/**
 * @brief Function runs given algorithm {fun} and tests it with given criterias
 * 
 * @param fun 
 * @param start 
 * @param step 
 * @param steps 
 * @param runs 
 */
void testAlgorithm(void (*alg)(int *list, int n), int start, int step, int steps, int runs)
{
    int *array;
    int sorted, n;
    clock_t begin, end;

    for (int i = 0; i < steps; i++)
    {
        n = start + step * i;
        printf("Run %d:", i + 1);

        double timepassed = 0;

        int j;

        for (j = 0; j < runs; j++)
        {
            array = (int *)malloc(n * sizeof(int));

            getRandomData(array, n);

            begin = clock();
            alg(array, n);
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
        
        timepassed /= runs;

        if (sorted == 1)
        {
            printf(" Passed in %fms\n", timepassed);
        }
    }
}