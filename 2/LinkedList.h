typedef struct Node
{
  int val;
  Node *next;
} Node;

Node *initNode(Node *node, int value);
void cleanNode(Node *node);
