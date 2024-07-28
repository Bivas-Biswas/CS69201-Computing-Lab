#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 1000

struct Stack
{
    int top;
    char items[MAX];
};

typedef struct Stack st;

int isFull(st *s)
{
    if (s->top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(st *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char pop(st *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        return '\0';
    }
    else
    {
        return s->items[s->top--];
        // printf("Item poped: %d", s->items[s->top]);
        // s->top--;
    }
}

void push(st *s, char ele)
{
    if (isFull(s))
    {
        printf("Stack is Full\n");
    }
    else
    {
        s->top++;
        s->items[s->top] = ele;
    }
}

int top(st *s)
{
    if (s->top == -1)
        return -1;
    else
    {
        return s->items[s->top];
    }
}
struct Stack *initStack()
{
    st *s = malloc(sizeof(st));
    s->top = -1;
    return s;
}

int intermediateEvaluation(char operator, int op1, int op2){
    int eval;
    switch (operator)
    {
    case '+':
        eval = op1 + op2;
        break;
    
    case '-':
        eval = op1 - op2;
        break;

    case '*':
        eval = op1 * op2;
        break;

    case '/':
        eval = op1 / op2;
        break;
    }

    return eval;
}


int postfix_evaluation(char  str[]){
    st *s = initStack();
    int n = strlen(str);
    int ans;

    for(int i = 0; i < n; i++){
        char c = str[i];

        if(isspace(c)){
            continue;
        }

        if(c >= '0' && c <= '9'){
            // get relative value as interger
            // '0' == 48
            // '1' == 49
            // '1' - '0' == 1
            int value = c - '0';
            push(s, value);
        } else {
            int val1 = pop(s);
            int val2 = pop(s);

            int eval = intermediateEvaluation(c, val2, val1);
            push(s, eval);
        }
    }

    ans = pop(s);
    free(s);

    return ans;
}

// Driver code
int main()
{
    char exp[] = "1 2 + 2 / 5 * 7 +";
   
    // Function call
    printf("postfix evaluation: %d", postfix_evaluation(exp));
    return 0;
}