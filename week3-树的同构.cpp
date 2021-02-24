

#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

#define MaxSize 10
typedef struct TreeNode *BinTree;
struct TreeNode
{
  int Data;
  BinTree Left;
  BinTree Right;
};

//############ 递归法 ################
// 前序遍历
void PreOrderTraversal(BinTree BT) {
  if(BT != nullptr) {
    cout << BT->Data;             // 访问根结点
    PreOrderTraversal(BT->Left);  // 遍历左子树
    PreOrderTraversal(BT->Right); // 访问右子树
  }
}

// 中序遍历
void InOrderTraversal( BinTree BT ) {
  if(BT != nullptr) {
    InOrderTraversal(BT->Left);  // 遍历左子树
    cout << BT->Data;            // 访问根结点
    InOrderTraversal(BT->Right); // 访问右子树
  }
}

// 后序遍历
void PostOrderTraversal(BinTree BT) {
  if(BT != nullptr) {
    PostOrderTraversal(BT->Left);  // 遍历左子树
    PostOrderTraversal(BT->Right); // 访问右子树
    cout << BT->Data;              // 访问根结点
  }
}
//############### 递归法 ################

// ########### 非递归遍历算法 ##############
// 中序遍历
void InOrderTraversal(BinTree BT) {
  BinTree T = BT;
  stack<int> s;
  

}

int Tree_omorphism(BinTree& x, BinTree& y);

int main() {
  struct LNode* L1 = (struct LNode*)malloc(sizeof(struct LNode));
  struct LNode* L2 = (struct LNode*)malloc(sizeof(struct LNode));
  // struct LNode* L3 = (struct LNode*)malloc(sizeof(struct LNode));
  struct LNode* head_l1 = (struct LNode*)malloc(sizeof(struct LNode));
  struct LNode* head_l2 = (struct LNode*)malloc(sizeof(struct LNode));
  head_l1->next = L1;
  head_l2->next = L2;
  // insert from tail
  for (;; L1 = L1->next) {
    scanf("%d", &L1->Data);
    if (L1->Data == -1) {
      break;
    }
    L1->next = (struct LNode*)malloc(sizeof(struct LNode));
  }

  for (;; L2 = L2->next) {
    scanf("%d", &L2->Data);
    if (L2->Data == -1) {
      break;
    }
    L2->next = (struct LNode*)malloc(sizeof(struct LNode));
  }
  if(head_l1->next->Data == -1 || head_l2->next->Data == -1) {
    printf("NULL");
    return NULL;
  }
  // printf("head_l2->next->Data: %d\n", head_l2->next->Data);

  Combine_LinkedList(head_l1->next, head_l2->next);

  return 0;
}

int Combine_LinkedList(struct LNode* x, struct LNode* y) {
  // struct LNode* l3 = (LNode *)malloc(sizeof(LNode));
  struct LNode* head_l3 = (struct LNode*)malloc(sizeof(struct LNode));
  struct LNode* l3 = (struct LNode*)malloc(sizeof(struct LNode));
  head_l3->next = l3;
  while( x->Data != -1 && y->Data != -1) {
    if(x->Data > y->Data) {
      l3->Data = y->Data;
      // printf("if l3->Data = y->Data: %d\n", l3->Data);
      l3->next = (struct LNode*)malloc(sizeof(struct LNode));
      l3 = l3->next;
      l3->Data = x->Data;
      // printf("if l3->Data = x->Data: %d\n", l3->Data);
    }
    else {
      l3->Data = x->Data;
      // printf("else l3->Data = x->Data: %d\n", l3->Data);
      l3->next = (struct LNode*)malloc(sizeof(struct LNode));
      l3 = l3->next;
      l3->Data = y->Data;
      // printf("else l3->Data = y->Data: %d\n", l3->Data);
    }
    x = x->next;
    y = y->next;
    l3->next = (struct LNode*)malloc(sizeof(struct LNode));
    l3 = l3->next;
  }
  while(x->Data != -1) {
    l3->Data = x->Data;
    // printf("x != NULL: l3->Data = x->Data: %d\n", l3->Data);
    l3->next = (struct LNode*)malloc(sizeof(struct LNode));
    l3 = l3->next;
    x = x->next;
  }
  while(y->Data != -1) {
    l3->Data = y->Data;
    // printf("y != NULL: l3->Data = y->Data: %d\n", l3->Data);
    l3->next = (struct LNode*)malloc(sizeof(struct LNode));
    l3 = l3->next;
    y = y->next;
  }
  // if(head_l3->next == NULL) {
  //   printf("%d",NULL);  
  // }
  printf("%d",head_l3->next->Data);
  head_l3 = head_l3->next;
  for(;head_l3->next->next != NULL; head_l3 = head_l3->next) {
    printf(" %d", head_l3->next->Data);
  }
}