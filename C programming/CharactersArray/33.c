#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char s[100];

    printf("Enter a word: ");
    scanf("%s", s);

    int i, lowers = 0, uppers = 0, digits = 0;

    for(i = 0; i < strlen(s); i++) {
        if(isupper(s[i]))
            uppers++;
        if(islower(s[i]))
            lowers++;
        if(isdigit(s[i]))
            digits++;
    }
    
    printf("Word has %d big letters\n", uppers);
    printf("Word has %d small letters\n", lowers);
    printf("Word has %d digits\n", digits);
    return 0;
}
