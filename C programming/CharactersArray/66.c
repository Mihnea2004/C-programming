#include <stdio.h>
#include <string.h>

///cum ii zic calculatorului sa imi puna '?' dupa un cuvant? (nu dupa o litera)
int main() {
    char s[100];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    char word[15];
    printf("Enter the word after that should be put character '?': ");
    scanf("%s", word);

    char *token = strtok(s, " ");
    while(token != NULL){
        printf("%s", token);
        if(strcmp(token, word) == 0)
            printf("%c", '?');
        
        printf(" ");
        token = strtok(NULL, " ");
    }

    return 0;
}
