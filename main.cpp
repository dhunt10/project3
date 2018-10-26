// Project 3a written by Darin Hunt & Ojasvi DSilva
// This is the CPP file for Project 3. 
// It build class dictionary and grid
// It calls the dictionary and prints the sorted dictionary. Then calls the search function. 


#include <iostream>
#include "dictionary.h"
#include "grid.h"
#include "header.h"
#include <fstream>

using namespace std;

int main()
{
    ofstream fout("Unsorted Dictionary.txt");
    ofstream fout2("Sorted Dictionary.txt");
    dictionary d1;
    d1.readword();// Reads the dictionary file
    //cout << d1;
     fout << d1;// Prints unsorted dictionary 
   d1.selectionSort();
   fout2 << d1;//Prints sorted dictionary
   search(d1);

    //cout << d1;
}
