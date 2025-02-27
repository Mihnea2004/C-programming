#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int count = 0;

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    char *token = strtok(s, " ");

    while(token != NULL) {
        if(token[0] == 'a')
            count++;
        token = strtok(NULL, " "); 
    }

    printf("%d words begin with character 'a'", count);
    return 0;
}
