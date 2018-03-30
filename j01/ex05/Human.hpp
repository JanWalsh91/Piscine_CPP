#ifndef HUMAN_H
# define HUMAN_H

#include "Brain.hpp"

#include <string>

class Human {
	private:
		Brain const _brain;

	public:
		Human( void );
		~Human( void );

		std::string identify( void ) const;
		Brain const & getBrain( void ) const;
};

#endif