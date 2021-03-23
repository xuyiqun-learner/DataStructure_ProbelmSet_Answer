#include <iostream>

using std::cout;
using std::cin;

struct node {
  int left;
  int right;
  bool root = true;
};
typedef node BinTree;

int main(int argc, char argv[]) {
  int NodeNum = 0;
  cin >> NodeNum;
  node bt[NodeNum];
  char l, r;
  int root1;
  int tree[NodeNum];
  int isfirst = 1; // 判断是否为第一个输入
  for (int i = 0; i < NodeNum; ++i) {
    cin >> l >> r;
    if(l == '-') {
      bt[i].left = -1;
    }
    else {
      bt[i].left = l - '0';
      bt[l-'0'].root = false; // 为孩子则不可能为根结点
    }
    if(r == '-') {
      bt[i].right = -1;
    }
    else {
      bt[i].right = r - '0';
      bt[r-'0'].root = false;
    }
  }
  for(int i = 0; i < NodeNum; ++i) {
    if(bt[i].root == true) {
      root1 = i;
    }
  }

  //层序遍历保存结点的值
  int j = 0;
  tree[j++] = root1;
  for(int i = 0; i< NodeNum; ++i) {
    if(bt[tree[i]].left != -1) { // 有左孩子
      tree[j++] = bt[tree[i]].left;
    }
    if(bt[tree[i]].right != -1) { // 有右孩子
      tree[j++] = bt[tree[i]].right;
    }
  }

  // 遍历树输出所有的叶节点
  for(int i = 0; i < NodeNum; ++i) {
    if(bt[tree[i]].left == -1 && bt[tree[i]].right == -1) {
      if(isfirst == true) {
        cout << tree[i];
        isfirst = 0;
      }
      else {
        cout << " " << tree[i];
      }
    }
  }
  return 0;
}

