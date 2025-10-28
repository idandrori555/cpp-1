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

Node *initNode(unsigned value, Node *next = nullptr)
{
  return new Node{value, next};
}

void add(Node *node, unsigned value)
{
}

void cleanNode(Node *node)
{
  if (nullptr == node)
  {
    return;
  }

  cleanNode(node->next);
  delete node;
}

int main(void)
{
  Node *head = initNode(1, initNode(2, initNode(3, nullptr)));

  std::cout << head << std::endl;

  cleanNode(head);
  return 0;
}
