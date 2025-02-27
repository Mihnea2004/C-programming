#include <stdio.h>
#include <string.h>

int isVowel(char c) {
    char vowels[] = "aeiou";
    for(int i = 0; i < strlen(vowels); i++)
        if(c == vowels[i])
            return 1;
    return 0;
}

int main () {
    char s[100];

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    for(int i = 0; i < strlen(s); i++){
        if(isVowel(s[i]))
            s[i] = s[i] + 1;
    }
    
    printf("%s", s);
}
