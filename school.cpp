#include "school.h"

School::School(){}
School::~School(){}

bool School::Create_School(int code, string name, bool status)
{
  iter = schools.find(code);
  if(iter != schools.end())
    return false;

  school s;
  s.code = code;
  s.name = name;
  s.status = status;

  schools[code] = s;
  ++length;
  return true;
}

bool School::Delete_School(int code)
{
  iter = schools.find(code);
  if(iter != schools.end())
  {
    schools.erase(iter);
    return true;
    --length;
  }
  return false;
}

string School::getNameSchool(int code)
{
  iter = schools.find(code);
  if(iter != schools.end())
    return iter->second.name;
  return "school not found";
}

bool School::getStatusSchool(int code)
{
  iter = schools.find(code);
  if(iter != schools.end())
    return iter->second.status;
  return false;
}

void School::setNameSchool(int code, string name)
{
  iter = schools.find(code);
  if(iter != schools.end())
    iter->second.name = name;
}

void School::setStatusSchool(int code, bool status)
{
  iter = schools.find(code);
  if(iter != schools.end())
    iter->second.status = status;
}
void School::ViewSchool()
{
  for(iter = schools.begin(); iter != schools.end(); iter++)
    cout << iter->second.code << " -> " << iter->second.name << endl;
}
