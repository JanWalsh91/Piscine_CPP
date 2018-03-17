#ifndef TACTICAL_MARINE_H
# define TACTICAL_MARINE_H

# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {

	public:
		TacticalMarine( void );
		TacticalMarine( TacticalMarine const & tacticalMarine );
		~TacticalMarine( void );

		TacticalMarine &    operator=( TacticalMarine const & rhs );

		TacticalMarine*	clone( void ) const ;
		void battleCry( void ) const ;
		void rangedAttack( void ) const ;
		void meleeAttack( void ) const ;
};

#endif