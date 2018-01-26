CPPFLAGS=-Wall -Werror -Wextra -Wfatal-errors
assignment=hw1

$(assignment): $(assignment).o
	g++ $(CPPFLAGS) -o $@ $^

tar:
	tar -cv $(MAKEFILE_LIST) *.cc >$(assignment).tar

