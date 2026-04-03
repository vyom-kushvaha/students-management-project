#ifndef TEACHER_H
#define TEACHER_H

#include<string>
#include "student.h"
#include <vector>
using namespace std ;

class teacher{
    private:
    int id;
    string name;

    public:
    teacher(int fid,string fname);
    void markAttendance(vector<student>& students);
    void enterMarks(vector<student>& students);
    void tchfunction(vector<student>& students);
    void teachmenu();
};
#endif 