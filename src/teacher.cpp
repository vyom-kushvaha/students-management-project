#include<iostream>
#include "teacher.h"
#include "student.h"
#include<vector>
#include<fstream>
#include"log.h"

using namespace std;
using namespace log;

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
       
        char status='\0';
        int i=searchstudent(students);
        while(status != 'D')  
        {  
            cout<<"Write p for present and a for absent"<<endl;
            cin>>status;    

                if(status == 'p' || status == 'P')
                    {
                     students[i].markPresent(students);
                     cout<<"Marked Present"<<endl;
                     status = 'D'; //d for done
                    }
                else if(status == 'a' || status == 'A')
                    {
                     students[i].markAbsent(students);
                     cout<<"Marked Absent"<<endl;
                     status = 'D'; //d for done
                    }
                else
                {

                    cout<<"Invalid Input !\n---TRY AGAIN---"<<endl;
                }
        }

    }
void teacher ::enterMarks(vector<student>& students)
    {
        int i=searchstudent(students);
        students[i].enterMarks(students);
    }

