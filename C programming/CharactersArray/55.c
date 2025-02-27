#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[11]; /// șirul de caractere pentru citirea datelor
    double number; /// variabila pentru stocarea numărului real

    printf("Introduceti un numar real: ");
    scanf("%s", s);

    /// convertim șirul de caractere la număr real
    number = atof(s);

    /// extragem partea întreagă și partea zecimală
    int integerPart = (int)number;

    /// înmulțim cu 1000 pentru a obține primele 3 cifre după virgulă
    int decimalPart = (int)((number - integerPart) * 1000);

    printf("Valoarea obtinuta prin adunarea partii intregi si a partii zecimale este: %d\n", integerPart + decimalPart);

    return 0;
}
