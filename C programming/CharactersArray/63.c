#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isVowel(char c) {
    if(strchr("aeiou", c) != NULL)
        return 1;
}

int main() {
    char s[201];
    printf("Enter first string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    char x[201];
    printf("Enter second string: ");
    fgets(x, sizeof(x), stdin);
    x[strcspn(x, "\n")] = '\0';

    for(int i = 0; i < strlen(s); i++) {
        if(isVowel(s[i]) && isVowel(x[i]))
            printf("%c", '*');
        else if(!isVowel(s[i]) && !isVowel(x[i]))
            printf("%c", '#');
        else
            printf("%c", '?');
    }
    return 0;
}