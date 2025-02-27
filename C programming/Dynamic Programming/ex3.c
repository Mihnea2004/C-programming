#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int verificaLegatura(char *s, char *cuvant){
    int len1 = strlen(s);
    int len2 = strlen(cuvant);

    if(len1 < 2 || len2 < 2)
        return 0;

    return tolower(s[len1 - 2]) == tolower(cuvant[0]) && tolower(s[len1 - 1]) == tolower(cuvant[1]);
}

int main() {
    char *result = NULL;
    int index = 0;

    char cuvant[101];
    while(scanf("%s", cuvant) == 1){
        cuvant[strcspn(cuvant, "\n")] = '\0';
        if(result == NULL){
            index = strlen(cuvant) + 1;
            result = malloc(index * sizeof(char));

            strcpy(result, cuvant);
        }
        else{
            if(verificaLegatura(result, cuvant)){
                index = index + strlen(cuvant) + 1;
                result = realloc(result, index * sizeof(char));

                strcat(result, "-");
                strcat(result, cuvant);
            }
        }
    }

    if(result != NULL){
        printf("%s\n", result);
        free(result);
    }
    else{
        printf("Nu s-a construit niciun sir!\n");
    }
    return 0;
}
