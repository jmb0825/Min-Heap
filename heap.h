#ifndef HEAP_H
#define HEAP_H

//Create the Heap data type
struct Heap
{
	//create size field for size of heap
	int size;
	//create capacity field for the maximum size of the heap
	int capacity;
	//Pointer the struct element;
	struct Element *H;
};
//Create the element data type
struct Element
{
	//Create the field named key
	int key;
};

//Definition of functions to be implemented in heap.cpp
//Initialize function takes in integer n, creates a heap with capacity
//given and size 0
Heap initialize(int n);
//buildHeap function builds a min heap given a heap object, an array
//of type Element, and a size n
void buildHeap(Heap heap, Element A[], int n);
//Inserts an element with key k into the heap
void insert(Heap * heap, int flag, int k);
//Deletes the element with the min key and returns to caller.
int deleteMin(Heap *heap, int flag);
//Decreases the key at index to value given and maintains heap order
void decreaseKey(Heap heap, int flag, int index, int value);
//Prints out all heap information
void printHeap(Heap heap);
//Performs min-heapify operation from x onwards
void heapify(Heap heap, int x);
//Returns the parent node of the given node
int parent(int x);
//Returns the left child of the given node
int leftChild(int x);
//Returns the right child of the given node
int rightChild(int x);
//Exchanges the two nodes pointed to by that parameters
void exchange(int *a, int *b);

#endif
