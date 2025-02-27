#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *insertPa(char *s){
    int len = 0;

    //aflam lungimea string-ului citit
    for(int i = 0; s[i] != '\0'; i++){
        if(strchr("aeiou", s[i]) != NULL)
            len = len + 3;
        else
            len = len + 1;
    }

    char *result = (char*) malloc((len + 1) * sizeof(char));
    if(result == NULL){
        perror("Error!");
        exit(-1);
    }

    int index = 0;
    for(int i = 0; i < len; i++){
        if(strchr("aeiou", s[i]) != NULL){
            result[index++] = s[i];
            result[index++] = 'p';
            result[index++] = 'a';
        }
        else
            result[index++] = s[i];
    }

    result[index] = '\0';
    return result;
}

int main(){
    char s[100];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    char *result = insertPa(s);
    printf("%s", result);

    free(result);
    printf("\n");

    return 0;
}