#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <stdlib.h>
#include <math.h> 
#include "util.h"
#include "heap.h"

using namespace std;

//Initialize function takes in integer n, creates a heap with capacity
//given and size 0
Heap initialize(int n)
{
	//Create new heap
	struct Heap heap;
	//Initialize struct components
	heap.size = 0;
	heap.capacity = n;
	//Allocate the appropriate amount of memory
	heap.H = (Element *) malloc(sizeof(Element) *heap.capacity);
	return heap;
}

//Inserts an element with key k into the heap
void insert(Heap * heap, int flag, int k)
{
	//check if heap has reached capacity
	if (heap->size == heap->capacity)
	{
		//reallocate memory if necessary
		heap-> capacity = nextPower_2(heap->capacity + 1);
		heap->H = (Element *) realloc(heap->H,sizeof(Element) * heap->capacity);
		
	}
	int index = heap->size;
	heap->size = heap->size + 1;
	//Properties of min heap checked
	while (index > 0 && heap->H[parent(index)].key > k)
	{
		heap->H[index].key = heap->H[parent(index)].key;
		index = parent(index);
	}
	//insert key
	heap->H[index].key = k;
	if (flag == 2)
	{
		//Print heap content
		printHeap(*heap);
	}
}

//buildHeap function builds a min heap given a heap object, an array
//of type Element, and a size n
void buildHeap(Heap heap, Element A[], int n)
{
	//builds heap initially
	for(int i = 0; i < heap.size; i++)
    {
		heap.H[i].key = A[i].key;
    }
	//performs min heapify on heap
	for(int i = floor(heap.size/2); i >= 0; i--)
    {
		heapify(heap, i);
    }
}

//Deletes the element with the min key and returns to caller.
int deleteMin(Heap *heap, int flag)
{
	//Check if heap empty
	if (heap->size <= 0)
	{
		printf("There are no elements in heap to delete. \n");
	}
	if(flag !=1 && flag != 2)
	{
		printf("This is not a valid flag value. This operation cannot be completed. \n");
	}
	if (flag == 2)
	{
		//Print heap content
		printHeap(*heap);
	}
	//If heap only has one element, delete it
	if (heap->size == 1)
	{
		heap->size = heap->size -1;
		return heap->H[0].key;
	}
	//Keep the min value here
	int minValue = heap->H[0].key;
	if(heap->size > 1)
	{
		//Shift heap elements
		heap->H[0].key = heap->H[heap->size - 1].key;
		heap->size = heap->size - 1;
		//Ensure that heap is heapified
		heapify(*heap, 0);
	 }
	if (flag == 2)
	{
		//Print heap content
		printHeap(*heap);
	}	
    //Return deleted value
	return minValue;

}
//Decreases the key at index to value given and maintains heap order
void decreaseKey(Heap heap, int flag, int index, int value)
{
	if(index == 0)
    {
		printf("Invalid index. \n");
		return;
    }
	if(index > heap.size)
    {
		cout << "There are only " << heap.size << " elements in the heap. Hence this operation cannot be completed." << endl;
		return;
    }
	//Adjust for index from one
	int oneIndexed = index - 1;
	if (value > heap.H[oneIndexed].key)
	{
		//Error given, new value is greater than key
		cout << value << " cannot be larger than the current value in the heap at index " << index << ". Hence this operation cannot be completed. \n";
		return;
	}
	if (flag == 2)
	{
		//Print heap content
		printHeap(heap);
	}
	//Set index to new key
	heap.H[oneIndexed].key = value;
	//Maintain heap order
	while (index != 0 && heap.H[parent(oneIndexed)].key > heap.H[oneIndexed].key)
	{
		exchange(&heap.H[oneIndexed].key, &heap.H[parent(oneIndexed)].key);
		oneIndexed = parent(oneIndexed);
	}
	if (flag == 2)
	{
		//Print heap content
		printHeap(heap);
	}
}

//Prints out all heap information
void printHeap(Heap heap)
{
	cout << "The capacity is " << heap.capacity << "." << endl;
	cout << "Size is " << heap.size << "." << endl;
	//Print heap content
	for (int x = 0; x < heap.size; x++)
	{
		cout << heap.H[x].key << endl;
	}
}
//Performs min-heapify operation from x onwards
void heapify(Heap heap ,int x )
{
	int left = leftChild(x);
	int right = rightChild(x);
	int smallest;
	//Compares left child to current index
	if(left < heap.size && heap.H[left].key < heap.H[x].key)
    {
      smallest = left;
    }
	else
    {
      smallest = x;
    }
	//Compares right child to current index
	if(right < heap.size && heap.H[right].key < heap.H[smallest].key)
    {
      smallest = right;
    }
	//Exchanges the two values
	if(smallest != x)
    {
      exchange(&heap.H[x].key, &heap.H[smallest].key);
      heapify(heap, smallest);
    }
}

//Returns the parent node of the given node
int parent(int x)
{
	int value;
	value = (x-1)/2;
	return value;
}

//Returns the left child of the given node
int leftChild(int x)
{
	int value;
	x++;
	value = 2 * x - 1;
	return value;
}

//Returns the right child of the given node
int rightChild(int x)
{
  x++;
	int value = 2 * x;
	
	return value;
}

//Exchanges the two nodes pointed to by that parameters
void exchange(int *a, int *b)
{
  int store = *a;
  *a = *b;
  *b = store;
}
