#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main() {
    List L = initialize(L);

    for(int i = 0; i < 7; i++){
        L.elem[i] = i * i;
        L.count++;
    }

    printf("Populated\n");
    display(L);

    L = insertPos(L, 9, 2);
    printf("\ninsertPos\n");
    display(L);

    L = deletePos(L, 2);
    printf("\ndeletePos\n");
    display(L);

    int pos = locate(L, 25);
    printf("\nlocate(25): %d\n", pos);

    printf("\ninsertSorted(32)\n");
    L = insertSorted(L, 32);
    display(L);

    return 0;
}

List initialize(List L) {
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position) {
    if (L.count == MAX) {
        printf("Array is full\n");
        return L;
    }

    if (position < 0 || position > L.count)
        position = L.count;  

    for (int i = L.count; i > position; i--) {
        L.elem[i] = L.elem[i - 1];
    }

    L.elem[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position) {
    if (position < 0 || position >= L.count) {
        printf("Invalid position\n");
        return L;
    }

    for (int i = position; i < L.count - 1; i++) {
        L.elem[i] = L.elem[i + 1];
    }

    L.count--;
    return L;
}

int locate(List L, int data) {
    for (int i = 0; i < L.count; i++) {
        if (L.elem[i] == data)
            return i; 
    }
    return -1; 
}

List insertSorted(List L, int data) {
    if (L.count == MAX) {
        printf("Array is full\n");
        return L;
    }

    int pos = 0;
    while (pos < L.count && L.elem[pos] < data)
        pos++;

    return insertPos(L, data, pos);
}

void display(List L) {
    for (int i = 0; i < L.count; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\nCount: %d\n", L.count);
}
