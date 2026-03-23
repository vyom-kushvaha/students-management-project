#ifndef ADMIN_H
#define ADMIN_H

#include "student.h"
#include<string>
#include<vector>
using namespace std ;

class admin{
    private:
    

    public:
    void adminmenu();
    void adminfunctions(student s[]);
    void addstudent(student s[]);
    void removestudent(student s[]);
    void addteacher();
    
};

#endif 