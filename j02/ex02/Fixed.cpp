#include "Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed( void ) {
	this->_i = 0;
	return ;
};

Fixed::Fixed( Fixed const & fixed ) {
	this->_i = fixed.getRawBits();
	return ;
};

Fixed::Fixed( int const i ) {
	this->_i = i << this->_bit;
	return ;
};

Fixed::Fixed( float const i ) {
	this->_i = i * (1 << this->_bit);
	return ;
};

Fixed::~Fixed( void ) {
	return ;
};

Fixed &	Fixed::operator=( Fixed const & rhs ) {
	this->_i = rhs._i;
	return (*this);
};

Fixed	Fixed::operator+( Fixed const & rhs ) {
	return Fixed( this->toFloat() + rhs.toFloat() );
};

Fixed	Fixed::operator-( Fixed const & rhs ) {
	return Fixed( this->toFloat() - rhs.toFloat() );
};

Fixed	Fixed::operator*( Fixed const & rhs ) {
	return Fixed( this->toFloat() * rhs.toFloat() );
};

Fixed	Fixed::operator/( Fixed const & rhs ) {
	return Fixed( this->toFloat() / rhs.toFloat() );
};

Fixed	Fixed::operator++( int i ) {
	Fixed fixed(*this);
	this->_i += i ? i : 1;
	return fixed;
};

Fixed	Fixed::operator--( int i ) {
	this->_i -= i ? i : 1;
	Fixed fixed(*this);
	return fixed;
};

Fixed &	Fixed::operator++( void ) {
	++this->_i;
	return *this;
};

Fixed &	Fixed::operator--( void ) {
	--this->_i;
	return *this;
};

bool	Fixed::operator<( Fixed const & rhs ) {
	return (this->_i < rhs.getRawBits());
};

bool	Fixed::operator>( Fixed const & rhs ) {
	return (this->_i > rhs.getRawBits());
};

bool	Fixed::operator<=( Fixed const & rhs ) {
	return (this->_i <= rhs.getRawBits());
};

bool	Fixed::operator>=( Fixed const & rhs ) {
	return (this->_i >= rhs.getRawBits());
};

bool	Fixed::operator==( Fixed const & rhs ) {
	return (this->_i == rhs.getRawBits());
};

bool	Fixed::operator!=( Fixed const & rhs ) {
	return (this->_i != rhs.getRawBits());
};

std::ostream &    operator<<( std::ostream & o, Fixed const & rhs ) {
	o << rhs.toFloat();
	return o;
};

int		Fixed::getRawBits( void ) const {
	return this->_i;
};

void	Fixed::setRawBits( int const raw ) {
	this->_i = raw;
};

float	Fixed::toFloat( void ) const {
	return ( (float)this->_i / (1 << this->_bit) );
};

int		Fixed::toInt( void ) const {
	return (this->_i >> this->_bit);
};

const Fixed & Fixed::min(const Fixed & a, const Fixed & b) {
	return ( a.getRawBits() < b.getRawBits() ? a : b );
};

const Fixed & Fixed::max(const Fixed & a, const Fixed & b) {
	return ( a.getRawBits() > b.getRawBits() ? a : b );
};