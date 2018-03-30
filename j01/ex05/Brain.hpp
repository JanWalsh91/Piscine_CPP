#ifndef BRAIN_H
# define BRAIN_H

#include <string>

class Brain {
	private:
		int _brainPower;

	public:
		Brain( int brainPower );
		~Brain( void );

		std::string identify( void ) const;
};

#endif