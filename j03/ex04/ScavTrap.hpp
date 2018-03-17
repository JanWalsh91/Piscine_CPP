#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public virtual ClapTrap {

	public:
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & scavTrap );
		virtual ~ScavTrap( void );

		ScavTrap &    operator=( ScavTrap const & rhs );

		virtual void rangedAttack( std::string & target );
		virtual void meleeAttack( std::string & target );
		void challengeNewcomer( std::string const & target );
};

#endif