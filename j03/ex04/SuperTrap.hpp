#ifndef SUPERTRAP_H
# define SUPERTRAP_H

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

#include <string>

class SuperTrap : public FragTrap, public NinjaTrap {

	private:
		SuperTrap( void );

	public:
		SuperTrap( std::string name );
		SuperTrap( SuperTrap const & superTrap );
		virtual ~SuperTrap( void );

		SuperTrap &    operator=( SuperTrap const & rhs );

		void rangedAttack( std::string const & target ) const;
		void meleeAttack( std::string const & target ) const;
};

#endif