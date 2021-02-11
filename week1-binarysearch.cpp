#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch( List L, ElementType X ) {
    int left = 1;
    int right = L->Last;
    int middle = (left+right)/2;
    for( ; left < right && middle != right && middle != left; middle = (left+right)/2) {
        if(X < L->Data[middle] && X > L->Data[left]) {
            right = middle;
        }
        else if(X > L->Data[middle] && X < L->Data[right]) {
            left = middle;
        }
        else if(X == L->Data[left]) {
            return left;
        }
        else if(X == L->Data[right]) {
            return right;
        }
        else if(X == L->Data[middle]) {
            return middle;
        }
        else {
            return NotFound;
        }
    }
    return NotFound;
}