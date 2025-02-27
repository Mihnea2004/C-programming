#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK 16

typedef struct{
    char titlu[100];
    int an;
    long int buget;
}Film;

int processLine(char *linie, Film *film){
    char *token = strtok(linie, ",");
    if(token == NULL)
        return 0;

    for(int i = 0; i < 7; i++){ //0-year, 2-title, 6-budget
        switch(i){
            case 0:
                film -> an = strtol(token, NULL, 10); //10 e baza, token e string-ul de convertit
                break;
            case 2:
                strcpy(film -> titlu, token);
                break;
            case 6:
                film -> buget = strtol(token, NULL, 10);
                break;
        }
        token = strtok(NULL, ",");
        if(token == NULL)
            return 0;
    }
    return 1;
}

void printMovies(Film *filme, int index){
    for(int i = 0; i < index; i++)
        printf("%d: Filmul %s, lansat in anul %d, a avut un buget de %ld euro!\n", i + 1, filme[i].titlu, filme[i].an, filme[i].buget);
    printf("\n");
}

void writeInFile(FILE *f, Film *filme, int index){
    for(int i = 0; i < index; i++)
        fprintf(f, "%d: Filmul %s, lansat in anul %d, a avut un buget de %ld euro!\n", i + 1, filme[i].titlu, filme[i].an, filme[i].buget);
    printf("\n");
}

int comparareDupaAn(const void *e1, const void *e2){
    Film *a = (Film*) e1;
    Film *b = (Film*) e2;

    return (a -> an < b -> an) ? -1 : 1;
}

void sortareDupaAnulAparitiei(Film *filme, int index){
    FILE *f2 = fopen("out1.txt", "w");
    if(f2 == NULL){
        perror("Error opening file!");
        exit(-1);
    }

    qsort(filme, index, sizeof(Film), comparareDupaAn);
    writeInFile(f2, filme, index);

    if(fclose(f2) != 0){
        perror("Error closing file!");
        exit(-1);
    }
}

int comparaDupaTitlu(const void *e1, const void *e2){
    Film *a = (Film*) e1;
    Film *b = (Film*) e2;

    return (strcmp(a -> titlu, b -> titlu) < 0) ? -1 : 1;
}

void sortareDupaTitlu(Film *filme, int index){
    FILE *f3 = fopen("out2.txt", "w");
    if(f3 == NULL){
        perror("Error opening file!");
        exit(-1);
    }

    qsort(filme, index, sizeof(Film), comparaDupaTitlu);
    writeInFile(f3, filme, index);

    if(fclose(f3) != 0){
        perror("Error closing file!");
        exit(-1);
    }
}

int comparaDupaBuget(const void *e1, const void *e2){
    Film *a = (Film*) e1;
    Film *b = (Film*) e2;

    return (a -> buget < b -> buget) ? -1 : 1;
}

void sortareDupaBuget(Film *filme, int index){
    FILE *f = fopen("out3.txt", "w");
    if(f == NULL){
        perror("Error opening file!");
        exit(-1);
    }

    qsort(filme, index, sizeof(Film), comparaDupaBuget);
    writeInFile(f, filme, index);

    if(fclose(f) != 0){
        perror("Error closing file!");
        exit(-1);
    }
}

int main(){
    FILE *f = fopen("movies.txt", "r");
    if(f == NULL){
        perror("Error opening file!");
        exit(-1);
    }

    Film *filme = NULL;
    int index = 0, currentSize = 0;

    Film film; //doar un singur film!
    char linie[200];
    if(fgets(linie, 200, f) == NULL) //consum prima linie = antetul tabelului
        return -1;

    while(fgets(linie, 200, f) != NULL){
        if(processLine(linie, &film) == 1){
            if(index == currentSize){
                currentSize += CHUNK;
                filme = (Film*) realloc(filme, currentSize * sizeof(Film));
                if(filme == NULL){
                    perror("Memorie insuficienta!");
                    exit(-1);
                }
            }
            filme[index++] = film;
        }
    }

    //printMovies(filme, index);

    if(fclose(f) != 0){
        perror("Error closing file!");
        exit(-1);
    }

    FILE *f1 = fopen("scriere.txt", "w");
    if(f1 == NULL){
        perror("Error opening file!");
        exit(-1);
    }

    writeInFile(f1, filme, index);
    sortareDupaAnulAparitiei(filme, index);
    sortareDupaTitlu(filme, index);
    sortareDupaBuget(filme, index);

    if(fclose(f1) != 0){
        perror("Error closing file!");
        exit(-1);
    }

    free(filme);
    return 0;
}