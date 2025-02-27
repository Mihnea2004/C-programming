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

void insertAmountAndProduct(int arr[], int *n){
    int i = 0, j = 1, k;
    while(i < *n - 1 && j < *n){

        int s = arr[i] + arr[i + 1];
        int p = arr[i] * arr[i + 1];
        *n = *n + 2;

        for(k = *n - 1; k > j + 1; k--)
            arr[k] = arr[k - 2];

        arr[i + 2] = s;
        arr[j + 2] = p;

        i = i + 4;
        j = j + 4;
    }
}

int main(){
    int n;
    printf("Enter a value: ");
    scanf("%d", &n);

    int arr[2 * n];
    printf("Enter %d values: ", n);
    insertArray(arr, n);

    printf("Initial array: \n");
    printArray(arr, n);

    insertAmountAndProduct(arr, &n);
    printf("\nNew array: \n");
    printArray(arr, n);
}