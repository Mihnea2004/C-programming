#include <stdio.h>
#include <string.h>

int main() {
    char s[50];

    printf("Enter a string: ");
    scanf("%s", s);

    for(int i = 0; i < strlen(s); i++)
        printf("%c\n", s[i]);

    printf("New string: %s", s);
    return 0;
}
