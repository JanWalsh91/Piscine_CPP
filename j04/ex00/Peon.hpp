#ifndef PEON_H
# define PEON_H

# include "Victim.hpp"

# include <string>

class Peon : public Victim {

	protected:
		Peon( void );

	public:
		Peon( std::string name );
		virtual ~Peon( void );

		Peon &    operator=( Peon const & rhs );

		virtual void getPolymorphed( void ) const;
};

#endif