#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[40];

    printf("Entetr a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    int found = 0;

    for(int i = 0; i < strlen(s); i++) {
        if(isalpha(s[i]) && strchr("aeiou", s[i]) != NULL)
            printf("%c ", s[i]);
        found = 1;
    }

    if(found == 0)
        printf("Doesn't exist!");
    return 0;
}
