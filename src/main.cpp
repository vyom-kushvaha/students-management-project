#include<iostream>
#include "log.h"
#include "student.h"
#include<string>
#include "teacher.h"
#include<vector>
#include "admin.h"

using namespace std;



int  main()
{   
    int role;
    vector<student> s;
    student s2(int k,string name2);

    
    int choice= log :: logincall();

   while(choice!=2)
    {
        role=log::auth();
        switch(role)
        {
         case 1:
           { 
            cout<<"login succesful"<<endl;
            student s1(00,"temp");
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
