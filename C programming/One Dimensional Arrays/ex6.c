#include <stdio.h>
#include <stdlib.h>

void insertArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int *result(int arr[], int n, int *index){
    int *result = malloc(n * sizeof(int));
    if(result == NULL){
        perror("Error memory alloc!");
        exit(-1);
    }

    *index = 0; 
    for(int i = 0; i < n; i++)
        if(abs(arr[i]) > 10)
            result[(*index)++] = arr[i]; 

    return result; 
}

int main(void) {
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Insert %d elements: ", n);
    insertArray(arr, n);

    int index;
    int *r = result(arr, n, &index);

    printf("Elements with absolute value bigger than 10 are: ");
    printArray(r, index);
    printf("\n");

    free(r); 
    return 0;
}
