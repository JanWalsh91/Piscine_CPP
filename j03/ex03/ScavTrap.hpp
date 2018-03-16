#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {

	private:
		std::string _name;
		int _maxHitPoints;
		int _maxEnergyPoints;
		int _hitPoints;
		int _energyPoints;
		int _level;
		int _meleeDmg;
		int _rangedDmg;
		int _armor;
	
	public:
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & scavTrap );
		virtual ~ScavTrap( void );

		ScavTrap &    operator=( ScavTrap const & rhs );

		void challengeNewcomer(std::string const & target);
};

#endif