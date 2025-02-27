#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isVowel(char s) {
    if(isalpha(s) && strchr("aeiouAEIOU", s) != NULL)
        return s;
}

int main() {
    char s[100];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    for(int i = 0; i < strlen(s); i++) {
        if(isVowel(s[i]))
            printf("%c*", s[i]);
        else
            printf("%c", s[i]);
    }

    return 0;
}
