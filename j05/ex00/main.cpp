#include "Bureaucrat.hpp"

#include <exception>
#include <iostream>

int    main ( void ) {
	
	try {
		Bureaucrat bob;
		std::cout << bob << std::endl;
		Bureaucrat joe("Joe", 140);
		std::cout << joe << std::endl;
		Bureaucrat joe2(joe);
		std::cout << joe2 << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat joe("Joe", 160);
		std::cout << joe << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat joe("Joe", 0);
		std::cout << joe << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat joe("Joe", -1);
		std::cout << joe << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat joe("Joe", 1);
		std::cout << joe << std::endl;
		joe.incrementGrade();
		std::cout << joe << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat joe("Joe", 150);
		std::cout << joe << std::endl;
		joe.decrementGrade();
		std::cout << joe << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat joe("Joe", 70);
		std::cout << joe << std::endl;
		joe.decrementGrade();
		std::cout << joe << std::endl;
		joe.decrementGrade();
		std::cout << joe << std::endl;
		joe.incrementGrade();
		std::cout << joe << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}