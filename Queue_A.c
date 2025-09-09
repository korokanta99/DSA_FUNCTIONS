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




#endif