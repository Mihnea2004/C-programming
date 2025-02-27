#include <stdio.h>
#include <string.h>

void eliminateVowels(char *s) {
    int j = 0;
    char vowels[] = "aeiou";
    for(int i = 0; i < strlen(s); i++) {
        if(!strchr(vowels, s[i])) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

int main() {
    char s[100];

    printf("Enter a string: ");
    fgets(s, 99, stdin);
    eliminateVowels(s);

    printf("String without vowels is: %s", s);
    return 0;
}
