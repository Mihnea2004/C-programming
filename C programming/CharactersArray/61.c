#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s1[20];
    printf("Enter the last name of a person: ");
    fgets(s1, sizeof(s1), stdin);

    char s2[20];
    printf("Enter the first name: ");
    fgets(s2, sizeof(s2), stdin);

    char result[40];
    int index = 0;

    for(int i = 0; i < strlen(s2); i++)
        if(isalpha(s2[i]) && strchr("aeiou", s2[i]) == NULL)
            result[index++] = s2[i];

    strcat(result, " ");
    strcat(result, s1);

    printf("New string is: %s", result);

    return 0;
}
