#include<iostream>
#include "log.h"
#include "student.h"
#include<string>
#include "teacher.h"
#include<vector>
#include "admin.h"
#include<utility>

using namespace std;



int  main()
{   
    int role;
    int id;
    vector<student> s;
    int choice = log :: logincall();

    while (choice != 2)
    {
        role=log::auth().first;
        id=stoi(log::auth().second);
        switch(role)
        {
         case 1:
           { 
               student s1(00,"temp");
               cout<<"login succesful"<<endl;
              s1.stufunctions();
              
           }
            break;

        case 2:
            {
            cout<<"login succesful"<<endl;
            teacher t;
            t.tchfunction(s);
          }
            break;
        case 3:
            {
            cout<<"login succesful";
            admin a;
            a.adminfunctions(s);
            }
        
            break;
                
        default:
             {
            cout<<"username and password was incorrect"<<endl;
            cout<<"please Try again"<<endl;
             }
             break;
        }
        choice= log :: logincall();    
    }

        
    return 0;
}



