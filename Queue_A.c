#ifndef QUEUE_A
#define QUEUE_A

#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    return q;
}

bool isEmpty(Queue* q) {
    return (q->rear < q->front);
}

bool isFull(Queue* q) {
    return ((q->rear - q->front + 1 + MAX) % MAX == MAX - 1);
}

void enqueue(Queue* q, int value) {
    if (!isFull(q)) {
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = value;
    } else {
        printf("Queue is full.\n");
    }
}

int dequeue(Queue* q) {
    if (!isEmpty(q)) {
        int val = q->items[q->front];
        q->front = (q->front + 1) % MAX;
        return val;
    } else {
        printf("Queue is empty.\n");
        return -1; // indicates failure
    }
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    int i = q->front;
    while (i != (q->rear + 1) % MAX) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}




#endif
