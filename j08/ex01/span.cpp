#include "span.hpp"

#include <iostream>
#include <algorithm>

Span::Span( void ) {
	std::cout << "Default constructor called" << std::endl;
}

Span::Span( unsigned int N ) : _N(N), _C(0) {
	std::cout << "Default constructor called" << std::endl;
}

Span::Span( Span const & span ) : _C(0) {
	std::cout << "Copy constructor called" << std::endl;
	*this = span;
}

Span::~Span( void ) {
	std::cout << "Destructor called" << std::endl;
}

Span &    Span::operator=( Span const & rhs ) {
	this->_C = rhs._C;
	this->_N = rhs._N;
	this->_set = rhs._set;
	return (*this);
}

void Span::addNumber( int n ) {
	if ( this->_set.size() >= this->_N ) {
		throw( Span::FullException() );
	}
	++(this->_C);
	this->_set.insert(n);
}

int Span::shortestSpan( void ) {
	if ( this->_set.size() < 2 ) {
		throw( Span::NotEnoughElementsToCompareException() );
		return -1;
	}
	int result = -1;
	std::multiset<int>::const_iterator it = this->_set.begin();
	std::multiset<int>::const_iterator itnext = this->_set.begin();
	++itnext;

	unsigned int i = 1;
	while ( i < this->_C ) {
		if ( result == -1 ) {
			result = *itnext - *it;
		}
		else if ( result > ( *itnext - *it ) ) {
			result = *itnext - *it;
		}
		++it;
		++itnext;
		++i;
	}
	return result;
}

int Span::longestSpan( void ) {
	if ( this->_set.size() < 2 ) {
		throw( Span::NotEnoughElementsToCompareException() );
		return -1;
	}
	std::multiset<int>::const_iterator itend = this->_set.begin();

	advance(itend, this->_C - 1);

	return *( itend ) - *( this->_set.begin() );
}

const char* Span::FullException::what() const throw() {
	return "Span is full";
};

const char* Span::NotEnoughElementsToCompareException::what() const throw() {
	return "Not enough elements to compare";
};