#include <stdio.h>
#include <string.h>

int main(){
    int n;
    printf("Enter a value: ");
    scanf("%d", &n);
    getchar();

    char names[n][100];

    for(int i = 0; i < n; i++){
        printf("Enter name %d: ", i + 1);
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    printf("%s", names[0]); //Ion
    for(int i = 1; i < n - 1; i++)
        printf(", %s", names[i]); // Ana

    printf(" si %s", names[n - 1]); //Maria
    printf(" invata\n");

    return 0;
}