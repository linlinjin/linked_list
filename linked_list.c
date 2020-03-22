/* working with dynamically allocated memory
 using valgrind
 linked list review */
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode{
    int val;
    struct LinkedListNode * next;
}Node;

/**
 struct linkedlist{
    Node *head;
    int length;
 }
 **/

void printll(Node *head){
    Node *tmp = head;
    printf("Linked List\n");
    while (tmp != NULL){
        printf("%d ",tmp->val);
    }
    printf("\n");
}
//pop from head
int pop(Node **head){//trying to modify the head pointer
    int val = (*head)->val;
    (*head) = (*head)->next;
    return val;
    }

//push at head
void push(Node **head, int val){
    Node *newNode = malloc(sizeof(Node));
    newNode -> val = val;
    newNode -> next = (*head);
    (*head) = newNode;
    }
int main(){
    Node *head = NULL;
    
    push(&head,3); // 3
    push(&head,4); // 4 3
    push(&head,7); // 7 4 3
    push(&head,8); // 8 7 4 3
    
    printll(head); //8 7 4 3
    
    int val;
    val = pop(&head);
    printf("popped val is: %d\n",val); //8
    printll(head);// 7 4 3

    val = pop(&head);
    printf("popped val is: %d\n",val); //7
    printll(head); //4 3

    val = pop(&head);
    printf("popped val is: %d\n",val); //4
    printll(head);//3

    
    push(&head,1);
    printll(head);
}
