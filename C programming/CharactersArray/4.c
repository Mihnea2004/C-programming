#include <stdio.h>

void printASCIICode() {
    for(int c = 65; c <= 90; c++)
        printf("%d ", c);
}

int main() {
    printASCIICode();
    return 0;
}
