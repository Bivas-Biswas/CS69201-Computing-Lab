#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void printLinkedList(struct node *p){
    while(p != NULL){
        printf("%d\n", p->data);
        p = p->next;
    }
}

struct node *createLinkList(){
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;
    struct node *four = NULL;

    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));
    four = malloc(sizeof(struct node));

    one->data = 1;
    two->data = 4;
    three->data = 3;
    four->data = 8;

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;

    head = one;

    return head;
}

void removeElement(struct node **head, int value){
    struct node* temp = *head, *prev = NULL;

    if(temp != NULL && temp->data == value){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return;

    prev->next = temp->next;

    free(temp);
}

void main(){
    struct node *head = NULL;
    head = createLinkList();
    printLinkedList(head);
    removeElement(&head, 1);
    printf("after removed\n");
    printLinkedList(head);
}