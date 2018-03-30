#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

#include <string>

class FragTrap : public ClapTrap {
	
	private:
		FragTrap( void );
		
	public:
		FragTrap( std::string name );
		FragTrap( FragTrap const & fragTrap );
		~FragTrap( void );

		FragTrap &    operator=( FragTrap const & rhs );

		void rangedAttack( std::string const & target );
		void meleeAttack( std::string const & target );
		void vaulthunter_dot_exe( std::string const & target );
};

#endif
