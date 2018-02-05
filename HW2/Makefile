CPPFLAGS=-Wall -Werror -Wextra -Wfatal-errors
assignment= hw2
MAKEFILE_LIST = hw2.cc parser.cc test.h Makefile

$(assignment): $(assignment).o
	g++ $(CPPFLAGS) parser.cc -o $@ $^

tar:
	tar -cv $(MAKEFILE_LIST) >$(assignment).tar

