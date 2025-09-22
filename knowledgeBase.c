#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct {
    int id;
    char title[64];
    char content[255];
    int link;
} Article;

typedef struct {
    Article elems[MAX];
    int avail;
} VirtualHeap;

typedef int CList;
typedef enum {false, true} Boolean;


void initVH(VirtualHeap *VH, CList *L);
Boolean isEmpty(CList L);
Boolean isFull(VirtualHeap VH);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int idx);
void insertArticle(VirtualHeap *VH, CList *L, char *title, char *content, int pos);
void viewArticles(VirtualHeap VH, CList L);
void searchArticle(VirtualHeap VH, CList L, int id);
void deleteArticle(VirtualHeap *VH, CList *L, int id);


int main() {
    VirtualHeap VH;
    CList KB;
    initVH(&VH, &KB);

    insertArticle(&VH, &KB, "Login Guide", "Use your company email to login.", -1);
    insertArticle(&VH, &KB, "Password Reset", "Click forgot password link.", -1);
    insertArticle(&VH, &KB, "System Access", "Admins have full access.", 0);

    viewArticles(VH, KB);

    searchArticle(VH, KB, 2);

    deleteArticle(&VH, &KB, 1);

    viewArticles(VH, KB);

    return 0;
}

void initVH(VirtualHeap *VH, CList *L) {
    int i;
    VH->avail = 0;
    for (i = 0; i < MAX - 1; i++) {
        VH->elems[i].link = i + 1;
    }
    VH->elems[i].link = -1;
    *L = -1;  
}

Boolean isEmpty(CList L) {
    return (L == -1) ? true : false;
}

Boolean isFull(VirtualHeap VH) {
    return (VH.avail == -1) ? true : false;
}

int allocSpace(VirtualHeap *VH) {
    int temp = VH->avail;
    if (temp != -1) {
        VH->avail = VH->elems[temp].link;
    }
    return temp;
}

void deallocSpace(VirtualHeap *VH, int idx) {
    VH->elems[idx].link = VH->avail;
    VH->avail = idx;
}


void insertArticle(VirtualHeap *VH, CList *L, char *title, char *content, int pos) {
    static int idCounter = 1;
    int newNode = allocSpace(VH);

    if (newNode == -1) {
        printf("No space available!\n");
        return;
    }


    VH->elems[newNode].id = idCounter++;
    strcpy(VH->elems[newNode].title, title);
    strcpy(VH->elems[newNode].content, content);


    if (pos == 0 || *L == -1) {
        VH->elems[newNode].link = *L;
        *L = newNode;
    }
    else {
        int prev = *L, curr = *L, i = 0;
       
        while (curr != -1 && (i < pos - 1 || pos == -1)) {
            prev = curr;
            curr = VH->elems[curr].link;
            i++;
            if (pos == -1 && curr == -1) break;
        }
        VH->elems[newNode].link = VH->elems[prev].link;
        VH->elems[prev].link = newNode;
    }
}

void viewArticles(VirtualHeap VH, CList L) {
    printf("\nArticles List:\n");
    for (int trav = L; trav != -1; trav = VH.elems[trav].link) {
        printf("[%d] %s\n", VH.elems[trav].id, VH.elems[trav].title);
    }
}

void searchArticle(VirtualHeap VH, CList L, int id) {
    for (int trav = L; trav != -1; trav = VH.elems[trav].link) {
        if (VH.elems[trav].id == id) {
            printf("\nFound Article %d:\nTitle: %s\nContent: %s\n",
                   VH.elems[trav].id, VH.elems[trav].title, VH.elems[trav].content);
            return;
        }
    }
    printf("\nArticle with ID %d not found.\n", id);
}

void deleteArticle(VirtualHeap *VH, CList *L, int id) {
    int trav = *L, prev = -1;

    while (trav != -1 && VH->elems[trav].id != id) {
        prev = trav;
        trav = VH->elems[trav].link;
    }

    if (trav == -1) {
        printf("\nArticle with ID %d not found.\n", id);
        return;
    }

    if (prev == -1) {  
        *L = VH->elems[trav].link;
    } else {
        VH->elems[prev].link = VH->elems[trav].link;
    }

    deallocSpace(VH, trav);
    printf("\nArticle with ID %d deleted.\n", id);
}
