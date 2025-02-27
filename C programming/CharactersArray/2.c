#include <stdio.h>

void printAlphabet() {
    for(char c = 'z'; c >= 'a'; c--)
        printf("%c ", c);
}

int main() {
    printAlphabet();
    return 0;
}