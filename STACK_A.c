#ifndef STACK_A
#define STACK_A

#include <stdio.h>
#define MAX 100


typedef struct {
    int top;
    int items[MAX];
} Stack;

void initStack(Stack *s){
    s->top = -1;
}

int isEmpty(Stack *s){
    
    int checker = -1;
    
    if(s->top == -1){
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

