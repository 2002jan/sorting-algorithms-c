void quickSort(int *list, int n);

void quickSort(int *list, int n)
{
   
    int pivot = list[n / 2];

    int i = -1, j = n, temp;

    while (1)
    {
        while (list[++i] < pivot);

        while (list[--j] > pivot);

        if (i > j)
        {
            break;
        }
        

        if (list[i] >= pivot && list[j] <= pivot)
        {
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }

    if (j > 0)
    {
        quickSort(list, j + 1);
    }

    if (i < n - 1)
    {
        quickSort(list + i, n - i);
    }
    
    
}