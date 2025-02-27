#include <stdio.h>
#include <string.h>
#include <limits.h>

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);
    getchar(); 

    char s[256];  
    char result[256] = "";  
    int minim = INT_MAX;

    for(int i = 0; i < n; i++) {  
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = '\0'; 

        int counter = 0; 
        for(int j = 0; j < strlen(s); j++)
            if(strchr("aeiou", s[j]) != NULL)
                counter++;

        if(counter <= minim) {
            minim = counter;
            strcpy(result, s);
        }
    }

    if(result[0] == '\0') 
        printf("No sentences processed.\n");
    else
        printf("Sentence with least vowels is: %s\n", result);

    return 0;
}