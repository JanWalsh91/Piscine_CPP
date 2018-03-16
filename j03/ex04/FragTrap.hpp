#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

#include <string>

class FragTrap : public virtual ClapTrap {

	public:
		FragTrap( std::string name );
		FragTrap( FragTrap const & fragTrap );
		virtual ~FragTrap( void );

		FragTrap &    operator=( FragTrap const & rhs );

		virtual void rangedAttack(std::string & target);
		virtual void meleeAttack(std::string & target);
		void vaulthunter_dot_exe(std::string const & target);
};

#endif