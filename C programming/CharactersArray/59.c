#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[256], freq[50] = {0};
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

//actualizeaza frecventa literei s[i] in vectorul de frecventa 
    for(int i = 0; i < strlen(s); i++)
        if(islower(s[i]))
            freq[s[i] - 'a']++;

//printing the characters 
    for(int i = 0; i < 50; i++)
        if(freq[i] > 0)
            printf("%c ", 'a' + i);

    return 0;
}
