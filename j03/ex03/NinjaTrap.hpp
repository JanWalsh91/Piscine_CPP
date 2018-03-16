#ifndef NINJATRAP_H
# define NINJATRAP_H

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <string>

class NinjaTrap : public ClapTrap {

	public:
		NinjaTrap( std::string name );
		NinjaTrap( NinjaTrap const & ninjaTrap );
		virtual ~NinjaTrap( void );

		NinjaTrap &    operator=( NinjaTrap const & rhs );

		virtual void rangedAttack(std::string & target);
		virtual void meleeAttack(std::string & target);
		void ninjaShoebox( FragTrap & fragTrap );
		void ninjaShoebox( ClapTrap & clapTrap );
		void ninjaShoebox( NinjaTrap & ninjaTrap );
};

#endif