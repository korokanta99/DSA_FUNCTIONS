#ifndef QUEUE_A
#define QUEUE_A

#include <stdio.h>

typedef struct node {
    int elem;
    struct node* link;
} *LIST;
typedef struct {
    LIST front, rear;
}LLQueue;


void intitQueue(LLQueue *q){
    q->front == NULL;
    q->rear == NULL;
}

int isEmpty(LLQueue *q){

    int checker = 0;

    if(q->front == NULL && q->rear == NULL){
        checker = 1;
    }

    return checker;
}

int front(LLQueue *q){
    return(q->front->elem);
}


void enqueue(LLQueue *q, int data){

LIST temp = malloc(sizeof(struct node));

temp->elem = data;
temp->link = NULL;

if(q->front != NULL){
    q->rear->link = temp;
}
else{
    q->front = temp;
}
q->rear = temp; 
}

void dequeue(LLQueue *q){

    q->front == q->front->link;


}

#endif