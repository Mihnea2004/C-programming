#include <stdio.h>

int verifyInArray(int arr[], int size, int k){
    for(int i = 0; i < size; i++)
        if(arr[i] > k)
            return 1;
    
    return 0;
}

int main(void){
    int arr[] = {7, -5, 4, 3, -9, 2, -8};
    int size = sizeof(arr) / sizeof(arr[0]);

    if(verifyInArray(arr, size, 5))
        printf("There is at least a number bigger than k!\n");
    else
        printf("There isn't any number bigger than k!\n");
    
    return 0;
}