#include <iostream>

typedef struct Node
{
  unsigned val;
  Node *next;
} Node;

Node *initNode(Node *node, int value);
void cleanNode(Node *node);
