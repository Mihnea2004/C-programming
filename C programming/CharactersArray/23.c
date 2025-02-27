#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *s;
    s = malloc(101 * sizeof(char));
    printf("Enter a word: ");
    fgets(s, 101, stdin);
    s[strcspn(s, "\n")] = '\0';

    for(int i = 0; i < strlen(s); i++) {
        for(int j = 0; j <= i; j++)
            printf("%c", s[j]);
        printf("\n");
    }

    free(s);

    return 0;
}
