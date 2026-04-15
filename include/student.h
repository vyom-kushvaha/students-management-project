#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;

class student
{
private:
    string name;
    int index = 0, id = 0, marks = 0, ac = 0, tc = 0;

public:
    void viewdet();
    void viewmarks();
    void viewattd();
    void stufunctions();
    void stumenu();
    void markPresent(vector<student> &students);
    void markAbsent(vector<student> &students);
    void enterMarks(vector<student> &students);
    inline int getid();
    inline int getac();
    inline int gettc();
    inline int getmarks();
    inline string getname();
    inline void setname(string newname);
    inline void setmarks(int newmarks);

    student(int id, string name);
    student();
    student(int findex, int fid, string fname, int fac, int ftc, int marks);
};

#endif