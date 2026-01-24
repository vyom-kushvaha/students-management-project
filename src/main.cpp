#include<iostream>
using namespace std;

int logincall()
  {
    int c;
    cout<<"Welcome to SMS"<<endl;
    cout<<"Menu:\n"<<"1.login"<<"\n"<<"2.exit"<<endl;
    cout<<"choice:";
    cin>>c;

    return c;
   }
int auth()//autheticator function
{
    string username,password;
    cout<<"Enter Username:";
    cin>>username;
    cout<<"Enter Password:";
    cin>>password;

    if(password=="1234")
    {
         if(username=="student123")
            return 1;
        else if(username=="teacher123")
            return 2;
        else if(username=="admin123")
            return 3;
         else 
        return 0;
    }
    else
    {
        cout<<"Passowrd Was Incorrect.Try Again!"<<endl;
        return 0;
    }
}

int  main()
{   
    int choice=logincall();

    switch (choice)
    {
    case 1:
           goto start;
        break;
    case 2:
            goto exit;
    default:
        break;
    }

    start:
        switch(auth())
        {
         case 1:
            cout<<"login succesful";
            goto student;
            break;

        case 2:
            cout<<"login succesful";
            goto teacher;
            break;
        case 3:
            cout<<"login succesful";
            goto admin;
            break;
                
        default:
        {
            cout<<"username and password was incorrect"<<endl;
            cout<<"please Try again"<<endl;
            goto start;
        }
    }
    
    student:
        cout<<"MENU:"<<endl;
        cout<<"1.View Attandance"<<endl;
        cout<<"2.View Marks"<<endl;
        cout<<"3.Logout"<<endl;
        
        goto exit;

    teacher:
        cout<<"MENU:"<<endl;
        cout<<"1.Mark Attendance"<<endl;
        cout<<"2.Enter Marks"<<endl;
        cout<<"3.View Timetable"<<endl;
        cout<<"4.Logout"<<endl;

        goto exit;

    admin:
        cout<<"MENU:"<<endl;
        cout<<"1.Add Student"<<endl;
        cout<<"2.Add Teacher"<<endl;
        cout<<"3.Logout"<<endl;

        goto exit;

    exit:
    return 0;
}
