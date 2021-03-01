#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

#define MaxSize 11 // N小于等于10
typedef struct TreeNode *BinTree;
struct TreeNode
{
  char value;
  int left;
  int right;
};

void CreateTree(vector<TreeNode>& tree, int N);
int FindTreeRoot(vector<TreeNode>& tree, int N);
bool IsOmorphism(int root1, int root2, vector<TreeNode>& tree1, vector<TreeNode>& tree2);

int main(int argc, char ** argv) {
  int tree1_node = 0;
  cin >> tree1_node;
  vector<TreeNode> tree1(MaxSize);
  CreateTree(tree1, tree1_node);

  int tree2_node = 0;
  vector<TreeNode> tree2(MaxSize);
  cin >> tree2_node;
  CreateTree(tree2, tree2_node);

  if(tree1_node != tree2_node) {
    cout << "No";
  }
  else {
    if(tree1_node == 0) {
      cout << "Yes";
    }
    else {
      int root1 = FindTreeRoot(tree1, tree1_node);
      int root2 = FindTreeRoot(tree2, tree2_node);
      if(IsOmorphism(root1, root2, tree1, tree2)) {
        cout << "Yes";
      }
      else {
        cout << "No";
      }
    }
  }
  return 0;
}

void CreateTree(vector<TreeNode>& Tree, int N) {
   char value, left, right;
   for(int i=0; i<N; ++i) {
     cin >> value >> left >> right;
     Tree[i].value = value;
     if(left == '-') {
       Tree[i].left  = -1;
     }
     else {
       Tree[i].left = left - '0';
     }
     if(right == '-') {
       Tree[i].right = -1;
     }
     else {
       Tree[i].right = right - '0';
     }
   }
}

int FindTreeRoot(vector<TreeNode>& Tree, int N) {
  int Flag[MaxSize];
  for(int i = 0; i < N; i++) {
    Flag[i] = 0;
  }
  for(int i=0; i<N; i++) {
    if(Tree[i].left != -1) {
      Flag[Tree[i].left] = 1; // 是左孩子，不是根结点
    }
    if(Tree[i].right != -1) {
      Flag[Tree[i].right] = 1; // 是右孩子，不是根结点
    }
  }
  int k = 0;
  for(; k < N; k++) {
    if(Flag[k] == 0) {
      break;
    }
  }
  return k;
}

// 核心在于进行递归遍历对不同的情况进行比较
bool IsOmorphism(int root1, int root2, vector<TreeNode>& tree1, vector<TreeNode>& tree2) {
  if(tree1[root1].value == tree2[root2].value) {
    // 此结点没有叶子结点
    if(tree1[root1].left == -1 && tree1[root1].right == -1 && tree2[root2].left == -1 && tree2[root2].right == -1) {
      return true;
    }
    // 两个结点都是有一个子树为空，另一个子树不空且相等
    if(tree1[tree1[root1].left].value == tree2[tree2[root2].left].value && tree1[root1].right == -1 && tree2[root2].right == -1) {
      // A左子树与B左子树首结点相等，A右子树为0，B右子树为空
      return IsOmorphism(tree1[root1].left, tree2[root2].left, tree1, tree2);
    }
    if(tree1[tree1[root1].left].value == tree2[tree2[root2].right].value && tree1[root1].right == -1 && tree2[root2].left == -1) {
      // A左子树与B右子树首结点相等，A右子树为0，B左子树为空
      return IsOmorphism(tree1[root1].left, tree2[root2].right, tree1, tree2);
    }
    if(tree1[tree1[root1].right].value == tree2[tree2[root2].left].value && tree1[root1].left == -1 && tree2[root2].right == -1) {
      // A右子树与B左子树首结点相等，A左子树为0，B右子树为空
      return IsOmorphism(tree1[root1].right,  tree2[root2].left, tree1, tree2);
    }
    if(tree1[tree1[root1].right].value == tree2[tree2[root2].right].value && tree1[root1].left == -1 && tree2[root2].left == -1) {
      // A右子树与B右子树首结点相等，A左子树为0，B左子树为空
      return IsOmorphism(tree1[root1].right, tree2[root2].right, tree1, tree2);
    }

    // 两个结点的两个子树都相等
    if(tree1[tree1[root1].left].value == tree2[tree2[root2].left].value && tree1[tree1[root1].right].value == tree2[tree2[root2].right].value) {
      return (IsOmorphism(tree1[root1].left, tree2[root2].left, tree1, tree2)) && (IsOmorphism(tree1[root1].right, tree2[root2].right, tree1, tree2));
    }
    if(tree1[tree1[root1].left].value == tree2[tree2[root2].right].value && tree1[tree1[root1].right].value == tree2[tree2[root2].left].value) {
      return (IsOmorphism(tree1[root1].left, tree2[root2].right, tree1, tree2)) && (IsOmorphism(tree1[root1].right, tree2[root2].left, tree1, tree2));
    }
  }
  return false;
}

bool IsOmorphic(int root1, int root2, vector<TreeNode>& tree1, vector<TreeNode>& tree2) {
  std::stack<BinTree> _tree1;
  std::stack<BinTree> _tree2;
  // if(tree1[root1].value == tree2[root2].value) {
    while(tree1[root2].value == tree2[root2].value) {
    // 此结点没有叶子结点
    if(tree1[root1].left == -1 && tree1[root1].right == -1 && tree2[root2].left == -1 && tree2[root2].right == -1) {
      return true;
    }
    // 两个结点都是有一个子树为空，另一个子树不空且相等
    if(tree1[tree1[root1].left].value == tree2[tree2[root2].left].value && tree1[root1].right == -1 && tree2[root2].right == -1) {
      // A左子树与B左子树首结点相等，A右子树为0，B右子树为空
      // A左子树与B右子树首结点相等，A右子树为0，B左子树为空
      return IsOmorphism(tree1[root1].left, tree2[root2].right, tree1, tree2);
    }
    if(tree1[tree1[root1].right].value == tree2[tree2[root2].left].value && tree1[root1].left == -1 && tree2[root2].right == -1) {
      // A右子树与B左子树首结点相等，A左子树为0，B右子树为空
      return IsOmorphism(tree1[root1].right,  tree2[root2].left, tree1, tree2);
    }
    if(tree1[tree1[root1].right].value == tree2[tree2[root2].right].value && tree1[root1].left == -1 && tree2[root2].left == -1) {
      // A右子树与B右子树首结点相等，A左子树为0，B左子树为空
      return IsOmorphism(tree1[root1].right, tree2[root2].right, tree1, tree2);
    }

    // 两个结点的两个子树都相等
    if(tree1[tree1[root1].left].value == tree2[tree2[root2].left].value && tree1[tree1[root1].right].value == tree2[tree2[root2].right].value) {
      return (IsOmorphism(tree1[root1].left, tree2[root2].left, tree1, tree2)) && (IsOmorphism(tree1[root1].right, tree2[root2].right, tree1, tree2));
    }
    if(tree1[tree1[root1].left].value == tree2[tree2[root2].right].value && tree1[tree1[root1].right].value == tree2[tree2[root2].left].value) {
      return (IsOmorphism(tree1[root1].left, tree2[root2].right, tree1, tree2)) && (IsOmorphism(tree1[root1].right, tree2[root2].left, tree1, tree2));
    }
  }
  return false;
}
