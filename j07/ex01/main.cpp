#include "iter.cpp"
#include <iostream>

template< typename T >
void		print( T & x ) {
	std::cout << x << std::endl;
}

int		main ( void ) {
	
	int *array = new int[3];
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;


	void (*func)( int & ) = print<int>;

	iter<int, void>( array, 3, func );

	return (0);
}