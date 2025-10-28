#include "Queue.h"
#include <iostream>

void initQueue(Queue *q, unsigned int size)
{
  q->arr = new unsigned[size];
  q->capacity = size;
  q->length = 0;
  q->rear = 0;
  q->front = 0;
}

void cleanQueue(Queue *q)
{
  q->capacity = 0;
  q->length = 0;
  delete[] q->arr;
  q->arr = nullptr;
}

void enqueue(Queue *q, unsigned newValue)
{
  q->arr[q->rear] = newValue;
  q->rear = (q->rear + 1) % q->capacity;
  q->length++;
}

int dequeue(Queue *q)
{
  int val = q->arr[q->front];
  q->front = (q->front + 1) % q->capacity;
  q->length--;
  return val;
}

bool isEmpty(Queue *s)
{
  return s->length == 0;
}

bool isFull(Queue *s)
{
  return s->length == s->capacity;
}

std::ostream &operator<<(std::ostream &os, Queue *queue)
{
  for (size_t i = 0; i < queue->length; i++)
  {
    os << queue->arr[i] << " ";
  }

  return os;
}

#define DEBUG 0

#if DEBUG == 1
int main(void)
{
  Queue *q = new Queue;
  initQueue(q, 5);

  std::cout << q << std::endl;

  cleanQueue(q);
  delete q;
  return 0;
}
#endif
