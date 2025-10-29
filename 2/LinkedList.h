#include <iostream>

typedef struct Node
{
  unsigned value;
  Node *prev;
  Node *next;
} Node;

Node *initNode(unsigned value, Node *prev, Node *next);
void cleanNode(Node *node);
