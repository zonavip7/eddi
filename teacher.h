#ifndef __TEACHER_H_
#define __TEACHER_H_

#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct teacher
{
  int dni;
  string name;
  string password;
  bool status;
  int school_code;
};

class Teacher
{
  private:
    map <int, teacher> teachers;
    map <int, teacher>::iterator iter;
 
  public:
    Teacher();
    ~Teacher();
    bool Create_Teacher(int dni, string name, string password, 
                        bool status, int school_code);
    string getNameTeacher(int dni);
    string getPasswordTeacher(int dni);
    bool   getStatusTeacher(int dni);
    int    getSchoolcodeTeacher(int dni);

    void setNameTeacher(int dni, string name);
    void setPasswordTeacher(int dni, string password);
    void setStatusTeacher(int dni, bool status);
    void setSchoolcodeTeacher(int dni, int school_code);

    void ViewTeachers();

    bool Delete_Teacher(int dni);
};

#endif /* __TEACHER_H_ */
