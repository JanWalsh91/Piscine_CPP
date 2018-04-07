#include "whatever.cpp"
#include "TestClass.hpp"

#include <iostream>

int    main ( void ) {
	
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string const c = "chaine1";
	std::string const d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	TestClass e(5);
	TestClass f(10);
	::swap(e, f);
	std::cout << "e = " << e._n << ", f = " << f._n << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f )._n << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f )._n << std::endl;
	return 0;
}