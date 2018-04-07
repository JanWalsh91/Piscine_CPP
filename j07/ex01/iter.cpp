template < typename T >
void iter( T* array, unsigned int length, void (*func)( T & ) ) {
	unsigned int i = 0;
	while ( i < length ) {
		func(array[i]);
		++i;
	}
}

template < typename T >
void iter( T* array, unsigned int length, void (*func)( T ) ) {
	unsigned int i = 0;
	while ( i < length ) {
		func(array[i]);
		++i;
	}
}
