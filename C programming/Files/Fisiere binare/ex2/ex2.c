#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define CHUNK 8

void BubbleSort(uint32_t *v, uint32_t n){
	int s,i,aux;
	do{
		s = 0;                             
		for (i = 1; i < n; i++){      
			if (v[i - 1] < v[i]){             
				aux = v[i - 1];                 
				v[i - 1] = v[i];
				v[i] = aux;
				s = 1;                            
			}
		}
	} while (s);                         
}

uint32_t *readFromFile(FILE *f, uint32_t *size){
    uint32_t index = 0, currentSize = CHUNK;
    uint32_t *v = (uint32_t *) malloc(currentSize * sizeof(uint32_t));
    if(v == NULL){
        perror(NULL);
        exit(-1);
    }

    uint32_t aux;

    while(fread(&aux, sizeof(uint32_t), 1, f) == 1){
        if(index == currentSize){
            currentSize += CHUNK;
            v = realloc(v, currentSize * sizeof(uint32_t));
            if(v == NULL){
                perror(NULL);
                exit(-1);
            }
        }
        v[index++] = aux;
    }

    *size = index;
    return v;
}

void writeInFile(FILE *out, uint32_t *v, int index){
    for(int i = 0; i < index; i++)
        fprintf(out, "%d\n", v[i]);
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

    uint32_t index = 0;
    uint32_t *v = NULL;
    v = readFromFile(f, &index);

    BubbleSort(v, index);
    writeInFile(out, v, index);

    if(fclose(f) < 0){
        perror(NULL);
        exit(-1);
    }

    if(fclose(out) < 0){
        perror(NULL);
        exit(-1);
    }

    free(v);

    return 0;
}