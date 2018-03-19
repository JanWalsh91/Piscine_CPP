#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>

Base *	generate( void );
void	identify_from_pointer( Base * p );
void	identify_from_reference( Base & p );

int    main ( void ) {
	std::srand ( std::time(NULL) );
	Base *	base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
	delete base;
	return (0);
}

Base *	generate( void ) {
	int i = std::rand() % 3 + 1;
	if ( i == 1 ) {
		std::cout << "Generated A" << std::endl; 
		A *a = new A;
		return a;
	}
	if ( i == 2 ) {
		std::cout << "Generated B" << std::endl; 
		B *b = new B;
		return b;
	}
	if ( i == 3 ) {
		std::cout << "Generated C" << std::endl; 
		C *c = new C;
		return c;
	}
	return new Base();
}

void	identify_from_pointer( Base * p ) {
	std::cout << "Identify from pointer: ";
	if ( dynamic_cast<A*>(p) ) {
		std::cout << "A !" << std::endl;
	}
	if ( dynamic_cast<B*>(p) ) {
		std::cout << "B !" << std::endl;
	}
	if ( dynamic_cast<C*>(p) ) {
		std::cout << "C !" << std::endl;
	}
}

void	identify_from_reference( Base & p ) {
	std::cout << "Identify from reference: ";
	try {
		Base& b = dynamic_cast<A&>(p);
		std::cout << "A !" << std::endl;
		return ;
	}
	catch ( std::exception &e ) {

	}
	try {
		Base& b = dynamic_cast<B&>(p);
		std::cout << "B !" << std::endl;
		return ;
	}
	catch ( std::exception &e ) {

	}
	try {
		Base& b = dynamic_cast<C&>(p);
		std::cout << "C !" << std::endl;
		return ;
	}
	catch ( std::exception &e ) {

	}
}