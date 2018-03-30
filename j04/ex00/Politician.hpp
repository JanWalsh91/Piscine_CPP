#ifndef POLITICIAN_H
# define POLITICIAN_H

# include "Victim.hpp"

# include <string>

class Politician : public Victim {

	protected:
		Politician( void );
		
	public:
		Politician( std::string name );
		virtual ~Politician( void );

		Politician &    operator=( Politician const & rhs );

		virtual void getPolymorphed( void ) const;
};

#endif