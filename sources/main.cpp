#include <iostream>
#include "sample.h"
#include "stacktraceDump.h"

int main(const int, const char**) {
    registerStackTraceDump();

    std::cout << "App running..." << std::endl;
    std::cout << message << std::endl;

    return 0;
}
