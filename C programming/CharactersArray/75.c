#include <stdio.h>
#include <string.h>

int main() {
    char word1[31], word2[31];

    printf("word1 = ");
    scanf("%s", word1);
    
    printf("word2 = ");
    scanf("%s", word2);

    int length1 = strlen(word1); ///start
    int length2 = strlen(word2);

    for(int i = length1; i > 0; i--) {
        int suffixLength = length1 - i;
        if(suffixLength < length2)
            if(strncmp(word1 + length1 - i, word2, i) == 0) ///compara sufixul cu sirul word2
                printf("%s\n", word1 + length1 - i); ///word1 + start
    }
    return 0;
}