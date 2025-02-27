#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;

void printList(Node *head){
    Node *current = head;
    while(current != NULL){
        printf("%d ", current -> value);
        current = current -> next;
    }
}

void eliberateMemory(Node *head){
    Node *current = head;
    while(current != NULL){
        Node *temp = current;
        current = current -> next;
        free(temp);
    }
}

int main(void){
    Node *head = NULL;

    int n;
    printf("Enter the first number: ");
    scanf("%d", &n);

    while(1){
        if(n == 0)
            break;

        Node *newNode = malloc(sizeof(Node));
        if(newNode == NULL){
            perror("Error memory alloc!");
            exit(-1);
        } 

        newNode -> value = n;
        newNode -> next = head;
        head = newNode;

        printf("Enter the next number: ");
        scanf("%d", &n);
    }

    printf("Reversed list: \n");
    printList(head);

    eliberateMemory(head);
}