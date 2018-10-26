// Project 3a written by Darin Hunt & Ojasvi DSilva
// This is a Header file for Project 3. 
// It creates Dictionary and builds the function of the class

#ifndef dictionary_hpp
#define dictionary_hpp
#include <iostream>
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
    void selectionSort();//Sorts the dictionary 
    void binarySearch(string target, vector <string> &found);//Searchs for word in dictionary
    vector <string> dWords;//stores dictionary words
private:
    int dictionarySize;
};


dictionary::dictionary(/*dictionary size file, int n (dictionary size)*/)
{
    //initialize
//    dictionarySize=n;
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
