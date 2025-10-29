#include "Stack.h"

#define DEBUG 0

void push(Stack *s, unsigned element)
{
  Node *newNode = initNode(element, nullptr, nullptr);

  if (s->length == 0)
  {
    s->top = s->bottom = newNode;
    return;
  }

  Node *temp = nullptr;

  s->top->next = newNode;
  temp = s->top;
  s->top = s->top->next;
  s->top->prev = temp;

  s->length++;
}

int pop(Stack *s)
{
  if (isEmpty(s))
  {
    return -1; // Empty
  }

  Node *toDelete = s->top;
  unsigned value = toDelete->value;

  s->top = s->top->prev;

  if (s->top)
  {
    s->top->next = nullptr;
  }
  else
  {
    s->bottom = nullptr;
  };

  delete toDelete;
  s->length--;

  return value;
}

void initStack(Stack *s)
{
  s->length = 0;
  s->bottom = s->top = nullptr;
}

void cleanStack(Stack *s)
{
  cleanNode(s->bottom);
}

bool isEmpty(Stack *s)
{
  return s->length == 0;
}

bool isFull(Stack *s)
{
  return false;
}

#if DEBUG == 1
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

int main(void)
{
  Stack *s = new Stack;
  initStack(s);
  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);

  std::cout << s << std::endl;

  int val = pop(s);
  std::cout << s << std::endl;
  std::cout << "Popped: " << val;

  val = pop(s);
  std::cout << s << std::endl;
  std::cout << "popped: " << val;

  val = pop(s);
  std::cout << s << std::endl;
  std::cout << "popped: " << val;

  val = pop(s);
  std::cout << s << std::endl;
  std::cout << "popped: " << val;

  val = pop(s);
  std::cout << s << std::endl;
  std::cout << "popped: " << val << '\n';

  cleanStack(s);
  delete s;
  return 0;
}
#endif
