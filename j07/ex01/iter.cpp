template < typename T, typename X >
void iter( T* array, unsigned int length, X (*func)( T & ) ) {
	unsigned int i = 0;
	while ( i < length ) {
		func(array[i]);
		++i;
	}
}