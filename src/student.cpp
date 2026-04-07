#include<iostream>
#include<vector>
#include "student.h"
#include<string>
#include<fstream>

using namespace std;
student::student(int findex, int fid,string fname,int fac,int ftc,int fmarks)
{
    index=findex;
    id=fid;
    name=fname;
    ac=fac;
    tc=ftc;
    marks=fmarks;

}
student::student(int i,string tempname)
{
    id=i;
    name= tempname;
}
student::student()
{
    id=0;
    name="null";
}
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
        cout<<"ID: "<<id<<"   "<<"NAME:"<<name<<endl;
    }
    void student :: viewattd()
    {
        cout<<"YOUR ATTENDANCE:"<<ac<<"/"<<tc<<endl;
    }
    void student::markPresent(vector<student>& students)
    {
        int i,n;
        n = students.size();
        ac++;
        tc++;
         ofstream  fwrite("students.txt");
        
            if (fwrite.is_open()) 
            {
                for(i=0;i<n;i++)
            {
                fwrite << students[i].index<<","<<students[i].id<<","<<students[i].name<<","<<students[i].ac<<","<<students[i].tc<<","<<students[i].marks<<"\n";
            }

              fwrite.close();
            }
    

    }

    void student::markAbsent(vector<student>& students)
    {
        tc++;
        int i;
        int n = students.size();
        ofstream  fwrite("students.txt");
        
            if (fwrite.is_open()) 
            {
                for(i=0;i<n;i++)
            {
                fwrite << students[i].index<<","<<students[i].id<<","<<students[i].name<<","<<students[i].ac<<","<<students[i].tc<<","<<students[i].marks<<"\n";
            }

              fwrite.close();
            }
        
    }
    void student::enterMarks(vector<student>& students)
    {
        int m;
        cout<<"Enter Marks:";
        cin>>m;
        marks = m;
        int i;
        int n = students.size();
        ofstream  fwrite("students.txt");
        
            if (fwrite.is_open()) 
            {
                for(i=0;i<n;i++)
            {
                fwrite << students[i].index<<","<<students[i].id<<","<<students[i].name<<","<<students[i].ac<<","<<students[i].tc<<","<<students[i].marks<<"\n";
            }

              fwrite.close();
            }
        
    }
   
int student::getid()
{
    
    return id;
}
int student::getac()
{
    return ac;
}
int student::getmarks()
{
    return marks;
}
int student::gettc()
{
    return tc;
}
string student::getname()
{
    return name;
}