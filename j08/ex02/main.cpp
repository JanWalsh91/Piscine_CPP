#include "mutantstack.hpp"

#include <iostream>

int    main ( void ) {
	
	MutantStack<int> mstack;
	
	mstack.push(5);
	
	mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
	
	std::cout << "===============" << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	mstack.push(737);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
	--it;


	std::cout << *it << std::endl;

	std::cout << "===============" << std::endl;

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "===============" << std::endl;
	
	std::stack<int> s(mstack);
	
	MutantStack<int> s2 = mstack;
	it = s2.begin();
	ite = s2.end();
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	s2.pop();
	s2.pop();
	s2.pop();
	s2.pop();
	return (0);
}