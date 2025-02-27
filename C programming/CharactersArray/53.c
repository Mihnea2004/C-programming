#include <stdio.h>
#include <string.h>

int main() {
    char s[53], result[53];
    int i, index;

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    while(s[i] != '\0') {
        result[index++] = s[i]; ///copy the chracter in the resulted string

        int k = s[i+1] - '0'; ///converting digit into integer
        while(k > 1) {
            result[index++] = s[i]; ///repeating the character k-1 times
            k--;
        }

        i = i + 2; ///skipping the character and digit from the starting string
    }
    result[index] = '\0';

    printf("New string is: %s", result);
    return 0;
}
