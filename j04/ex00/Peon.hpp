#ifndef PEON_H
# define PEON_H

# include "Victim.hpp"

# include <string>

class Peon : public Victim {

	public:
		Peon( std::string name );
		~Peon( void );

		Peon &    operator=( Peon const & rhs );

		void getPolymorphed( void ) const;
};

#endif