#include <stdio.h>
#include <string.h>

///finds first vowel
int firstVowel(char *s) {
    for(int i = 0; i < strlen(s); i++)
        if(strchr("aeiou", s[i]))
            return i;
}

///finds last consonant
int lastConsonant(char *s) {
    int n = strlen(s)-1;
    for(int i = n; i > 0; i--)
        if(!strchr("aeiou", s[i]) )
            return i;
}

int main() {
    char s[100];

    printf("Enter a word: ");
    scanf("%s", s);

    int x =  firstVowel(s);
    int y =  lastConsonant(s);

    char temp = s[x];
    s[x] = s[y];
    s[y] = temp;

    printf("Word after interchange is: %s", s);
    return 0;
}