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
  while (nullptr != node->next)
  {
    node = node->next;
  }

  node->next = initNode(value);
}

void remove(Node *node, unsigned target)
{
  while (node->next && node->next->val != target)
  {
    node = node->next;
    std::cout << node->val << ' ';
  }

  if (!node->next)
  {
    return;
  }

  Node *toDelete = node->next;
  node->next = toDelete->next;
  delete toDelete;
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
