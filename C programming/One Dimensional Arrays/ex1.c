#include <stdio.h>

unsigned int countEqualSegments(unsigned int n){
    unsigned int count = 1; //orice numar are cel putin 1 segment
    unsigned int currentBit = n & 1; //ultimul bit

    while(n != 0){
        n = n >> 1;
        unsigned int nextBit = n & 1;

        if(currentBit != nextBit){ //daca bitii consecutivi sunt diferiti, exista un segment
            count++;
            currentBit = nextBit;
        }
    }

    return count;
}

int main(){
    unsigned int n;
    printf("Enter a value: ");
    scanf("%u", &n);

    unsigned int count = countEqualSegments(n);
    printf("Number has %u equal segments!\n", count);

    return 0;
}