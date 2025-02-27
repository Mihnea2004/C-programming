#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

int main() {
    char s[101], result[202];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    int index = 0;

    for(int i = 0; i < strlen(s); i++){
        if(strchr("aeiou", s[i]) != NULL)
            result[index++] = s[i];
        result[index++] = s[i];
    }
    result[index] = '\0';
    printf("%s", result);
    return 0;
}

