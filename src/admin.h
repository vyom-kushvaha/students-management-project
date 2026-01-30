#ifndef ADMIN_H
#define ADMIN_H

#include<string>
#include<vector>
using namespace std ;

class admin{
    private:
    

    public:
    void adminmenu();
    void adminfunctions(vector<student>& s);
    void addstudent(vector<student>& s);
    void removestudent(vector<student>& s);
    void addteacher();
    
};

#endif 