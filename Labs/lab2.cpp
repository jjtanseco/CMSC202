#include <iostream>
#include <string>
using namespace std;

const int SCORE_AMOUNT = 3;

double calcAverage(double scoreList[], int scoreAmount ) {
  int total = 0;
  for (int i = 0; i < scoreAmount; i++)
    {
      total += scoreList[i];
    }
  double average = total / 3.0;

  return average;
}

int printGrade(int average) {
  if (average >= 90)
    cout << "You recieved an A.";

  else if (average >= 80)
    cout << "You recieved a B.";

  else if (average >= 70)
    cout << "You recieved a C.";

  else if (average >= 60)
    cout << "You recieved a D.";

  else
    cout << "You recieved an F.";
}

int main()
{

  double scores[SCORE_AMOUNT] = {0};

  for (int i = 0; i < SCORE_AMOUNT; i++)
    {
      double tempValue;
      cout << "Enter Your Score: ";
      cin >> tempValue;

      scores[i] = tempValue;
    }

  double average = calcAverage(scores, SCORE_AMOUNT);
  cout << "Your Average is " << average << endl;
  printGrade(average);

}


