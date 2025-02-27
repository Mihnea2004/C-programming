#include <stdio.h>
#include <string.h>

typedef struct{
    char nume[100];
    float cantitate;
    float pretUnitar;
}Produs;

void afiseaza(Produs produse[], int n){
    for(int i = 0; i < n; i++)
        printf("%s: %.2f, %.2f\n", produse[i].nume, produse[i].cantitate, produse[i].pretUnitar);
}

int main(){
    int n;
    printf("n = ");
    scanf("%d", &n);
    getchar();

    Produs produse[n];
    
    for(int i = 0; i < n; i++){
        printf("Nume: ");
        scanf("%19s", produse[i].nume);

        printf("Cantitate: ");
        scanf("%f", &produse[i].cantitate);

        printf("Pret Unitar: ");
        scanf("%f", &produse[i].pretUnitar);
        printf("\n");
    }

    for(int i = 0; i < n; i++)
        produse[i].pretUnitar *= produse[i].cantitate;

    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            if(strcmp(produse[i].nume, produse[j].nume) == 0){
                produse[i].cantitate += produse[j].cantitate;
                produse[i].pretUnitar += produse[j].pretUnitar;

                for(int k = j; k < n; k++)
                    produse[k] = produse[k + 1];
                n--;
            }
        }
    }

    printf("Produse: \n");
    afiseaza(produse, n);

    float pretGlobal = 0;
    for(int i = 0; i < n; i++)
        pretGlobal += produse[i].pretUnitar;

    printf("\nPret global: %.2f\n", pretGlobal);
}