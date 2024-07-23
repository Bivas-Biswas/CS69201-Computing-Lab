#include<stdio.h>
#include<stdlib.h>


#define MAX 10

struct Stack{
    int top;
    int items[MAX];
};

typedef struct Stack st;

int isFull(st *s){
    if(s->top == MAX - 1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(st *s){
    if(s->top == -1){
        return 1;
    }else{
        return 0;
    }
}

int pop(st *s){
    if(isEmpty(s)){
        printf("Stack is Empty\n");
    }else{
        printf("Item poped: %d", s->items[s->top]);
        s->top--;
    }
}

void push(st *s, int ele){
    if(isFull(s)){
        printf("Stack is Full\n");
    }else{
        s->top++;
        s->items[s->top] = ele;
    }
}

struct Stack *initStack(){
    st *s = malloc(sizeof(st));
    s->top = -1;
    return s;
}


void main(){
    st *s = initStack();

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 6);

    pop(s);
}