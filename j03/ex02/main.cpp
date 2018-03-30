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

	FragTrap a = kreig;
	FragTrap c = FragTrap(kreig);

	ScavTrap sally("Sally");
	sally.meleeAttack(targets[std::rand() % 5]);
	sally.rangedAttack(targets[std::rand() % 5]);
	sally.takeDamage(30);
	sally.challengeNewcomer(targets[std::rand() % 5]);
	sally.challengeNewcomer(targets[std::rand() % 5]);
	sally.takeDamage(20);

	ScavTrap a1 = sally;
	ScavTrap c1 = ScavTrap(sally);
	return (0);
}
