#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int A[n1], B[n2];

    for (int i = 0; i < n1; i++)
    {
        A[i] = arr[low + i];
    };
    for (int i = 0; i < n2; i++)
    {
        B[i] = arr[mid + i + 1];
    }

    int left = 0, right = 0;
    int i = low;

    while (left < n1 && right < n2)
    {
        if (A[left] > B[right])
        {
            arr[i] = B[right];
            right++;
        }
        else
        {
            arr[i] = A[left];
            left++;
        }
        i++;
    }

    while (left != n1)
    {
        arr[i] = A[left];
        left++;
        i++;
    }

    while (right != n2)
    {
        arr[i] = B[right];
        i++;
        right++;
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low != high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void main()
{
    int arr[] = { 1, 0, 5, 4, -4, 3, 1, 1, 0, -3, 2 };
    int len = (sizeof(arr) / sizeof(arr[0]));
    mergeSort(arr, 0, len - 1);
    printArray(arr, len);
}