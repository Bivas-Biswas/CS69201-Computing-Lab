#include<stdio.h>
#include<stdlib.h>

#define RUN 3


void insertionSort(int arr[], int low, int high)
{
    int j;
    for (int i = low + 1; i <= high; i++)
    {
        int temp = arr[i];
        for (j = i - 1; j >= low && arr[j] > temp; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

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

void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        printf("%d  ", arr[i]); 
    printf("\n"); 
}

int min(int x, int y){
    if(x > y){
        return y;
    } else {
        return x;
    }
}

void timSort(int arr[], int n)
{
    for(int i = 0; i < n;i += RUN){
        int minValue = min((i + RUN - 1), (n - 1));
        insertionSort(arr, i, minValue);
    }

    printf("After insetion \n");
    printArray(arr, n);

    for(int size = RUN; size < n; size = 2 * size){

        for(int low = 0; low < n; low += size * 2){

            int mid = low + size - 1;
            int high = min((low + 2 * size - 1), (n - 1));

            if(mid < high){
                merge(arr, low, mid, high);
                printf("merge low: %d mid:%d high:%d\n", low, mid, high);
                printArray(arr, n);
            }
        }
    }
}

int main(){
    int arr[] = { -2, 7,  15,  -14, 0, 15,  0, 7, -7, -4, -13, 5,   8, -14, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    timSort(arr, n);
    printArray(arr, n);
}