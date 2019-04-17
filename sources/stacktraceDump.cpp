#include "stacktraceDump.h"
#include <signal.h>
#include <boost/filesystem.hpp>
#include <boost/stacktrace.hpp>

std::string StacktraceDump::path;

const void StacktraceDump::reg(const std::string &dumpFilePath) {
    StacktraceDump::path = dumpFilePath;

    ::signal(SIGSEGV, &StacktraceDump::signalHandler);
    ::signal(SIGABRT, &StacktraceDump::signalHandler);

    if (boost::filesystem::exists(dumpFilePath)) {
        boost::filesystem::remove(dumpFilePath);
    }
}

void StacktraceDump::signalHandler(const int signalNumber) {
    ::signal(signalNumber, SIG_DFL);
    boost::stacktrace::safe_dump_to(StacktraceDump::path.c_str());
    ::raise(SIGABRT);
}