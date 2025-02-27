#include <stdio.h>
#include <string.h>

int main() {
    char s[100];

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    int i, j;
    char aux;

    for(i = 0; i < strlen(s) - 1; i++) {
        for(j = i + 1; j < strlen(s); j++) {
            if(s[i] > s[j]) {
                aux = s[i];
                s[i] = s[j];
                s[j] = aux;
            }
        }
    }
    printf("The ASCII order of the characters is: %s", s);
    return 0;
}
