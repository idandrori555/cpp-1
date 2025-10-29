#include "Stack.h"

#define DEBUG 0

void push(Stack *s, unsigned element)
{
}

int pop(Stack *s)
{
  if (isEmpty(s))
  {
    return 0;
  }

  return 0;
}

void initStack(Stack *s)
{
  s->capacity = 0;
  s->length = 0;
  s->node = new Node{0, nullptr};
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

#if DEBUG == 1
std::ostream &operator<<(std::ostream &os, Stack *s)
{
  while (!isEmpty(s))
  {
    std::cout << s->node->val << ' ';
  }
}

int main(void)
{
  Stack *s = new Stack;
  initStack(s);

  delete s;
  return 0;
}
#endif
