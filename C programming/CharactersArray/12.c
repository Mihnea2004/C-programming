#include <stdio.h>

int main() {
    char s[100];
    char c;
    int i = 0;

    printf("Enter a caracter: ");
    scanf("%c\n", c);

    while(c != '-') {
        s[i++] = c;
        printf("Enter another character: ");
        scanf("%c\n", c);

    }
    s[i] = '\0';
    printf("Introduced string is: %s\n", s);

    return 0;
}
