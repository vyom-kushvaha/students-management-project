#include<iostream>
#include "log.h"
#include<string>
#include<fstream>
#include<sstream>

using namespace std;
namespace log
{
    int auth()//autheticator function
    {
        string username;
        int password;
        cout<<"Enter Username:";
        cin>>username;
        cout<<"Enter Password:";
        cin>>password;

        int role = check(username, password);
        if(role == 0){
            cout<<"Invalid credentials. Try again."<<endl;
            return auth();
        }
        return role;
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

    int check(string username, int password)
    {
        ifstream fread("stupass.txt");
        string line;
        while (getline(fread, line)) {   // line by line read
            string fusername;
            int fpassword;
            string fcatagorie;

            stringstream ss(line);      // line ko todne ke liye

            ss >> fusername >> fpassword >> fcatagorie;   
            
            if(username==fusername && password==fpassword)        
            {
                if(fcatagorie=="student")
                    return 1;
                else if(fcatagorie=="teacher")
                    return 2;
                else if(fcatagorie=="admin")
                    return 3;
            }
            
        }
        return 0;
    }

}