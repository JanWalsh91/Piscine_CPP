#include "Cat.hpp"

void leave(int sig);

int main ( int ac, char** av ) {
	Cat cat;
	
	if (ac == 1) {
		cat.handleArg("-");
	}
	else {
		for (int i = 1; i < ac; i++) {
			cat.handleArg(av[i]);
		}
	}
}