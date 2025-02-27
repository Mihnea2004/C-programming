#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    /* char s[50];
    printf("Enter a string: ");
    gets(s);

    puts(strupr(s));
    */

    /* char *s;
    printf("Enter a string: ");
    gets(s);

    for(int i = 0; s[i] != '\0'; i++) {
        if(islower(s[i]))
            s[i] = s[i] - 32;
    }

    printf("%s", s);
    */

    char *s;
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    for(int i = 0; s[i] != '\0'; i++)
        s[i] = toupper(s[i]);

    printf("%s", s);
    return 0;
}

