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

int isFull(Stack *s){
    
    int checker = -1;
    
    if(s->top == MAX - 1){
        checker = 0;
    }
    
}

void push(Stack *s, int data){
    if(s->top < MAX - 1){
        s->items[++s->top] = data;
        s->top++;
    }
}

void pop(Stack *s){
    
    if(s->top != -1){
        s->top--;
    }
}

int peek(Stack *s){
    
    return (s->items[s->top]);
    
}

#endif

