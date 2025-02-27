#include <stdio.h>
#include <string.h>

int main(){
    char s[21];
    printf("Enter first and last name: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    char firstName[21], lastName[21];
    sscanf(s, "%s %s", firstName, lastName);  

    char result[21];
    sprintf(result, "%c. %s", firstName[0], lastName);
    printf("%s", result);

    return 0;   
}