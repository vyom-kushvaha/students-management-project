#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<vector>
using namespace std ;

class student{
    private:
    string name;
    int index=0,id=0,marks=0,ac=0,tc=0;

    public:
    void viewdet();
    void viewmarks();
    void viewattd();
    void stufunctions();
    void stumenu();
    void markPresent(vector<student>& students);
    void markAbsent(vector<student>& students);
    void enterMarks(vector<student>& students);
    int getid();
    int getac();
    int gettc();
    int getmarks();
    string getname();
    void setname(string newname);
    void setmarks(int newmarks);


    student(int id, string name);
    student();
    student(int findex, int fid,string fname,int fac,int ftc,int marks);

};

#endif 