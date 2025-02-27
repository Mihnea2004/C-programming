#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[101];
    printf("Enter a text: ");
    fgets(text, sizeof(text), stdin);

    int length = strlen(text);
    if (text[length - 1] == '\n')
        text[length - 1] = '\0';

    char* word = strtok(text, " ");
    int modified = 0;

    while (word != NULL) {
        int wordLength = strlen(word);
        if (wordLength >= 3 && wordLength % 2 == 1) {
            int middleIndex = wordLength / 2;
            strcpy(word + middleIndex, word + middleIndex + 1);
            modified = 1;
        }
        word = strtok(NULL, " ");
    }

    if (modified)
        printf("Modified text is: %s\n", text);
    else
        printf("Error!\n");

    return 0;
}