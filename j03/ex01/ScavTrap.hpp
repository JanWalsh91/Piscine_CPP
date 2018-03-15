#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include <string>

class ScavTrap {

	private:
		int _maxHitPoints;
		int _maxEnergyPoints;
	
	public:
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & scavTrap );
		~ScavTrap( void );

		ScavTrap &    operator=( ScavTrap const & rhs );

		std::string name;
		int hitPoints;
		int energyPoints;
		int level;
		int meleeDmg;
		int rangedDmg;
		int armor;
		
		void rangedAttack(std::string & target);
		void meleeAttack(std::string & target);
		void takeDamage(unsigned int dmg);
		void beRepaired(unsigned int hitPoints);
		void challengeNewcomer(std::string const & target);
};

#endif