#include <stdio.h>
#include <string.h>

int main(){
    int n;
    printf("Enter a value: ");
    scanf("%d", &n);
    getchar(); //consum caracterul '\n' ramas dupa scanf!

    char name[10];
    char longestName[10];
    int maxLength = 0;

    for(int i = 0; i < n; i++){
        printf("Enter name %d: ", i + 1);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        int length = strlen(name);
        if(length > maxLength){
            maxLength = length;
            strcpy(longestName, name);
        }
    }

    printf("Longest name is %s and has %d letters!\n", longestName, maxLength);
    return 0;
}