#include <iostream>
#include "teacher.h"
#include "student.h"
#include <vector>
#include <fstream>
#include "log.h"

using namespace std;
using namespace log;

teacher::teacher(int fid, string fname)
{
    id = fid;
    name = fname;
}
void teacher ::teachmenu()
{
    cout << "\n=== Teacher Menu ===" << endl;
    cout << "1. Mark Attendance" << endl;
    cout << "2. Enter Marks" << endl;
    cout << "3. Logout" << endl;
}
void teacher::tchfunction(vector<student> &students)
{
    teachmenu();
    int ch;
    cout << "Enter your choice:" << endl;
    cin >> ch;
    while (ch != 3)
    {
        switch (ch)
        {
        case 1:
            markAttendance(students);
            break;
        case 2:
            enterMarks(students);
            break;
        case 3:
            cout << "Logging out..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        teachmenu();
        cout << "Enter your choice:" << endl;
        cin >> ch;
    }
}
void teacher ::markAttendance(vector<student> &students)
{

    char status = '\0';
    int i = searchstudent(students);
    if (i == -1)
    {
        cout << "Try Again" << endl;
    }
    else
    {
        cout << "\n--- Mark Attendance ---" << endl;
        while (status != 'D')
        {
            cout << "P = Present  |  A = Absent : ";
            cin >> status;

            if (status == 'p' || status == 'P')
            {
                students[i].markPresent(students);
                cout << "Marked Present." << endl;
                status = 'D';
            }
            else if (status == 'a' || status == 'A')
            {
                students[i].markAbsent(students);
                cout << "Marked Absent." << endl;
                status = 'D';
            }
            else
            {
                cout << "Invalid input. Try again." << endl;
            }
        }
    }
}
void teacher ::enterMarks(vector<student> &students)
{
    int i = searchstudent(students);
    if (i == -1)
    {
        cout << "Try Again" << endl;
    }
    else
    {
        students[i].enterMarks(students);
    }
}
