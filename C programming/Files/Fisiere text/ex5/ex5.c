#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABETH_SIZE 26

void calculateHistogram(FILE *f, char *out){
    int freq[ALPHABETH_SIZE] = {0};
    long index = 0;

    char c;
    while((c = fgetc(f)) != EOF){ //citim fisierul caracter cu caracter
        if(isalpha(c)){
            c = tolower(c);
            freq[c - 'a']++; //index-ul lui a este 0, b = 2, c = 2 in vectorul de frecventa
            index++;
        }
    }

    for(int i = 0; i < ALPHABETH_SIZE; i++){
        if(freq[i] > 0){
            float procentaj = (float)freq[i] / index * 100;
            fprintf(out, "%c - %.2f %%\n", 'a' + i, procentaj);
        }
    }
}

int main(){
    FILE *f = fopen("scrisoare.txt", "r");
    FILE *out = fopen("histo.txt", "w");
    if(f == NULL){
        perror("Eroare la deschiderea fisierului!");
        exit(-1);
    }

    if(out == NULL){
        perror("Eroare la deschiderea fisierului!");
        exit(-1);
    }

    calculateHistogram(f, out);

    if(fclose(f) != 0){
        perror("Eroare la inchiderea fisierului!");
        exit(-1);
    }

    if(fclose(out) != 0){
        perror("Eroare la inchiderea fisierului!");
        exit(-1);
    }
}