#include <iostream>

typedef struct LNode* List;
struct LNode {
  int variable;
  int coefficients;
  LNode* next;
};

void unary_polynomial_multiplication_Addition_operation(List& x, List& y);

int main() {
  List L1 = new LNode();
  List L2 = new LNode();

  List head_L1 = new LNode();
  List head_L2 = new LNode();
  head_L1->next = L1;
  head_L2->next = L2;
  // insert from tail
  for (;; L1 = L1->next) {
    scanf("%d", &L1->variable);
    scanf("%d", &L1->coefficients);
    if (L1->coefficients == 0) {
      break;
    }
    L1->next = new LNode();
  }

  for (;; L2 = L2->next) {
    scanf("%d", &L2->variable);
    scanf("%d", &L2->coefficients);
    if (L2->coefficients == 0) {
      break;
    }
    L2->next = new LNode();
  }
  if(head_L1->next->coefficients == 0 || head_L2->next->coefficients == 0) {
    printf("0 0");
    return -1;
  }

  unary_polynomial_multiplication_Addition_operation(head_L1, head_L2);
  return 0;
}

void unary_polynomial_multiplication_Addition_operation(List& x, List& y) {
  List head_L3 = new LNode();
  List L3 = new LNode();
  for(; x->coefficients >=0; x = x->next ) {
    for(; y->coefficients >=0; y = y->next ) {

    }
  }


}