#include "Queue.h"

#define DEBUG 0

#if DEBUG == 1
#include <iostream>
#endif

void initQueue(Queue *q, unsigned size)
{
  q->arr = new unsigned[size];
  q->capacity = size;
  q->length = 0;
  q->rear = 0;
  q->front = 0;
}

void cleanQueue(Queue *q)
{
  delete[] q->arr;
  q->arr = nullptr;
  q->capacity = 0;
  q->length = 0;
  q->front = 0;
  q->rear = 0;
}

void enqueue(Queue *q, unsigned newValue)
{
  if (isFull(q))
  {
    unsigned newCapacity = q->capacity * 2;
    unsigned *newArr = new unsigned[newCapacity];

    unsigned i = 0;
    for (i = 0; i < q->length; i++)
    {
      newArr[i] = q->arr[(q->front + i) % q->capacity];
    }

    delete[] q->arr;
    q->arr = newArr;
    q->capacity = newCapacity;
    q->front = 0;
    q->rear = q->length;
  }

  q->arr[q->rear] = newValue;
  q->rear = (q->rear + 1) % q->capacity;
  q->length++;
}

int dequeue(Queue *q)
{
  if (isEmpty(q))
  {
    return -1;
  }

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

#if DEBUG == 1
std::ostream &operator<<(std::ostream &os, Queue *queue)
{
  unsigned i = 0;
  for (i = 0; i < queue->length; i++)
  {
    os << queue->arr[(queue->front + i) % queue->capacity] << " ";
  }
  return os;
}

int main(void)
{
  Queue *q = new Queue;
  initQueue(q, 5);
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  enqueue(q, 5);
  enqueue(q, 6); // resizes here to 10

  cleanQueue(q);
  delete q;
  return 0;
}
#endif
