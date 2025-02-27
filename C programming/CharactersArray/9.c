#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter first string: ");
    scanf("%s", s2);

    char *q = strncat(s2, s1, 3);
    printf("String q is: %s\n", q);
    return 0;
}
