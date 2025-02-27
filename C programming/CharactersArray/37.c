#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countVowels(char s[]) {
    int vowels = 0;
    for(int i = 0; i < strlen(s); i++)
        if(isalpha(s[i]) && strchr("aeiou", s[i]) != NULL)
            vowels++;
    return vowels;
}

int countConsonants(char s[]) {
    int consonants = 0;
    for(int i = 0; i < strlen(s); i++)
        if(isalpha(s[i]) && strchr("aeiou", s[i]) == NULL)
            consonants++;
    return consonants;
}

int main() {
    char s[101];
    printf("Introduceti textul: ");
    fgets(s, sizeof(s), stdin);

    int found = 0;

    char *token = strtok(s, " ");

    while (token != NULL) {
        if(countVowels(token) < countConsonants(token)) {
            printf("%s\n", token);
            found = 1;
        }
        token = strtok(NULL, " ");
    }

    if (!found)
        printf("doesn't exist!\n");

    return 0;
}

