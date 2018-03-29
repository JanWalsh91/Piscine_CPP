#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <iostream>

int    main ( void ) {
	std::string targets[] = {"Maya", "Zer0", "Gaige", "Handsome Jack", "Tiny Tina"};

	FragTrap kreig("Krieg");
	ScavTrap sally("Sally");
	NinjaTrap nino("Nino");

	SuperTrap max("Max");
	
	max.ninjaShoebox(nino);
	max.vaulthunter_dot_exe(targets[std::rand() % 5]);
	max.meleeAttack(targets[std::rand() % 5]);
	max.rangedAttack(targets[std::rand() % 5]);
	max.takeDamage(60);
	max.takeDamage(2);
	max.takeDamage(40);
	max.takeDamage(20);

	return (0);
}
