
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int precedence(char a)
{
    if (a == '^')
    {
        return 3;
    }
    else if (a == '/' || a == '*')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

char associativity(char a)
{
    if (a == '^')
    {
        return 'R';
    }
    else
    {
        return 'L';
    }
}

char infixToPostfix(char str[], int len, char result[])
{
    st *s = initStack();

    // int len = strlen(str);
    // char result[len + 1];
    int resultIdx = 0;

    for (int i = 0; i < len; i++)
    {
        char c = str[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result[resultIdx++] = c;
        }
        else if (c == '(')
        {
            push(s, c);
        }
        else if (c == ')')
        {
            while (s->top >= 0 && top(s) != '(')
            {
                result[resultIdx++] = pop(s);
            }
            pop(s);
        }
        else
        {
            while (s->top >= 0 && precedence(c) <= precedence(top(s)) && associativity(c) == 'L')
            {
                result[resultIdx++] = pop(s);
            }
            push(s, c);
        }
    }

    while (s->top != -1)
    {
        result[resultIdx++] = pop(s);
    }

    result[resultIdx] = '\0';
    free(s);
    
}

void main()
{
    char str[] = "a+b*(c^d-e)^(f+g*h)-i";
    int len = strlen(str);
    char result[len+1];
    

    infixToPostfix(str, len, result);

    printf("Infix: %s\n", str);
    printf("Postfix: %s\n", result);
}
