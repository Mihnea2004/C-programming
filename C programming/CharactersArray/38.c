#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char s[21];

    printf("Enter a word: ");
    scanf("%s", s);

    for(int i = 0; s[i] != '\0'; i++) {
        if(isalpha(s[i]) && strchr("aeiou", s[i]) != NULL)
            printf("%c%c", s[i], toupper(s[i]));
        else
            printf("%c", s[i]);
    }
    return 0;
}
