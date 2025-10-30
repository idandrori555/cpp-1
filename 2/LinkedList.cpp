#include "LinkedList.h"

#if DEBUG == 1
std::ostream &operator<<(std::ostream &os, Node *node)
{
  while (nullptr != node)
  {
    os << node->val << " ";
    node = node->next;
  }
  return os;
}
#endif

Node *initNode(unsigned value, Node *prev, Node *next)
{
  return new Node{value, prev, next};
}

void cleanNode(Node *node)
{
  Node *next = nullptr;
  while (nullptr != node)
  {
    next = node->next;
    delete node;
    node = next;
  }
}

#if DEBUG == 1
int main(void)
{
  Node *head = initNode(0);
  std::cout << head << std::endl;

  add(head, 1);
  add(head, 2);
  add(head, 3);
  add(head, 4);
  std::cout << head << std::endl;

  remove(head, 1);
  std::cout << head << std::endl;

  remove(head, 4);
  std::cout << head << std::endl;

  cleanNode(head);
  return 0;
}
#endif
