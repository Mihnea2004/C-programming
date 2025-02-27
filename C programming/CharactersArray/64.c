#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isVowel(char c) {
    if(strchr("aeiouAEIOU", c) != NULL)
        return 1;
}

char firstConsonantPosition(char *s){
    for(int i = 0; i < strlen(s); i++)
        if(!isVowel(s[i])){
            return i;
            break;
        }
}

char lastVowelPosition(char *s){
    for(int i = strlen(s)-1; i >= 0; i--)
        if(isVowel(s[i])){
            return i;
            break;
        }
}

void interchange(char *s) {
    for(int i = 0; i < strlen(s); i++){
        char x = firstConsonantPosition(s);
        char y =lastVowelPosition(s);
        char temp = s[x];
        s[x] = s[y];
        s[y] = temp;
        break;
        }

    printf("Word after interchange is: %s", s);
}

int main() {
    char s[20];
    printf("Enter a word: ");
    scanf("%19s", s);

    interchange(s);

    return 0;
}