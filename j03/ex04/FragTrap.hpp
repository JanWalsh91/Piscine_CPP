#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

#include <string>

class FragTrap : public virtual ClapTrap {

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

		void rangedAttack(std::string & target);
		void meleeAttack(std::string & target);
		void vaulthunter_dot_exe(std::string const & target);
};

#endif