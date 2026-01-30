#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using namespace std ;

class student{
    private:
    string name;
    int id=0,marks=0,ac=0,tc=0;

    public:
    void viewdet();
    void viewmarks();
    void viewattd();
    void stufunctions();
    void stumenu();
    void markPresent();
    void markAbsent();
    int getid();

    student();

};

#endif 