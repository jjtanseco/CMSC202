// NAME: Media.cpp
// AUTHOR: Joby Tanseco
// DATE: 7/5/2017
// SECTION: 2
// DESCRIPTION: This is the implementation of the Media class

#include "Media.h"


//Default constructor for the media
Media::Media(){
  m_rank = 0;
  m_name = "Joby";
  m_year = 0;
  m_type = "None";
} 


//Overloaded constructor
Media::Media(int rank, string name, int year, string type){
  m_rank = rank;
  m_name = name;
  m_year = year;
  m_type = type;
}

// NAME: getRank()
// PRE: Existing Media Object
// POST: returns m_rank as an int
int Media::getRank(){
  return m_rank;
}


// NAME: getName()
// PRE: Existing Media Object
// POST: returns string name
string Media::getName(){
  return m_name;
}


// NAME: getYear()
// PRE: Existing Media Object
// POST: returns Year as an int
int Media::getYear(){
  return m_year;
}


// NAME: getType()
// PRE: Existing Media Object
// POST: returns Type as an int
string Media::getType(){
  return m_type;
}


// NAME: setName()
// PRE: Valid argument type
// POST: updated m_name
void Media::setName(string name){
  m_name = name;
}


// NAME: setYear()
// PRE: Valid argument type
// POST: updated m_year
void Media::setYear(int year){
  m_year = year;
}


// NAME: setType()
// PRE: Valid argument type
// POST: updated m_type
void Media::setType(string type){
  m_type = type;
}


// NAME: setRank()
// PRE: Valid argument type
// POST: updated m_rank
void Media::setRank(int rank){
  m_rank = rank;
}
