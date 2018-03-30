#ifndef NINJATRAP_H
# define NINJATRAP_H

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <string>

class NinjaTrap : public ClapTrap {

	private:
		NinjaTrap( void );

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
};

#endif