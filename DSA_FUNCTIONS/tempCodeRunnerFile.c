#include <stdio.h>
#include <stdlib.h>
#include "STACK_A.c"  

#define NUM_STACKS 3

void checkness(Stack s[], int data);
void remover(Stack s[]);
void locate2(Stack s[], int data);

int main(void) {
    Stack stacks[NUM_STACKS];


    for (int i = 0; i < NUM_STACKS; i++) {
        initStack(&stacks[i]);
    }


    checkness(stacks, 101);
    checkness(stacks, 102);
    checkness(stacks, 103);
    checkness(stacks, 104);
    checkness(stacks, 105);
    checkness(stacks, 106); 
    checkness(stacks, 107);

    printf("\nCurrent stacks:\n");
    for (int i = 0; i < NUM_STACKS; i++) {
        printf("Stack %d: ", i);
        display(&stacks[i]);
    }

    locate2(stacks, 105);

    remover(stacks);

    printf("\nAfter removal:\n");
    for (int i = 0; i < NUM_STACKS; i++) {
        printf("Stack %d: ", i);
        display(&stacks[i]);
    }

    return 0;
}

void checkness(Stack s[], int data){
    
int i;

for(i = 0; i < 3;i++){
    if(!isFull(&s[i])){
        push(&s[i],data);
        printf("pushed at %d", i);
        return;
    }
}

}

void remover(Stack s[]){
    int i;

    for(i = 0; i < 3;i++){
        if(!isEmpty(&s[i])){
            pop(&s[i]);
            break;
        }
    }
}

void initUlt(Stack *s){

int i;
for(i = 0; i < 3;i++){
    initStack(&s[i]);
}

}


void locate2(Stack s[], int data){
    int locater,locater2;

    for(int i = 0; i < 3 ; i++){

        Stack temp;
        initStack(&temp);
        while(!isEmpty(&s[i])){
            if(peek(&s[i]) != data){
                push(&temp,peek(&s[i]));
                pop(&s[i]);
            }
            else{
                locater2 =i;
                locater = s[i].top;
            }
        }

        while(!isEmpty(&temp)){
            push(&s[i],peek(&temp));
            pop(&temp);
        }



    }

    printf("Found in index %d containder %d", locater, locater2);
}

