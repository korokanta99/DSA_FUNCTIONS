#ifndef CB_L
#define CB_L

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int data;
    int link;
}cellType;
typedef struct{
    cellType elems[MAX];
    int avail;
}VirtualHeap;
typedef enum {false, true} Boolean;
typedef int CList;

void initStackCB (VirtualHeap *VH, CList *s){

    *s = -1;
    VH->avail = 0;
    int x;

    for(x = VH->avail; x < MAX-1; x++){
        VH->elems[x].link = x+1;  
    }
    VH->elems[x].link = -1;

}

Boolean isEmpty(CList S){
    return (S == -1)? true: false ;
}

Boolean isFull(VirtualHeap S){
    return (S.avail == -1)? true: false;
}

int allocSpace (VirtualHeap *VH){
    int temp = VH->avail;
    if(temp != -1){
        VH->avail = VH->elems[temp].link;
    }
    return temp;
}

void deallocSpace (VirtualHeap *VH, int idx){
    VH->elems[idx].link = VH->avail;
    VH->avail = idx;
}

int top(VirtualHeap VH, CList S){
    return (S != -1)? VH.elems[S].data: '\0';
}

void push(VirtualHeap *VH, CList *S, int x){
    if(VH->avail != -1){
        int temp = allocSpace(VH);
        if(temp != -1){
            VH->elems[temp].data = x;
            VH->elems[temp].link = *S;
            *S = temp;
        }
    }
}

void pop (VirtualHeap *VH, CList *S){
    if(*S != -1){
        int temp = *S;
        *S = VH->elems[temp].link;
        deallocSpace(VH, temp);
    }
}

#endif