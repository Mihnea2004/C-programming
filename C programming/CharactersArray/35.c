#include <stdio.h>
#include <string.h>

int main() {
    char s[102], word[102];

    printf("Enter a text: ");
    fgets(s, 102, stdin);
    s[strcspn(s, "\n")] = '\0';

    printf("Enter the word to be inserted: ");
    fgets(word, 102, stdin);
    word[strcspn(word, "\n")] = '\0';

    char *token = strtok(s, " ");
    char lastLetter = '\0';
    char result[200] = "";

    while(token != NULL) {
        if(lastLetter == token[strlen(token) - 1])
            strcat(result, "succes ");

        strcat(result, token);
        strcat(result, " ");

        lastLetter = token[strlen(token) - 1];
        token = strtok(NULL, " ");
    }

    printf("%s\n", result);

    return 0;
}
