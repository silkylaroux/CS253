CPPFLAGS=-Wall -Werror -Wextra -Wfatal-errors
assignment= hw2
MAKEFILE_LIST = hw2.cc Makefile

$(assignment): $(assignment).o
	g++ $(CPPFLAGS) -o $@ $^

tar:
	tar -cv $(MAKEFILE_LIST) >$(assignment).tar

