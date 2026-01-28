#include<iostream>
#include "teacher.h"
#include "student.h"
#include<vector>

using namespace std;

void teacher ::teachmenu()
    {
        cout<<"1. Mark Attendance"<<endl;
        cout<<"2. Enter Marks"<<endl;
        cout<<"3. Logout"<<endl;
    }
void teacher :: tchfunction(vector<student>& students)
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
                markAttendance(students);
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
void teacher ::markAttendance(vector<student>& students)
    {
        cout<<"Write p for present and a for absent"<<endl;
        for(int i=0;i<students.size();i++)
        {
            cout<<"Mark attendance for student ID "<<students[i].getid()<<": ";
            char status;
            cin>>status;    

            if(status == 'p' || status == 'P')
                students[i].markPresent();
            else if(status == 'a' || status == 'A')
                students[i].markAbsent();
            else
            {
                --i; // Repeat for the same student
                cout<<"Invalid input for student ID "<<students[i].getid()<<". Skipping..."<<endl;
            }

        }
        cout<<"Attendance marked successfully."<<endl;
    }
void teacher ::enterMarks()
    {
        cout<<"Marks entered successfully."<<endl;
    }

