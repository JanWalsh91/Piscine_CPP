// Swaps the values of two arguments. Does not return anything.
template < typename T >
void 		swap( T & x, T & y) {
	T tmp = x;
	x = y;
	y = tmp;
}

// Compares the two arguments and returns the biggest one. If the two arguments
// are equal, then it returns the second one.
template< typename T>
T &	max( T & x, T & y ) {
	return ( x > y ? x : y );
}
template< typename T>
T const &	max( T const & x, T const & y ) {
	return ( x > y ? x : y );
}

// Compares the two arguments and returns the smallest one. If the two arguments
// are equal, then it returns the second one.
template< typename T>
T &	min( T & x, T & y ) {
	return ( x < y ? x : y );
}
template< typename T>
T const &	min( T const & x, T const & y ) {
	return ( x < y ? x : y );
}
