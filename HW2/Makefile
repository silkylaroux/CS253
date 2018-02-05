CPPFLAGS=-Wall -Werror -Wextra -Wfatal-errors
assignment= hw2
MAKEFILE_LIST = hw2.cc parser.cc printer.cc test.h Makefile
SOURCES = hw2.cc parser.cc printer.cc


all:
	g++ $(CPPFLAGS) -o $(assignment) $(SOURCES) 

tar:
	tar -cv $(MAKEFILE_LIST) >$(assignment).tar

