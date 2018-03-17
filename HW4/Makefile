CXXFLAGS=-Wall -Werror -Wextra -Wfatal-errors
assignment= hw4
MAKEFILE_LIST = hw4.cc parser.cc printer.cc unserParser.cc runner.cc test.h unserParser.h runner.h Makefile
SOURCES = hw4.cc parser.cc printer.cc runner.cc unserParser.cc
OSOURCES = hw4.o parser.o printer.o runner.o unserParser.o

$(assignment): $(assignment).o
	g++ $(CXXFLAGS) -c $(SOURCES)
	ar rcs $(assignment).a $(OSOURCES)
tar:
	tar -cv $(MAKEFILE_LIST) >$(assignment).tar

clean:
	rm -f $(assignment) $(assignment).ar *.o *.gch