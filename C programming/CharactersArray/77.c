#include <stdio.h>
#include <string.h>

int main(){
    int n;
    char words[20][21];
    int count = 0;

    printf("n = ");
    scanf("%d", &n);

    printf("Enter %d words: ", n);
    for(int i = 0; i < n; i++)
        scanf("%s", words[i]);

    for(int i = 1; i < n; i++)
        if(strncmp(words[i], words[0], strlen(words[0])) == 0)
            count++;

    printf("Number of words is: %d", count);
    return 0;
}