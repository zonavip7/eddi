#include "teacher.h"

Teacher::Teacher(){}
Teacher::~Teacher(){}

bool Teacher::Create_Teacher(int dni, string name, string password,
                             bool status, int school_code)
{
  iter = teachers.find(dni);
  if(iter != teachers.end())
    return false;

  teacher t;
  t.dni = dni;
  t.name = name;
  t.password = password;
  t.status = status;
  t.school_code = school_code;

  teachers[dni] = t;
  return true;
}

bool Teacher::Delete_Teacher(int dni)
{
  iter = teachers.find(dni);
  if(iter != teachers.end())
  {
    teachers.erase(iter);
    return true;   
  }
  return false;
}


string Teacher::getNameTeacher(int dni)
{
  iter = teachers.find(dni);
  if(iter != teachers.end())
    return iter->second.name;
  return "teacher not found";
}

string Teacher::getPasswordTeacher(int dni)
{
  iter = teachers.find(dni);
  if(iter != teachers.end())
    return iter->second.password;
  return "teacher not found";
}

bool Teacher::getStatusTeacher(int dni)
{
  iter = teachers.find(dni);
  if(iter != teachers.end())
    return iter->second.status;
  return false;
}

int Teacher::getSchoolcodeTeacher(int dni)
{
  iter = teachers.find(dni);
  if(iter != teachers.end())
    return iter->second.school_code;
  return -1;
}

void Teacher::setNameTeacher(int dni, string name)
{
  iter = teachers.find(dni);
  if(iter != teachers.end())
    iter->second.name = name;
}

void Teacher::setPasswordTeacher(int dni, string password)
{
  iter = teachers.find(dni);
  if(iter != teachers.end())
    iter->second.password = password;
}

void Teacher::setStatusTeacher(int dni, bool status)
{
  iter = teachers.find(dni);
  if(iter != teachers.end())
    iter->second.status = status;
} 

void Teacher::setSchoolcodeTeacher(int dni, int school_code)
{
  iter = teachers.find(dni);
  if(iter != teachers.end())
    iter->second.school_code = school_code;
}

void Teacher::ViewTeachers()
{
  cout << " *********** TEACHER *********** " << endl;
  for(iter = teachers.begin(); iter != teachers.end(); iter++)
    cout << iter->second.dni << " " << iter->second.name << endl;
  cout << endl;
}
