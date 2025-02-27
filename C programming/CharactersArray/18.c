#include <stdio.h>
#include <string.h>

int main() {
    char s[50];
    int count = 0;
    char vowels[] = "aeiou";

    printf("Enter a string: ");
    scanf("%s", s);

    for(int i = 0; i < strlen(s); i++) {
        if(strchr(vowels, s[i]) != NULL)
            count++;
    }

    printf("Word has %d vowels", count);
    return 0;
}
