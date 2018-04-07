#ifndef EASY_FIND_H
# define EASY_FIND_H

# include <algorithm>
# include <exception>
# include <iostream>

template< typename T >
int & easyfind( T & t, int i ) {

	typename T::iterator it = std::find(t.begin(), t.end(), i);

	if (it == t.end()) {
		throw std::logic_error("Element not found");
	}

	return *it;
};

#endif