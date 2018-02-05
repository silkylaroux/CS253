CPPFLAGS=-Wall -Werror -Wextra -Wfatal-errors
assignment= hw2
MAKEFILE_LIST = hw2.cc parser.cc test.h Makefile
SOURCES = hw2.cc parser.cc

#$(assignment): $(assignment).o
$(SOURCES): $(SOURCES).o	
	g++ $(CPPFLAGS) $(SOURCES) -o $@ $^

tar:
	tar -cv $(MAKEFILE_LIST) >$(assignment).tar

