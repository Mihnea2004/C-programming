#include <stdio.h>
#include <string.h>

int main() {
    char s[100];

    printf("Enter the name of a institution or organisation: ");
    fgets(s, 100, stdin);

    char *token = strtok(s, " ");

    while(token != NULL) {
        if(isupper(token[0]))
           printf("%c.", token[0]);
        token = strtok(NULL, " ");
    }
    return 0;
}
