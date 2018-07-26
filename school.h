#ifndef __SCHOOL_H_
#define __SCHOOL_H_

#include <iostream>
#include <map>

using namespace std;

struct school
{
  int code;
  string name;
  bool status;
};

class School
{
  private:
    map <int, school> schools;
    map <int, school>::iterator iter;
  public:
    int length = 0;
    School();
    ~School();

    bool Create_School(int code, string name, bool status);

    string getNameSchool(int code);
    bool   getStatusSchool(int code);

    void   setNameSchool(int code, string name);
    void   setStatusSchool(int code, bool status);

    bool Delete_School(int code);
    void ViewSchool();
};

#endif /* __SCHOOL_H_ */
