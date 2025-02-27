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

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int v[], int low, int high){
    low = 0;

	int pivot = v[low];
	while (low <= high){
		while (v[low] > pivot)
			low++;
		while (pivot > v[high])
			high--;
		if (low < high)
			swap(&v[low++], &v[high--]);
		else
			low++;
	}

	if (low < high - 1)
		quickSort(v, low, high - 1);
	if (high + 1 < high)
		quickSort(v, high + 1, high);
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

    quickSort(arr, 0, n - 1);
    
    printf("\nSorted array: \n");
    printArray(arr, n);
    free(arr);  
    return 0;
}
