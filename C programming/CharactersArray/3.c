#include <stdio.h>

void printASCIICode() {
    for(int c = 97; c <= 122; c++)
        printf("%d ", c);
}

int main() {
    printASCIICode();
    return 0;
}
