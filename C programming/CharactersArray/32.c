#include <stdio.h>
#include <string.h>

int main() {
    char s[100];

    printf("Enter a string: ");
    gets(s);

    for(int i = 0; i < strlen(s); i++) {
        if(strchr("aeiou", s[i]))
            printf("%c ", s[i]);
    }
    return 0;
}
