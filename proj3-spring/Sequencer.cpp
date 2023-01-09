// NAME: Sequencer.cpp
// AUTHOR: Joshua Julian Tanseco
// DATE: 3/29/2017
// SECTION: 19
// THIS FILE CONTAINS THE FUNCTION DEFINITIONS FOR THE SEQUENCER CLASS

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Sequencer.h"

using namespace std;



//Name: Sequencer() - Default constructor
//Precondition: valid filename
//Postcondition: file loaded into linked list, deleted after user ends program
Sequencer::Sequencer(string fileName){

  m_fileName = fileName; //sets filename as a member
  
  readFile(); //reads the file and loads it into a m_dna

  mainMenu(); //gives user options and acts accordingly

}



//Name: ~Sequencer() - Destructor
//Precondition: filled DNA linked list
//Postcondition: Dynamically allocated data is erased
Sequencer::~Sequencer(){

  m_dna.Clear();

}



//Name: readFile()
//Precondition: valid filename value for m_fileName
//Postcondition: file opened and contents are put into linked list
void Sequencer::readFile(){

  //opening file
  ifstream inputStream;
  inputStream.open(m_fileName.c_str());

  //adds contents into linked list one by one
  char tempChar;
  while (inputStream >> tempChar){

    m_dna.InsertEnd(tempChar);  

  }

  //closing file
  inputStream.close();

  //populates dna size
  m_dna.SizeOf();

  //tells user that sequence was loaded
  cout << "New Sequencer loaded" << endl;

}



//Name: mainMenu() - this function acts according to user input
//Precondtion: filled linked list
//Postcondition: program takes in user input until 5 is called
void Sequencer::mainMenu(){

  //number that the user inputs
  int inNum = 0;

  while (inNum != 5){

    //Makes sure input is valid
    while (inNum < 1 || inNum > 5){

      //asks the user what they want to do
      cout << "What would you like to do?" << endl;
      cout << "1. Display Sequencer (Leading Strand)" << endl;
      cout << "2. Display Sequencer (Base Pairs)" << endl;
      cout << "3. Inventory Basic Amino Acids" << endl;
      cout << "4. Sequence Entire DNA Strand" << endl;
      cout << "5. Exit" << endl;
      
      cin >> inNum;
      
    }

    //switch statement for different user options
    switch (inNum){

      //Display leading strands
    case 1:
      m_dna.Display(inNum);
      break;

      //Display base pairs
    case 2:
      m_dna.Display(inNum);
      break;

      //Inventory basic amino acids
    case 3:
      m_dna.NumAmino("Tryptophan", "TGG");
      m_dna.NumAmino("Phenylalanine", "TTT");
      break;

      //Sequencer DNA strand
    case 4:
      m_dna.Sequence();
      break;

      //exits the program
    case 5:

      break;

    }


    //if 5 wasn't the number
    if (inNum != 5){
      //asks the user what they want to do
      cout << "What would you like to do?" << endl;
      cout << "1. Display Sequencer (Leading Strand)" << endl;
      cout << "2. Display Sequencer (Base Pairs)" << endl;
      cout << "3. Inventory Basic Amino Acids" << endl;
      cout << "4. Sequence Entire DNA Strand" << endl;
      cout << "5. Exit" << endl;
      
      cin >> inNum;

    }
  }
  
  //end
  cout << "DNA removed from memory" << endl;
  
}
