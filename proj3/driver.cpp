/*Title: driver.cpp
Author: Prof. Dixon
Date: 6/13/2017
Description: This is the driver for project 3 - Digital Redbox
*/
#include "Storage.h"
#include "Media.h"
#include "System.h"

int main (int argc, char *argv[]) {
  if ( argc != 2 ){
    cout << "This requires a media file to be loaded." << endl;
    cout << "Usage: ./proj3 proj3_data1.txt" << endl;
    exit(1);
  }
  string fileName = argv[1];
  System mySystem(fileName);
  return 0;
}
