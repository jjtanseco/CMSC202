#ifndef SCENTED_H
#define SCENTED_H
#include "Candle.h"

#include <string>
#include <iostream>
using namespace std;


class Scented : public Candle {
 public:
  Scented(string name, 
	  double burnRate, 
	  string flavor);

  void SetFlavor(string flavor);

  string GetFlavor();

  //  void SetLit(bool isLit);

 private:

  string m_flavor;


};


#endif
