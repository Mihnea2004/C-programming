#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countLetters(char s[], int count[26]){
    for(int i = 0; i < strlen(s); i++)
        if(isalpha(s[i]))
            count[s[i] - 'a']++;  //a in cod ASCII este 97
        //daca s[i] = 'z' => count[25]++;
} 

void printLetterCounts(int count[26]){
    for(int i = 0; i < 26; i++)
        if(count[i] > 0)
            printf("Letter %c appears %d times in array!\n", 'a' + i, count[i]);
}

int main(){
    char s[100];
    int count[26] = {0};

    printf("Enter the text: ");
    fgets(s, sizeof(s), stdin);\
    s[strcspn(s, "\n")] = '\0';

    countLetters(s, count);
    printLetterCounts(count);

    return 0;
}