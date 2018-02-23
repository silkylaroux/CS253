CPPFLAGS=-Wall -Werror -Wextra -Wfatal-errors
assignment= hw3
MAKEFILE_LIST = hw3.cc parser.cc printer.cc runner.cc test.h Makefile
SOURCES = hw3.cc parser.cc printer.cc runner.cc unserParser.cc


all:
	g++ $(CPPFLAGS) -o $(assignment) $(SOURCES) 

tar:
	tar -cv $(MAKEFILE_LIST) >$(assignment).tar

