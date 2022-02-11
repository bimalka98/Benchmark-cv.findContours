# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = gcc
CFLAGS  = -g -Wall

output: main.o dsa.o tsa.o utilities.o
	$(CC) $(CFLAGS) main.o dsa.o tsa.o utilities.o -o output

main.o: main.c dsa.h tsa.h utilities.h
	$(CC) $(CFLAGS) -c main.c

dsa.o: dsa.c dsa.h
	$(CC) $(CFLAGS) -c dsa.c

tsa.o: tsa.c  tsa.h 
	$(CC) $(CFLAGS) -c tsa.c

utilities.o: utilities.c utilities.h
	$(CC) $(CFLAGS) -c utilities.c

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	rm *.o output 
