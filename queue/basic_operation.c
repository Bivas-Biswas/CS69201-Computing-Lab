#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue
{
    int items[MAX];
    int front;
    int rear;
};

typedef struct Queue qu;

int isFull(qu *q)
{
    if (q->rear == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(qu *q)
{
    if (q->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(qu *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is FULL\n");
    }
    else
    {
        if (q->front == -1)
        {
            q->front++;
        }
        q->rear++;
        q->items[q->rear] = val;
    }
}

void dequeue(qu *q){
    if(isEmpty(q)){
        printf("QUEUE is EMPTY\n");
    }else{
        printf("\nDeleted : %d\n", q->items[q->front]);
        q->front++;
        if(q->front > q->rear){
            q->front = q->rear = 0;
        }
    }
}

struct Queue *initQueue()
{
    qu *q = malloc(sizeof(qu));
    q->front = -1;
    q->rear = -1;

    return q;
}

void main()
{
    qu *q = initQueue();

    enqueue(q, 10);
    enqueue(q, 5);
    enqueue(q, 15);
    enqueue(q, 25);
    enqueue(q, 30);

    dequeue(q);
    enqueue(q, 10);
}
