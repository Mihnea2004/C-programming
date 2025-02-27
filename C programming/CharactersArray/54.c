#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    char str[31];
  
    char vowels[] = "aeiou";
    int counter = 0;
    
    for(int i = 1; i <= n; i++){
        int isVowel = 1;
        printf("String %d: ", i);
        scanf("%s", str);
        for(int j = 0; j < strlen(str); j++)
            if(!strchr(vowels, str[j])){
                isVowel = 0;
                break;
            }
            
        if(isVowel)
            counter++;
            
    }
        
    printf("Number of strings formed only with vowels is %d", counter);
    return 0;
}
