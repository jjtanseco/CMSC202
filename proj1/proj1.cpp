// NAME: proj1.cpp
// AUTHOR: Joby Tanseco
// SECTION: 1
// DATE: 6.7.2017
// DESCRIPTION: This program serves as a life expentency calculator.

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>


using namespace std;

const string FILE_NAME = "proj1_data.txt";

const int ROW_AMOUNT = 120;
const int COL_AMOUNT = 7;

const int AGE_COL = 0;
const int MALE_DEATH_COL = 1;
const int MALE_NUM_COL = 2;
const int MALE_LIFE_COL = 3;
const int FEM_DEATH_COL = 4;
const int FEM_NUM_COL = 5;
const int FEM_LIFE_COL = 6;


// NAME: loadTable()
// PRE: existing file with 120 rows and 7 columns
// POST: file loaded into two dimensional array
void loadTable(double data[][COL_AMOUNT]);

// NAME: loopMenu()
// PRE: File is loaded
// POST: loops program until user quits
void loopMenu(double data[][COL_AMOUNT]);


// NAME: mainMenu()
// PRE: File is loaded
// POST: Outputs greeting and returns input request
int mainMenu();


// NAME: printTable()
// PRE: loaded 2d array
// POST: console outputted data
void printTable(double data[][COL_AMOUNT]);


// NAME: simulatePerson()
// PRE: loaded 2d array
// POST: outputs life expentency and actual life
int simulatePerson(double data[][COL_AMOUNT]);


//main function
int main(){

  srand(time(NULL));

  double data[ROW_AMOUNT][COL_AMOUNT];//makes 2d array

  loadTable(data); //loads table into the array

  loopMenu(data); //runs the rest of the program using the loaded 2d array

  return 0;
}


// NAME: loadTable() - Definition
// PRE: existing file with 120 rows and 7 columns
// POST: file loaded into two dimensional array
void loadTable(double data[][COL_AMOUNT]){

  //opens proj1_data file
  fstream inputStream;
  string fileName = FILE_NAME;
  inputStream.open(fileName.c_str());

  //uploads data into appropriate place in the 2d array
  for(int row = 0; row < ROW_AMOUNT; row++){
    for (int col = 0; col < COL_AMOUNT; col++){
      inputStream >> data[row][col];
    }
  }

  inputStream.close(); //closes the stream
}


// NAME: loopMenu() - Definition
// PRE: File is loaded
// POST: loops program until user quits
void loopMenu(double data[][COL_AMOUNT]){
  
  cout << "Welcome to the Life Expectancy Calculator" << endl;

  int userIn = mainMenu();//prompts the user for options

  while (userIn != 3){
    switch (userIn){
    case 1:
      printTable(data);//if the user wants to see the table
      break;
      
    case 2: 
      simulatePerson(data);//if the user wants to simulate a person
      break;
      
    case 3:
      break;//cancels program
    }
    userIn = mainMenu(); //reprompts the user
  }

  //Thanks user
  cout << "Thank you for using our Life Expectency Calculator." << endl;
  cout << "Bye!" << endl;
}


// NAME: mainMenu() - Definition
// PRE: File is loaded
// POST: Outputs options and returns input request
int mainMenu(){
  //activates loop
  int userIn = 4;
  //validates user input
  while (userIn < 1 || userIn > 3){
    cout << "What would you like to do?" << endl;
    cout << "1. Print Actuarial Table" << endl;
    cout << "2. Simulate Person" << endl;
    cout << "3. Exit" << endl;
    cin >> userIn;
  }
  return userIn;
}


// NAME: printTable() - Definition
// PRE: loaded 2d array
// POST: console outputted data
void printTable(double data[][COL_AMOUNT]){

  //iterates through each row
  for (int row = 0; row < ROW_AMOUNT; row++){
    //iterates through each item in rows
    for (int col = 0; col < COL_AMOUNT; col++){
      cout <<  data[row][col] << "   ";
    }
    //moves to next line once row is iterated through
    cout << endl;
  }
}


// NAME: simulatePerson() - Definition
// PRE: loaded 2d array
// POST: outputs life expentency and actual life
int simulatePerson(double data[][COL_AMOUNT]){
  //gets sex
  string sex = "O";
  while (sex != "M" && sex != "F"){
    cout << "Enter sex, 'M' or 'F'." << endl;
    cin >> sex;
  }

  // gets age
  int age = ROW_AMOUNT;
  while (age < 0 || age >= ROW_AMOUNT){
    cout << "Enter age." << endl;
    cin >> age;
  }

  //determines which column to choose life expentency from
  int sexCol = 6;
  if (sex == "M"){
    sexCol = 3;
  }

  double lifeExpectency = data[age][sexCol];
  //statement that gives life expentency
  cout << "Based on your gender, " << sex << ", and your age, " << 
    age << ", your life expentency is " << lifeExpectency << endl;
    

  //Actual simulation here.
  //random Number
  double chance;
  sexCol = 4;
  if (sex == "M"){
    sexCol = 1;
  }
  bool isDead = false;
  int ageCount = age;
  //iterates through each year
  while (not isDead){
    chance = ((double) rand() / (RAND_MAX)); // creates random number
    if (chance < data[ageCount][sexCol]){
      isDead = true; //kills you if you fall short
    }
    else 
      ageCount ++; //live another year
  }

  //outputs result
  cout << "You lived to age " << ageCount << endl;
  if (ageCount < lifeExpectency + age){
    cout << "You did not exceed your expected life span." << endl;;
  } else {
    cout << "You exceeded your expected life span." << endl;;
  }
}

