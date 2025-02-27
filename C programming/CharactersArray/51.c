#include <stdio.h>
#include <string.h>
#include <ctype.h>

void eliminateConsonants(char s[]){
    for(int i = 0; i < strlen(s); i++){
        if(strchr("aeiou", s[i]) != NULL)
            printf("%c", s[i]);
    }
}

int main () {
    char s[20], result[20], index = 0;

    printf("Enter a word: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    eliminateConsonants(s);
    return 0;
}