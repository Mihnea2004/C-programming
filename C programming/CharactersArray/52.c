#include <stdio.h>
#include <string.h>
#include <ctype.h>

int firstVowel(char *s){
    for(int i = 0; i < strlen(s); i++)
        if(strchr("aeiou", s[i]))
            return i;
}

int lastVowel(char *s){
    for(int i = strlen(s)-1; i >= 0; i--)
        if(strchr("aeiou", s[i]))
            return i;
}

char *eliminate(char *s) {
    int first = firstVowel(s);
    int last = lastVowel(s);
    
    // ana + 1 =>  n 
    // ana + 2 => a
    strcpy(s + first, s + first + 1); 
    strcpy(s + last, s + last + 1); 
    return s;
}

int main() {
    char s[21];
    printf("Enter the word: ");
    scanf("%s", s);

    printf("%s", eliminate(s));
    return 0;
}