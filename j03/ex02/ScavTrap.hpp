#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

#include <string>

class ScavTrap : public ClapTrap {

	private:
		ScavTrap( void );

	public:
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & scavTrap );
		~ScavTrap( void );

		ScavTrap &    operator=( ScavTrap const & rhs );

		void rangedAttack( std::string const & target ) const;
		void meleeAttack( std::string const & target ) const;
		void challengeNewcomer( std::string const & target ) const;
};

#endif