#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s[100];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    
    int freq[10] = {0};
    int maxFreq = 0;
    char minDigit = '0'; 
    
    for(int i = 0; i < strlen(s); i++){
        if(isdigit(s[i])){
            freq[s[i] - '0']++; ///incrementam frecventa cifrei gasite
            if(freq[s[i] - '0'] > maxFreq){
                maxFreq = freq[s[i] - '0'];
                minDigit = s[i];
            }
            else if(freq[s[i] - '0'] == maxFreq && s[i] < minDigit)
                minDigit = s[i];
        }
    }
    
    if(maxFreq == 0)
        printf("Error!\n");
    else
        printf("%c\n", minDigit);
        
    return 0;
}