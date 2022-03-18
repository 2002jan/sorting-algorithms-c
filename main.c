#include <stdio.h>
#include <time.h>
#include "algorithms/IS.h"
#include "algorithms/QS.h"
#include "sortingUtils.h"
#include "algorithms/HS.h"

int main()
{

    printf("\nInsert Sort: \n");

    void (*ALG)(int *array, int n) = insertionSort;

    testAlgorithm(ALG, 100, 100, 100, 5);

    printf("\nQuick Sort: \n");

    ALG = quickSort;
    
    testAlgorithm(ALG, 2000, 2000, 100, 5);

    printf("\nHeap Sort: \n");

    ALG = heapSort;
    
    testAlgorithm(ALG, 2000, 2000, 100, 5);

    return 0;

}