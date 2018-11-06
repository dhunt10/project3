// Project 3b written by Darin Hunt & Ojasvi DSilva
// This is a Header file for Project 3.
// It creates Dictionary and builds the function of the class

#ifndef dictionary_hpp
#define dictionary_hpp
#include <iostream>
#include "d_heap.h"
#include <vector>
#include <fstream>
#include <stdio.h>
using namespace std;

class dictionary
{
public:
    dictionary(/*dictionary size file, int n (dictionary size)*/);
    void readword(); // reads the words from the dictionary.txt
    friend ostream& operator << (ostream& ostr, const dictionary &rhs);//prints dictionary
    void selectionSort();//Sorts the dictionary using selection sort
    void binarySearch(string target, vector <string> &found);//Searchs for word in dictionary
    void quickSort( int left, int right); // Sorts dictionary using quick sort
    int partition( int p, int r);// Partition function called in quick sort
    vector <string> dWords;//stores dictionary words
    void heapSort(); // Sort Dictionary using heap sort
    
private:
    int dictionarySize;// Size of Dictionary
};

dictionary::dictionary()
{
    
}

void dictionary::readword()
{
    /*initialize ifstream object to go through dictionary file,
     for loop that goes through file and adds the word into private data member vector
     using the dWord.push_back() function; */
    ifstream infile;
    string data;
    infile.open("Dictionary.txt"); // Reads dictionary text
    
    while(infile >> data)
    {
        dWords.push_back(data);
    }
    
    infile.close();
    
    
}





ostream& operator << (ostream& ostr, const dictionary &rhs)
{
    /*for loop size of the dictionary, need to make size of dictionary private data member
     ostr << dWords[i] << endl;*/
    for (int i=0; i<rhs.dWords.size(); i++)
    {
        ostr << rhs.dWords[i] << endl;
    }
    return ostr;
}

void dictionary::selectionSort()
{
    int n = dWords.size(); //Sets N to size of dictionary.
    
    int min;
    //Selection Sort
    for (int i=0; i<=n-2; i++) // n-1 steps
    {
        min=i; //intial as final elemnt
        // scanning unsorted sublist
        
        for (int j=i+1; j<=n-1; j++)
        {
            if (dWords[j]<dWords[min])
            {
                min=j;   //good
            }
            
        }
        swap(dWords[i], dWords[min]);// putting DWords[min] in friend position
    }
}

// Partition function 
int dictionary::partition( int p, int r)
{
    string x = dWords[r]; // Selecting Pivot
    int i = p-1;
    
    // Divide against Pivot
    for (int j = p; j<=r-1; j++)
    {
        if (dWords[j]<= x)
        {
            i++;
            swap(dWords[i], dWords[j]);
        }
    }
    swap(dWords[i+1], dWords[r]);
    return (i+1); // return partitionn 
}

void dictionary::quickSort( int left, int right)
{
    int s;
    if (left<right) // check if there are elements 
    {
        s = partition(left, right);// select pivot. Rearranges vector
        // Recursive Function Call
        quickSort(left, (s-1));
        quickSort((s+1), right);
        
    }
    
    
}
// Call Heapsort 
void dictionary::heapSort()
{
    heap<string> newHeap;
    newHeap.initializeMaxheap(dWords); // Copys unsorted dictionary into heap
    newHeap.heapSort();	// Sorts the dictionary
    dWords=newHeap.heaplist; // copy the sorted words out 
    
}

void dictionary::binarySearch(string target, vector <string> &found)
{
    // Binary search
    string midValue;
    int first = 0;
    int mid;
    int last;
    last = dWords.size();
    while (first<=last)
    {
        
        mid = (first + last)*0.5; // Setting mid values
        midValue=dWords[mid]; //setting words in dictionary vector
        
        
        if (target==midValue)// if word in Matrix equals MidValue Word, print the word.
        {
            // cout << target << endl;
            found.push_back(target);
            //cout << "target     " << target << "     midvalue    " << midValue << endl;
            break;
        }
        else if (target<midValue) // If smaller than midvalue word go to word before
        {
            last = mid-1;
            if (last == -1)
            {
                break;
            }
            
        }
        else if (target>midValue)// if great than midValue word go to word after
        {
            first=mid+1;
            if (first == dWords.size())
            {
                break;
            }
            
        }
        
        
        
    }
}



#endif /* dictionary_hpp */
