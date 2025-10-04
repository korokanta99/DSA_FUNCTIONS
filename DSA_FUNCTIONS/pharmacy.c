#include <stdio.h>
#include <stdlib.h>
#include "Queue_A.c"   

#define NUM_QUEUES 2 


void Priority(Queue q[], int *customerNumber);
void enterRegular(Queue q[], int *customerNumber);
void callNextCustomer(Queue q[]);

int main() {
    Queue queues[NUM_QUEUES];


    for (int i = 0; i < NUM_QUEUES; i++) {
        Queue *newQ = initialize();
        queues[i] = *newQ;  
        free(newQ);         
    }

    int customerNumber = 1;


    enterRegular(queues, &customerNumber);
    Priority(queues, &customerNumber);
    enterRegular(queues, &customerNumber);
    Priority(queues, &customerNumber);
    enterRegular(queues, &customerNumber);

    printf("\nCurrent Queues:\n");
    printf("Priority Queue: ");
    display(&queues[0]);
    printf("Regular Queue: ");
    display(&queues[1]);

    printf("\nCalling Customers:\n");
    callNextCustomer(queues);
    callNextCustomer(queues);
    callNextCustomer(queues);

    printf("\nRemaining Queues:\n");
    printf("Priority Queue: ");
    display(&queues[0]);
    printf("Regular Queue: ");
    display(&queues[1]);

    return 0;
}


void Priority(Queue q[], int *customerNumber) {
    enqueue(&q[0], *customerNumber);
    printf("Customer %d entered PRIORITY queue.\n", *customerNumber);
    (*customerNumber)++;
}

void callNextCustomer(Queue q[]) {
    if (!isEmpty(&q[0])) {
        int next = dequeue(&q[0]);
        printf("Now serving PRIORITY customer %d\n", next);
    }
    else if (!isEmpty(&q[1])) {
        int next = dequeue(&q[1]);
        printf("Now serving REGULAR customer %d\n", next);
    }
    else {
        printf("No customers waiting.\n");
    }
}


void enterRegular(Queue q[], int *customerNumber) {
    enqueue(&q[1], *customerNumber);
    printf("Customer %d entered REGULAR queue.\n", *customerNumber);
    (*customerNumber)++;
}



