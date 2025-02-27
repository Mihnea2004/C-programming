#include <stdio.h>
#include <string.h>

int main() {
    char s[100];

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    int countA = 0, countX = 0;

    for(int i = 0; i < 100; i++) {
        if(s[i] == 'a')
            countA++;
        if(s[i] == 'x')
            countX++;
    }

    printf("Character 'a' appears %d times\n", countA);
    printf("Character 'x' appears %d times\n", countX);

    return 0;
}
