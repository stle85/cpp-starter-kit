#include <iostream>
#include "sample.h"

void do_something() {
  std::cout << "doing something" << std::endl;
  std::cout << message << std::endl;
}

int main(const int, const char**) {
  do_something();

  return 0;
}
