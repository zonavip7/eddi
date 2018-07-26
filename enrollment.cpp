#include "enrollment.h"

bool Enrollment::Create_Enrollment(int student_code, int course_code)
{
  for(int i = 0; i < (int)enrollments.size(); ++i)
  {
    if(enrollments[i].student_code == student_code && 
       enrollments[i].course_code == course_code)
      return false;
  }

  enrollment e;
  e.course_code = course_code;
  e.student_code = student_code;
  e.qualification = 0;

  enrollments.push_back(e);

  return true;
}

bool Enrollment::Delete_Enrollment(int student_code, int course_code)
{
  iter = enrollments.begin();
  while(iter != enrollments.end())
  {
    if(iter->student_code == student_code && 
       iter->course_code == course_code)
    {
      enrollments.erase(iter);
      return true;
    }
    iter++;
  }
  return false;
}

bool Enrollment::setQualificationEnrollment(int student_code,
                                            int course_code,
                                            int qualification)
{
  for(int i = 0; i < (int)enrollments.size(); ++i)
  {
    if(enrollments[i].student_code == student_code &&
       enrollments[i].course_code == course_code)
    {
      enrollments[i].qualification = qualification;
      return true;
    }
  }
  return false;
}

vector <enrollment> Enrollment::getEnrollmentStudent(int student_code)
{
  vector<enrollment> ret;
  for(int i = 0; i < (int)enrollments.size(); ++i)
  {
    if(enrollments[i].student_code == student_code)
    {
      ret.push_back(enrollments[i]);
    }
  }
  return ret;
}

int Enrollment::getQualificationStudentCourse(int student_code, 
                                              int course_code)
{
  for(int i = 0; i < (int)enrollments.size(); ++i)
  {
    if(enrollments[i].student_code == student_code &&
       enrollments[i].course_code == course_code)
    {
      return enrollments[i].qualification;
    }
  }
  return -1; 
}

vector <enrollment> Enrollment::getEnrollmentCourse(int course_code)
{
  vector<enrollment> ret;
  for(int i = 0; i < (int)enrollments.size(); ++i)
  {
    if(enrollments[i].course_code == course_code)
    {
      ret.push_back(enrollments[i]);
    }
  }
  return ret;   
}

void Enrollment::ViewEnrollments()
{
  for(int i = 0; i < (int)enrollments.size(); ++i)
    cout << "Codigo Estudiante " << enrollments[i].student_code << " -> " <<
            "Codigo Curso " << enrollments[i].course_code << endl;
}

