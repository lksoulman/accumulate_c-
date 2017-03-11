COMPILER      = -c++
OPTIONS       = -ansi -pedantic -Wall -o
OPTIONS_LIBS  = -ansi -pedantic -Wall -c

all: hashfunc.o hashtest

hashfunc.o: hashfunc.cpp hashfunc.h
	$(COMPILER) $(OPTIONS_LIBS) hashfunc.cpp

hashtest: hashfunc.o hashtest.cpp
	$(COMPILER) $(OPTIONS) hashtest hashtest.cpp hashfunc.o


clean:
	rm -f core *.o *.bak *stackdump *#
  
