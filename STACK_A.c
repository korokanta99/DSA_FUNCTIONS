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

int isEmptyStack(Stack *s){
    return (s->top == -1);
}

int isFullStack(Stack *s){
    return (s->top == MAX - 1);
}

void push(Stack *s, int data){
    if(!isFullStack(s)){
        s->items[++(s->top)] = data;
    }
}

void pop(Stack *s){
    if(!isEmptyStack(s)){
        s->top--;
    }
}

int peek(Stack *s){
    return s->items[s->top];
}

void pushUnique(Stack *s, int data){
    for(int i=0; i<=s->top; i++){
        if(s->items[i]==data){
            printf("%d already exists.\n", data);
            return;
        }
    }
    if(!isFullStack(s)){
        s->items[++(s->top)] = data;
    } else {
        printf("Stack full.\n");
    }
}

void popUnique(Stack *s, int data){
    Stack temp; initStack(&temp);
    while(!isEmptyStack(s)){
        int val = peek(s);
        pop(s);
        if(val != data) push(&temp, val);
    }
    while(!isEmptyStack(&temp)){
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
