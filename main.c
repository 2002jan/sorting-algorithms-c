#include <stdio.h>
#include <time.h>
#include "algorithms/IS.h"
#include "algorithms/QS.h"
#include "sortingUtils.h"
#include "algorithms/HS.h"
#include "algorithms/SS.h"

int main()
{
    printf("\nInsert Sort: \n");

    void (*ALG)(int *array, int n) = insertionSort;

    testAlgorithm(ALG, 100, 100, 100, 5, Random);

    printf("\nSelection Sort: \n");

    ALG = selectionSort;

    testAlgorithm(ALG, 100, 100, 100, 5, Random);

    printf("\nQuick Sort: \n");

    ALG = quickSort;
    
    testAlgorithm(ALG, 2000, 2000, 100, 5, Random);

    printf("\nHeap Sort: \n");

    ALG = heapSort;
    
    testAlgorithm(ALG, 2000, 2000, 100, 5, Random);

    return 0;

}