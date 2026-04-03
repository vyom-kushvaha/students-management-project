#include<iostream>
#include "teacher.h"
#include "student.h"
#include<vector>
#include<fstream>

using namespace std;

teacher::teacher(int fid,string fname)
{
    id=fid;
    name=fname;
}
void teacher ::teachmenu()
    {
        cout<<"1. Mark Attendance"<<endl;
        cout<<"2. Enter Marks"<<endl;
        cout<<"3. Logout"<<endl;
    }
void teacher::tchfunction(vector<student>& students)
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
                enterMarks(students);
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
        int i=0;
        char status;
        cout<<"Enter ID Of Student For Attendance:";
        cin>>i;
        cout<<"Write p for present and a for absent"<<endl;
        cin>>status;    

            if(status == 'p' || status == 'P')
                {
                 students[i].markPresent(students);
                 cout<<"Marked Present";
                }
            else if(status == 'a' || status == 'A')
                {
                 students[i].markAbsent(students);
                 cout<<"Marked Absent";
                }
            else
            {
                
                cout<<"Invalid Input !\n---TRY AGAIN---"<<endl;
            }
            
    }
void teacher ::enterMarks(vector<student>& students)
    {
        int i;
        cout<<"Enter ID Of Student To Enter Marks:";
        cin>>i;
        students[i].enterMarks(students);
    }

