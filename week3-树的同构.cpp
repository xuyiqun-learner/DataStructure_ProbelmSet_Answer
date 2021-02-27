

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
  while (T != nullptr || s.size() > 0)
  {
    while (T != nullptr)
    {
      s.push(T->Data);
      T = T->Left;
    }
   if(s.empty() != true) {
     s.pop(T->Data);
     cout << T->Data;
     T = T->Right;
   }
  }
}

int Tree_omorphism(BinTree& x, BinTree& y);

int main() {
  

  return 0;
}

int Tree_omorphism(BinTree& x, BinTree& y) {

  return 0;
}