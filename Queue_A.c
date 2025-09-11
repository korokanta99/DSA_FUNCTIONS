#ifndef QUEUE_A
#define QUEUE_A

#include <stdio.h>
#define MAX 100   // Queue capacity

// Queue structure
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void enqueue(Queue *q, int data){

    int checker = 0;

    if(checker == isFull(&q)){
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = data;
    }
    else{
        printf("This full");
    }

}

void dequeue(Queue *q){
    int checker = 0;

    if(checker == isEmpty(&q)){
        q->front = (q->front + 1) % MAX;
    }
    else{
        printf("Empty");
    }
}

int front(Queue *q){

    return(q->items[q->front]);
}

int isEmpty(Queue *q){

    int checker = 0;

    if((q->rear + 2) % MAX == q->front){
        checker = 1;
    }

    return checker;
}

int isFull(Queue *q){
    int checker = 0;

    if((q->rear + 1) % MAX == q->front){
        checker = 1;
    }

    return checker;
}

void initQueue(Queue *q){

    q->front = 0;
    q->rear = MAX - 1;

}

#endif