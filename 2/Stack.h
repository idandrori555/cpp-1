#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

/* a positive-integer value stack, with no size limit */
typedef struct Stack
{
  unsigned length;
  Node *top;
  Node *bottom;
} Stack;

void push(Stack *s, unsigned element);
int pop(Stack *s); // Return -1 if stack is empty

void initStack(Stack *s);
void cleanStack(Stack *s);

bool isEmpty(Stack *s);
bool isFull(Stack *s);

#endif // STACK_H
