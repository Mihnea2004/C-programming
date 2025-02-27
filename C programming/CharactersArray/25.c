#include <stdio.h>
#include <string.h>

int isPalidromV1(char word[], int left, int right){
    while(left <= right){
        if(word[left] != word[right])
            return 0;
        
        left++;
        right--;
    }

    return 1;
}

int isPalidromV2(char word[], int length){
    for(int i = 0; i < length / 2; i++)
        if(word[i] != word[length - i - 1])
            return 0;

    return 1;
}


int main() {
    char word[100];

    printf("Insert a word: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0';

    if(isPalidromV1(word, 0, strlen(word) - 1))
        printf("Word %s is palindrom.", word);
    else
        printf("Word %s is not palindrom.", word);

    if(isPalidromV2(word, strlen(word)))
        printf("\nWord %s is palindrom.", word);
    else
        printf("\nWord %s is not palindrom.", word);
        
    return 0;
}
