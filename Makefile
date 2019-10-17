EXEC = run
CC = g++
CFLAGS = -c -Wall

# $(EXEC) has the value of shell variable EXEC, which is run.
# run depends on the files main.o util.o heap.o
$(EXEC) :main.o util.o heap.o
	$(CC) -o $(EXEC) main.o util.o heap.o

# main.o depends on the files main.h main.cpp
main.o: main.h main.cpp
	$(CC) $(CFLAGS) main.cpp

# util.o depends on the files util.h util.cpp
util.o :util.h util.cpp
	$(CC) $(CFLAGS) util.cpp

# heap.o depends on the files heap.h heap.cpp
heap.o :heap.h heap.cpp
	$(CC) $(CFLAGS) heap.cpp

clean :
	rm *.o
