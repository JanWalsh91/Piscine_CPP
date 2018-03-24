#ifndef EASY_FIND_H
# define EASY_FIND_H

# include <algorithm>
# include <exception>

class NotFoundException: public std::exception
{
  virtual const char* what() const throw()
  {
    return "Value not found";
  }
};

template< typename T >
int & easyfind( T & t, int i ) {

	typename T::iterator it = t.begin();

	it = std::find(it, t.end(), i);

	if (it == t.end()) {
		throw NotFoundException();
	}

	return *it;
};

#endif