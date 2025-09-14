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

void popUnique(Stack *s, int data) {
    Stack temp;
    initStack(&temp);


    while (!isEmptyStack(s)) {
        int val = peek(s);
        pop(s);
        if (val != data) {
            push(&temp, val);
        }
    }


    while (!isEmptyStack(&temp)) {
        int val = peek(&temp);
        pop(&temp);
        push(s, val);
    }
}

void displayStack(Stack *s) {
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}
#endif

