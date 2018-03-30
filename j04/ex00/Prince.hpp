#ifndef PRINCE_H
# define PRINCE_H

# include "Noble.hpp"

# include <string>

class Prince : public Noble {

	protected:
		Prince( void );

	public:
		Prince( std::string name );
		virtual ~Prince( void );

		Prince &    operator=( Prince const & rhs );

		virtual void getPolymorphed( void ) const;
};

#endif