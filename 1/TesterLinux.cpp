#include "Queue.h"
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

// Color codes using ANSI escape sequences
#define RESET "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define LIGHT_RED "\033[1;31m"
#define LIGHT_GREEN "\033[1;32m"
#define LIGHT_YELLOW "\033[1;33m"
#define LIGHT_BLUE "\033[1;34m"
#define LIGHT_PURPLE "\033[1;35m"
#define LIGHT_CYAN "\033[1;36m"
#define BRIGHT_WHITE "\033[1;37m"

void set_console_color(const std::string &color)
{
  cout << color;
}

std::string removeElementsAndGetPrintedQueue(Queue *q)
{
  std::stringstream output;
  while (!isEmpty(q))
  {
    output << dequeue(q) << " ";
  }
  std::string outputString = output.str();
  if (!outputString.empty())
    outputString.pop_back(); // remove trailing space
  return outputString;
}

bool test1()
{
  try
  {
    set_console_color(LIGHT_BLUE);
    cout << "*******************************\n"
            "Test 1 - basic queue functions\n"
            "*******************************\n"
         << endl;
    set_console_color(WHITE);

    cout << "Initializing queue with size 5 ... \n" << endl;
    Queue *q0 = new Queue;
    initQueue(q0, 5);

    bool empty = isEmpty(q0);
    cout << "Checking if queue is empty ... \n"
         << "Expected: true\n"
         << "Got     : " << (empty ? "true" : "false") << "\n"
         << endl;

    if (!empty)
      return false;

    const std::string queue0elements = "1 4 9 16 25";

    cout << "Adding elements to queue ... " << queue0elements << "\n" << endl;
    for (int i = 0; i < 5; i++)
      enqueue(q0, (i + 1) * (i + 1));

    bool full = isFull(q0);
    cout << "Checking if queue is full ... \n"
         << "Expected: true\n"
         << "Got     : " << (full ? "true" : "false") << "\n"
         << endl;

    if (!full)
      return false;

    std::string output = removeElementsAndGetPrintedQueue(q0);
    cout << "Removing elements and printing queue ...\n"
         << "Expected: " << queue0elements << "\n"
         << "Got     : " << output << "\n " << endl;

    if (output != queue0elements)
      return false;

    cout << "Cleaning queue...\n" << endl;
    cleanQueue(q0);
    delete q0;
  }
  catch (...)
  {
    std::cerr << "Test crashed" << endl;
    return false;
  }

  return true;
}

bool test2()
{
  try
  {
    set_console_color(LIGHT_BLUE);
    cout << "*******************************\n"
            "Test 2 - two queues\n"
            "*******************************\n"
         << endl;
    set_console_color(WHITE);

    cout << "Initializing first queue with size 3 ... \n" << endl;
    Queue *q1 = new Queue;
    initQueue(q1, 3);

    const std::string queue1elements = "10 20 30";

    cout << "Adding elements to first queue ... " << queue1elements << "\n"
         << endl;
    for (int i = 0; i < 3; i++)
      enqueue(q1, (i + 1) * 10);

    cout << "Initializing second queue with size 5 ... \n" << endl;
    Queue *q2 = new Queue;
    initQueue(q2, 5);

    bool empty = isEmpty(q2);
    cout << "Checking if second queue is empty ... \n"
         << "Expected: true\n"
         << "Got     : " << (empty ? "true" : "false") << "\n"
         << endl;

    if (!empty)
      return false;

    const std::string queue2elements = "1 2 3 4 5";

    cout << "Adding elements to second queue ... " << queue2elements << "\n"
         << endl;
    for (int i = 0; i < 5; i++)
      enqueue(q2, i + 1);

    bool full = isFull(q2);
    cout << "Checking if second queue is full ... \n"
         << "Expected: true\n"
         << "Got     : " << (full ? "true" : "false") << "\n"
         << endl;

    if (!full)
      return false;

    int dequeueResult = dequeue(q1);
    cout << "Using dequeue() on first queue and printing element... \n"
         << endl
         << "Expected: 10\n"
         << "Got     : " << dequeueResult << "\n"
         << endl;

    if (dequeueResult != 10)
      return false;

    dequeue(q2);
    dequeue(q2);
    std::string q2output = removeElementsAndGetPrintedQueue(q2);
    cout << "Using dequeue() twice on second queue and printing queue... \n"
         << endl
         << "Expected: 3 4 5\n"
         << "Got     : " << q2output << "\n"
         << endl;

    if (q2output != "3 4 5")
      return false;

    empty = isEmpty(q1);
    cout << "Checking if first queue is empty ... \n"
         << "Expected: false\n"
         << "Got     : " << (empty ? "true" : "false") << "\n"
         << endl;

    if (empty)
      return false;

    cout << "Cleaning first queue...\n" << endl;
    cleanQueue(q1);
    delete q1;

    cout << "Cleaning second queue...\n" << endl;
    cleanQueue(q2);
    delete q2;
  }
  catch (...)
  {
    std::cerr << "Test crashed" << endl;
    return false;
  }

  return true;
}

int main()
{
  bool test1Result = test1();
  bool test2Result = test2();

  if (test1Result && test2Result)
  {
    set_console_color(GREEN);
    std::cout << "\n########## Ex1 Part1 Tests Passed!!! ##########\n" << endl;
    set_console_color(RESET);
  }
  else
  {
    set_console_color(RED);
    std::cout << "\n########## TEST Failed :( ##########\n";
    set_console_color(RESET);
  }

  return 0;
}
