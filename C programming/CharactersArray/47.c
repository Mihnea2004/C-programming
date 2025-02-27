#include <stdio.h>
#include <string.h>

int main() {
    char s[255], word[50];

    printf("Enter a text: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    ///eliminate the first word
    char *firstWord = strtok(s, "*");
    printf("*");

    ///goes to the next word
    char *nextWord = strtok(NULL, "*");

    while(nextWord != NULL) {
        if(strcmp(firstWord, nextWord) != 0)
            printf("%s", nextWord);

        printf("*");

        nextWord = strtok(NULL, "*");

    }
    return 0;
}
