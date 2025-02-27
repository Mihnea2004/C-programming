#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concatenateStrings(char *s1, char *s2){
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    // +1 pt spatiu si +1 pt \0
    char *result = malloc((len1 + len2 + 2) * sizeof(char));
    if(result == NULL){
        perror("Error memory alloc result!");
        free(s1);
        free(s2);
        exit(-1);
    }

    strcpy(result, s1);
    strcat(result, " ");
    strcat(result, s2);

    return result;
}

int main(){
    char *s1 = malloc(100 * sizeof(char));
    if(s1 == NULL){
        perror("Error memory alloc s1!");
        exit(-1);
    }

    printf("Enter 1'st string: ");
    fgets(s1, 100, stdin);
    s1[strcspn(s1, "\n")] = '\0';

    char *s2 = malloc(100 * sizeof(char));
    if(s2 == NULL){
        perror("Error memory alloc s2!");
        free(s1);
        exit(-1);
    }

    printf("Enter 2'nd string: ");
    fgets(s2, 100, stdin);
    s2[strcspn(s2, "\n")] = '\0';

    char *result = concatenateStrings(s1, s2);
    printf("Result: %s", result);

    free(s1);
    free(s2);
    free(result);

    return 0;
}