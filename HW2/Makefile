CPPFLAGS=-Wall -Werror -Wextra -Wfatal-errors
assignment= hw2
MAKEFILE_LIST = hw2.cc parser.cc test.h Makefile
SOURCES = hw2.cc parser.cc
ass = parser

$(assignment): $(ass).o
	g++ $(CPPFLAGS) -o $(assignment) $(SOURCES) 
	
$(ass): $(assignment).o
	g++ $(CPPFLAGS) -o $(assignment) $(SOURCES) 

tar:
	tar -cv $(MAKEFILE_LIST) >$(assignment).tar

