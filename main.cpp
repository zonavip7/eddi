#include "teacher.h"
#include "school.h"
#include "student.h"
#include "course.h"
#include "enrollment.h"

#include <iostream>     /* cout and cin */
#include <stdlib.h>     /* system() */
#include <vector>

using namespace std;

void Menu_Admin();
void Menu_Student(int dni);
void Menu_Teacher(int dni);

/* 
 *
 * */
Teacher     teachers;
Student     students;
School      schools;
Course      courses;
Enrollment  enrollments;

int main(void)
{
  string opt;
  string dni;
  string password;
  while(1)
  {
    cout << "(1) Admin" << endl;
    cout << "(2) Teacher" << endl;
    cout << "(3) Student" << endl;
    cout << "(99) Exit" << endl;
    cout << endl;
    cin >> opt;
  
    if(opt == "99")        /* Exit */
      exit(0);

    if(opt == "1")        /* Admin */
    {
      cout << "ADMIN" << endl;
      cout << "PASSWORD: "; cin >> password;

      if(password == "ADMIN")
        Menu_Admin();
      else 
        cout << "Password Incorrect" << endl;
    
    }
    else if(opt == "2")   /* Teacher */
    {
      cout << "TEACHER" << endl;
      cout << "DNI : "; cin >> dni;
      cout << "PASSWORD : "; cin >> password;
      
      int _dni = atoi(dni.c_str());
      
      if(teachers.getPasswordTeacher(_dni) == password &&
         teachers.getStatusTeacher(_dni) == true)
        Menu_Teacher(_dni);
      else
        cout << "Error en la verificacion de los datos" << endl;

    }
    else if(opt == "3")   /* Student */
    {
      cout << "STUDENT" << endl;
      cout << "DNI : "; cin >> dni;
      cout << "PASSWORD : "; cin >> password;
      
      int _dni = atoi(dni.c_str());
      
      if(students.getPasswordStudent(_dni) == password &&
         students.getStatusStudent(_dni) == true)
        Menu_Student(_dni);
      else
        cout << "Error en la verificacion de los datos" << endl;
    }
  }

  system("PAUSE");
  return 0;
}

void Menu_Admin()
{
  system("clear");
  string opt;

  string dni;
  string name;
  string password;
  string status;
  string school_code;
 
  string course_code; 
  string student_code;
  string teacher_code;
  int _dni;

  string code;
  string theory;
  string practical;
 

  while(1)
  {
    cout << "******** ADMIN *********" << endl;
    cout << "**** PROFESOR *****" << endl;
    cout << "(1) Agregar Profesor" << endl;
    cout << "(2) Ver Lista de Profesores" << endl;
    cout << "(3) Actulizar datos de un profesor" << endl;
    cout << "(4) Activar o desactivar un Profesor" << endl << endl;

    cout << "**** ESTUDIANTE ****" << endl;
    cout << "(11) Agregar Estudiante" << endl;
    cout << "(12) Ver Lista de Estudiantes" << endl;
    cout << "(13) Actualizar datos de un Estudiante" << endl;
    cout << "(14) Activar o desactivar un Estudiante" << endl << endl;

    cout << "**** CURSO ****" << endl;
    cout << "(21) Agregar Curso" << endl;
    cout << "(22) Ver Lista de Cursos" << endl;
    cout << "(23) Actualizar datos de un Curso" << endl;
    cout << "(24) Activar o desactivar un Curso" << endl << endl;

    cout << "**** ESCUELA ****" << endl;
    cout << "(31) Agregar Escuela" << endl;
    cout << "(32) Ver Lista de Escuelas" << endl;
    cout << "(33) Actualizar datos de una Escuela" << endl;
    cout << "(34) Activar o desactivar una escuela" << endl;

    cout << "**** MATRICULA ****" << endl;
    cout << "(41) Agregar Matricula" << endl;
    cout << "(42) Ver Lista de Matriculas" << endl << endl;

    cout << "(99) Salir" << endl << endl;
    cin >> opt;

    if(opt == "99")       /* exit */
      break;

    switch(atoi(opt.c_str()))
    {
      case 1:
        cout << "Agregar Profesor" << endl;
        cout << "Ingrese DNI : "; cin >> dni;
        cout << "Nombre : "; cin >> name;
        cout << "Password : "; cin >> password;
        cout << "Codigo de la escuela : "; cin >> school_code;
 
        if(schools.length == 0)
        {
          cout << "NO HAY UNA ESCUELA CREE UNA POR FAVOR" << endl;
          break;
        }

        if(teachers.Create_Teacher(atoi(dni.c_str()), name, password, true, atoi(school_code.c_str())) == true)
          cout << "Se agrego correctamente al profesor" << endl;
        else 
          cout << "No se pudo agregar al profesor VERIFIQUE QUE LOS DATOS SEAN CORRECTOS" << endl;

        break;
      case 2:
        teachers.ViewTeachers();
        break;
      case 3:
        teachers.ViewTeachers();
        cout << "Seleccione el codigo del profesor que desea cambiar sus datos" << endl;
        cin >> dni;
        cout << "Si no desea cambiar los datos precione el '*'" << endl;
        cout << "Agregar Profesor" << endl;

        cout << "Nuevo Nombre : "; cin >> name;
        cout << "Nuevo Ingrese Password : "; cin >> password;
        cout << "Nuevo Codigo de la escuela : "; cin >> school_code;

        _dni = atoi(dni.c_str());
        if(name != "*")
        {
          teachers.setNameTeacher(_dni, name);
        }
        if(password != "*")
        {
          teachers.setPasswordTeacher(_dni, password);
        }
        if(school_code != "*")
        {
          teachers.setSchoolcodeTeacher(_dni, atoi(school_code.c_str()));
        }

        break;
      case 4:
        cout << "Seleccione a un profesor" << endl;
        teachers.ViewTeachers();
        cin >> dni;

        cout << "(1) Si desea desactivar un profesor" << endl;
        cout << "(2) Si desea activar un profesor" << endl;
        cin >> status;

        if(status ==  "1")
          teachers.setStatusTeacher(atoi(dni.c_str()), false);  
        else if(status == "2")
          teachers.setStatusTeacher(atoi(dni.c_str()), true);
        break;
      
      case 11:
        cout << "Agregar ESTUDIANTE" << endl;
        cout << "Ingrese DNI : "; cin >> dni;
        cout << "Nombre : "; cin >> name;
        cout << "Password : "; cin >> password;
        cout << "Codigo de la escuela : "; cin >> school_code;

      
        if(schools.length == 0)
        {
          cout << "NO HAY UNA ESCUELA CREE UNA POR FAVOR" << endl;
          break;
        }

        if(students.Create_Student(atoi(dni.c_str()), name, password, true, atoi(school_code.c_str())) == true)
          cout << "Se agrego correctamente al estudiante" << endl;
        else 
          cout << "No se pudo agregar al estudiante VERIFIQUE QUE LOS DATOS SEAN CORRECTOS" << endl;

        break;
      case 12:
        cout << "ESTUDIANTES" << endl;
        students.ViewStudent();
        cout << endl << endl;
        break;
      case 13:
        students.ViewStudent();
        cout << "Seleccione el codigo del alumno que desea cambiar datos" << endl;
        cin >> dni;
        cout << "Si no desea cambiar los datos precione el '*'" << endl;
        cout << "Agregar Profesor" << endl;

        cout << "Nuevo Nombre : "; cin >> name;
        cout << "Nuevo Ingrese Password : "; cin >> password;
        cout << "Nuevo Codigo de la escuela : "; cin >> school_code;

        _dni = atoi(dni.c_str());
        if(name != "*")
        {
          students.setNameStudent(_dni, name);
        }
        if(password != "*")
        {
          students.setPasswordStudent(_dni, password);
        }
        if(school_code != "*")
        {
          students.setSchoolcodeStudent(_dni, atoi(school_code.c_str()));
        }

        break;
      case 14:
        cout << "Seleccione a un estudiante" << endl;
        students.ViewStudent();
        cin >> dni;

        cout << "(1) Si desea desactivar un estudiante" << endl;
        cout << "(2) Si desea activar un estudiante" << endl;
        cin >> status;

        if(status ==  "1")
          students.setStatusStudent(atoi(dni.c_str()), false);  
        else if(status == "2")
          students.setStatusStudent(atoi(dni.c_str()), true);
        break;
 
      case 21:
        cout << "CURSOS" << endl;
        cout << "Codigo : "; cin >> code;
        cout << "Nombre : "; cin >> name;
        cout << "Theory : "; cin >> theory;
        cout << "Practical : "; cin >> practical;
        
        cout << "Seleccione al uno de los profesores" << endl;
        teachers.ViewTeachers();
        cin >> teacher_code;
        
        cout << "Seleccione el codigo de una escuela" << endl;
        schools.ViewSchool();
        cin >> school_code;

        if(schools.length == 0)
        {
          cout << "NO HAY UNA ESCUELA CREE UNA POR FAVOR" << endl;
          break;
        }

        if(courses.Create_Course(atoi(code.c_str()), name, theory,
                                 practical, true, atoi(teacher_code.c_str()), 
                                 atoi(school_code.c_str()) ) == true)
          cout << "Se agrego correctamente el CURSO" << endl;
        else
          cout << "Se ha producido un ERROR AL INSERTAR LOS DATOS" << endl;

        break;
      case 22:
        cout << "CURSOS" << endl;
        courses.ViewCourse();
        cout << "**************************" << endl;
        break;
      case 23:
        cout << "Seleccione el codigo del curso que desea cambiar notas" << endl;
        cin >> dni;
        cout << "Si no desea cambiar los datos precione el '*'" << endl;

        cout << "Nuevo Nombre : "; cin >> name;
        cout << "Theory : "; cin >> theory;
        cout << "Practical : "; cin >> practical;
        
        cout << "Seleccione al uno de los profesores" << endl;
        teachers.ViewTeachers();
        cin >> teacher_code;
        
        cout << "Seleccione el codigo de una escuela" << endl;
        schools.ViewSchool();
        cin >> school_code;


        _dni = atoi(dni.c_str());
        if(name != "*")
        {
          courses.setNameCourse(_dni, name);
        }
        if(theory != "*")
        {
          courses.setTheoryCourse(_dni, theory);
        }
        if(practical != "*")
        {
          courses.setPracticalCourse(_dni, practical);
        }
        if(teacher_code != "*")
        {
          courses.setTeachercodeCourse(_dni, atoi(teacher_code.c_str()));
        }
        if(school_code != "*")
        {
          courses.setSchoolcodeCourse(_dni, atoi(school_code.c_str()));
        }
        break;
      case 24:
        cout << "Seleccione a un curso" << endl;
        courses.ViewCourse();
        cin >> dni;

        cout << "(1) Si desea desactivar un courso" << endl;
        cout << "(2) Si desea activar un curso" << endl;
        cin >> status;

        if(status ==  "1")
          courses.setStatusCourse(atoi(dni.c_str()), false);  
        else if(status == "2")
          courses.setStatusCourse(atoi(dni.c_str()), true);
        break;

      case 31:
        cout << "ESCUELA" << endl;
        cout << "Codigo : "; cin >> code;
        cout << "Name : "; cin >> name;
      
        if(schools.Create_School(atoi(code.c_str()), name, true) == true)
          cout << "Se agrego correctamente la escuela" << endl;
        else
          cout << "Se ha producido un error AL INSERTAR LOS DATOS" << endl;

        break;
      case 32:
        cout << "ESCUELAS" << endl;
        schools.ViewSchool();
        cout << endl;
        break;
      case 33:
        schools.ViewSchool();
        cout << "Ingrese el codigo de una escuela" << endl;
        cin >> code;

        _dni = atoi(code.c_str());
        cout << "Nuevo Nombre" ; cin >> name;
        schools.setNameSchool(_dni, name);

        break;
      case 34:
        schools.ViewSchool();
        cout << "Ingrese el codigo de una escuela" << endl;
        cin >> code;
        
        cout << "(1) Si desea desactivar la escuela" << endl;
        cout << "(2) Si desea activar la escuela" << endl;
        cin >> status;

        if(status ==  "1")
          schools.setStatusSchool(atoi(dni.c_str()), false);  
        else if(status == "2")
          schools.setStatusSchool(atoi(dni.c_str()), true);
        break;

      case 41:
        cout << "Agregar Matricula" << endl;
        students.ViewStudent();
        cout << "Seleccione el codigo del alumno a matricular" << endl;
        cin >> student_code;
        courses.ViewCourse();
        cout << "Seleccione el codigo del curso a matricular" << endl;
        cin >> course_code;
        
        if(enrollments.Create_Enrollment(atoi(student_code.c_str()),
                                      atoi(course_code.c_str())) == true)
          cout << "Se ha agregado correctamente la MATRICULA"<< endl;
        else
          cout << "Se ha producido un error al agregar la matricula" << endl;
        break;

      case 42:
        cout << "MATRICULAS" << endl;
        enrollments.ViewEnrollments();
        cout << endl;
        break;
    }
  }
}
void Menu_Student(int dni)
{
  system("clear");
  string opt;
  while(1)
  {
    cout << students.getNameStudent(dni) << endl; 
    cout << "(1) Ver Cursos que lleva " << endl;
    cout << "(2) Ver Notas de un curso que lleva" << endl;
    cout << "(3) Ver consolidado de Notas" << endl;
    cout << "(99) Salir " << endl; 
    cin >> opt;
    if(opt == "99")
      break;

    vector <enrollment> tmp;
    string code_course;

    switch(atoi(opt.c_str()))
    {
      case 1:
        tmp = enrollments.getEnrollmentStudent(dni);
        cout << "Cursos" << endl;
        for(int i = 0; i < (int)tmp.size(); ++i)
          cout << courses.getNameCourse(tmp[i].course_code) << endl;
        cout << "********************" << endl;

        break;
      case 2:
        cout << "Ingrese el codigo del curso que desea ver sus notas" << endl;
        cin >> code_course;
        cout << "Su nota es : " << enrollments.getQualificationStudentCourse(dni, atoi(code_course.c_str())) << endl;    
        break;
      case 3:
        tmp = enrollments.getEnrollmentStudent(dni);
        for(int i = 0; i < (int)tmp.size(); ++i)
        {
          cout << teachers.getNameTeacher(courses.getTeachercodeCourse(tmp[i].course_code)) <<  " -> ";
          cout << courses.getNameCourse(tmp[i].course_code) << " -> " << tmp[i].qualification << endl;
        }
        cout << "********************" << endl;
        break;
    }
  }
}
void Menu_Teacher(int dni)
{
  system("clear");
  string opt;
  while(1)
  {
    cout << teachers.getNameTeacher(dni) << endl;
    cout << "(1) Ver Cursos que enseña" << endl;
    cout << "(2) Ver Alumnos de un curso que enseña" << endl;
    cout << "(3) Ver notas de los alumnos de un curso que enseña" << endl;
    cout << "(4) Ingresar o corregir Nota de un alumno que enseña" << endl;
    cout << "(99) Salir " << endl;
    cin >> opt;

    if(opt == "99")
      break;
    vector <course> tmp;
    vector <enrollment> tmp_e;
    
    string code_course;
    string code_student;
    string calificacion;

    switch(atoi(opt.c_str()))
    {
      case 1:
        tmp = courses.getCoursesTeacher(dni);
        cout << "CURSOS "<< endl;
        for(int i = 0; i < (int)tmp.size(); ++i)
          if(courses.getStatusCourse(tmp[i].code) == true)
            cout << tmp[i].name << endl;
        cout << "******************" << endl; 
        break;
      case 2:
        tmp = courses.getCoursesTeacher(dni);
        cout << "Seleccione el codigo de los cursos que enseña" << endl;
        for(int i = 0; i < (int) tmp.size(); ++i)
          if(courses.getStatusCourse(tmp[i].code) == true)
            cout << tmp[i].code << " -> " << tmp[i].name << endl;
        cout << "-------------------------" << endl;

        cin >> code_course;
        tmp_e = enrollments.getEnrollmentCourse(atoi(code_course.c_str()));
        
        cout << "ESTUDIANTES" << endl;
        for(int i = 0; i < (int)tmp_e.size(); ++i)
          cout << students.getNameStudent(tmp_e[i].student_code) << endl;
        cout << "-------------------------" << endl;

        break;
      case 3:
        tmp = courses.getCoursesTeacher(dni);
        cout << "Seleccione el codigo de los cursos que enseña" << endl;
        for(int i = 0; i < (int) tmp.size(); ++i)
          if(courses.getStatusCourse(tmp[i].code) == true)
            cout << tmp[i].code << " -> " << tmp[i].name << endl;
        cout << "-------------------------" << endl;

        cin >> code_course;
        tmp_e = enrollments.getEnrollmentCourse(atoi(code_course.c_str()));
        
        cout << "ESTUDIANTES" << endl;
        for(int i = 0; i < (int)tmp_e.size(); ++i)
          if(students.getStatusStudent(tmp_e[i].student_code) == true)
            cout << students.getNameStudent(tmp_e[i].student_code) << 
                    tmp_e[i].qualification << endl;

        cout << "-------------------------" << endl;

        break;
      case 4:
        tmp = courses.getCoursesTeacher(dni);
        cout << "Seleccione el codigo de los cursos que enseña" << endl;
        for(int i = 0; i < (int) tmp.size(); ++i)
          if(courses.getStatusCourse(tmp[i].code) == true)
            cout << tmp[i].code << " -> " << tmp[i].name << endl;
        cout << "-------------------------" << endl;

        cin >> code_course;           // codigo curso
        tmp_e = enrollments.getEnrollmentCourse(atoi(code_course.c_str()));
        
        cout << "Seleccione el codigo del estudiante ha ingresar la nota" << endl;
        for(int i = 0; i < (int)tmp_e.size(); ++i)
          if(students.getStatusStudent(tmp_e[i].student_code) == true)
            cout << tmp_e[i].student_code << " -> " << 
                    students.getNameStudent(tmp_e[i].student_code) << endl;
        cout << "-------------------------" << endl;
        cin >> code_student;          // codigo estudiante

        cout << "Ingrese la calificacion del alumno" << endl;
        cin >> calificacion;          // calificacion

        enrollments.setQualificationEnrollment(atoi(code_student.c_str()),
                                               atoi(code_course.c_str()),
                                               atoi(calificacion.c_str()));

        break;
    }
  }
}


