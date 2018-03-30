#include "Human.hpp"

#include <iostream>

void Human::meleeAttack(std::string const & target) {
	std::cout << "melee attack on " << target << std::endl;
}

void Human::rangedAttack(std::string const & target) {
	std::cout << "ranged attack on " << target << std::endl;
}

void Human::intimidatingShout(std::string const & target) {
	std::cout << "intimidating shout at " << target << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target) {
	std::string actionNames[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	typedef void (Human::*Actions)( std::string const & target );
	Actions actions[3] = { &Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout };
	
	for (int i = 0; i < 3; i++) {
		if (action_name == actionNames[i]) {
			(this->*(actions[i]))( target );
		}
	}
}