#ifndef FIXED_H
# define FIXED_H

class Fixed {
	
	private:
		int	_i;
		static const int _f = 8;
	
	public:
		Fixed( void );
		Fixed( Fixed const & fixed );
		~Fixed( void );

		Fixed &    operator=( Fixed const & rhs );

		int	getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif