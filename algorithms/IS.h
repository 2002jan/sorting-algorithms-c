void insertionSort(int *list, int n);

void insertionSort(int *list, int n)
{
    int i;

    for(i = 1; i < n; i++)
    {
        int j = i - 1, temp;

        while (list[j] > list[j + 1] && j >= 0)
        {
            temp = list[j];
            list[j] = list[j + 1];
            list[j + 1] = temp;

            j -= 1;
        }
        
    }
}