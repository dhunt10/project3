// Project 3b written by Darin Hunt & Ojasvi DSilva
// This is the CPP file for Project 3.
// It build class dictionary and grid
// It calls the dictionary and the reads dictionary. Then calls the search function.


#include <iostream>
#include "dictionary.h"
#include "grid.h"
#include "Header.h"
#include <fstream>

using namespace std;

int main()
{
   // Creat dictionnary 
    dictionary d1;
    d1.readword();
    // Call global function Searth
    search(d1);
    
   
}
