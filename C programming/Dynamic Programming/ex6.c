/*
Să se scrie o funcție care primește ca argument un string și returnează 
un alt string alocat dinamic în care fiecare caracter din string-ul 
inițial va fi înlocuit cu valoarea în hexazecimal a caracterului conform 
tabelei ASCII în format text pe strict două cifre hexazecimale fără 
prefixul 0x. Antetul funcției poate fi următorul:
char *text2hex(const char *string);
Exemplu: string = "abc" -> funcția va returna un string de forma "616263"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *text2hex(char *s){
    int len = strlen(s);
    char *result = malloc((2 * len + 1) * sizeof(char));

    for(int i = 0; i < len; i++){
        sprintf(result + 2 * i, "%02X", s[i]);
    }

    return result;
}

int main(){
    char s[50];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    char *result = text2hex(s);
    printf("Result: %s\n", result);

    free(result);
}