#include<iostream>
#include <algorithm>
#include "admin.h"
#include<string>
#include "student.h"
#include <vector>

using namespace std;

void admin::adminmenu()
{
    cout << "1. Add Student" << endl;
    cout << "2. Remove Student" << endl;
    cout << "3. Add Teacher" << endl;
    cout << "4. Logout" << endl;
}

void admin::adminfunctions(vector<student>& students)
{
    adminmenu();
    int ch;
    cout << "Enter your choice:" << endl;
    cin >> ch;
    while (ch != 4)
    {
        switch (ch)
        {
            case 1:
                addstudent(students);
                break;
            case 2:
                removestudent(students);
                break;
            case 3:
                addteacher();
                break;
            case 4:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        adminmenu();
        cout << "Enter your choice:" << endl;
        cin >> ch;
    }
}



   