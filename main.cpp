#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <stdio.h>
#include "heap.h"
#include "util.h"

using namespace std;

Element *element;
//Ensures that the file exists
bool fexists(const char *filename)
{
	ifstream ifile(filename);
	return (bool)ifile;
}
int main()
{
	char c;
	int i, v, f;
	Heap heap;

	bool heapCreated = false;
	while (1)
	{
		c = nextCommand(&i, &v, &f);
		switch (c)
		{
		//Exit
		case 's':
		case 'S': 
			printf("COMMAND: %c. \n", c);
			printf("The program is going to be terminated. \n");
			exit(0);
		//Decrease key
		case 'k':
		case 'K': 
			printf("COMMAND: %c %d %d %d. \n", c, f, i, v);
			if(f<1 || f > 2)
			  {
			    printf("This is not a valid flag value. This operation cannot be completed. \n");
			    break;
			  }
			if (heapCreated == false)
			{
				printf("Sorry!!! It cannot be done. Please initialize the heap first and put the elements into it. \n");
			}
			else
			{
				decreaseKey(heap, f, i, v);
			}
			break;
		//Read from file
		case 'r':
		case 'R':
			printf("COMMAND: %c. \n", c);
			if (fexists("HEAPinput.txt"))
			{
			  if(heapCreated == false)
			    {
			      printf("Sorry!!! It cannot be done. Please initialize the heap first. \n");
			      break;
			    }
			  else 
			    {
				readFromFile(&heap);
				break;
			    }
			}
			else
			{
				printf("There was a problem opening file HEAPinput.txt for reading. \n");
				break;
			}
		//Display heap information
		case 'w':
		case 'W':
			printf("COMMAND: %c. \n", c);
			if (heapCreated == false)
			{
				printf("Sorry!!! It cannot be done. Please initialize the heap first. \n");
			}
			else
			{
				printHeap(heap);
			}
			break;
		//Insert a value into heap
		case 'i':
		case 'I':
			printf("COMMAND: %c %d %d. \n", c, f, i);
			if(f != 1 && f != 2)
			  {
			    printf("This is not a valid flag value. This operation cannot be completed. \n");
			    break;
			  }
			if (heapCreated == false)
			{
				printf("Sorry!!! It cannot be done. Please initialize the heap first. \n");
			}
			else
			{
			  if(f == 2)
			    {
			      printHeap(heap);
			    }
				insert(&heap, f, i);
			}
			break;
		//Delete minimum value
		case 'd':
		case 'D':
			printf("COMMAND: %c %d. \n", c, f);
			if (heapCreated == false)
			{
				printf("Sorry!!! It cannot be done. Please initialize the heap first and put the elements into it. \n");
			}
			else if (heap.size <= 0)
			{
				printf("There are no elements in heap to delete. \n");
			}
			else
			{
				int value = deleteMin(&heap, f);
				printf("%d \n", value);
			}
			break;
		// Initialize heap
		case 'c':
		case 'C':
			printf("COMMAND: %c %d. \n", c, i);
			if (i > 0)
			{
				heap = initialize(i);
				heapCreated = true;
			}
			else 
			{
				printf("Capacity cannot be negative. \n");
			}
			break;
		default:
			break;
		}
	}
	return 0;
}
