#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElementType;

typedef struct LNode *List;
struct LNode {
    ElementType Data;
    LNode *next; 
};

void Combine_LinkedList(List& x, List& y);

int main()
{
    List L1;
    List L2;
    List L3;
    // ElementType X;

    for(;L1->Data != -1; L1 = L1->next) {
        scanf("%d",&L1->Data);

    }
    for(;L2->Data != -1; L2 = L2->next) {
        scanf("%d",&L2->Data);
    }
    // scanf("%d", &X);
    Combine_LinkedList(L1, L2);

    return 0;
}

void Combine_LinkedList(List& x, List& y) {


}