/*
Să se scrie o funcție care primește ca argument un string ce conține în format text valori în hexazecimal pe două cifre hexazecimale fără prefixul 0x.
 Aceste valori reprezintă caractere conform tabelei ASCII. Funcția va decodifica textul și il va returna într-un string alocat dinamic. 
 Antetul funcției poate fi următorul:
char *hex2text(const char *hexstring);
Exemplu: hexstring = "616263" -> funcția va returna string-ul "abc"

Această problemă reprezintă inversa funcției dezvoltate la problema anterioară.

Pentru testare se pot folosi datele din fisierul ce se poate descarca prin comanda urmatoare
wget http://staff.cs.upt.ro/~valy/pt/hexlines.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *hex2text(char *s){
    int len = strlen(s);
    char *result = malloc((len / 2 + 1) * sizeof(char));

    for(int i = 0; i < len; i += 2){
        char hexpair[3] = {s[i], s[i + 1], '\0'};
        result[i / 2] = (char) strtol(hexpair, NULL, 16);
    }

    result[len / 2] = '\0';

    return result;
}

int main(){
    char s[50];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    char *result = hex2text(s);
    printf("Result: %s\n", result);

    free(result);
}