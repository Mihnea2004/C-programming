#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[51];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    int freq[26] = {0};
    int maxFreq = 0;
    char maxChar = '\0';

    for(int i = 0; i < strlen(s); i++) {
        if(islower(s[i])){
            freq[s[i] - 'a']++; ///incrementam frecventa literei mici
        
            if(freq[s[i] - 'a'] > maxFreq){
                maxFreq = freq[s[i] - 'a'];
                maxChar = s[i];
            }
            else if(freq[s[i] - 'a'] == maxFreq && s[i] < maxChar)
                maxChar = s[i];
        }
    }

    if(maxChar != '\0')
        printf("Small character most frequented in the string is %c\n", maxChar);
    else
        printf("Error!\n");
        
    return 0;
}
