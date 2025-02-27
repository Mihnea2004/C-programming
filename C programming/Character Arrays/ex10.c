#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *f = fopen("produse.txt", "r");
    if (f == NULL) {
        perror("Eroare la deschiderea fișierului!");
        exit(-1);
    }

    char linie[100];
    char produs[15];
    float pret;
    float pretMax = -1;
    char produsMax[16];

    while(fgets(linie, sizeof(linie), f)){
        linie[strcspn(linie, "\n")] = '\0';

        if(sscanf(linie, "%15s, %f", produs, &pret) == 2){
            if(pret > pretMax){
                pretMax = pret;
                strcpy(produsMax, produs);
            }
            else{
                fprintf(stderr, "Format invalid!\n");
            }
        }
    }
    
    if(strlen(produsMax) > 0)
        printf("Produs cu pret maxim: %s - %.2f\n", produsMax, pretMax);
    else
        printf("Nu s-au gasit produse valide in fisier!");

    if(fclose(f) != 0){
        perror("Error closing file!");
        exit(-1);
    }
}