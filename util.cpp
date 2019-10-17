#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "util.h"
#include "heap.h"

using namespace std;

int nextCommand(int *i, int *v, int *f)
{
	char c;
	while (1)
	{
		scanf("%c", &c);
		if (c == ' ' || c == '\t' || c == '\n')
		{
			continue;
		}
		if (c == 'S' || c == 'R' || c == 'W')
		{
			break;
		}
		if (c == 's' || c == 'r' || c == 'w')
		{
			break;
		}
		if (c == 'D' || c == 'd')
		{
			scanf("%d", f);
			break;
		}
		if (c == 'K' || c == 'k')
		{
			scanf("%d", f);
			scanf("%d", i);
			scanf("%d", v);
			break;
		}
		if (c == 'C' || c == 'c')
		{
			scanf("%d", i);
			break;
		}
		if (c == 'I' || c == 'i')
		{
			scanf("%d", f);
			scanf("%d", i);
			break;
		}
		printf("Invalid Command\n");
	}
	return c;
}

//Given a value, returns the next highest power of 2
int nextPower_2(unsigned int x)
{
	int power = 1;
	while(power < x)
	{
		power *= 2;
	}
	return power;
}

//Read content from file and places it into the heap
void readFromFile(Heap *heap)
{
	int size;
	int count = 0;
	string line;
	//Open file
	ifstream myfile ("HEAPinput.txt");
	myfile >> size;
	//Create new element array
	Element *array;
	array = new Element[size];
	//Copy elements from file into element array
	for (int i = 0; i < size; i++)
    {
		myfile >> array[i].key;
    }
	//Find actual size of file
	count = readFileSize();
	if(size > heap->capacity)
    {
		printf("Sorry!!! It cannot be done. Please increase the capacity of heap first. \n");
		return;
    }
	if(size > count)
    {
		printf("Sorry!!! It cannot be done. The number of elements in file is less than as specified in the beginning of file. \n");
		return;
    }
	//Update heap size
	heap->size = size;
	//Call linear time build heap function
	buildHeap(*heap, array, size);
	myfile.close();
}

//Counts how many numbers are in the file
int readFileSize()
{
	int number_of_lines = 0;
	string line;
	ifstream myfile("HEAPinput.txt");
	if(myfile.is_open())
	{
		//Goes through every line in file
		while(!myfile.eof())
		{
			getline(myfile,line);
			//Increment count
			++number_of_lines;
		}
	}
    myfile.close();
    return number_of_lines - 2;
}
