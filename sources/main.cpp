#include <cereal/archives/json.hpp>
#include <iostream>
#include "models/group/group.h"
#include "models/user/user.h"
#include "stacktraceDump/stacktraceDump.h"

int main(const int, const char**) {
    StacktraceDump::reg("stacktrace.dump");
    std::cout << "App running..." << std::endl;

    const Group group{1, "name"};
    const User user{1, "firstName", "lastName"};

    cereal::JSONOutputArchive archive(std::cout);
    archive(group, user);

    return 0;
}
