#include<iostream>
#include "log.h"
#include "student.h"
#include<string>
#include "teacher.h"
using namespace std;




int  main()
{   
    int choice= log :: logincall();

   while(choice!=2)
    {
        switch(log::auth())
        {
         case 1:
           { 
            cout<<"login succesful"<<endl;
            student s;
            s.stufunctions();
           }
            break;

        case 2:
            {
            cout<<"login succesful"<<endl;
            teacher t;
            t.tchfunction();
          }
            break;
        case 3:
            {
            cout<<"login succesful";
           // void adminmenu();
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
