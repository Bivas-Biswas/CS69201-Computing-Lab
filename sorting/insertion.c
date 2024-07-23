#include <stdio.h>

void insertion(int arr[], int n)
{
    int j;
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

void main()
{
    int arr[] = {4, 5, 1, 3, 2, 8};
    int len = sizeof(arr) / sizeof(arr[0]);

    insertion(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}