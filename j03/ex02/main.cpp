#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

int    main ( void ) {
	FragTrap kreig("Krieg");
	std::string targets[] = {"Maya", "Zer0", "Gaige", "Handsome Jack", "Tiny Tina"};

	kreig.rangedAttack(targets[std::rand() % 5]);
	kreig.meleeAttack(targets[std::rand() % 5]);
	
	kreig.takeDamage(20);
	kreig.vaulthunter_dot_exe(targets[std::rand() % 5]);
	kreig.takeDamage(30);
	kreig.takeDamage(30);
	kreig.vaulthunter_dot_exe(targets[std::rand() % 5]);
	kreig.takeDamage(30);
	kreig.vaulthunter_dot_exe(targets[std::rand() % 5]);
	std::cout << "----" << std::endl;

	ScavTrap sally("Sally");
	sally.meleeAttack(targets[std::rand() % 5]);
	sally.rangedAttack(targets[std::rand() % 5]);
	sally.takeDamage(30);
	sally.challengeNewcomer(targets[std::rand() % 5]);
	sally.challengeNewcomer(targets[std::rand() % 5]);
	sally.takeDamage(20);
	return (0);
}
