#ifndef SUPERTRAP_H
# define SUPERTRAP_H

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

#include <string>

class SuperTrap : public FragTrap, public NinjaTrap {

	public:
		SuperTrap( std::string name );
		SuperTrap( SuperTrap const & superTrap );
		virtual ~SuperTrap( void );

		SuperTrap &    operator=( SuperTrap const & rhs );

		void rangedAttack( std::string & target );
		void meleeAttack( std::string & target );
};

#endif