#ifndef SUPERTRAP_H
# define SUPERTRAP_H

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

#include <string>

class SuperTrap : public FragTrap, public NinjaTrap {

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
		SuperTrap( std::string name );
		SuperTrap( SuperTrap const & superTrap );
		virtual ~SuperTrap( void );

		SuperTrap &    operator=( SuperTrap const & rhs );

		void rangedAttack(std::string & target);
		void meleeAttack(std::string & target);
};

#endif