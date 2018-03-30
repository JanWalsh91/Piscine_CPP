#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <string>

class FragTrap {

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
		FragTrap( void );
	
	public:
		FragTrap( std::string name );
		FragTrap( FragTrap const & fragTrap );
		~FragTrap( void );

		FragTrap &    operator=( FragTrap const & rhs );

		void rangedAttack( std::string const & target );
		void meleeAttack( std::string const & target );
		void takeDamage(unsigned int amount );
		void beRepaired( unsigned int amount );
		void vaulthunter_dot_exe( std::string const & target );
};

#endif
