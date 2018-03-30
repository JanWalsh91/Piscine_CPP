#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include <string>

class ScavTrap {

	private:
		std::string _name;
		int _maxHitPoints;
		int _hitPoints;
		int _maxEnergyPoints;
		int _energyPoints;
		int _level;
		int _meleeDmg;
		int _rangedDmg;
		int _armor;
		ScavTrap( void );
	
	public:
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & scavTrap );
		~ScavTrap( void );

		ScavTrap &    operator=( ScavTrap const & rhs );

		void rangedAttack( std::string const & target );
		void meleeAttack( std::string const & target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
		void challengeNewcomer( std::string const & target );
};

#endif
