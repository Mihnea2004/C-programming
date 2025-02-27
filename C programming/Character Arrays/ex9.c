#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

uint32_t stringReplace(char *s1, const char *s2, const char *s3){
    char temp[100];
    char *pos;
    uint32_t count = 0;
    size_t s2Len = strlen(s2);
    size_t s3Len = strlen(s3);

    if(s2Len == 0)
        return 0;

    char *current = s1;
    while((pos = strstr(current, s2)) != NULL){
        strncat(temp, current, pos - current);
        strcat(temp, s3);

        current = pos + s2Len;
        count++;
    }
    strcat(temp, current);
    strcpy(s1, temp);

    return count;
}

int main(){
    char s1[1000];
    char s2[] = "string";
    char s3[] = "sir de caractere";

    strcpy(s1, "Acesta este un string si un string este terminat cu 0x00");

    int r = stringReplace(s1, s2, s3);

    printf("Modified string: %s\n", s1);
    printf("Number of replacements: %d\n", r);

    return 0;
}