#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[255];

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; 

    if(islower(s[0]))
        s[0] = toupper(s[0]);

    for(int i = 1; i < strlen(s); i++) {
        if(s[i] == ' ' && islower(s[i+1]))
            s[i+1] = toupper(s[i+1]);

        if(s[i] == ' ' && islower(s[i-1]))
            s[i-1] = toupper(s[i-1]);
    }

    if(islower(s[strlen(s)-1]))
        s[strlen(s)-1] = toupper(s[strlen(s)-1]);

    printf("New string is: %s", s);
    return 0;
}
