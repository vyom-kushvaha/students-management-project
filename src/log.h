#ifndef LOG_H
#define LOG_H

#include <string>

namespace log {
    int logincall();
    int auth();
    int check(std::string username, int password);
}

#endif