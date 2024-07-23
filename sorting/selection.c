
#include<stdio.h>


void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection(int arr[], int n){
    int min, temp;
    for(int i = 0; i < n -1; i++){
        min = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}


void main(){
    int arr[] = {4, 5, 1, 3, 2, 8};
    int len = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, len);
    selection(arr, len);
    printArray(arr, len);

}