#include<iostream>
#include "teacher.h"

using namespace std;

void teacher ::teachmenu()
    {
        cout<<"1. Mark Attendance"<<endl;
        cout<<"2. Enter Marks"<<endl;
        cout<<"3. Logout"<<endl;
    }
void teacher :: tchfunction()
    {   
        teachmenu();
        int ch;
        cout<<"Enter your choice:"<<endl;
        cin>>ch;
        while(ch!=3)
        {
        switch(ch)
        {
            case 1:
                markAttendance();
                break;
            case 2:
                enterMarks();
                break;
            case 3:
                cout<<"Logging out..."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
        teachmenu();
        cout<<"Enter your choice:"<<endl;   
        cin>>ch;
        }
    }
void teacher ::markAttendance()
    {
        cout<<"Attendance marked successfully."<<endl;
    }
void teacher ::enterMarks()
    {
        cout<<"Marks entered successfully."<<endl;
    }

