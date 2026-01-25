#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using namespace std ;

class student{
    private:
    string name;
    int id,marks,ac,tc;

    public:
    void viewdet();
    void viewmarks();
    void viewattd();
    void stufunctions();
    void stumenu();

};

#endif 