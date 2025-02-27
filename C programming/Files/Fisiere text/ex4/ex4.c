/*
Se considera un fisier text ce contine un numar necunoscut de linii de 
text de o dimensiune necunoscuta. Sa se scrie un program ce citeste un 
astfel de fisier si stocheaza datele intr-un tablou alocat dinamic de 
string-uri C alocate dinamic. Se va folosi o amprenta minima de memorie. 
Se vor scrie de asemenea si urmatoarele functii: 
    o functie void write_sort(char **lines, char *filepath); - functia va 
prelua tabloul de linii, le va sorta alfabetic si le va scrie in fisierul
cu calea filepath. Se va realiza conex si o functie de sortare a tabloului 
de linii lines. Se poate folosi bubble-sort. Pentru compararea 
aflabetica a doua linii se poate folosi functia strcmp(...) 
    o functie void write_random(char **lines, char *filepath); - functia va prelua 
tabloul de linii si le va scrie in fisierul referit prin calea filepath 
in ordine aleatoare a liniilor. Hint! Se poate folosi functia rand(...); 
    o functie uint32_t find_word(char **lines, char *word); - functia va cauta
 cuvantul referit prin word in tabloul de linii lines si va returna 
numarul de aparitii.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_CHUNK 10
#define TEXT_CHUNK 10

char *readLine(FILE *f){
    char *line = NULL; //vector de linii alocat dinamic
    char ch = 0;
    int index = 0, currentSize = 0;

    while((ch = fgetc(f)) != EOF){
        if(index == currentSize){
            currentSize += LINE_CHUNK;
            line = (char*) realloc(line, currentSize * sizeof(char));
            if(line == NULL){
                perror("Memorie insuficienta!");
                exit(-1);
            }
        }
        // if(ch == '\n')
        //     break;
    
        line[index++] = ch;
    }

    if(line == NULL || index == 0){
        free(line);
        return NULL;
    }

    line[index] = '\0';
    return line;
}

char **readLines(FILE *f){
    char **lines = NULL;
    char *line = NULL;
    int index = 0, currentSize = 0;

    while((line = readLine(f)) != NULL){
        if(index == currentSize){
            currentSize += TEXT_CHUNK;
            lines = (char**) realloc(lines, currentSize * sizeof(char*));
            if(lines == NULL){
                perror("Error alocating lines!");
                exit(-1);
            }
        }
        lines[index++] = line;
    }

    if(lines == NULL)
        return NULL;

    lines[index] = NULL;
    return lines;
}

void printLines(char **lines){
    int index = 0;
    while(lines[index] != NULL){
        printf("%s\n", lines[index]);
        index++;
    }
}

void freeLines(char **lines){
    int index = 0;
    while(lines[index] != NULL){
        free(lines[index]);
        index++;
    }
    free(lines);
}

int main(){
    FILE *f = fopen("scrisoare.txt", "r");
    if(f == NULL){
        perror("Eroare la deschiderea fisierului!");
        exit(-1);
    }

    char **lines = NULL;
    if((lines = readLines(f)) == NULL){
        printf("Eroare!");
        exit(-1);
    }

    printLines(lines);
    freeLines(lines);

    if(fclose(f) != 0){
        perror("Eroare la inchiderea fisierului!");
        exit(-1);
    }
}