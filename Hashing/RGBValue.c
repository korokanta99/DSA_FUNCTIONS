#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64

typedef struct {
    char name[20];
} String;

typedef struct Node {
    String colourName;
    int RGBval[3];
    struct Node *next;
} *colour;

typedef colour dict[SIZE];

int hasher(int RGBval[]);
void initDict(dict *d);  
void insert(dict *d, int RGBval[], String name);

int main() {
    dict d;
    initDict(&d); 

    String name = {"Red"};
    int rgb[] = {255, 0, 0};

    insert(&d, rgb, name); 

    printf("Color Name: %s\n", d[hasher(rgb)]->colourName.name);
    printf("RGB: (%d, %d, %d)\n", d[hasher(rgb)]->RGBval[0], d[hasher(rgb)]->RGBval[1], d[hasher(rgb)]->RGBval[2]);

    return 0;
}

int hasher(int RGBval[]) {
    return ((RGBval[0] + 11) + (RGBval[1] + 7) + (RGBval[2] + 3)) % SIZE;
}

void initDict(dict *d) {  
    for (int i = 0; i < SIZE; i++) {
        (*d)[i] = NULL; 
    }
}

void insert(dict *d, int RGBval[], String name) {  
    int index = hasher(RGBval);

    if ((*d)[index] != NULL) { 
        colour newNode = malloc(sizeof(struct Node));
        newNode->RGBval[0] = RGBval[0];
        newNode->RGBval[1] = RGBval[1];
        newNode->RGBval[2] = RGBval[2];
        newNode->colourName = name;
        newNode->next = NULL;
        (*d)[index]->next = newNode;
    } else {
        (*d)[index] = malloc(sizeof(struct Node));
        (*d)[index]->RGBval[0] = RGBval[0];
        (*d)[index]->RGBval[1] = RGBval[1];
        (*d)[index]->RGBval[2] = RGBval[2];
        (*d)[index]->colourName = name;
        (*d)[index]->next = NULL;
    }
}

void delete(dict *d, int RGBval[]) {
    int index = hasher(RGBval);
    colour curr = (*d)[index];
    colour prev = NULL;

    while (curr != NULL) {
        if (curr->RGBval[0] == RGBval[0] &&
            curr->RGBval[1] == RGBval[1] &&
            curr->RGBval[2] == RGBval[2]) {
            
            if (prev == NULL) {  

                (*d)[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            
            free(curr); 
            return;     
        }
        prev = curr;
        curr = curr->next;
    }
}
