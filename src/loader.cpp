#include<iostream>
#include "loader.h"
#include<fstream>
#include<string>

using namespace std;

 namespace loader
 {

  void loadstudents(vector<student>& students)
{
    ifstream fread("data/students.txt");
    string line;

    while (getline(fread, line)) 
    {
        string fname;
        int findex=0, fid = 0, fac = 0, ftc = 0, fmarks = 0;

        string tempindex, tempid, tempfac, tempftc, tempmarks;

        int i = 0;
        // index
        while (i < line.size() && line[i] != ',') {
            tempindex += line[i];
            i++;
        }
        findex = stoi(tempindex);
        i++;

        // id
        while (i < line.size() && line[i] != ',') {
            tempid += line[i];
            i++;
        }
        fid = stoi(tempid);
        i++;

        // name
        while (i < line.size() && line[i] != ',') {
            fname += line[i];
            i++;
        }
        i++;

        // fac
        while (i < line.size() && line[i] != ',') {
            tempfac += line[i];
            i++;
        }
        fac = stoi(tempfac);
        i++;

        // ftc
        while (i < line.size() && line[i] != ',') {
            tempftc += line[i];
            i++;
        }
        ftc = stoi(tempftc);
        i++;

        // marks (last field)
        while (i < line.size()) {
            tempmarks += line[i];
            i++;
        }
        fmarks = stoi(tempmarks);

        // pushback
        student s(findex, fid, fname, fac, ftc, fmarks);
        students.push_back(s);
    }
}

      void loadteachers(vector<teacher>& teachers)
{
    ifstream fread("data/teachers.txt");
    string line;

   
    while (getline(fread, line)) 
    {
        string tname;
        int tid = 0;
        string tempid;

        int i = 0;

        // id
        while (i < line.size() && line[i] != ',') {
            tempid += line[i];
            i++;
        }
        tid = stoi(tempid);
        i++;

        // name
        while (i < line.size()) {
            tname += line[i];
            i++;
        }

        // pushback
        teacher t(tid, tname);
        teachers.push_back(t);
    }
}

      void loadadmins(vector<admin>& admins)
{
    ifstream fread("data/admins.txt");
    string line;

    // skip header
    getline(fread, line);

    while (getline(fread, line)) 
    {
        string aname;
        int aid = 0;
        string tempid;

        int i = 0;

        // id
        while (i < line.size() && line[i] != ',') {
            tempid += line[i];
            i++;
        }
        aid = stoi(tempid);
        i++;

        // name
        while (i < line.size()) {
            aname += line[i];
            i++;
        }

        // pushback
        admin a(aid, aname);
        admins.push_back(a);
    }
}

  }