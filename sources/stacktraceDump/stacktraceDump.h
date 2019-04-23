#pragma once
#include <string>

/**
 * @brief Stacktrace dump helper class.
 *
 * Provide an easy way to save dump when the program fails.
 */
class StacktraceDump {
   public:
    /**
     * @brief Register dump creation on failure.     *
     */
    static const void reg(const std::string &dumpFilePath);

   private:
    StacktraceDump() = delete;
    StacktraceDump(const StacktraceDump &) = delete;
    StacktraceDump(StacktraceDump &&) = delete;
    StacktraceDump &operator=(const StacktraceDump &) = delete;
    StacktraceDump &operator=(StacktraceDump &&) = delete;

    static void signalHandler(const int);

   private:
    static std::string path;
};
