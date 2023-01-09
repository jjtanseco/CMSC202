#include "Candle.h"
#include "Scented.h"

#include <iostream>
#include <string>


Scented::Scented(string name, double burnRate, string flavor)
  : Candle(name, burnRate)
{
  m_flavor = flavor;
}

void Scented::SetFlavor(string flavor){
  m_flavor = flavor;
}

string Scented::GetFlavor(){
  return m_flavor;
}

