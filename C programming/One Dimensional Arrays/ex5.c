#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int printMinElInRange(int arr[], int size, int x, int y) {
    if(x > y) 
        exit(-1);

    int min = INT_MAX;

    for(int i = 0; i < size; i++) 
        if(arr[i] >= x && arr[i] <= y) 
            if(arr[i] < min) 
                min = arr[i];

    return min;
}

int main(void) {
    int x, y;
    printf("Enter value x: ");
    scanf("%d", &x);

    printf("Enter value y: ");
    scanf("%d", &y);

    int arr[] = {7, -5, 4, 3, -9, 2, -8};
    int size = sizeof(arr) / sizeof(arr[0]);

    int minimumEl = printMinElInRange(arr, size, x, y);
    if(minimumEl == 0)
        printf("No element found in the range [%d, %d]!\n", x, y);
    else
        printf("Minimum element in array in range [%d, %d] is %d!\n", x, y, minimumEl);
    
    return 0;
}
