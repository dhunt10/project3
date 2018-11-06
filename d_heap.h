// Project 3b written by Darin Hunt & Ojasvi DSilva
//THis is a header file for Project 3.
// It builds the heap class and builds it functions. 

#ifndef HEAP_CLASS
#define HEAP_CLASS
#include <vector>
#include <iostream>
#include <string>
#include <math.h> 
using namespace std;

template <typename T>

class heap
{
public:
	heap(); // Constructor
	// Heap Storage
	int parent(int n); // Parent of heap
	int left(int n) ; // left child of heap
	int right(int n);// right child of heap
	T getItem(int n); // Getting Item
	void initializeMaxheap(vector<T> data); // Takes unsorted vector
	void maxheapify(int n);// Maintain Heap Property 
	void buildMaxheap();// Builds Max Heap
	void heapSort(); // Sorts the Heap
	vector<T> heaplist;

private:
 	
	int heapsize;
};




template <typename T>
heap<T>::heap()
{
		
	
}
// Heap Storage
template <typename T>
int heap<T>::parent(int n)
{ 
return n/2; 
}


template <typename T>
int heap<T>::left(int n) 
{
 return 2*n;
}

template <typename T>
int heap<T>::right(int n) 
{
return 2*n+1;
}

template <typename T>
T heap<T>::getItem(int n)
{
return T(heaplist[n]);
}



	
// Max Heapify FUnction 

template <typename T>
void heap<T>::maxheapify(int n)
{
	// Children index
	int l = left(n); // set left child
	int r = right(n); // set right child
	int largest;
	// check if nodes left and right are in the hoop
	//checks if they do not satisfy heap property
        if (l <= heapsize && heaplist[l] > heaplist[n])
    {
        largest = l;
    }
    
    else
        largest = n;
    
    if (r <= heapsize && heaplist[r] > heaplist [largest])
    {
        largest = r;
    }
    
    if (largest != n) // "float down"
    {
        swap(heaplist[n], heaplist[largest]);
        maxheapify(largest); // Recursive Function Call
    }
}
// BuildMaxheap function 
template <typename T>
void heap<T>::buildMaxheap()
{
    for (int i=floor(heapsize/2); i>=1; i--)
    {
        maxheapify(i);
    }
}
// initialize Max Heap
template <typename T>
void heap<T>::initializeMaxheap(vector<T> data)
{
	heaplist.resize(data.size()); // Resiszes Heap Vector
	 for (int i=0; i<data.size(); i++)
    {
        
		heaplist.push_back(data[i]);// Copys Dictionary into Heap
        
    }
    buildMaxheap();
    heapsize = heaplist.size() - 1;
	
}
// Heapsort Function 
template <typename T>
void heap<T>::heapSort()
{
    buildMaxheap();// Ensure it is a max heap
    
    for (int i = heapsize; i>=2; i--)
    {
        swap(heaplist[1],heaplist[i]); // heaplist[1] = root
        heapsize--; //removes the root which is the largest valueFamilyguy10
        
        maxheapify(1);
    }
}

#endif	// heap<T>_CLASS 

