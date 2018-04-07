#include "easyfind.hpp"

#include <vector>
#include <list>
#include <deque>
#include <iostream>


int    main ( void ) {
	
	{
		std::vector<int> container;
		
		container.push_back(4);
		container.push_back(2);
		container.push_back(3);

		int & i = easyfind< std::vector< int > >(container, 4);

		std::cout << i << std::endl;
		i = 5;
		std::cout << container[0] << std::endl;
	}
	
	{
		std::list<int> container;
		
		container.push_back(4);
		container.push_back(2);
		container.push_back(3);

		int & i = easyfind< std::list< int > >(container, 4);
		std::cout << i << std::endl;
	}

	{
		std::deque<int> container;
		
		container.push_back(4);
		container.push_back(2);
		container.push_back(3);

		int & i = easyfind< std::deque< int > >(container, 4);
		std::cout << i << std::endl;
	}

	try 
	{
		std::deque<int> container;
		
		container.push_back(4);
		container.push_back(2);
		container.push_back(3);

		int & i = easyfind< std::deque< int > >(container, 50);

		std::cout << i << std::endl;
	}
	catch ( std::exception & e ) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
