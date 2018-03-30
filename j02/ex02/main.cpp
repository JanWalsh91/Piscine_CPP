#include "Fixed.hpp"

#include <iostream>

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;

    std::cout << "================" << std::endl;

    Fixed n1(10);
    Fixed n2(-5);
    Fixed n3(-2);

    std::cout << "n1 = " << n1 << std::endl;
    std::cout << "n2 = " << n2 << std::endl;
    std::cout << "n3 = " << n3 << std::endl;
    std::cout << "n1 + n2 = " << n1 + n2 << std::endl;
    std::cout << "n1 - n2 = " << n1 - n2 << std::endl;
    std::cout << "n1 * n2 = " << n1 * n2 << std::endl;
    std::cout << "n3 / n1 = " << n3 / n1 << std::endl;

    std::cout << "n1 > n2 = " << std::boolalpha << (n1 > n2) << std::endl;
    std::cout << "n1 < n2 = " << std::boolalpha << (n1 < n2) << std::endl;
    std::cout << "n1 <= n2 = " << std::boolalpha << (n1 <= n2) << std::endl;
    std::cout << "n1 >= n2 = " << std::boolalpha << (n1 >= n2) << std::endl;

    return 0;
}