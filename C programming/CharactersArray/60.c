#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isVowel(char c) {
    char vowels[] = "aeiouAEIOU";
    for(int i = 0; i < strlen(vowels); i++)
        if(c == vowels[i])
            return 1;
    return 0;
}

int main() {
    char s[201];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    int count = 0;
    char *token = strtok(s, " ");
    while(token != NULL){
        if(isVowel(token[0]) && isVowel(token[strlen(s)-1]))
            count ++;
        token = strtok(NULL, " ");
    }
    if(count)
        printf("Number of words is %d", count);
    else
        printf("Doesn't exist!\n");
    return 0;
}