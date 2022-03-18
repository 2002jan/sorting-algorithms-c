#include <stdio.h>
#include <time.h>
#include "algorithms/IS.h"
#include "algorithms/QS.h"
#include "sortingUtils.h"
#include "algorithms/HS.h"
#include "algorithms/SS.h"
#include "algorithms/BS.h"
#include "algorithms/MS.h"
#include "algorithms/ShS.h"
#include "algorithms/CS.h"

int main()
{

    void (*ALG)(int *array, int n);

    printf("\nInsert Sort: \n");

    ALG = insertionSort;

    testAlgorithm(ALG, 10, 10, 100, 5, Random);

    printf("\nSelection Sort: \n");

    ALG = selectionSort;

    testAlgorithm(ALG, 10, 10, 100, 5, Random);

    printf("\nBubble Sort: \n");

    ALG = bubbleSort;
    
    testAlgorithm(ALG, 10, 10, 100, 5, Random);

    printf("\nQuick Sort: \n");

    ALG = quickSort;
    
    testAlgorithm(ALG, 1000, 1000, 100, 5, Random);

    printf("\nHeap Sort: \n");

    ALG = heapSort;
    
    testAlgorithm(ALG, 1000, 1000, 100, 5, Random);
    
    printf("\nMerge Sort: \n");

    ALG = mergeSort;
    
    testAlgorithm(ALG, 1000, 1000, 100, 5, Random);
    
    printf("\nShell Sort: \n");

    ALG = shellSort;
    
    testAlgorithm(ALG, 1000, 1000, 100, 5, Random);
    
    printf("\nCounting Sort: \n");

    ALG = countingSort;
    
    testAlgorithm(ALG, 1000, 1000, 100, 5, Random);

    return 0;

}