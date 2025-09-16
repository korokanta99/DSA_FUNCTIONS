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
    return ((q->rear - q->front + 1 + MAX) % MAX == MAX - 1);
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
    if(!isEmptyQueue(q)){
        while(i != (q->rear+1)%MAX){
            if(q->items[i] == data){
                printf("%d already exists.\n", data);
                return;
            }
            i = (i+1)%MAX;
        }
    }
    enqueue(q, data);
}

void dequeueUnique(Queue *q, int data){
    Queue temp; initQueue(&temp);
    int i = q->front;

    if(!isEmptyQueue(q)){
        while(i != (q->rear+1)%MAX){
            int val = q->items[i];
            if(val != data){
                enqueue(&temp, val);
            }
            i = (i+1)%MAX;
        }
    }
    *q = temp;
}

void displayQueue(Queue *q){
    if(isEmptyQueue(q)){
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    int i = q->front;
    while(i != (q->rear+1)%MAX){
        printf("%d ", q->items[i]);
        i = (i+1)%MAX;
    }
    printf("\n");
}

#endif
