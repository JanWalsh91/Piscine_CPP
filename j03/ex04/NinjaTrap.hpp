#ifndef NINJATRAP_H
# define NINJATRAP_H

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <string>

class SuperTrap;

class NinjaTrap : public virtual ClapTrap {
	
	protected:
		NinjaTrap( void );

		const static int _defaultHitPoints;
		const static int _defaultEnergyPoints;
		const static int _defaultLevel;
		const static int _defaultMeleeDmg;
		const static int _defaultRangedDmg;
		const static int _defaultArmor;

	public:
		NinjaTrap( std::string name );
		NinjaTrap( NinjaTrap const & ninjaTrap );
		~NinjaTrap( void );

		NinjaTrap &    operator=( NinjaTrap const & rhs );

		void rangedAttack( std::string const & target ) const;
		void meleeAttack( std::string const & target ) const;
		void ninjaShoebox( FragTrap & fragTrap ) const;
		void ninjaShoebox( ClapTrap & clapTrap ) const;
		void ninjaShoebox( NinjaTrap & ninjaTrap ) const;
		void ninjaShoebox( ScavTrap & scavTrap ) const;
		void ninjaShoebox( SuperTrap & superTrap ) const;
};

#include "SuperTrap.hpp"

#endif