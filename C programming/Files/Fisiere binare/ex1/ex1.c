#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void readAndWriteNo(FILE *f, FILE *out){
    uint32_t aux;
    while(fread(&aux, sizeof(uint32_t), 1, f) == 1){
        fprintf(out, "%08X ", aux);
    }
}

int main(){
    FILE *f = fopen("integers.bin", "rb");
    if(f == NULL){
        perror("integers.bin");
        exit(-1);
    }

    FILE *out = fopen("rezultat.txt", "w");
    if(out == NULL){
        perror("rezultat.txt");
        exit(-1);
    }

    readAndWriteNo(f, out);

    if(fclose(f) < 0){
        perror(NULL);
        exit(-1);
    }

    if(fclose(out) < 0){
        perror(NULL);
        exit(-1);
    }
}