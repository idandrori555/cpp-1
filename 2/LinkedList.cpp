#include "LinkedList.h"

Node *initNode(Node *node, int value)
{
  return new Node{value, nullptr};
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
