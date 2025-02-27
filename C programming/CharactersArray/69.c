#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    char s[256], c[21];
    printf("Enter string s: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; 

    printf("Enter string c: ");
    fgets(c, sizeof(c), stdin);
    c[strcspn(c, "\n")] = '\0'; 

    int lungimeC = strlen(c);
    char* pozitie = strstr(s, c);  // Caută prima apariție a lui c în s
    bool apare = false;

    while (pozitie != NULL) {
        apare = true;
        memset(pozitie, '*', lungimeC);  // Înlocuiește cu caractere ''
        pozitie = strstr(pozitie + lungimeC, c);  // Continuă căutarea după ultima înlocuire
    }

    if(apare)
        printf("%s", s);
    else
        printf("Error!");

    return 0;
}