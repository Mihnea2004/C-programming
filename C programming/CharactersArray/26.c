#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[100];

    printf("Enter a sentance: ");
    fgets(s, 100, stdin);
    s[strcspn(s, "\n")] = '\0';

    char *token = strtok(s, " ");

    while(token != NULL) {
        for(int i = 0; i < strlen(s); i++) {
            if(islower(s[0]))
                s[0] = toupper(s[0]);
            if(islower(s[strlen(s)-1]))
                s[strlen(s)-1] = toupper(s[strlen(s)-1]);
        }
        token = strtok(NULL, " ");
    }

    printf("New sentance is: %s", s);
    return 0;
}
