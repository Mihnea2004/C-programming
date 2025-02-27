#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK 16

typedef struct{
    char judet[20]; //0
    long int populatie; //1
    int beneficiariPlatiti; //2
    long int suma; //4
    long int altePlati; //5
}Indemnizatie;

int processLine(char *linie, Indemnizatie *ind){
    char *token = strtok(linie, ";");
    if(token == NULL)
        return 0;

    for(int i = 0; i < 7; i++){
        switch(i){
            case 0:
                strcpy(ind->judet, token);
                break;
            case 1:
                ind->populatie = strtol(token, NULL, 10);
                break;
            case 2:
                ind->beneficiariPlatiti = strtol(token, NULL, 10);
                break;
            case 4:
                ind->suma = strtol(token, NULL, 10);
                break;
            case 5:
                ind->altePlati = strtol(token, NULL, 10);
                break;
        }
        token = strtok(NULL, ";");
        if(token == NULL && i < 5)
            return 0;
    }
    return 1;
}

void afisare(Indemnizatie *in, int index){
    for(int i = 0; i < index; i++)
        printf("%d. Judetul %s are %d beneficiari platiti, iar suma totala platita pt drepturile curente este %ld!\n", i + 1, in[i].judet, in[i].beneficiariPlatiti, in[i].suma);
    printf("\n");
}

int comparaDupaJudet(const void *e1, const void *e2){
    Indemnizatie *a = (Indemnizatie*) e1;
    Indemnizatie *b = (Indemnizatie*) e2;

    return strcmp(a -> judet, b -> judet);
}

int comparaDupaSumaPlatita(const void *e1, const void *e2){
    Indemnizatie *a = (Indemnizatie*) e1;
    Indemnizatie *b = (Indemnizatie*) e2;

    return (b -> suma - a -> suma);
}

void cautaMaxime(FILE *out, Indemnizatie *in, int index){
    Indemnizatie maxP = in[0];
    Indemnizatie maxA = in[0];

    for(int i = 1; i < index; i++){
        if(in[i].populatie > maxP.populatie)
            maxP.populatie = in[i].populatie;
        if(in[i].altePlati > maxA.populatie)
            maxA.populatie = in[i].altePlati;
    }

    fprintf(out, "Judetul cu cea mai mare populatie este: %s - %ld\n", maxP.judet, maxP.populatie);
    fprintf(out, "Judetul cu cea mai mare suma din alte plati este: %s - %ld\n", maxA.judet, maxA.altePlati);
}

int main(){
    FILE *f = fopen("indemnizatie.txt", "r");
    if(f == NULL){
        perror("Eroare la deschiderea fisierului!");
        exit(-1);
    }

    char linie[200];
    Indemnizatie ind;
    int currentSize = 0;

    if(fgets(linie, 200, f) == NULL)
        return -1;

    Indemnizatie *in = NULL;
    int index = 0;

    while(fgets(linie, 200, f) != NULL){
        if(processLine(linie, &ind) == 1){
            if(index == currentSize){
                currentSize += CHUNK;
                in = (Indemnizatie*) realloc(in, currentSize * sizeof(Indemnizatie));
                if(in == NULL){
                    perror("Memorie insuficienta!");
                    exit(-1);
                }
            }
            in[index++] = ind;
        }
    }

    if(fclose(f) != 0){
        perror("Eroare la inchiderea fisierului!");
        exit(-1);
    }

    qsort(in, index, sizeof(Indemnizatie), comparaDupaJudet);
    printf("Sortare dupa judet: \n");
    afisare(in, index);
    printf("\n\n");

    qsort(in, index, sizeof(Indemnizatie), comparaDupaSumaPlatita);
    printf("Sortare dupa suma totala platita drepturi curente: \n");
    afisare(in, index);
    printf("\n\n");

    FILE *out = fopen("rezultat.txt", "w");
    if(out == NULL){
        perror("Eroare la deschiderea fisierului!");
        exit(-1);
    }

    cautaMaxime(out, in, index);

    if(fclose(out) != 0){
        perror("Eroare la inchiderea fisierului!");
        exit(-1);
    }

    free(in);
    return 0;
}