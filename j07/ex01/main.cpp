#include "iter.cpp"
#include <iostream>

template< typename T >
void		print( T & x ) {
	std::cout << x << std::endl;
}

template< typename T >
void		add10( T & x ) {
	x = x + 10;
}

int		main ( void ) {
	
	int *array = new int[3];
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;

	iter<int, void>( array, 3, print<int> );
	iter<int, void>( array, 3, add10<int> );
	iter<int, void>( array, 3, print<int> );

	// for ( int i = 0; i < 3; i++ ) {
	// 	std::cout << array[i] << std::endl;
	// }
	return (0);
}