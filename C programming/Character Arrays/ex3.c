#include <stdio.h>
#include <string.h>

int main(){
    int n;
    printf("Enter a value: ");
    scanf("%d", &n);
    getchar();

    char names[n][100];

    //for pt citirea numelor
    for(int i = 0; i < n; i++){
        printf("Enter name %d: ", i + 1);
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    //for pt calcularea lungimilor
    for(int i = 0; i < n; i++){
        int count = 1;
        
        for(int j = i + 1; j < n; j++){
            if(strcmp(names[i], names[j]) == 0){
                count++;
                names[j][0] = '\0'; //nume procesat
            }
        }

        if(names[i][0] != '\0')
            printf("The names %s appears %d times!\n", names[i], count);
    }
    return 0;
}