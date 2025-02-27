#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b; 
    *b = temp;
}

void bubbleSort(int *v, int n){
    int s, i;
    do{
        s = 0; //nu s-a efectuat nicio schimbare
        for(i = 1; i < n; i++){
            if(v[i - 1] < v[i]){
                swap(&v[i - 1], &v[i]);
                s = 1;
            }
        }
    }while(s);
}

void printArray(int *v, int n){
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
}

int main(){
    int x;
    int *v = NULL;
    int n = 0;

    printf("Enter first number: ");
    scanf("%d", &x);

    while(1){
        if(x == 0)
            break; 

        v = (int*) realloc(v, (n + 1) * sizeof(int));
        if(v == NULL){
            printf("Error!");
            exit(-1);
        }
        v[n++] = x;

        printf("Enter the next number: ");
        scanf("%d", &x);
    }

    bubbleSort(v, n);
    printArray(v, n);

    free(v);

    return 0;
}