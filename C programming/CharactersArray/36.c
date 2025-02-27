#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[201][21];
    char lastWord[21];

    printf("n =  ");
    scanf("%d", &n);

    printf("Enter %d different words:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%s", s[i]);

    printf("Enter the last word: ");
    scanf("%s", lastWord);

    int found = 0;
    printf("Words with '%s' as prefix are: ", lastWord);
    for(int i = 0; i < n; i++) {
        if(strncmp(s[i], lastWord, strlen(lastWord)) == 0) {
            printf("%s ", s[i]);
            found = 1;
        }
    }

    if(!found)
        printf("nu exista");

    return 0;
}
