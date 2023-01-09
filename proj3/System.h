/*Title: System.h
Author: Prof. Dixon
Date: 6/30/2017
Description: This is the class System that manages the user input and storage for
project 3 - Digital Redbox.
*/

#ifndef SYSTEM_H
#define SYSTEM_H

#include "Media.h"
#include "Storage.h"
#include <fstream>
#include <stdlib.h> 

class System {
public:
  //Name: System (Default Constructor) UNUSED
  //Precondition: None
  //Postcondition: Builds a new Redbox system
  System();
  //Name: System (Overloaded Constructor)
  //Precondition: Requires valid filename
  //Postcondition: Builds a new Redbox system from a specific file
  System(string fileName);
  //Name: mainMenu
  //Precondition: None
  //Postcondition: User interface that calls all functions
  void mainMenu();
  //Name: loadMedia
  //Precondition: Requires valid filename
  //Postcondition: Loads all data from file into node and pushes into storage
  int loadMedia(string fileName);
  //Name: printStorage
  //Precondition: 
  //Postcondition: Loads all data from file into node and pushes into storage
  void printStorage(bool isNumbered);
  //Name: printStorage
  //Precondition: Must have list
  //Postcondition: Prompts user for name (can have spaces) and searches list for
  // matching media name. If found, removes from list. Double check begin/end of list.
  void removeMedia(string name);
  //Name: insertMedia
  //Precondition: Must have a list
  //Postcondition: Prompts and validates users input to create new media and to insert
  //into the storage. Asks for name (can have spaces), rank, type, and year.
  void insertMedia();
private:
  Storage m_media; //Each System contains one linked list (storage)
};

#endif
