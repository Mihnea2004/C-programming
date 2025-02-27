#include <stdio.h>
#include <string.h>

int main() {
    char s1[31], s2[31];

    printf("s1 = ");
    scanf("%s", s1);

    printf("s2 = ");
    scanf("%s", s2);

    int found = 1;
    for (int i = 0; i < strlen(s1); i++) {
        found = 0;
        for (int j = 0; j < strlen(s2); j++) {
            if (s1[i] == s2[j]) {
                found = 1;
                break;
            }
        }
        if (found)
            break;
    }

    if (found)
        printf("YES\n");
    else
        printf("NO\n");
    
    return 0;
}