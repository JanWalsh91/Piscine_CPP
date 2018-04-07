#include "span.hpp"

#include <iostream>

int    main ( void ) {
	
	Span span(6);

	span.addNumber(10);
	try {
		std::cout << "shortest: " << span.shortestSpan() << std::endl;
	}
	catch ( std::exception & e ) {
		std::cout << e.what() << std::endl;
	}

	span.addNumber(50);
	
	int list[] = {20, -10, 1654, 130};
	span.addNumbers(list, 4);

	std::cout << "shortest: " << span.shortestSpan() << std::endl;
	std::cout << "longest: " << span.longestSpan() << std::endl;

	try {
		span.addNumber(1);
	}
	catch ( std::exception & e ) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}