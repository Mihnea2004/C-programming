#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

int main() {
    char s[101];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    char *token = strtok(s, " ");
    while(token != NULL){
        if(strlen(token) == 3)
            printf("* ");
        else
            printf("%s ", token);

        token = strtok(NULL, " ");
    }

    return 0;
}

