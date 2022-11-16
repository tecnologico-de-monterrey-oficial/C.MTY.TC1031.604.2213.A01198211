#include "Stack.h"
#include <__nullptr>
#include <iostream>

int main() {
  Stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);
  stack.push(6);
  std::cout << stack.getTop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.getTop() << std::endl;
  return 0;
}
