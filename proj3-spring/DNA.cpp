// NAME: DNA.cpp
// AUTHOR: Joshua Julian Tanseco
// DATE: 3/28/17
// SECTION: 19
// EMAIL: tanseco1@umbc.edu
// DESCRIPTION: THIS FILE CONTAINS THE MAIN FUNCTIONS FOR THE DNA CLASS
// IN PROJECT 3

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "DNA.h"


using namespace std;


//Name: DNA() Default constructor
//Precondition: None
//Postcondition: A linked list for the DNA where m_head and m_tail
//               Points to NULL
DNA::DNA(){
  m_head = NULL;
  m_tail = NULL;

  m_size = 0;

}



//Name: ~DNA() (Destructor)
//Precondition: a filled linked list
//Postcondition: the members of the node are deleted
DNA::~DNA(){

  //deletes member function
  delete m_head;
  m_head = NULL;

  delete m_tail;
  m_tail = NULL;

}



//Name: InsertEnd()
//Precondition: A character (amino acid) loaded from a file
//Postcondition: Character is added to the linked list DNA
void DNA::InsertEnd(char payload){

  //makes temp nucleotide from given payload
  Nucleotide *temp = new Nucleotide();
  temp -> m_payload = payload;
  temp -> m_next = NULL;


  //adds temp nucleotide if first node in linked list
  if (IsEmpty()){
    m_head = temp;
    m_tail = temp;

  }else {
    //adds temp nucleotide if not first node in linked list
    m_tail -> m_next = temp;
    m_tail = temp;

  }

}




//Name: Display()
//Precondition: filled linked list
//Postcondition: the amino acid chain is displayed
void DNA::Display(int numStrand){


  //makes temporary node
  Nucleotide *CURR;

  cout << "Base Pairs:" << endl;

  //prints out each payload if the user only wants just the nucleotide
  if (numStrand == 1){
    for (CURR = m_head; CURR != NULL; CURR = CURR -> m_next){

      cout << CURR -> m_payload << endl;

    }
  }

  //prints out base pairs if the user wants the base pairs printed
  else {

    for (CURR = m_head; CURR != NULL; CURR = CURR -> m_next) {

      //prints out pair specific to the given nucleotide
      switch (CURR -> m_payload){

      case 'A':
	cout << "A - T" << endl;
	break;

      case 'T':
        cout << "T - A" << endl;
        break;

      case 'C':
        cout << "C - G" << endl;
        break;

      case 'G':
        cout << "G - C" << endl;
        break;
	
      }
    }
  }

  cout << "END" << endl;

  //prints out the amount of nucleotides and trinucleotides
  cout << m_size << " nucleotides listed." << endl;
  cout << m_size / 3 << " trinucleotides listed." << endl;

}



//Name: NumAmino()
//Precondition: given trinucleotide and its name, a filled linked list
//Postcondition: prints out how much of a speicifc trinucleotide
void DNA::NumAmino(string name, string trinucleotide){

  //Initializes temporary nodes
  Nucleotide * CURR;
  Nucleotide * second;
  Nucleotide * third;

  //initializes temporary payloads
  string pay1;
  string pay2;
  string pay3;

  //initializes the trinucleotide string
  string tempTri;
  int counter = 0;

  //iterates through linked list in threes
  for (CURR = m_head;
       CURR != NULL; 
       CURR = third -> m_next){

    second = CURR -> m_next, third = second -> m_next;

    //sets temporary payloads
    pay1 = CURR -> m_payload;
    pay2 = second -> m_payload;
    pay3 = third -> m_payload;

    //sets trinucleotide string
    tempTri = pay1 + pay2 + pay3;

    //increases counter every time the function finds a match
    if (tempTri == trinucleotide){
      counter ++;

    }
  }

  //outputs result
  cout << name << ": " << counter << " identified" << endl;

}


//Name: Sequence()
//Precondition: a linked list
//Postconditions: outputs the amino acid list based on nucleotides
void DNA::Sequence(){

  //initializes temporary nodes
  Nucleotide * CURR;
  Nucleotide * second;
  Nucleotide * third;

  //initializes temporary nucleotide characters
  string pay1;
  string pay2;
  string pay3;

  cout << "Amino Acid List:" << endl;

  //initializes trinucleotide
  string tempTri;

  //iterates through nucleotides in threes
  for (CURR = m_head;
       CURR != NULL;
       CURR = third -> m_next){
    
    second = CURR -> m_next, third = second -> m_next;
    
    //sets temporary payloads
    pay1 = CURR -> m_payload;
    pay2 = second -> m_payload;
    pay3 = third -> m_payload;

    //sets temp trinucleotide string
    tempTri = pay1 + pay2 + pay3;

    //outputs the trinucleotide translated into the amino acid
    cout << Translate(tempTri) << endl;
  }

  cout << "Total Amino Acids Identified: " << m_size / 3 << endl;
}



//Name: Translate()
//Precondition: string of three letters (nucleotide)
//Postcondition: three letters are translated into the name fo a nucleotide
//               or (unknown)
//(GIVEN FUNCTION)
string DNA::Translate(const string trinucleotide){
  if((trinucleotide=="ATT")||(trinucleotide=="ATC")||(trinucleotide=="ATA"))
    return ("Isoleucine");
  else if((trinucleotide=="CTT")||(trinucleotide=="CTC")||(trinucleotide=="CTA")||
          (trinucleotide=="CTG")|| (trinucleotide=="TTA")||(trinucleotide=="TTG"))
    return ("Leucine");
  else if((trinucleotide=="GTT")||(trinucleotide=="GTC")||
          (trinucleotide=="GTA")||(trinucleotide=="GTG"))
    return ("Valine");
  else if((trinucleotide=="TTT")||(trinucleotide=="TTC"))
    return ("Phenylalanine");
  else if((trinucleotide=="ATG"))
    return ("Methionine");
  else if((trinucleotide=="TGT")||(trinucleotide=="TGC"))
    return ("Cysteine");
  else if((trinucleotide=="GCT")||(trinucleotide=="GCC")||
          (trinucleotide=="GCA")||(trinucleotide=="GCG"))
    return ("Alanine");
  else if((trinucleotide=="GGT")||(trinucleotide=="GGC")||
          (trinucleotide=="GGA")||(trinucleotide=="GGG"))
    return ("Glycine");
  else if((trinucleotide=="CCT")||(trinucleotide=="CCC")||
          (trinucleotide=="CCA")||(trinucleotide=="CCG"))
    return ("Proline");
  else if((trinucleotide=="ACT")||(trinucleotide=="ACC")||
          (trinucleotide=="ACA")||(trinucleotide=="ACG"))
    return ("Threonine");
  else if((trinucleotide=="TCT")||(trinucleotide=="TCC")||
          (trinucleotide=="TCA")||(trinucleotide=="TCG")||
          (trinucleotide=="AGT")||(trinucleotide=="AGC"))
    return ("Serine");
  else if((trinucleotide=="TAT")||(trinucleotide=="TAC"))
    return ("Tyrosine");
  else if((trinucleotide=="TGG"))
    return ("Tryptophan");
  else if((trinucleotide=="CAA")||(trinucleotide=="CAG"))
    return ("Glutamine");
  else if((trinucleotide=="AAT")||(trinucleotide=="AAC"))
    return ("Asparagine");
  else if((trinucleotide=="CAT")||(trinucleotide=="CAC"))
    return ("Histidine");
  else if((trinucleotide=="GAA")||(trinucleotide=="GAG"))
    return ("Glutamic acid");
  else if((trinucleotide=="GAT")||(trinucleotide=="GAC"))
    return ("Aspartic acid");
  else if((trinucleotide=="AAA")||(trinucleotide=="AAG"))
    return ("Lysine");
  else if((trinucleotide=="CGT")||(trinucleotide=="CGC")||(trinucleotide=="CGA")||
          (trinucleotide=="CGG")||(trinucleotide=="AGA")||(trinucleotide=="AGG"))
    return ("Arginine");
  else if((trinucleotide=="TAA")||(trinucleotide=="TAG")||(trinucleotide=="TGA"))
    return ("Stop");
  else
    cout << "returning unknown" << endl;
  return ("Unknown");
}



//Name: IsEmpty()
//Precondition: an initialized linked list.
//Postcondition: returns true or false based on if the linked is list is/isn't
//               empty.
bool DNA::IsEmpty(){

  //if its empty
  if (m_head == NULL){
    return true;
  } 
  //if it's not empty
  else {
    return false;
  }

}



//Name: SizeOf()
//Precondition: an initialized linked list.
//Postcondition: returns the size of the list
void DNA::SizeOf(){

  //initializes temporary node
  Nucleotide *CURR;
  
  //sets size to zero before counting
  m_size = 0;

  //iterates through linked list, counting each node
  for (CURR = m_head; CURR != NULL; CURR = CURR -> m_next){

    m_size ++;
  }
}



//Name: Clear()
//Precondition: an initialized and loaded linked list
//Postcondition: linked list is cleared and deleted
void DNA::Clear(){

  Nucleotide *CURR;
  Nucleotide *second;

  //iterates through linked list
  for (CURR = m_head;
       CURR != NULL;
       CURR = second) {

    second = CURR -> m_next;

    //deletes node
    delete CURR;
  }
}
