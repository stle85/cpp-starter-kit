#include <iostream>
#include "sample.h"
#include "stacktraceDump.h"

int main(const int, const char**) {
    StacktraceDump::reg("stacktrace.dump");

    std::cout << "App running..." << std::endl;
    std::cout << message << std::endl;

    return 0;
}
