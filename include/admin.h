#ifndef ADMIN_H
#define ADMIN_H

#include "student.h"
#include <string>
#include <vector>
using namespace std;

class admin
{
private:
    int id;
    string name;

public:
    admin(int fid, string fname);
    void adminmenu();
    void adminfunctions(vector<student> &students);
    void addstudent(vector<student> &students);
    void removestudent(vector<student> &students);
    void viewstudent(vector<student> &students);
    void updatestudent(vector<student> &students);
};

#endif