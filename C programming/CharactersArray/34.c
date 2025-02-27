#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];

    printf("Enter first word: ");
    scanf("%s", s1);

    printf("Enter second word: ");
    scanf("%s", s2);

    if(s1[strlen(s1)-2] == s2[strlen(s2)-2] && s1[strlen(s1)-1] == s2[strlen(s2)-1])
        printf("%s rhymes with %s\n", s1, s2);
    else
        printf("%s doesn't ryhm with %s", s1, s2);
    return 0;
}
