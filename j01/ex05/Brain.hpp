#ifndef BRAIN_H
# define BRAIN_H

#include <string>

class Brain {
	public:
		Brain( void );
		~Brain( void );

		std::string identify( void ) const;
};

#endif