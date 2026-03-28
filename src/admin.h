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
    void adminfunctions(vector<student>& students);
    void addstudent(vector<student>& students);
    void removestudent(vector<student>& students);
    void addteacher();
    
};

#endif 