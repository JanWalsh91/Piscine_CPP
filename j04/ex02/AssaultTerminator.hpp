#ifndef ASSAULT_TERMINATOR_H
# define ASSAULT_TERMINATOR_H

# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {

	public:
		AssaultTerminator( void );
		AssaultTerminator( AssaultTerminator const & assaultTermiantor );
		~AssaultTerminator( void );

		AssaultTerminator &    operator=( AssaultTerminator const & rhs );

		AssaultTerminator*	clone( void ) const ;
		void battleCry( void ) const ;
		void rangedAttack( void ) const ;
		void meleeAttack( void ) const ;
};

#endif