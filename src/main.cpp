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
    vector<student> students;
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
            t.tchfunction(students);
          }
            break;
        case 3:
            {
            cout<<"login succesful";
            admin a;
            a.adminfunctions(students);
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

//shortcut to run g++ main.cpp student.cpp teacher.cpp admin.cpp log.cpp -o app
// .\app
