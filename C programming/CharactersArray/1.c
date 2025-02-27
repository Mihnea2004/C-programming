#include <stdio.h>

void printAlphabet() {
    for(char c = 'a'; c <= 'z'; c++)
        printf("%c ", c);
}

int main() {
    printAlphabet();
    return 0;
}