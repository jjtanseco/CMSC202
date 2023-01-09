#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

  int num;
  cout << "How many students?" << endl;
  cin >> num;

  float *ptr;

  ptr = new float[num];

  cout << "Enter GPA of students." << endl;

  for (int i = 0; i < num; i++){
    float tempGrade;
    cout << "Student" << i + 1 << endl;
    cin >> tempGrade;
    ptr[i] = tempGrade;
  }


  Student s(num, ptr);


  s.Display();
  return 0;
}
