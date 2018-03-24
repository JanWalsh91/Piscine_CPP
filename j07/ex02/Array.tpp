#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include <exception>

template< typename T >
class Array {

	private:
		unsigned int	_size;
		T*				_a;

	public:
		Array<T>( void ) : _size(0), _a(new T[0]) {
			std::cout << "Default constructor called" << std::endl;
			return ;
		};
		
		Array<T>( unsigned int n ) : _size(n), _a(new T[n]) {
			std::cout << "Constructor with params called" << std::endl;
			return ;
		};

		Array<T>( Array<T> const & array ) :
			_size( array.size() ) {

			this->_a = new T[ this->size() ];
			for ( int i = 0; i < this->size(); i++ ) {
				this->_a[i] = array._a[i];
			}
			std::cout << "Copy constructor called" << std::endl;
			*this = array;
			return ;
		};

		~Array<T>( void ) {
			delete [] this->_a;
			std::cout << "Destructor called" << std::endl;
			return ;
		};

		Array<T> &    operator=( Array<T> const & rhs ) {
			if ( this != &rhs) {
				delete [] this->_a;
				this->_size = rhs.size();
				this->_a = new T[ this->size() ];
				for ( int i = 0; i < this->size(); i++ ) {
					this->_a[i] = rhs._a[i];
				}
			}
			return (*this);
		};

		T &		operator[]( int x ) {
			if ( x >= this->size() ) {
				throw ( std::out_of_range("Out of range") );
			}
			return this->_a[x];
		};

		unsigned int size( void ) const {
			return this->_size;
		};
};

#endif