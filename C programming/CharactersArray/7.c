#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);

    char *p = strncpy(s2, s1, 3);

    printf("String p is: %s\n", p);
    return 0;
}
