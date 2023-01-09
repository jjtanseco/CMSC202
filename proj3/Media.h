/*Title: Media.h
Author: Prof. Dixon
Date: 6/30/2017
Description: This is class that defines the media. The media can be either
from a Bluray, DVD, Ps4, or Xbox One. Picture it as either an image of a disc or
a disc itself (like at a real Redbox).
*/

#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Media{
public:
  Media(); //Default constructor for the media
  Media(int rank, string name, int year, string type); //Overloaded constructor 
  int getRank(); //Accessor for rank
  string getName(); //Accessor for name
  int getYear(); //Accessor for year
  string getType(); //Accessor for type
  void setName(string name); //Mutator for name
  void setYear(int year); //Mutator for year
  void setType(string type); //Mutator for type
  void setRank(int rank); //Mutator for rank
private:
  string m_name;
  int m_year;
  string m_type;
  int m_rank;
};

#endif
