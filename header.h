// Project 3b written by Darin Hunt & Ojasvi DSilva
// This is a Header file for Project 3.
// It calls the Grid and Dictionary headers files and builds global functions.

#ifndef Header_h
#define Header_h
#include "grid.h"
#include "dictionary.h"
#include "d_matrix.h"
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

vector <string> vFound;
// Functuon to go down the rows of the matrix.
void checkDown(dictionary &d, grid &g)
{
    
    for (int i=0; i<g.getColumns(); i++) // gets columns
    {
        for (int j=0; j<g.getRows();j++) //gets the rows
        {
            string selected;//string of chars
            selected=g.charMat[i][j];
            int tempdown = i+1;
            int tempdown2=0;
            for (int k = i; k<i+g.getColumns(); k++)
            {
                
                
                if (tempdown==g.getColumns())
                {
                    tempdown=0;
                }
                
                
                selected = selected+ g.charMat[tempdown++][j];
                
                tempdown2++;
                
                
                
                if (tempdown2>=4)
                {
                    d.binarySearch(selected, vFound);// Calls Binary Search Function
                    
                }
                else
                {
                    continue;
                }
                
            }
            
        }
    }
    
}
// Functuon to go right the rows of the matrix.
void checkRight(dictionary &d, grid &g)
{
    
    for (int i=0; i<g.getColumns(); i++)
    {
        for (int j=0; j<g.getRows();j++)
        {
            string selected;
            selected=g.charMat[i][j];
            int tempdown = j+1;
            int tempdown2=0;
            for (int k = i; k<i+g.getColumns(); k++)
            {
                
                
                if (tempdown==g.getColumns())
                {
                    tempdown=0;
                }
                
                selected = selected + g.charMat[i][tempdown++];
                
                tempdown2++;
                
                
                if (tempdown2>=4)
                {
                    d.binarySearch(selected, vFound);
                  
                }
                else
                {
                    continue;
                }
                
            }
            
        }
    }
    
}
// Functuon to go up the rows of the matrix.
void checkUp(dictionary &d, grid &g)
{
    for (int i=g.getColumns()-1; i>=0; i--)
    {
        for (int j=g.getRows()-1;j>=0;j--)
        {
            string selected;
            selected=g.charMat[i][j];
            
            int tempdown = i-1;
            int tempdown2=0;
            for (int k = i; k<i+g.getColumns()-1; k++)
            {
                
                if (tempdown==-1)
                {
                    tempdown=g.getColumns()-1;
                }
                
                
                selected = selected+ g.charMat[tempdown--][j];
                
                tempdown2++;
                
                
                if (tempdown2>=4)
                {
                    d.binarySearch(selected, vFound);
                  
                }
                else
                {
                    continue;
                }
                
            }
            
        }
    }
    
}
// Functuon to go down the left of the matrix.
void checkLeft(dictionary &d, grid &g)
{
    for (int i=g.getColumns()-1; i>=0; i--)
    {
        for (int j=g.getRows()-1;j>=0;j--)
        {
            string selected;
            selected=g.charMat[i][j];
            
            int tempdown = j-1;
            int tempdown2=0;
            for (int k = i; k<i+g.getColumns()-1; k++)
            {
                
                if (tempdown==-1)
                {
                    tempdown=g.getColumns()-1;
                }
               
                
                selected = selected+ g.charMat[i][tempdown--];
               
                tempdown2++;
               
                
                if (tempdown2>=4)
                {
                    d.binarySearch(selected, vFound);
                   
                }
                else
                {
                    continue;
                }
                
            }
            
        }
    }
    
    
}
// Functuon to go down right the rows of the matrix.
void checkDR(dictionary &d, grid &g)
{
    
    for (int i=g.getColumns()-1; i>=0; i--)
    {
        for (int j=g.getRows()-1;j>=0;j--)
        {
            string selected;
            selected=g.charMat[i][j];
            int tempright = j+1;
            int tempright2=0;
            int tempdown = i+1;
            
            for (int k = i; k<i+g.getColumns(); k++)
            {
                
                
                if (tempdown==g.getColumns())
                {
                    tempdown=0;
                }
                
                if (tempright==g.getColumns())
                {
                    tempright=0;
                }
                
                
                selected = selected+ g.charMat[tempdown++][tempright++];
                
                tempright2++;
                
                
                
                if (tempright2>=4)
                {
                    d.binarySearch(selected, vFound);
                  
                }
				else
                {
                    continue;
                }
                
            }
            
        }
    }
}
// Function to go down left the rows of the matrix.
void checkDL(dictionary &d, grid &g)
{
    for (int i=g.getColumns()-1; i>=0; i--)
    {
        for (int j=g.getRows()-1;j>=0;j--)
        {
            string selected;
            selected=g.charMat[i][j];
            int templeft = j-1;
            int templeft2=0;
            int tempdown = i+1;
            
            for (int k = i; k<i+g.getColumns(); k++)
            {
                
                
                if (tempdown==g.getColumns())
                {
                    tempdown=0;
                }
                
                if (templeft==-1)
                {
                    templeft=g.getColumns()-1;
                }
                
                
                selected = selected+ g.charMat[tempdown++][templeft--];
               
                templeft2++;
                
                
                
                if (templeft2>=4)
                {
                    d.binarySearch(selected, vFound);
                   
                }
                else
                {
                    continue;
                }
                
            }
            
        }
    }
}
// Functuon to go up right the rows of the matrix.
void checkUR(dictionary &d, grid &g)
{
    for (int i=g.getColumns()-1; i>=0; i--)
    {
        for (int j=g.getRows()-1;j>=0;j--)
        {
            string selected;
            selected=g.charMat[i][j];
            int tempright = j+1;
            int tempright2=0;
            int tempup = i-1;
            
            for (int k = i; k<i+g.getColumns(); k++)
            {
                
                
                if (tempup==-1)
                {
                    tempup=g.getColumns()-1;
                }
                
                if (tempright==g.getColumns())
                {
                    tempright=0;
                }
                
                
                selected = selected+ g.charMat[tempup--][tempright++];
                
                tempright2++;
                
              
                if (tempright2>=4)
                {
                    d.binarySearch(selected, vFound);
                   
                }
                else
                {
                    continue;
                }
                
            }
            
        }
    }
}
// Functuon to go up left the rows of the matrix.
void checkUL(dictionary &d, grid &g)
{
    
    for (int i=g.getColumns()-1; i>=0; i--)
    {
        for (int j=g.getRows()-1;j>=0;j--)
        {
            string selected;
            selected=g.charMat[i][j];
            int templeft = j-1;
            int templeft2=0;
            int tempup = i-1;
            
            for (int k = i; k<i+g.getColumns(); k++)
            {
                
                
                if (tempup==-1)
                {
                    tempup=g.getColumns()-1;
                }
                
                if (templeft==-1)
                {
                    templeft=g.getColumns()-1;
                }
                
                
                selected = selected+ g.charMat[tempup--][templeft--];
                
                templeft2++;
                
              
                if (templeft2>=4)
                {
                    
                    d.binarySearch(selected, vFound);
                    
                }
                else
                {
                    continue;
                }
                
            }
            
        }
    }
}


// GLobal Function
// Calls the the all 8 check functions to find words.
void findMatches(dictionary &d, grid &g)
{
    
    checkDown(d,g);
    checkRight(d,g);
    checkUp(d,g);
    checkLeft(d,g);
    checkDR(d,g);
    checkDL(d,g);
    checkUR(d,g);
    checkUL(d,g);
    
    
    
    ofstream fout1(("Words_found.txt"));
    for (int p=0; p<vFound.size(); p++)
    {
        cout << vFound[p] << endl;// prints the words found
        fout1 << vFound[p] << endl;// prints the words found
    }
    
}

//Global Function

void search(dictionary &d1) //takes in name of file from keyboard and checks it for words
{
    
   // Ask user to select sort methord 
    int sort;
    cout << "What sorting algorithm would you like to use? 1.) Selection Sort 2.) Quick Sort 3.) Heap Sort" << endl;
    cin>>sort;
    
    
    ofstream fout2("Sorted Dictionary.txt");
    ofstream fout3("QuickSorted Dictionary.txt");
    ofstream fout4("Heapsorted Dictionary.txt");
    switch (sort)
    {
        case 1: // Calls selectionsort
        {
            d1.selectionSort(); // speed = 77.95 seconds.
            fout2 << d1;
            break;
        }
            
        case 2: // calls quicksort
        {
            int size = d1.dWords.size() - 1;
            d1.quickSort(0, size); // speed = 3.492 seconds. Fastest Sort
            fout3 << d1;
            break;
        }

        case 3: // calls heapsort
        {
            d1.heapSort(); // Speed = 5.278 seconds. 
            fout4 << d1;
            break;
        }
    }
    
  
    
    ifstream fin; //input stream object
    int file; //will be the inputed name of file
    
    cout << "Pick an option: " << endl << "1.) 15x15 matrix" << endl << "2.) 30x30 matrix" << endl << "3.) 50x50 matrix" << endl;//Asks user
    cin>>file;
    
    grid mtrx(file);// takes number and selects matri
    
    findMatches(d1, mtrx);// calls the find matchs.
    fin.close();
}



#endif /* header_h */
