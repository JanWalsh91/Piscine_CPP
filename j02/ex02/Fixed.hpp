#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {
	
	private:
		int					_i;
		static const int	_bit = 8;
	
	public:
		Fixed( void );
		Fixed( Fixed const & fixed );
		Fixed( int const i );
		Fixed( float const i );
		~Fixed( void );

		Fixed &	   operator=( Fixed const & rhs );
		Fixed	   operator+( Fixed const & rhs );
		Fixed	   operator-( Fixed const & rhs );
		Fixed	   operator*( Fixed const & rhs );
		Fixed	   operator/( Fixed const & rhs );
		//post
		Fixed	   operator++( int i );
		Fixed	   operator--( int i );
		//pre
		Fixed &	   operator++( void );
		Fixed &	   operator--( void );
		bool 	   operator<( Fixed const & rhs );
		bool 	   operator>( Fixed const & rhs );
		bool 	   operator<=( Fixed const & rhs );
		bool 	   operator>=( Fixed const & rhs );
		bool 	   operator==( Fixed const & rhs );
		bool 	   operator!=( Fixed const & rhs );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		static const Fixed & min(const Fixed & a, const Fixed & b);
		static const Fixed & max(const Fixed & a, const Fixed & b);
};

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs );

#endif