#include <stdio.h>
#include "STACK_A.c"
#include "QUEUE_A.c"

int main() {
    Stack S;
    Queue Q;

    initStack(&S);
    initQueue(&Q);

    pushUnique(&S, 10);
    pushUnique(&S, 20);
    pushUnique(&S, 10);

    enqueueUnique(&Q, 1);
    enqueueUnique(&Q, 2);
    enqueueUnique(&Q, 1); 

    displayStack(&S);
    displayQueue(&Q);

    popUnique(&S, 10);   
    dequeueUnique(&Q, 1); 

    displayStack(&S);
    displayQueue(&Q);

    return 0;
}
