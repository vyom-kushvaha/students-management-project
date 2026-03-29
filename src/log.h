#ifndef LOG_H
#define LOG_H

#include <string>
#include<utility>

using namespace std;
namespace log {
    int logincall();
    pair<int,string> auth(int &authtrial);
    pair<int,string> check(string username, string password);
}

#endif