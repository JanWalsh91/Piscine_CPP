#ifndef PONY_H
# define PONY_H

#include <string>

class Pony {
	private:
		std::string _color;

	public:
		Pony(std::string color);
		~Pony( void );
		void neigh( void );
};

#endif