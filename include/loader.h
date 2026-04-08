#ifndef LOADER_H
#define LOADER_H

#include <vector>
#include "student.h"
#include "teacher.h"
#include "admin.h"

using namespace std;

namespace loader
{
  void loadstudents(vector<student> &students);

  void loadteachers(vector<teacher> &teachers);

  void loadadmins(vector<admin> &admins);

}

#endif