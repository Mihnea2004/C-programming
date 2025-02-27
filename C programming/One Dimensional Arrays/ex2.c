#include <stdio.h>
#include <limits.h>

int printMinEl(int arr[], int size){
    int min = INT_MAX;
    for(int i = 0; i < size; i++)
        if(arr[i] < min)
            min = arr[i];
    
    return min;
}

int main(void){
    int arr[] = {7, -5, 4, 3, -9, 2, -8};
    int size = sizeof(arr) / sizeof(arr[0]);

    int minimumEl = printMinEl(arr, size);
    printf("Minimum element in array is %d!\n", minimumEl);
    
    return 0;
}