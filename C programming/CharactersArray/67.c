#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[50];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    char *token = strtok(s, " ");
    while (token != NULL)
    {
        token[0] = toupper(token[0]);
        token[strlen(token) - 1] = toupper(token[strlen(token) - 1]);

        printf("%s ", token);
        token = strtok(NULL, " ");
    }

    return 0;
}
