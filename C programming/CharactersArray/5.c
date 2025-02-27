#include <stdio.h>
#include <string.h>

int main() {
    char text1[100], text2[100];
    printf("Insert 1'st text: ");
    scanf("%s", &text1);

    printf("Insert 2'nd text: ");
    scanf("%s", &text2);

    int length1 = strlen(text1);
    int length2 = strlen(text2);

    printf("1'st text '%s' has length %d.\n", text1, length1);
    printf("2'nd text '%s' has length %d.\n", text2, length2);


    if(length1 > length2)
        printf("1'st text is bigger.");
    else if(length1 < length2)
        printf("2'nd text is bigger.");
    else
        printf("The 2 texts are equal.");
    return 0;
}

