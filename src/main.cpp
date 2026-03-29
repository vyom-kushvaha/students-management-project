#include <iostream>
#include "log.h"
#include "student.h"
#include <string>
#include "teacher.h"
#include <vector>
#include "admin.h"
#include <utility>
#include "loader.h"
using namespace std;

int main()
{
    vector<student> students;
    loader ::loadstudents(students);
    vector<teacher> teachers;
    loader::loadteachers(teachers);
    vector<admin> admins;
    loader::loadadmins(admins);
    int authtrial = 0;
    int role;
    int id;

    int choice = log ::logincall();

    while (choice != 2)
    {
        auto result = log::auth(authtrial);
        role = result.first;
        if (role != 0)
        {
            id = stoi(result.second);
        }
        switch (role)
        {

        case 1:
        {
            cout << "login succesful" << endl;
            students[id].stufunctions();
        }
        break;

        case 2:
        {
            cout << "login succesful" << endl;
            teachers[id].tchfunction(students);
        }
        break;
        case 3:
        {
            cout << "login succesful";
            admins[id].adminfunctions(students);
        }

        break;

        default:
        {
            cout << "username and password was incorrect" << endl;
            cout << "please Try again" << endl;
        }
        break;
        }
        choice = log ::logincall();
    }

    return 0;
}

// shortcut to run g++ main.cpp student.cpp teacher.cpp admin.cpp log.cpp loader.cpp -o app
//  .\app
