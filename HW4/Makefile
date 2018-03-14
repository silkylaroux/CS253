CXXFLAGS=-Wall -Werror -Wextra -Wfatal-errors
assignment= hw4
MAKEFILE_LIST = hw4.cc parser.cc printer.cc unserParser.cc runner.cc test.h unserParser.h runner.h Makefile
SOURCES = hw4.cc parser.cc printer.cc runner.cc unserParser.cc

all:
	g++ $(CPPFLAGS) -o $(assignment).o $(SOURCES)
	ar rcs $(assignment).a $(assignment).o 

tar:
	tar -cv $(MAKEFILE_LIST) >$(assignment).tar

clean:
	rm -f $(assignment) $(assignment).ar *.o *.gch