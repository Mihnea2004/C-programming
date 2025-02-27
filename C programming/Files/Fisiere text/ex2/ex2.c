#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void writeArray(FILE *out, float arr[], int index){
    for(int i = 0; i < index; i++)
        fprintf(out, "%.2f|", arr[i]);
    printf("\n");
}

int compare(const char *e1, const char *e2){
    float a = *(float*) e1;
    float b = *(float*) e2;

    return a - b;
}

int main(){
    float n;
    printf("Enter 1'st number: ");
    scanf("%f", &n);

    float arr[100];
    int index = 0;

    while(n != 0){
        arr[index++] = n;

        printf("Enter the next number: ");
        scanf("%f", &n);
    }

    qsort(arr, index, sizeof(float), compare);

    FILE *out = fopen("rezultat.txt", "w");
    if(out == NULL){
        perror("Eroare la deschiderea fisierului!");
        exit(-1);
    }

    writeArray(out, arr, index);

    if(fclose(out) != 0){
        perror("Eroare la inchiderea fisierului!");
        exit(-1);
    }
    return 0;
}