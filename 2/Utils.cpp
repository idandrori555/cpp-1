#include "Stack.h"

#define DEBUG 0

void reverse(int *nums, unsigned size)
{
  Stack *s = new Stack;
  initStack(s);

  size_t i = 0;
  for (i = 0; i < size; i++)
  {
    push(s, nums[i]);
  }

  for (i = 0; i < size; i++)
  {
    nums[i] = pop(s);
  }

  cleanStack(s);
  delete s;
}

int *reverse10()
{
  const constexpr int ARR_SIZE = 10;
  int *arr = new int[ARR_SIZE];

  unsigned i = 0;
  for (i = 0; i < ARR_SIZE; i++)
  {
    std::cout << "Enter number " << i + 1 << ": ";
    std::cin >> arr[i];
  }

  for (i = 0; i < ARR_SIZE; i++)
  {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}

#if DEBUG == 1
#include <iostream>

int main(void)
{
  // int nums[] = {1, 2, 3, 4, 5, 6};
  // unsigned len = sizeof(nums) / sizeof(nums[0]);
  // reverse(nums, len);
  //
  // for (unsigned i = 0; i < len; i++)
  // {
  //   std::cout << nums[i] << ' ';
  // }
  // std::cout << '\n';

  reverse10();
  return 0;
}
#endif
