#include <iostream>
#include <string>
using namespace std;

int main() {

  int count;
  cout << "What number would you like to start with?:" << endl;
  cin >> count;

  char name[20];
  cout << "What type of bottle would you like?: " << endl;
  cin >> name;

  while (count != 0)
    {
      cout << count << " bottles of " << name << " on the wall. " << " \n " << count << " bottles of " << name << "You take one down, pass it around" << endl;

      count = count - 1;
      cout << count << "bottles of " << name << " on the wall." << endl;

    }
  cout << "No bottles of beer on the wall" << endl;


}
