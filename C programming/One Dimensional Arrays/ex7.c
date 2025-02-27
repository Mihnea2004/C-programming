#include <stdio.h>

void insertArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;  
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++)
        for(int j = i; j < n; j++)
            if(arr[j] % 2 == 0 && arr[j + 1] % 2 != 0)
                swap(&arr[j], &arr[j + 1]);
}

int main(){
    int n;
    printf("Enter a value: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d values: ", n);
    insertArray(arr, n);

    printf("Initial array: \n");
    printArray(arr, n);

    bubbleSort(arr, n);
    printf("\nSorted array: \n");
    printArray(arr, n);
}