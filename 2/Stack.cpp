#include "Stack.h"

void push(Stack *s, unsigned int element);
int pop(Stack *s)
{
  if (isEmpty(s))
  {
    return 0;
  }
}

void initStack(Stack *s)
{
  s = new Stack;
  s->capacity = 0;
  s->length = 0;
  s->next = nullptr;
}

void cleanStack(Stack *s)
{
  while (!isEmpty(s))
  {
    pop(s);
  }
}

bool isEmpty(Stack *s)
{
  return s->length == 0;
}

bool isFull(Stack *s)
{
  return s->capacity == s->length;
}
