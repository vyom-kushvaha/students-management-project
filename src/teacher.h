#ifndef TEACHER_H
#define TEACHER_H

#include<string>
#include "student.h"
#include <vector>
using namespace std ;

class teacher{
    private:
    
    public:
    void markAttendance(vector<student>& students);
    void enterMarks();
    void tchfunction(vector<student> s);
    void teachmenu();
};
#endif 