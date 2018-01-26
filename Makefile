CPPFLAGS=-Wall -Werror -Wextra -Wfatal-errors
assignment=hw0

$(assignment): $(assignment).o
	g++ $(CPPFLAGS) -o $@ $^

tar:
	tar -cv $(MAKEFILE_LIST) *.cc >$(assignment).tar

