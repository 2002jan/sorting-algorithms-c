#include <stdio.h>
#include <time.h>
#include "algorithms/IS.h"
#include "sortingUtils.h"

int main()
{

    void (*IS)(int *array, int n) = insertionSort;

    testAlgorithm(IS, 100, 100, 100, 5);

    return 0;

}