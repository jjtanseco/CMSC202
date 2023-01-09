#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

  int numIcedTea = 10;

  int *ptrIcedTea;

  ptrIcedTea = &numIcedTea;

  cout << "ptrIcedTea = " << ptrIcedTea << endl;

  cout << "*ptrIcedTea = " << *ptrIcedTea << endl;


  *ptrIcedTea = 20;

  cout << "numIcedTea = " << numIcedTea << endl;

  cout << "*ptrIcedTea = " << *ptrIcedTea << endl;

}
