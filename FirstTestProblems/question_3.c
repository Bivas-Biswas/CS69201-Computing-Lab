// The guardian, a wise old sage, gives you a list of integers (at least five integers). Your
// task is to find any five distinct integers from the list so that the product of those numbers
// is maximum. Print the answer(the maximum product) in the terminal.

// In simple words, for an array (of size n >=5) comprising integer elements (positive, zero
// or negative and may contain duplicates), you need to find such 5 elements whose
// product is maximum among the elements chosen.

// Testcase #1
// Input : n=5 array=[-1, -2, -3, -4, -5]
// OUTPUT: -120
// Testcase #2
// Input: n=11 array= [1, 0, 5, 4, -4, 3, 1, 1, 0, -3, 2]
// OUTPUT: 720
// Testcase #3
// Input: n=6 array=[-1, 0, 0, 0, -1, -1]
// OUTPUT : 0
// Testcase #4
// Input n=10 array=[-23,12,34,-1,2,3,1,1,2,10]
// OUTPUT: 93840
// Testcase #5
// Input n=10 array=[-23,12,34,1,2,3,1,1,2,10]
// OUTPUT: 24480

//-------------------------------


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

    int k = 5;

    int prod1 = 1, prod2 = 1, prod3 = 1;

    // last five elements product
    for(int i = len - k; i < len; i++){
        prod1 *= arr[i];
    }

    // first two * last 3 elements
    prod2 *= arr[0] * arr[1];

    for(int i = len - 2 - 1; i < len; i++){
        prod2 *= arr[i];
    }

   // first 4 * last 1 elements
   for(int i=0; i<4; i++){
    prod3 *= arr[i];
   }
   prod3 *= arr[len - 1];


   int maxProd = prod1;

   if(prod2 > maxProd){
    maxProd = prod2;
   }

   if(prod3 > maxProd){
    maxProd = prod3;
   }

   printf("%d\n", maxProd);
}