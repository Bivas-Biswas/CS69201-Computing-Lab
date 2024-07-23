#include<stdio.h>

void bubble(int arr[], int n){
    for(int i=0; i< n -1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main(){
    int arr[] = {4, 5, 1, 3, 2, 8};
    int len = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, len);
    bubble(arr, len);
    printArray(arr, len);

}