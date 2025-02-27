#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

uint32_t upper_sub_string(char str[], const char substr[]){
    uint32_t count = 0;
    size_t len = strlen(substr);

    if(len == 0)
        return 0;

    char *p = str;
    while((p = strstr(p, substr)) != NULL){
        for(size_t i = 0; i < len; i++)
            p[i] = toupper(p[i]);
        count++;
        p = p + len; //avansam pozitia
    }
    return count;
}

int main(){
    char s1[100], s2[100];

    printf("Enter the main string: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0';

    printf("Enter the substring: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0';

    uint32_t result = upper_sub_string(s1, s2);

    printf("New string: %s\n", s1);
    printf("Number of modifications: %u", result);

    return 0;
}