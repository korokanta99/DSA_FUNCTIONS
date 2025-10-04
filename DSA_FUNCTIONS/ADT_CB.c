#ifndef VHEAP_LIST_H
#define VHEAP_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int data;
    int link;
} Cell;

typedef struct {
    Cell Nodes[MAX];
    int avail;
} VirtualHeap;

typedef int List;

void initList(List *L){
    *L = -1;                               
}

void initVH(VirtualHeap *VH){
    VH->avail = 0;                         
    for (int i = 0; i < MAX - 1; i++){
        VH->Nodes[i].link = i + 1;          
    }
    VH->Nodes[MAX - 1].link = -1;           
}

int allocSpace(VirtualHeap *VH){
    List space = VH->avail;                    
    if (space != -1){                           
        VH->avail = VH->Nodes[space].link;      
    }
    return space;                              
}

void deAllocSpace(VirtualHeap *VH, int index){
    if (index >= 0 && index < MAX){
        VH->Nodes[index].link = VH->avail;     
        VH->avail = index;                     
    }
}

void display(List L, VirtualHeap VH){
    for (List trav = L; trav != -1; trav = VH.Nodes[trav].link){
        printf("%d ", VH.Nodes[trav].data);
    }
    printf("\n");
}

void insertFirst(List *L, VirtualHeap *VH, int num){
    List space = allocSpace(VH);
    if (space != -1){
        VH->Nodes[space].data = num;           
        VH->Nodes[space].link = *L;             
        *L = space;                            
    }
}

void insertLast(List *L, VirtualHeap *VH, int num){
    List *trav;
    List space = allocSpace(VH);
    if (space != -1){
        VH->Nodes[space].data = num;            
        VH->Nodes[space].link = -1;
    }

    for (trav = L; *trav != -1; trav = &(VH->Nodes[*trav].link)) {}

    *trav = space;                              
}

void insertSorted(List *L, VirtualHeap *VH, int data){
    List *trav;
    List temp = allocSpace(VH);
    if (temp != -1){
        VH->Nodes[temp].data = data;
        VH->Nodes[temp].link = -1;
    }

    for (trav = L; *trav != -1 && VH->Nodes[*trav].data < data; 
         trav = &(VH->Nodes[*trav].link)) {}

    VH->Nodes[temp].link = *trav;            
    *trav = temp;
}

void deleteValue(List *L, VirtualHeap *VH, int data){
    List *trav;

    for (trav = L; *trav != -1 && VH->Nodes[*trav].data != data; 
         trav = &(VH->Nodes[*trav].link)) {}

    if (*trav != -1){
        List temp = *trav;                  
        *trav = VH->Nodes[temp].link;       
        deAllocSpace(VH, temp);              
    }
}



#endif