#include <iostream>

typedef struct Node
{
  unsigned val;
  Node *next;
} Node;

Node *initNode(Node *node, int value);
void cleanNode(Node *node);

#define DEBUG 1
#if DEBUG == 1
std::ostream &operator<<(std::ostream &os, Node *node);
#endif
