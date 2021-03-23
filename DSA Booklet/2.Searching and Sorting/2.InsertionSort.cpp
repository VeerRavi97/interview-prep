int upper_boundCC(int arr[], int i)
{
    int start = 0;
    int end = i;
    int x = arr[i];
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (x < arr[mid])
            end = mid;
        else
            start = mid + 1;
    }
    return start;
}
void BinaryinsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int pos = upper_boundCC(arr, i);
        int j = i - 1;
        int key = arr[i];
        while (j >= pos)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void InsertionSort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {

        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}