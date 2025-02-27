#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    /* char s[50];
    printf("Enter a string: ");
    gets(s);

    puts(strlwr(s));
    */

    /* char *s;
    printf("Enter a string: ");
    gets(s);

    for(int i = 0; s[i] != '\0'; i++) {
        if(isupper(s[i]))
            s[i] = s[i] + 32;
    }

    printf("%s", s);
    */

    char s[50];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    for(int i = 0; s[i] != '\0'; i++)
        s[i] = tolower(s[i]);

    printf("%s", s);
    return 0;
}
