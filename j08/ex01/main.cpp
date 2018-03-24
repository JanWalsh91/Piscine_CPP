#include "span.hpp"

#include <iostream>

int    main ( void ) {
	
	Span span(5);

	// for ( int i = 0; i < 5; ++i ) {
	// 	span.addNumber( i * (i + 2) + 2 );
	// }

	span.addNumber(3654056);
	span.addNumber(50);
	span.addNumber(5);
	span.addNumber(50);
	span.addNumber(1560);

	std::cout << "shortest: " << span.shortestSpan() << std::endl;

	std::cout << "longest: " << span.longestSpan() << std::endl;


	return (0);
}