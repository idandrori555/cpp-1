#include "Stack.h"
#include "Utils.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

// ANSI escape color codes for Linux
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BRIGHT_RED "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN "\033[96m"
#define BRIGHT_WHITE "\033[97m"

// Replacement for Windows SetConsoleTextAttribute
void set_console_color(unsigned int color)
{
  // map numeric color codes (from original code) to ANSI sequences
  switch (color)
  {
  case 2:
    cout << GREEN;
    break; // GREEN
  case 4:
    cout << RED;
    break; // DARK_RED
  case 5:
    cout << PURPLE;
    break; // PURPLE
  case 6:
    cout << YELLOW;
    break; // YELLOW
  case 9:
    cout << BRIGHT_BLUE;
    break; // LIGHT_BLUE
  case 10:
    cout << BRIGHT_GREEN;
    break; // LIGHT_GREEN
  case 11:
    cout << CYAN;
    break; // TEAL
  case 12:
    cout << BRIGHT_RED;
    break; // RED
  case 13:
    cout << BRIGHT_MAGENTA;
    break; // PURPLE (duplicate)
  case 14:
    cout << BRIGHT_YELLOW;
    break; // LIGHT_YELLOW
  case 15:
    cout << WHITE;
    break; // WHITE
  default:
    cout << RESET;
    break;
  }
}

std::string popElementsAndGetPrintedStack(Stack *s)
{
  std::stringstream output;
  while (!isEmpty(s))
  {
    output << pop(s) << " ";
  }
  std::string outputString = output.str();
  outputString = outputString.substr(0, outputString.length() - 1);
  return outputString;
}

bool test1()
{
  set_console_color(14); // LIGHT_YELLOW
  cout << "*******************************\n"
       << "Test 1 - basic stack functions\n"
       << "*******************************\n"
       << endl;
  set_console_color(15); // WHITE

  cout << "Initializing new stack ... \n" << endl;
  Stack *s0 = new Stack;
  initStack(s0);

  bool empty = isEmpty(s0);
  cout << "Checking if stack is empty ... \n"
       << "Expected: true\n"
       << "Got     : " << (empty ? "true" : "false") << "\n"
       << endl;

  if (!empty)
    return false;

  const std::string stack0elements = "11 22 33 44 55";

  cout << "Pushing elements to stack ... " << stack0elements << "\n" << endl;
  for (int i = 0; i < 5; i++)
  {
    push(s0, (i + 1) * 11);
  }

  std::string output = popElementsAndGetPrintedStack(s0);
  const std::string expected = "55 44 33 22 11";

  cout << "Popping and printing each element in stack ...\n"
       << "Expected: " << expected << "\n"
       << "Got     : " << output << "\n"
       << endl;

  if (output != expected)
    return false;

  cout << "Cleaning stack...\n" << endl;
  cleanStack(s0);
  delete s0;
  return true;
}

bool test2()
{
  set_console_color(14);
  cout << "*******************************\n"
       << "Test 2 - More Stack tests\n"
       << "*******************************\n"
       << endl;
  set_console_color(15);

  cout << "Initializing new stack ... \n" << endl;
  Stack *s0 = new Stack;
  initStack(s0);

  bool empty = isEmpty(s0);
  cout << "Checking if stack is empty ... \n"
       << "Expected: true\n"
       << "Got     : " << (empty ? "true" : "false") << "\n"
       << endl;

  if (!empty)
    return false;

  cout << "Pushing 100,000 elements to stack ... \n" << endl;
  for (int i = 0; i < 100000; i++)
    push(s0, i);

  cout << "Popping 10,000 elements from stack ... \n" << endl;
  for (int i = 0; i < 10000; i++)
    pop(s0);

  empty = isEmpty(s0);
  cout << "Checking if stack is empty ... \n"
       << "Expected: false\n"
       << "Got     : " << (empty ? "true" : "false") << "\n"
       << endl;

  if (empty)
    return false;

  cout << "Pop 90,000 elements from stack ... \n" << endl;
  for (int i = 0; i < 90000; i++)
    pop(s0);

  empty = isEmpty(s0);
  cout << "Checking if stack is empty ... \n"
       << "Expected: true\n"
       << "Got     : " << (empty ? "true" : "false") << "\n"
       << endl;

  if (!empty)
    return false;

  cout << "Cleaning stack...\n" << endl;
  cleanStack(s0);
  delete s0;
  return true;
}

std::string arrayToString(int numbers[], int size)
{
  std::stringstream output;
  for (int i = 0; i < size; i++)
    output << numbers[i] << " ";
  std::string outputString = output.str();
  return outputString.substr(0, outputString.length() - 1);
}

bool test3()
{
  set_console_color(14);
  cout << "*******************************\n"
       << "Test 3 - utils\n"
       << "*******************************\n"
       << endl;
  set_console_color(15);

  cout << "Creating array ... [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]\n" << endl;
  int numbers[10];
  for (int i = 0; i < 10; i++)
    numbers[i] = (i + 1) * 2;

  reverse(numbers, 10);
  std::string expected = "20 18 16 14 12 10 8 6 4 2";
  std::string result = arrayToString(numbers, 10);
  cout << "Using reverse() on array and printing it... \n"
       << "Expected: " << expected << "\n"
       << "Got     : " << result << "\n"
       << endl;

  return result == expected;
}

void printGreatJob()
{
  cout << "  _____             __       __     __  \n"
          " / ___/______ ___ _/ /_  __ / /__  / /  \n"
          "/ (_ / __/ -_) _ `/ __/ / // / _ \\/ _ \\ \n"
          "\\___/_/  \\__/\\_,_/\\__/  \\___/\\___/_.__/ \n"
          "\n\t\t\tYou are amazing!!!\n";
}

int main()
{
  bool t1 = test1();
  bool t2 = test2();
  bool t3 = test3();

  if (t1 && t2 && t3)
  {
    set_console_color(2); // GREEN
    cout << "\n########## Ex1 Part3 Tests Passed!!! ##########\n" << endl;
    printGreatJob();
  }
  else
  {
    set_console_color(12); // RED
    cout << "\n########## TEST Failed :( ##########\n";
  }

  set_console_color(15); // WHITE (reset)
  cout << RESET;
  return 0;
}
