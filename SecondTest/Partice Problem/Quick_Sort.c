#include<stdio.h>
#include<stdlib.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;

    for(int j = i + 1; j <= high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i], &arr[low]);

    return i;
}

void quickSort(int arr[], int low, int high){
    if( low < high){

        int partitionIdx = partition(arr, low, high);

        quickSort(arr, low, partitionIdx - 1);
        quickSort(arr, partitionIdx + 1, high);

    }
}




int main()
{
    int arr[] = { 50, 80, 90, 15, 25, 35, 150, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // printing the original array
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // calling quickSort() to sort the given array
    quickSort(arr, 0, n - 1);

    // printing the sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


