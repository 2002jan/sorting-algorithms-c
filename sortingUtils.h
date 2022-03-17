#include <stdio.h>


void printArray(int *list, int n);

int checkIfSorted(int *list, int n);

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