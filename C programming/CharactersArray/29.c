#include <stdio.h>
#include <string.h>

int main() {
    char s[100];

    printf("Enter a word: ");
    scanf("%s", s);

    for(int i = 0; i < strlen(s); i++) {
        if(strchr("aeiou", s[i]) != NULL)
            printf("%c*", s[i]);
        else
            printf("%c", s[i]);
    }
    return 0;
}
