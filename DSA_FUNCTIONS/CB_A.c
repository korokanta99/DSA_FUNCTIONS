#ifndef CB_A
#define CB_A

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int elem;
    int link;
}cellType;
typedef struct {
    cellType nodes[MAX];
    int avail;
}VirtualHeap;
typedef int CList;
typedef struct{
    CList front, rear;
}QueueCB;
typedef enum {true, false} Boolean;

void initQueueCB (QueueCB *Q) {
    Q->front = Q->rear = -1;
}

Boolean isEmpty (QueueCB Q) {
    return (Q.front == -1)? true: false;
}

Boolean isFull (VirtualHeap VH) {
    return (VH.avail == -1)? true: false;
}

char getFront (QueueCB Q, VirtualHeap VH) {
    return (Q.front != -1)? VH.nodes[Q.front].elem: '\0';
}


void Enqueue (VirtualHeap *VH, QueueCB *Q, char x) {
    if (VH->avail != -1) {
        int temp = allocSpace (VH);
        if (temp != -1) {
            VH->nodes[temp].elem = x;
            VH->nodes[temp].link = -1;

            if (Q->front != -1) {
                VH->nodes[Q->rear].link = temp;
            } else {
                Q->front = temp;
            }

            Q->rear = temp;
        }
    }
}


void Dequeue(VirtualHeap *VH, QueueCB *Q) {
    if (Q->front != -1) {
        int temp = Q->front;
        Q->front = VH->nodes[temp].link;
        if (temp == Q->rear) {
            Q->rear = -1;
        }
        deallocSpace (VH, temp);
    }
}


int allocSpace (VirtualHeap *VH) {
    int idx = VH->avail;
    if (idx != -1) {
        VH->avail = VH->nodes[idx].link;
    }
    return idx;
}


void deallocSpace (VirtualHeap *VH, int pos) {
    VH->nodes[pos].link = VH->avail;
    VH->avail = pos;
}


#endif