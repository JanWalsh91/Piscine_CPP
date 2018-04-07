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
	if ( this->_set.size() + 1 > this->_N ) {
		throw( Span::FullException() );
	}
	++(this->_C);
	this->_set.insert(n);
}

void Span::addNumbers( int n[], int count ) {
	if ( this->_set.size() + count > this->_N ) {
		throw( Span::FullException() );
	}
	this->_C += count;
	this->_set.insert(n, n + count);
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

/* ========== FullException ========== */

Span::FullException::FullException( void ) {}

Span::FullException::FullException( Span::FullException const & e ) {
	*this = e;
}

Span::FullException::~FullException( void ) throw() {}

Span::FullException &    Span::FullException::operator=( Span::FullException const & rhs ) throw() {
	( void )rhs;
	return *this;
}

const char* Span::FullException::what() const throw() {
	return "Span is full";
}

/* ========== NotEnoughElementsToCompareException ========== */

Span::NotEnoughElementsToCompareException::NotEnoughElementsToCompareException( void ) {}

Span::NotEnoughElementsToCompareException::NotEnoughElementsToCompareException( Span::NotEnoughElementsToCompareException const & e ) {
	*this = e;
}

Span::NotEnoughElementsToCompareException::~NotEnoughElementsToCompareException( void ) throw() {}

Span::NotEnoughElementsToCompareException &    Span::NotEnoughElementsToCompareException::operator=( Span::NotEnoughElementsToCompareException const & rhs ) throw() {
	( void )rhs;
	return *this;
}

const char* Span::NotEnoughElementsToCompareException::what() const throw() {
	return "Not enough elements to compare";
}