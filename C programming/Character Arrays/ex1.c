#include <stdio.h>
#include <string.h>
#include <ctype.h>

void capitalizeWords(char s[]) {
    char temp[100]; //salvez intr-un vector auxiliar, altfel nu imi face trecerea la urmatorul cuvant
    strcpy(temp, s);
    char *token = strtok(temp, " ");

    while (token != NULL) {
        char *position = strstr(s, token);
        if (position != NULL)
            position[0] = toupper(position[0]);
        token = strtok(NULL, " ");
    }
}

int main() {
    char s[100];
    printf("Enter a row: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    capitalizeWords(s);
    printf("%s\n", s);
    return 0;
}
