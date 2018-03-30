#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

#include <string>

class FragTrap : public virtual ClapTrap {
	
	protected:
		FragTrap( void );
		const static int _defaultHitPoints;
		const static int _defaultEnergyPoints;
		const static int _defaultLevel;
		const static int _defaultMeleeDmg;
		const static int _defaultRangedDmg;
		const static int _defaultArmor;
	
	public:
		FragTrap( std::string name );
		FragTrap( FragTrap const & fragTrap );
		~FragTrap( void );

		FragTrap &    operator=( FragTrap const & rhs );

		void rangedAttack( std::string const & target ) const;
		void meleeAttack( std::string const & target ) const;
		void vaulthunter_dot_exe( std::string const & target );
};

#endif