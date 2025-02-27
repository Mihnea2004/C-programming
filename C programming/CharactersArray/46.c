#include <stdio.h>
#include <string.h>

void reverseWord(char word[]){
    int length = strlen(word) - 1;
    for(int i = 0; i <= length / 2; i++){
        char temp = word[i];
        word[i] = word[length - i];
        word[length - i] = temp;
    }
}

int main() {
    char text[255], vowels[6] = "aeiou";

    printf("Enter a text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    char *word = strtok(text, " ");

    while(word){
        if(strchr(vowels, word[0]))
            reverseWord(word);

        printf("%s ", word);
        word = strtok(NULL, " ");
    }

    return 0;
}
