#include<iostream>
#include "student.h"

using namespace std;

void student :: stumenu()
    {
        cout<<"1. View Attendance"<<endl;
        cout<<"2. View Marks"<<endl;
        cout<<"3. View Details"<<endl;
        cout<<"4. Logout"<<endl;
    }
void student :: stufunctions()
    {   
        int ch;
        stumenu();
        cout<<"Enter your choice:"<<endl;
        cin>>ch;
        while(ch!=4)
        {
        switch(ch)
        {
            case 1:
                viewattd();
                break;
            case 2:
                viewmarks();
                break;
            case 3:
                viewdet();
                break;
            case 4:
                cout<<"Logging out..."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
        stumenu();
        cout<<"Enter your choice:"<<endl;
        cin>>ch;
        }
    }
    void student ::viewmarks()
    {
        cout<<"MARKS:"<<marks<<"%"<<endl;
    }
    void student :: viewdet()
    {
        cout<<"ID: "<<id<<"NAME:"<<name<<endl;
    }
    void student :: viewattd()
    {
        cout<<"YOUR ATTENDANCE:"<<ac<<"/"<<tc<<endl;
    }
    void student::markPresent()
    {
        ac++;
        tc++;
    }

    void student::markAbsent()
    {
        tc++;
    }
    int student::getid()
    {
        return id;
    }

