#include <iostream>;
#include <string>;
#include <fstream>;

using namespace std;

void quaff(int &points);

int main(){

  int points = 10;

  string action;

  cout << "You have " << points << " hit points." << endl << "What would you like to do?:" << endl;

  getline(cin, action);

  if (action == "quaff potion") {

    quaff(points);
    cout << "You have quaffed the potion!" << endl << "YOu have " << points << " hit points." << endl;
  }

  return 0;
}

void quaff(int &points) {

  points += 2;
}
