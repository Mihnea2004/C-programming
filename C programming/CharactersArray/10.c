#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", &s1);
    printf("Enter second string: ");
    scanf("%s", &s2);

    printf("New string is: %d\n", strcmp(s1, s2));
    return 0;
}
