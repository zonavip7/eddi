#ifndef __COURSE_H_
#define __COURSE_H_

#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct course
{
  int code;
  string name;
  string theory;
  string practical;
  bool status;
  int teacher_code;
  int school_code;
};

class Course
{
  private:
    map <int, course> courses;
    map <int, course>::iterator iter;
  public:
    Course();
    ~Course();

    bool Create_Course(int code, string name, string theory,
                       string practical, bool status, 
                       int teacher_code, int school_code);

    string getNameCourse(int code);
    string getTheoryCourse(int code);
    string getPracticalCourse(int code);
    bool   getStatusCourse(int code);
    int    getTeachercodeCourse(int code);
    int    getSchoolcodeCourse(int code);

    void setNameCourse(int code, string name);
    void setTheoryCourse(int code, string theory);
    void setPracticalCourse(int code, string practical);
    void setStatusCourse(int code, bool status);
    void setTeachercodeCourse(int code, int teacher_code);
    void setSchoolcodeCourse(int code, int school_code);

    vector <course> getCoursesTeacher(int teacher_code);

    bool Delete_Course(int code);

    void ViewCourse();
};

#endif /* __COURSE_H_ */
