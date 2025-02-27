#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

int findLastConsonant(char *s) {
    int n = strlen(s) - 1;
    for(int i = n; i >= 0; i--) 
        if(isalpha(s[i]) && strchr("aeiou", s[i]) == NULL)
            return i;
    return -1;
}

int main() {
    char s[256];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    int position = findLastConsonant(s);
    if(position) {
        for(int i = position; i < strlen(s)-1; i++)
            s[i] = s[i+1];
        s[strlen(s)-1] = '\0';
    }
    printf("New string is: %s", s);
    return 0;
}

