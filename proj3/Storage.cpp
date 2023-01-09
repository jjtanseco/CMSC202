// NAME: Storage.cpp
// AUTHOR: Joby Tanseco
// DATE: 7/5/2017
// DESCRIPTION: THIS IS THE IMPLEMENTATION OF THE STORAGE CLASS

#include "Storage.h"
#include <cstdlib>

//Name: Storage (Default Constructor) UNUSED
//Precondition: None
//Postcondition: Creates a new linked list to store media data
Storage::Storage(){
  m_head = NULL;
  m_tail = NULL;
}


//Name: Storage (Overloaded Constructor)
//Precondition: Imports a file of data (file must be formatted correctly)
//Postcondition: Creates a new linked list to store media data and imports
// data directly from file
Storage::Storage(string fileName){
  
  m_head = NULL;
  m_tail = NULL;
}

//Name: ~Storage
//Precondition: Already existing Storage object
//Postcondition: When object goes out of scope, removes dynamically allocated
// data
Storage::~Storage(){
  Node *CURR = m_head;
  while (CURR != NULL){
    delete CURR;
    CURR = CURR->next;
  }

}


//Name: sortByRank
//Precondition: Must have a list to sort
//Postcondition: Uses a bubble sort to order media by ranking
void Storage::sortByRank(){


  //gets size of list
  int size = 0;
  Node* CURR = m_head;
  while (CURR != NULL){
    CURR = CURR -> next;
    size ++;
  }

  CURR = m_head->next;
  Node* TRAIL = m_head;
  Media tempMedia;

  //actual bubble sort
  for (int i = 0; i < (size^(2)) ; i++){
    CURR = m_head->next;
    TRAIL = m_head;
    while (CURR != NULL){

      if (CURR->data.getRank() < TRAIL->data.getRank()){
	tempMedia = CURR->data;
	CURR->data = TRAIL->data;
	TRAIL->data = tempMedia;
      }
      TRAIL = CURR;
      CURR = CURR->next;
    }
  }
}


//Name: insertEnd
//Precondition: Must have Media to load into a new node
//Postcondition: Inserts a new node into storage at the end of the list
void Storage::insertEnd(Media myMedia){

  //makes temporary Node with myMedia as data
  Node *temp = new Node();
  temp -> data = myMedia;
  temp -> next = NULL;
  
  //if there is currently no nodes in list
  if (m_head == NULL){
    m_head = temp;
    m_tail = temp;
  }
  //if linked list is currently populated
  else {
    m_tail -> next = temp;
    m_tail = temp;
  }



}



//Name: removeByName
//Precondition: Pass it a name
//Postcondition: Calls CheckName and if valid name, tries to remove from 
//Storage
void Storage::removeByName(string name){

  bool isName;
  if (checkName(name)){

    Node *CURR = m_head;
    Node *LAST = m_head;
    for (CURR = m_head; isName == false; CURR = CURR -> next){
      //checks if name is correct
      if (CURR -> data.getName() == name){
	isName = true;
	//removes if its the first item in the list
	if (CURR == m_head)
	  m_head = CURR -> next;
	else
	  LAST -> next = CURR -> next;	  
      }
    }
    cout << name << " removed" << endl;
  }
  else //if it can't be found
    cout << "No Media with that name found" << endl;
}

//Name: checkName
//Precondition: Pass it a name
//Postcondition: Iterates over storage list to see if the name exists at all
bool Storage::checkName(string name){

  //makes temporary nodes to iterate through list
  Node *CURR = m_head;

  //iterates through linked list
  while (CURR != NULL){
    //checks name of current 
    if(CURR -> data.getName() == name) 
      return true;
    CURR = CURR -> next;
  }
  //if it can't be found
  return false;
}



//Name: printStorage (isNumbered)
//Precondition: Pass it if you want to be numbered or not
//Postcondition: Iterates over storage list and displays the name of the 
// media
//   It can either number 1. Caddy Shack or not Caddy Shack
void Storage::printStorage(bool isNumbered){

  //  int counter;
  Node *CURR;
  cout << "*********************************" << endl;
  cout << "Name\tYear" << endl;

  CURR = m_head;
  //itereates through list
  while (CURR != NULL){
    cout << CURR->data.getName() << '\t' <<
      CURR->data.getYear() << endl;

    CURR = CURR->next;
  }
  cout << "*********************************" << endl;
}



//Name: printByMedia
//Precondition: Pass it a type of media BLURAY, DVD, PS4, or XBOX
//Postcondition: Prints the type of media and then all media that matches 
//the type
void Storage::printByMedia(string type){

  Node *CURR;
  //iterates through list and couts the proper type
  cout << "*********************************" << endl;
  cout << "Rank\tName" << endl;
  //iterates through list
  for (CURR = m_head; CURR != NULL; CURR = CURR -> next){
    if (CURR -> data.getType() == type){
      cout << CURR -> data.getRank() << '\t' << CURR -> data.getName()
	   << endl;
    }
  }
  cout << "*********************************" << endl;
}


//Name: printByRank
//Precondition: Must have a valid list
//Postcondition: Prints all media based on their ranking starting at 1 
//and continuing
void Storage::printByRank(){
  sortByRank();

  Node *CURR;
  cout << "*********************************" << endl;
  cout << "Rank\tName" << endl;
  //iterates through list
  for (CURR = m_head; CURR != NULL; CURR = CURR -> next){
    cout << CURR -> data.getRank() << "     " << CURR -> data.getName()
	 << endl;
  }
  cout << "*********************************" << endl;
}
