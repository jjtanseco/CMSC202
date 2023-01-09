/*Title: Storage.h
Author: Prof. Dixon
Date: 6/30/2017
Description: This is the linked list for holding the media. Each node is
made of the media itself (picture an image of a disc or an actual disc) and a pointer
to the next node.
*/
#ifndef STORAGE_H
#define STORAGE_H

#include "Media.h"
#include <fstream>

struct Node{
  Media data; //The data of the node
  Node *next; //Pointer to the next node
};

class Storage {
public:
  //Name: Storage (Default Constructor) UNUSED
  //Precondition: None
  //Postcondition: Creates a new linked list to store media data
  Storage();
  //Name: Storage (Overloaded Constructor)
  //Precondition: Imports a file of data (file must be formatted correctly)
  //Postcondition: Creates a new linked list to store media data and imports data
  //               directly from file
  Storage(string fileName);
  //Name: ~Storage
  //Precondition: Already existing Storage object
  //Postcondition: When object goes out of scope, removes dynamically allocated data
  ~Storage();
  //Name: sortByRank
  //Precondition: Must have a list to sort
  //Postcondition: Uses a bubble sort to order media by ranking
  void sortByRank();
  //Name: insertEnd
  //Precondition: Must have Media to load into a new node
  //Postcondition: Inserts a new node into storage at the end of the list
  void insertEnd(Media myMedia);
  //Name: removeByName
  //Precondition: Pass it a name
  //Postcondition: Calls CheckName and if valid name, tries to remove from Storage
  void removeByName(string name);
  //Name: checkName
  //Precondition: Pass it a name
  //Postcondition: Iterates over storage list to see if the name exists at all
  bool checkName(string name);
  //Name: printStorage (isNumbered)
  //Precondition: Pass it if you want to be numbered or not
  //Postcondition: Iterates over storage list and displays the name of the media
  //               It can either number 1. Caddy Shack or not Caddy Shack
  void printStorage(bool isNumbered);
  //Name: printByMedia
  //Precondition: Pass it a type of media BLURAY, DVD, PS4, or XBOX
  //Postcondition: Prints the type of media and then all media that matches the type
  void printByMedia(string type);
  //Name: printByRank
  //Precondition: Must have a valid list
  //Postcondition: Prints all media based on their ranking starting at 1 and continuing
  void printByRank();
private:
  Node* m_head; //Linked list head
  Node* m_tail; //Linked list tail (used for insertEnd)
};

#endif
