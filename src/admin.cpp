#include <iostream>
#include <algorithm>
#include "admin.h"
#include <string>
#include <limits>
#include "student.h"
#include <vector>
#include "log.h"
#include <fstream>
#include "loader.h"
using namespace std;
using namespace log;

admin::admin(int fid, string fname)
{
    id = fid;
    name = fname;
}
void admin::adminmenu()
{
    cout << "\n=== Admin Menu ===" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Remove Student" << endl;
    cout << "3. View Student Details" << endl;
    cout << "4. Update Student" << endl;
    cout << "5. Logout" << endl;
}

void admin::adminfunctions(vector<student> &students)
{
    adminmenu();
    int ch;

    cout << "Enter your choice:" << endl;
    cin >> ch;
    while (ch != 5)
    {
        switch (ch)
        {
        case 1:
            addstudent(students);
            break;
        case 2:
            removestudent(students);
            break;
        case 3:
            viewstudent(students);
            break;
        case 4:
            updatestudent(students);
            break;
        case 5:
            cout << "Logging out..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        adminmenu();
        cout << "Enter your choice:" << endl;
        cin >> ch;
    }
}

void admin::addstudent(vector<student> &students)
{
    int k = students.size();
    int eid, eac = 0, etc = 0, emarks = 0;
    string ename, euser, epass;

    cout << "\n--- Add Student ---" << endl;
    cout << "Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, ename);
    cout << "ID: ";
    cin >> eid;
    cout << "Username: ";
    cin >> euser;
    cout << "Password: ";
    cin >> epass;
    int i;
    students.push_back(student(k, eid, ename, eac, etc, emarks));
    ofstream fwrite("data/students.txt");
    int n = students.size();
    if (fwrite.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            int id = students[i].getid();
            int ac = students[i].getac();
            int tc = students[i].gettc();
            int marks = students[i].getmarks();
            string name = students[i].getname();

            fwrite << i << "," << id << "," << name << "," << ac << "," << tc << "," << marks << "\n";
        }

        fwrite.close();
    }

    // write to stupass.txt
    ofstream passwrite("data/stupass.txt", ios::app);
    if (passwrite.is_open())
    {
        passwrite << "\n"
                  << k << "," << euser << "," << epass << ",student\n";
        passwrite.close();
    }
}
void admin::removestudent(vector<student> &students)
{
    int index = searchstudent(students);
    if (index == -1)
    {
        cout << "Try Again" << endl;
    }
    else
    {
        students.erase(students.begin() + index);

        int n = students.size();

        ofstream fwrite("data/students.txt");

        if (fwrite.is_open())
        {
            for (int i = 0; i < n; i++)
            {
                int id = students[i].getid();
                int ac = students[i].getac();
                int tc = students[i].gettc();
                int marks = students[i].getmarks();
                string name = students[i].getname();

                fwrite << i << "," << id << "," << name << "," << ac << "," << tc << "," << marks << "\n";
            }

            fwrite.close();
        }

        // Rewrite stupass.txt to update indexes and delete credentials
        ifstream fread("data/stupass.txt");
        vector<string> passLines;
        string pline;
        while (getline(fread, pline))
        {
            string fusername = "";
            string fpassword = "";
            string fcatagorie = "";
            string sid = "";
            int pos = 0;

            // id extract
            while (pos < pline.size() && pline[pos] != ',')
            {
                sid += pline[pos];
                pos++;
            }
            int fidx = stoi(sid);
            pos++;

            // username extract
            while (pos < pline.size() && pline[pos] != ',')
            {
                fusername += pline[pos];
                pos++;
            }
            pos++;

            // password extract
            while (pos < pline.size() && pline[pos] != ',')
            {
                fpassword += pline[pos];
                pos++;
            }
            pos++;

            // category extract
            while (pos < pline.size() && pline[pos] != '\n' && pline[pos] != '\0')
            {
                fcatagorie += pline[pos];
                pos++;
            }

            if (fcatagorie == "student")
            {
                if (fidx == index)
                {
                    continue; // discard deleted student
                }
                else if (fidx > index)
                {
                    fidx--; // shift index downwards
                }
            }

            // format properly
            string newLine = to_string(fidx) + "," + fusername + "," + fpassword + "," + fcatagorie;
            passLines.push_back(newLine);
        }
        fread.close();

        ofstream fpwrite("data/stupass.txt");
        if (fpwrite.is_open())
        {
            for (int j = 0; j < passLines.size(); j++)
            {
                fpwrite << passLines[j] << "\n";
            }
            fpwrite.close();
        }

        students.clear();
        loader ::loadstudents(students);
    }
}
void admin::viewstudent(vector<student> &students)
{
    int i = searchstudent(students);
    if (i == -1)
    {
        cout << "Try Again" << endl;
    }
    else
    {
        students[i].viewdet();
        students[i].viewmarks();
        students[i].viewattd();
    }
}

void admin::updatestudent(vector<student> &students)
{
    int i = searchstudent(students);
    if (i == -1)
    {
        cout << "Try Again" << endl;
        return;
    }

    int ch;
    cout << "\n1. Update Name" << endl;
    cout << "2. Update Marks" << endl;
    cout << "Choice: ";
    cin >> ch;

    if (ch == 1)
    {
        string newname;
        cin.ignore();
        cout << "Enter New Name: ";
        getline(cin, newname);
        students[i].setname(newname);
    }
    else if (ch == 2)
    {
        int newmarks;
        cout << "Enter New Marks: ";
        cin >> newmarks;
        students[i].setmarks(newmarks);
    }
    else
    {
        cout << "Invalid choice" << endl;
        return;
    }

    int n = students.size();
    ofstream fwrite("data/students.txt");
    if (fwrite.is_open())
    {
        for (int j = 0; j < n; j++)
        {
            fwrite << j << "," << students[j].getid() << "," << students[j].getname() << "," << students[j].getac() << "," << students[j].gettc() << "," << students[j].getmarks() << "\n";
        }
        fwrite.close();
        cout << "Updated successfully" << endl;
    }
}