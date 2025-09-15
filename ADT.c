#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}List;

List initialize(List);
List insertPos(List, int, int);
List deletePos(List , int);
int locate(List, int);
List insertSorted(List, int);
void display(List);

int main() {

    List L;
    L.count = 0;
    
    // L = initialize(L);

    for(int i = 0; i < 7;i++){
            L.elem[i] = i * i;
            L.count++;
        }
        
        printf("Populated\n");
        display(L);
    
        printf("\n");
        L = insertPos(L, 9,2);
        printf("\n\ninsertPos\n");
        display(L);
     
        printf("\n");
        L = deletePos(L, 2);
        printf("\n\ndeletePos\n");
     
        display(L);
        int hi = locate(L, 25);
        printf("\n\nLocate: %d", hi);
        

        
        printf("\n\ninsertSorted\n");
        L = insertSorted(L,32);
        display(L);
        
    return 0;
}

List intialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    
    List temp;
    temp = L;
    int i;
    
    
    if(temp.count == MAX){
        printf("Array is full");
        return temp;
    }


    for(i = temp.count;i > position;i--){

            temp.elem[i] = temp.elem[i-1];
        
    }
    temp.elem[position] = data;
    temp.count++;
    return temp;
}

List deletePos(List L, int position){
    
    List temp; 
    temp = L;
    int i;
   
    
    for(i = 0; i < temp.count;i++){
        if(i >= position){
            temp.elem[i] = temp.elem[i+1];
        }
    }
    temp.count--;
    
    return temp;
    
}

int locate(List L, int data){
    int i;
    unsigned int returner = -1;
    for(i = 0; i < L.count;i++){
        if(data == L.elem[i]){
            returner = i;
        }
    }
    
    return returner;
}

List insertSorted(List L, int data){
    List temp;
    temp = L;
    int i;
    int position;
    
    for(i = 0;i < temp.count;i++){
        if(temp.elem[i] < data && temp.elem[i+1] >= data){
           position = i;
            break;
             
        }
    }
    

    temp = insertPos(temp,data, position + 1);
    return temp;
}

void display(List L){
    int i;
    for(i = 0; i < L.count;i++){
        printf("%d ", L.elem[i]);
    }
    printf("\nCount:%d" , L.count);
}