#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int count = 0;

    printf("Enter a string: ");
    fgets(s, 99, stdin);

    for(int i = 0; i <= strlen(s); i++) {
        if(s[i] == ' ' || s[i] == '\n')
            count++;
    }

    printf("String has %d words", count);
    return 0;
}
