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

    printf("\n<----Exercise 1---->\n");

    printf("\nBubble Sort: \n");

    ALG = bubbleSort;

    testAlgorithm(ALG, 400, 100, 30, 1, Random, 1, "1", "BS");

    printf("\nHeap Sort: \n");

    ALG = heapSort;

    testAlgorithm(ALG, 10000, 33000, 30, 5, Random, 1, "1", "HS");

    printf("\nCounting Sort: \n");

    ALG = countingSort;

    testAlgorithm(ALG, 10000, 33000, 30, 5, Random, 1, "1", "CS");

    printf("\nShell Sort: \n");

    ALG = shellSort;

    testAlgorithm(ALG, 10000, 33000, 30, 5, Random, 1, "1", "ShS");

    printf("\n<----Exercise 2---->\n");

    printf("\nQuick Sort: \n");

    ALG = quickSort;

    printf("\nRandom data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 5, Random, 1, "2", "QS");

    printf("\nConstant data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 5, Constant, 1, "2", "QS");
    
    printf("\nIncreasing data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 5, Increasing, 1, "2", "QS");
    
    printf("\nDescending data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 5, Descending, 1, "2", "QS");
    
    printf("\nAShaped data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 5, AShaped, 1, "2", "QS");
    
    printf("\nVShaped data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 1, VShaped, 1, "2", "QS");

    printf("\nHeap Sort: \n");

    ALG = heapSort;

    printf("\nRandom data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 5, Random, 1, "2", "HS");

    printf("\nConstant data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 5, Constant, 1, "2", "HS");
    
    printf("\nIncreasing data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 5, Increasing, 1, "2", "HS");
    
    printf("\nDescending data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 5, Descending, 1, "2", "HS");
    
    printf("\nAShaped data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 5, AShaped, 1, "2", "HS");
    
    printf("\nVShaped data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 5, VShaped, 1, "2", "HS");

    printf("\nMerge Sort: \n");

    ALG = mergeSort;

    printf("\nRandom data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 5, Random, 1, "2", "MS");

    printf("\nConstant data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 5, Constant, 1, "2", "MS");
    
    printf("\nIncreasing data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 5, Increasing, 1, "2", "MS");
    
    printf("\nDescending data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 5, Descending, 1, "2", "MS");
    
    printf("\nAShaped data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 5, AShaped, 1, "2", "MS");
    
    printf("\nVShaped data: \n");
    testAlgorithm(ALG, 20000, 6000, 30, 5, VShaped, 1, "2", "MS");

    return 0;

}