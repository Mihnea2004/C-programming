#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {
    char s[51];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    for(int i = 0; i < strlen(s); i++) {
        if(isalpha(s[i]))
            printf("%c", s[i]);
    }
    return 0;
}
