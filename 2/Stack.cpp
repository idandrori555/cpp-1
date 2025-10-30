#include "Stack.h"

#define DEBUG 0

void initStack(Stack *s)
{
  s->top = nullptr;
  s->bottom = nullptr;
  s->length = 0;
}

bool isEmpty(Stack *s)
{
  return s->length == 0;
}

void push(Stack *s, unsigned element)
{
  Node *newNode = initNode(element, s->top, nullptr);

  if (isEmpty(s))
  {
    s->bottom = newNode;
  }
  else
  {
    s->top->next = newNode;
  }

  s->top = newNode;
  s->length++;
}

int pop(Stack *s)
{
  if (isEmpty(s))
  {
    return -1;
  }

  unsigned value = s->top->value;
  Node *toDelete = s->top;

  s->top = s->top->prev;
  if (s->top)
  {
    s->top->next = nullptr;
  }
  else
  {
    s->bottom = nullptr;
  }

  delete toDelete;
  s->length--;

  return value;
}

void cleanStack(Stack *s)
{
  Node *cur = s->bottom;
  Node *next = nullptr;

  while (cur)
  {
    next = cur->next;
    delete cur;
    cur = next;
  }

  s->bottom = s->top = nullptr;
  s->length = 0;
}

#if DEBUG == 1
#include <iostream>
std::ostream &operator<<(std::ostream &os, Stack *s)
{
  Node *tmp = s->bottom;
  while (tmp)
  {
    os << tmp->value << '\n';
    tmp = tmp->next;
  }
  return os;
}

int main()
{
  Stack *s = new Stack;
  initStack(s);

  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);

  std::cout << s << std::endl;

  int val = pop(s);
  std::cout << "Popped: " << val << "\n";
  std::cout << s << std::endl;

  val = pop(s);
  std::cout << "Popped: " << val << "\n";
  std::cout << s << std::endl;

  val = pop(s);
  std::cout << "Popped: " << val << "\n";
  std::cout << s << std::endl;

  val = pop(s);
  std::cout << "Popped: " << val << "\n";
  std::cout << s << std::endl;

  val = pop(s);
  std::cout << "Popped: " << val << "\n";

  cleanStack(s);
  delete s;

  return 0;
}
#endif
