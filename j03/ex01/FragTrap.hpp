#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <string>

class FragTrap {

	private:
		int _maxHitPoints;
		int _maxEnergyPoints;
	
	public:
		FragTrap( std::string name );
		FragTrap( FragTrap const & fragTrap );
		~FragTrap( void );

		FragTrap &    operator=( FragTrap const & rhs );

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
		void vaulthunter_dot_exe(std::string const & target);
};

#endif