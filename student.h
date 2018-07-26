#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <iostream>
#include <map>

using namespace std;

struct student
{
  int dni;
  string name;
  string password;
  bool status;
  int school_code;
};

class Student
{
  private:
    map <int, student> students;
    map <int ,student>::iterator iter;
  public:
    Student();
    ~Student();
    bool Create_Student(int dni, string name, string password,
                        bool status, int school_code);
    string getNameStudent(int dni);
    string getPasswordStudent(int dni);
    bool   getStatusStudent(int dni);
    int    getSchoolcodeStudent(int dni);

    void   setNameStudent(int dni, string name);
    void   setPasswordStudent(int dni, string password);
    void   setStatusStudent(int dni, bool status);
    void   setSchoolcodeStudent(int dni, int school_code);

    bool Delete_Student(int dni);

    void ViewStudent();
};

#endif /* __STUDENT_H_ */
