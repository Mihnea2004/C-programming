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

void insertSquareAfterNo(int arr[], int *n){
    int i = 0;
    while(i < *n){
        for(int j = *n; j > i; j--)
            arr[j] = arr[j - 1];
        arr[i + 1] = arr[i] * arr[i];
        (*n)++;
        i += 2;
    }
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

    insertSquareAfterNo(arr, &n);
    printf("\nNew array: \n");
    printArray(arr, n);
}