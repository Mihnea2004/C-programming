#include <stdio.h>
#include <stdbool.h>

void insertArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

bool areAllPosElEven(int arr[], int n) {
    for(int i = 0; i < n; i++)
        if(arr[i] > 0)
            if(arr[i] % 2 != 0) 
                return false; //imediat ce gaseste un element care nu respecta conditia, returneaza false 
    return true; 
}

int main(void) {
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Insert %d elements: ", n);
    insertArray(arr, n);

    if(areAllPosElEven(arr, n))
        printf("All positive elements are even!\n");
    else
        printf("Error: Not all positive elements are even!\n");

    return 0;
}
