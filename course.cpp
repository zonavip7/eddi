#include "course.h"

Course::Course(){}
Course::~Course(){}

bool Course::Create_Course(int code, string name, string theory,
                           string practical, bool status, 
                           int teacher_code, int school_code)
{
  iter = courses.find(code);
  if(iter != courses.end())
    return false;

  course c;
  c.code = code;
  c.name = name;
  c.theory = theory;
  c.practical = practical;
  c.status = status;
  c.teacher_code = teacher_code;
  c.school_code = school_code;

  courses[code] = c;

  return true;
}

bool Course::Delete_Course(int code)
{
  iter = courses.find(code);
  if(iter != courses.end())
  {
    courses.erase(iter);
    return true;
  }
  return false;
}

string Course::getNameCourse(int code)
{
  iter = courses.find(code);
  if(iter != courses.end())
    return iter->second.name;
  return "course not found";
}

string Course::getTheoryCourse(int code)
{
  iter = courses.find(code);
  if(iter != courses.end())
    return iter->second.theory;
  return "course not found";
}

string Course::getPracticalCourse(int code)
{
  iter = courses.find(code);
  if(iter != courses.end())
    return iter->second.practical;
  return "course not found";
}

bool Course::getStatusCourse(int code)
{
  iter = courses.find(code);
  if(iter != courses.end())
    return iter->second.status;
  return false;
}

int Course::getTeachercodeCourse(int code)
{
  iter = courses.find(code);
  if(iter != courses.end())
    return iter->second.teacher_code;
  return -1;
}

int Course::getSchoolcodeCourse(int code)
{
  iter = courses.find(code);
  if(iter != courses.end())
    return iter->second.school_code;
  return -1;
}

void Course::setNameCourse(int code, string name)
{
  iter = courses.find(code);
  if(iter != courses.end())
    iter->second.name = name;
}

void Course::setTheoryCourse(int code, string theory)
{
  iter = courses.find(code);
  if(iter != courses.end())
    iter->second.theory = theory;
}

void Course::setPracticalCourse(int code, string practical)
{
  iter = courses.find(code);
  if(iter != courses.end())
    iter->second.practical = practical;
}

void Course::setStatusCourse(int code, bool status)
{
  iter = courses.find(code);
  if(iter != courses.end())
    iter->second.status = status;
}

void Course::setTeachercodeCourse(int code, int teacher_code)
{
  iter = courses.find(code);
  if(iter != courses.end())
    iter->second.teacher_code = teacher_code;
}

void Course::setSchoolcodeCourse(int code, int school_code)
{
  iter = courses.find(code);
  if(iter != courses.end())
    iter->second.school_code = school_code;
}

vector <course> Course::getCoursesTeacher(int teacher_code)
{
  vector <course> ret;

  iter = courses.begin();
  for(; iter != courses.end(); iter++)
  {
    if(iter->second.teacher_code == teacher_code)
    {
      ret.push_back(iter->second);  
    }
  }
  return ret;
}

void Course::ViewCourse()
{
  for(iter = courses.begin(); iter != courses.end(); iter++)
    cout << iter->second.code << " -> " << iter->second.name << endl;
}
