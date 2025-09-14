#ifndef QUEUE_A
#define QUEUE_A

#include <stdio.h>
#define MAX 100

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q){
    q->front = 0;
    q->rear = -1;
}

int isEmptyQueue(Queue *q){
    return (q->rear < q->front);
}

int isFullQueue(Queue *q){
    return (q->rear - q->front + 1 == MAX);
}

void enqueue(Queue *q, int data){
    if(!isFullQueue(q)){
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = data;
    } else {
        printf("Queue full.\n");
    }
}

void dequeue(Queue *q){
    if(!isEmptyQueue(q)){
        q->front = (q->front + 1) % MAX;
    } else {
        printf("Queue empty.\n");
    }
}

void enqueueUnique(Queue *q, int data){
    int i = q->front;
    while(i != (q->rear+1)%MAX){
        if(q->items[i]==data){
            printf("%d already exists.\n", data);
            return;
        }
        i = (i+1)%MAX;
    }
    enqueue(q, data);
}

void dequeueUnique(Queue *q, int data){
    Queue temp; initQueue(&temp);
    while(!isEmptyQueue(q)){
        int val = q->items[q->front];
        dequeue(q);
        if(val != data) enqueue(&temp, val);
    }
    *q = temp;
}

void displayQueue(Queue *q){
    printf("Queue: ");
    for(int i=q->front; i<=q->rear; i++){
        printf("%d ", q->items[i]);
    }
    printf("\n");
}
#endif
