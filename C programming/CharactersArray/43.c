#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isVowel(char c) {
    char vowels[] = "aeiou";
    for(int i = 0; i < strlen(vowels); i++)
        if(c == vowels[i])
            return 1;
    return 0;
}

void generateClones(char s[]) {
    for(int i = 0; i < strlen(s); i++) {
        if(isVowel(s[i])) {
            for(int j = 0; j < strlen(s); j++)
                if(j != i) 
                    printf("%c", s[j]);
            printf("\n");
        }
    }
}

int main() {
    char s[20];

    printf("Enter a word: ");
    scanf("%s", s);

    printf("Clones are:\n");
    generateClones(s);

    return 0;
}
