#include <stdio.h>
#include <stdlib.h>

void insertArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertZeroAfterOddNo(int arr[], int *n){
    int i = 0;
    while (i < *n) {
        if (arr[i] % 2 != 0) {  
            for (int j = *n; j > i; j--)
                arr[j] = arr[j - 1];

            arr[i + 1] = 0; 
            (*n)++;  
            i += 2; 
        }
        else 
            i++; 
    }
}

int main(){
    int n;
    printf("Enter a value: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d values: ", n);
    insertArray(arr, n);

    printf("Initial array: \n");
    printArray(arr, n);

    insertZeroAfterOddNo(arr, &n);
    printf("\nArray after inserting zeros after odd numbers: \n");
    printArray(arr, n);

    free(arr);  
    return 0;
}
