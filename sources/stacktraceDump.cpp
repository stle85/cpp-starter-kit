#include "stacktraceDump.h"
#include <signal.h>
#include <boost/filesystem.hpp>
#include <boost/stacktrace.hpp>
#include <fstream>
#include <iostream>

static const char traceDumpPath[] = "./trace.dump";

/**
 * Signal handler.
 */
static void signalHandler(const int signum) {
    ::signal(signum, SIG_DFL);
    boost::stacktrace::safe_dump_to(traceDumpPath);
    ::raise(SIGABRT);
}

/**
 *
 */
void registerStackTraceDump() {
    ::signal(SIGSEGV, &signalHandler);
    ::signal(SIGABRT, &signalHandler);

    if (boost::filesystem::exists(traceDumpPath)) {
        std::ifstream ifs(traceDumpPath);

        const auto st = boost::stacktrace::stacktrace::from_dump(ifs);
        std::cout << "Previous run crashed:\n" << st << std::endl;

        ifs.close();
        boost::filesystem::remove(traceDumpPath);
    }
}
