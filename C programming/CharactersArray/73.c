#include <stdio.h>
#include <string.h>

int main() {
    char text[101];
    printf("Enter a text: ");
    fgets(text, sizeof(text), stdin);

    int i, j;
    int spaceCount = 0;///spatii consecutive

    for (i = 0, j = 0; i < strlen(text); i++) {
        if (text[i] == ' ')
            spaceCount++;
        else
            spaceCount = 0;

        if (spaceCount <= 1)
            text[j++] = text[i];
    }

    text[j] = '\0'; 

    printf("%s\n", text);

    return 0;
}

