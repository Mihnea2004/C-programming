#include <stdio.h>
#include <string.h>

int main() {
    char s[251];

    printf("Enter a text: ");
    fgets(s, sizeof(s), stdin);

    printf("The sequences formed by 2 letters are: ");
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i] == s[i+1] && s[i] != '*')
            printf("%c%c ", s[i], s[i]);
            
    return 0;
}
