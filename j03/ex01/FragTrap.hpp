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
	
	public:
		FragTrap( std::string name );
		FragTrap( FragTrap const & fragTrap );
		virtual ~FragTrap( void );

		FragTrap &    operator=( FragTrap const & rhs );

		void rangedAttack( std::string & target );
		void meleeAttack( std::string & target );
		void takeDamage(unsigned int dmg );
		void beRepaired( unsigned int hitPoints );
		void vaulthunter_dot_exe( std::string const & target );
};

#endif