#include <stdio.h>
#include <stdlib.h>

void printArray(int *v, int n){
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArray(int *v, int n){
    for(int i = 0; i < n / 2; i++)
        swap(&v[i], &v[n - i - 1]);
}

int main(){
    int n;
    printf("Enter first number: ");
    scanf("%d", &n);

    int *v = (int *) malloc(sizeof(int));
    if(v == NULL){
        perror("Error appeared while trying to alocate the memory!");
        exit(EXIT_FAILURE);
    }   
    int index = 0;

    while(n != 0){
        v = (int*) realloc(v, (index + 1) * sizeof(int));
        if(v == NULL){
            perror("Error appeared while trying to alocate the memory!");
            exit(EXIT_FAILURE);
        }  
        v[index++] = n;

        printf("Enter next number: ");
        scanf("%d", &n);
    }

    printf("Initial array: ");
    printArray(v, index);

    reverseArray(v, index);
    printf("Reversed array: ");
    printArray(v, index);
    printf("\n");
    
    free(v);
}