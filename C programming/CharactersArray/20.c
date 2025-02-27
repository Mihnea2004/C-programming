#include <stdio.h>
#include <string.h>

int main() {
    char s[100];

    printf("Enter a string: ");
    scanf("%s", s);

    for(int i = 0; i <= strlen(s); i++) {
        if(s[i] == 'a')
            s[i] = 'x';
    }

    printf("%s", s);
    return 0;
}
