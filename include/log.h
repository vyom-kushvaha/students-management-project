#ifndef LOG_H
#define LOG_H

#include <string>
#include<utility>
#include <vector>
#include "student.h"

using namespace std;
namespace log {
    int logincall();
    pair<int,string> auth(int &authtrial);
    pair<int,string> check(string username, string password);
    int searchstudent(vector<student>& students);
}

#endif