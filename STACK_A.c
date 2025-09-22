#ifndef STACK_A
#define STACK_A

#include <stdio.h>
#include <stdbool.h>
#define MAX 5


typedef struct {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->items[++s->top] = value;
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    }
    return -1;
}

int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return -1;
}

int top(Stack *s) {
    return s->top;
}

void display(Stack *s) {
    printf("[ ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("]\n");
}

void popUnique(Stack *s, int data){
    Stack temp; initStack(&temp);
    while(!isEmpty(s)){
        int val = peek(s);
        pop(s);
        if(val != data) push(&temp, val);
    }
    while(!isEmpty(&temp)){
        int val = peek(&temp);
        pop(&temp);
        push(s, val);
    }
}

void displayStack(Stack *s){
    printf("Stack: ");
    for(int i=0; i<=s->top; i++) printf("%d ", s->items[i]);
    printf("\n");
}
#endif
