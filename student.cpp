#include "student.h"

Student::Student(){}
Student::~Student(){}

bool Student::Create_Student(int dni, string name, string password, 
                             bool status, int school_code)
{
  iter = students.find(dni);
  if(iter != students.end())
    return false;

  student s;
  s.dni = dni;
  s.name = name;
  s.password = password;
  s.status = status;
  s.school_code = school_code;
  
  students[dni] = s;
  return true;
}

bool Student::Delete_Student(int dni)
{
  iter = students.find(dni);
  if(iter != students.end())
  {
    students.erase(iter);
    return true;  
  }
  return false;
}

string Student::getNameStudent(int dni)
{
  iter = students.find(dni);
  if(iter != students.end())
    return iter->second.name;
  return "student not found";
}

string Student::getPasswordStudent(int dni)
{
  iter = students.find(dni);
  if(iter != students.end())
    return iter->second.password;
  return "student not found";
}

bool Student::getStatusStudent(int dni)
{
  iter = students.find(dni);
  if(iter != students.end())
    return iter->second.status;
  return false;
}

int Student::getSchoolcodeStudent(int dni)
{
  iter = students.find(dni);
  if(iter != students.end())
    return iter->second.school_code;
  return -1;
}

void Student::setNameStudent(int dni, string name)
{
  iter = students.find(dni);
  if(iter != students.end())
    iter->second.name = name;
}

void Student::setPasswordStudent(int dni, string password)
{
  iter = students.find(dni);
  if(iter != students.end())
    iter->second.password = password;
}

void Student::setStatusStudent(int dni, bool status)
{
  iter = students.find(dni);
  if(iter != students.end())
    iter->second.status = status;
}

void Student::setSchoolcodeStudent(int dni, int school_code)
{
  iter = students.find(dni);
  if(iter != students.end())
    iter->second.school_code = school_code;
}
void Student::ViewStudent()
{
  for(iter = students.begin(); iter != students.end(); iter++)
    cout << iter->second.dni << " -> " << iter->second.name << endl; 
}
