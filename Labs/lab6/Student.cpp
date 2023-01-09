#include <iostream>
#include <string>

#include "Student.h"

using namespace std;

//Constructor
Student::Student(int num, float *ptr){

  m_num = num;
  m_ptr = ptr;

}


//Destructor
Student::~Student()
{
  delete[] m_ptr;
}


//Display
void Student::Display(){

  cout << "Student's Grades" << endl;

  for (int i = 0; i < m_num; i++)

    cout << "Student" << i << ": " << m_ptr[i] << endl; 

}
