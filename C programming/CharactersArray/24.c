#include <stdio.h>

int main() {
    char s[100];

    printf("Enter a word: ");
    scanf("%s", s);

    for(int i = 0; i < strlen(s); i++) {
        printf("%s\n", s + i);
    }
    return 0;
}
