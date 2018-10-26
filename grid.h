// Project 3a written by Darin Hunt & Ojasvi DSilva
// This is a Header file for Project 3. 
// It creates Grid and builds the function of the class

#ifndef grid_hpp
#define grid_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "d_matrix.h"
#include "d_except.h"


using namespace std;

class grid
{
    
public:
    grid(int file);
    void readLetters(); //reads letters in a file and stores them in chargrid
    matrix <char> charMat;// Creates Matrix to store file
    int getRows();// gets rows of matrix
    int getColumns(); // gets columns of matric
    
private:
     //matrix <string> chargrid(n,m); //include matrix header file
     ifstream fin; // in put matrix.
     int column, row; // stores matrix and rows
     char ch_data;// stores matrix letters
     
     
};

// gets rows anf columns
int grid::getColumns()
{
	return column;
}

int grid::getRows()
{
	return row;
}
// Selects matrix chosen by user
grid::grid(int file)
{

      if (file == 1)
    {
        fin.open("15x15.txt");
    }
    
    else if (file==2)
    {
        fin.open("30x30.txt");
    }
    
    else if (file==3)
    {
        fin.open("50x50.txt");
    }

    if (!fin)
    {
        cout << "invalid file" << endl;
    }
    cout << "assigned" << endl;
    fin >> column >> row;// Takes column and row numbers
    cout << row << " " <<  column << endl;
    
    readLetters();
    


}
//reads the matrix characters and stores them into matrix. 
void grid::readLetters()
{
	
	charMat.resize(column,row);
 	for (int i=0; i<column; i++)
 	{
 		for (int j=0; j<row; j++)
 		{
 			fin >> charMat[i][j];
 			
		 }
	 }
	
	 fin.close();


	for (int k=0; k<charMat.rows(); k++)
	{
		for (int l=0; l< charMat.cols(); l++)
		{
			cout << charMat[k][l] << "  ";
		}
		cout << endl;
	}
}






#endif /* grid_hpp */
