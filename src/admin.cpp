#include<iostream>
#include "admin.h"
#include<string>
#include<vector>
#include "student.h"

using namespace std ;

void admin :: adminmenu() {
    cout << "1. Add Student" << endl;
    cout << "2. Remove Student" << endl;
    cout << "3. Add Teacher" << endl;
    cout << "4. Logout" << endl;
}       
void admin::adminfunctions() {
    adminmenu();
    int ch;
    cout << "Enter your choice:" << endl;
    cin >> ch;
    while (ch != 4) {
        switch (ch) {
            case 1:
                addstudent();
                break;
            case 2:
                removestudent();
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
        cout<<"Enter your choice:" << endl;
        cin>>ch;
    }
}
void admin::addstudent() {
    cout << "Adding a new student..." << endl;
    students.push_back(student());
    cout << "Student added successfully." << endl;  
}
