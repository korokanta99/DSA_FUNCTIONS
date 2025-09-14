#ifndef STACK_A
#define STACK_A

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;


void initStack(Stack *s){
    s->top = NULL;
}

int isEmpty(Stack *s){
    
    int checker = -1;
    
    if(s->top != NULL){
        checker = 0;
    }
    
    return checker;
}


void push(Stack *s, int data){

    Node *temp = (Node*)malloc(sizeof(Node));

    temp->data = data;
    temp->next = s->top;
    s->top = temp;


}

void pop(Stack *s){
    
s->top = s->top->next;

}

int peek(Stack *s){
    
    return(s->top->data);
    
}


#endif

