#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <iostream>

int    main ( void ) {
	std::string targets[] = {"Maya", "Zer0", "Gaige", "Handsome Jack", "Tiny Tina"};

	// FragTrap kreig("Krieg");
	// kreig.rangedAttack(targets[std::rand() % 5]);
	// kreig.meleeAttack(targets[std::rand() % 5]);
	// kreig.takeDamage(20);
	// kreig.vaulthunter_dot_exe(targets[std::rand() % 5]);
	// kreig.takeDamage(30);
	// kreig.takeDamage(30);
	// kreig.vaulthunter_dot_exe(targets[std::rand() % 5]);
	// kreig.takeDamage(30);
	// kreig.vaulthunter_dot_exe(targets[std::rand() % 5]);
	// std::cout << "----" << std::endl;

	// ScavTrap sally("Sally");
	// sally.meleeAttack(targets[std::rand() % 5]);
	// sally.rangedAttack(targets[std::rand() % 5]);
	// sally.takeDamage(30);
	// sally.challengeNewcomer(targets[std::rand() % 5]);
	// sally.challengeNewcomer(targets[std::rand() % 5]);
	// sally.takeDamage(20);
	// std::cout << "----" << std::endl;

	NinjaTrap nino("Nino");
	// nino.meleeAttack(targets[std::rand() % 5]);
	// nino.rangedAttack(targets[std::rand() % 5]);
	// nino.takeDamage(30);
	// nino.ninjaShoebox(sally);
	// nino.ninjaShoebox(kreig);
	// nino.ninjaShoebox(nino);
	// nino.takeDamage(20);
	// std::cout << "----" << std::endl;

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
