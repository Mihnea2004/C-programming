#include <stdio.h>
#include <string.h>

void reverseString(char s[]) {
    int length = strlen(s);
    for (int i = 0; i < length / 2; i++) {
        char temp = s[i]; 
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
}

int main() {
    char s1[101], s2[101], result[202];
    int count = 0;

    printf("Enter the first string: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0';

    printf("Enter the next string: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0';

    int i = strlen(s1) - 1;
    int j = strlen(s2) - 1;

    while(i >= 0 && j >= 0) {
        if(s1[i] == s2[j]) {
            result[count++] = s1[i];
            i--;
            j--;
        }
        else
            break;
    }

    result[count] = '\0';

    reverseString(result);

    printf("\nThe longest suffix is: %s\n", result);

    return 0;
}
