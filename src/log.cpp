#include<iostream>
#include "log.h"
#include<string>
#include<fstream>
#include<sstream>
#include<utility>

using namespace std;
namespace log
{
    pair<int,string> auth()//autheticator function
    {
        string username;
        string password;
        cout<<"Enter Username:";
        cin>>username;
        cout<<"Enter Password:";
        cin>>password;

        auto result = check(username, password);
        int role = result.first;
        string id = result.second;
        if(role == 0){
            cout<<"Invalid credentials. Try again."<<endl;
            return auth();
        }
        return {role,id};
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

    pair<int, string> check(string username, string password)
    {
        ifstream fread("stupass.txt");
            string name;
            while (getline(fread, name)) 
            {     // line by line read
                  string fusername;
                  string fpassword;
                  string fcatagorie;
                  string id;
                  int role;
                  int i = 0, j = 0, k = 0, n=0;
                
                  // id extract
                while (name[i] != ',') 
                 {
                     id += name[i];
                     i++;
                     n++;
                 }
                 id[n] = '\0';
                 i++;

                 // username extract
                 while (name[i] != ',') 
                 {
                     fusername += name[i];
                     i++;
                 }
                 fusername[i] = '\0';
                 i++;
                 
                 // password extract
                 while (name[i] != ',') 
                 {
                     fpassword  += name[i];
                     i++;
                     j++;
                 }
                 fpassword[j] = '\0';
                 i++;
                 
                 // category extract
                 while (name[i] != '\n' && name[i] != '\0')
                  {
                     fcatagorie += name[i];
                     i++;
                     k++;
                 }
                 fcatagorie[k] = '\0';
                 
                 // comparison
                 if (username == fusername) 
                 {
                     cout << "username found" << endl;
                 
                     if (password == fpassword)
                      {
                         cout << "password is correct" << endl;
                         
                         if(fcatagorie=="student")
                            role=1;
                        else if(fcatagorie=="teacher")
                            role=2;
                        else
                            role=3;
                     } else {
                         cout << "password is incorrect";
                     }
                 
                 }
                 else
                 {
                     cout << "username does not found";
                 }      

                 if (username == fusername && password == fpassword)
                 {
                    return {role,id};
                }
            }       
    }
    

}