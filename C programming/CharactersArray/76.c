#include <stdio.h>
#include <string.h>

int main(){
    char word1[31], word2[31];

    printf("word1 = ");
    scanf("%s", word1);
    
    printf("word2 = ");
    scanf("%s", word2);

    for(int i = 0; i < strlen(word1); i++){
        int j;
        for(j = 0; j < strlen(word2); j++){
            if(word1[i+j] != word2[j] && word2[j] != '*') ///gaseste pozitia cuvantului comun
                break;
        }
        if(j == strlen(word2))
            for(int k = 0; k < strlen(word2); k++)
                printf("%c", word1[i+k]);
    }
}