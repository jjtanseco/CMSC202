#include "File.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void populateDirectory(vector<File>&);
// fill vector - fills file info
// @param vector<File>& - files in directory
void printDirectory(vector<File>&);
//printDirectory - prints the information of the files in the directory
//@param const vector<File>& files in directory 

int main () {
	//Creates a new directory of files
  vector<File> myDirectory;
	//Populates the vector
  populateDirectory(myDirectory);
  //Prints the contents of the vector
  printDirectory(myDirectory);
  return 0;
}

void populateDirectory(vector<File>& newDirectory) {
  
  //Write this function
  //Needs to ask how many files
  cout << "How many files are in the directory?:" << endl;
  int direcSize;
  cin >> direcSize;
  //Gets file name, file type, and file size
  for (int i = 0; i< direcSize; i++){
    string tempName, tempType;
    int tempSize;

    cout << "File " << (i + 1) << endl;
    cout << "File Name: " << endl;
    cin >> tempName;
    
    cout << "File Type: " << endl;
    cin >> tempType;
    
    cout << "File Size (in kB): " << endl;
    cin >> tempSize;
    
    File myFile;
    myFile.SetFileName(tempName);
    myFile.SetFileType(tempType);
    myFile.SetFileSize(tempSize);

    newDirectory.push_back(myFile);

  }

  //Uses the overloaded constructor for the file
  //Needs to add files to the directory vector
}

void printDirectory(vector<File>& newMyFile){
  //Needs to loop through the directory of files and outputs the information
  for (int i = 0; i < (int) newMyFile.size(); i++){

    File tempFile = newMyFile.at(i);

    cout << "File Name: " << tempFile.GetFileName() << endl;
    cout << "File Type: " << tempFile.GetFileType() << endl;
    cout << "File SIze: " << tempFile.GetFileSize() << endl;
    cout << " " << endl;

  }

}
