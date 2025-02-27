#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int count = 0;
    int i;

    printf("Enter a string: ");
    scanf("%s", s);

    for(i = 0; i < strlen(s); i++) {
        if(s[i] == 'a')
            count++;
    }
    printf("Character 'a' appears %d times", count);
    return 0;
}
