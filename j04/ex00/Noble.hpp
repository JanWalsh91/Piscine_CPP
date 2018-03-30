#ifndef NOBLE_H
# define NOBLE_H

# include "Victim.hpp"

# include <string>

class Noble : public Victim {

	protected:
		Noble( void );

	public:
		Noble( std::string name );
		virtual ~Noble( void );

		Noble &    operator=( Noble const & rhs );

		virtual void getPolymorphed( void ) const;
};

#endif