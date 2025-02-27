#include <stdio.h>
#include <string.h>

int main() {
    char s[40];

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    for(int i = 0; i < strlen(s); i++) {
        for(int j = 0; j < strlen(s); j++)
            if(i != j)
                printf("%c", s[j]);
        printf("\n");
    }
    return 0;
}
