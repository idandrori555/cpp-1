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
  if (nullptr == node)
  {
    return;
  }

  if (node->val == target)
  {
    Node *toDelete = node;
    node = node->next;
    delete toDelete;
    return;
  }

  Node *temp = node;
  while (nullptr != temp->next && temp->next->val != target)
  {
    temp = temp->next;
  }

  if (!temp->next)
  {
    return;
  }

  Node *toDelete = temp->next;
  temp->next = toDelete->next;
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
