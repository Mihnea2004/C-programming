#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[100];

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    char *token = strtok(s, " \n");

    while(token != NULL) {
        token[0] = toupper(token[0]);
        printf("%s ", token);
        token = strtok(NULL, " \n");
    }

    return 0;
}