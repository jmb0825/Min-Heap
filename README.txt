Author: Jacob Babik

Language: C++
Compiler: g++

Files included: main.h, main.cpp, util.h, util.cpp, heap.h, heap.cpp

Description: This program is an implementation of the min-heap data structure. User commands are as follows:

On reading S, the program stops. On reading C n, the program creates an empty heap with capacity equal to n,
and waits for the next command. On reading R, the program reads in the array A from ﬁle HEAPinput.txt, calls
the build heap algorithm to build the min-heap based on A, and waits for the next command. On reading W, the
program writes the current heap information to the screen, and waits for the next command. On reading I f k,
the program inserts an element with key equal to k into the current heap with the corresponding ﬂag set to f.
On reading D f, the program deletes the minimum element from the heap with the corresponding ﬂag set to f,
and prints the key ﬁeld of the deleted element on the screen, and then waits for the next command. When the
flag is set to 2 for any operation, the program prints the heap content before that operation. When the flag
is set to 1 no there is no additional printing.

An example HEAPinput.txt file is given. The ﬁrst line of the ﬁle contains an integer n, which indicates the
number of array elements to be read in. The next n lines contain n integers, one integer per line. These
integers are the key values of the n array elements, from the ﬁrst element to the nth element.
