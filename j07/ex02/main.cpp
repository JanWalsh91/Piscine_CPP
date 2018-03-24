#include "Array.tpp"

#include <iostream>

int    main ( void ) {
	
	int size = 10;

	Array<int> a( size );

	for( int i = 0; i < size; i++ ) {
		a[i] = i;
	}

	Array<int> b( a );

	for( int i = 0; i < size; i++ ) {
		a[i] = i * 10;
	}

	for( int i = 0; i < size; i++ ) {
		std::cout << "a[" << i << "]: " << a[i] << std::endl; 
		std::cout << "b[" << i << "]: " << b[i] << std::endl; 
	}

	a[50];

	return (0);
}