#ifndef __ENROLLMENT_H_
#define __ENROLLMENT_H_

#include <iostream>
#include <vector>

using namespace std;

struct enrollment
{
  int student_code;
  int course_code;
  int qualification;
};

class Enrollment
{
  private:
    //   code_student
    vector<enrollment> enrollments;
    vector<enrollment>::iterator iter;
  
  public:
    bool Create_Enrollment(int student_code, int course_code);
    bool setQualificationEnrollment(int student_code, int course_code, 
                                    int qualification);
    bool Delete_Enrollment(int student_code, int course_code);
    int  getQualificationStudentCourse(int student_code, int course_code);
    vector <enrollment> getEnrollmentStudent(int student_code);
    vector <enrollment> getEnrollmentCourse(int course_code);

    void ViewEnrollments();
};

#endif /* __ENROLLMENT_H_ */
