// 1 5 3 2 6 4
//5 3 6 4
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

void deleteIncreasingNo(int arr[], int *n){
    for(int i = 0; i < *n - 1; i++){
        if(arr[i] < arr[i+1]){
            for(int j = i; j < *n; j++)
                arr[j] = arr[j+1];
            (*n)--;
        }
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

    deleteIncreasingNo(arr, &n);
    printf("\nNew array: \n");
    printArray(arr, n);
}