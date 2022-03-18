#ifndef MERGE_SORT
#define MERGE_SORT

void mergeSort(int *list, int n);

static void merge(int *list, int n);

void mergeSort(int *list, int n)
{
    if (n < 2)
    {
        return;
    }

    int middlePoint = n / 2;

    mergeSort(list, middlePoint);
    mergeSort(list + middlePoint, n - middlePoint);

    merge(list, n);
}

void merge(int *list, int n)
{
    int middle = n / 2;

    int l = middle, r = n - middle;

    int listL[l], listR[r];

    int i, j, p;

    for (i = 0; i < l; i++)
        listL[i] = list[i];

    for (; i < n; i++)
        listR[i - middle] = list[i];


    i = 0;
    j = 0;
    p = 0;

    while (i < l && j < r)
    {
        if (listL[i] <= listR[j])
        {
            list[p] = listL[i++];
        }
        else
        {
            list[p] = listR[j++];
        }
        p++;
    }

    while (i < l) list[p++] = listL[i++];

    while (j < r) list[p++] = listR[j++];

}

#endif