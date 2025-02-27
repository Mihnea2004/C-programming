#include <stdio.h>
#include <string.h>

int main() {
    char c1, c2;

    printf("c1 = ");
    scanf("%s", &c1);

    printf("c2 = ");
    scanf("%s", &c2);

    char s[250];
    printf("Enter a text: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == c1)
            c1 = c2;
        if(s[i] == c2)
            c2 = c1;
    }

    printf("New text is: %s", s);

    return 0;
}
