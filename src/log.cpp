#include<iostream>
#include "log.h"
#include<string>
using namespace std;
namespace log
{
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
    int logincall()
    {
    int c;
    cout<<"Welcome to SMS"<<endl;
    cout<<"Menu:\n"<<"1.login"<<"\n"<<"2.exit"<<endl;
    cout<<"choice:";
    cin>>c;
    if(c!=1 && c!=2)
    {
        cout<<"Invalid choice.Try again!"<<endl;
        logincall();
    }
    return c;
   }

}