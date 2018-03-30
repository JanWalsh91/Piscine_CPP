#include "FragTrap.hpp"

int    main ( void ) {
	FragTrap fragTrap("Krieg");
	std::string targets[] = {"Maya", "Zer0", "Gaige", "Handsome Jack", "Tiny Tina"};

	fragTrap.rangedAttack(targets[std::rand() % 5]);
	fragTrap.meleeAttack(targets[std::rand() % 5]);

	fragTrap.takeDamage(1);
	fragTrap.takeDamage(20);
	fragTrap.vaulthunter_dot_exe(targets[std::rand() % 5]);
	fragTrap.takeDamage(30);
	fragTrap.takeDamage(30);
	fragTrap.vaulthunter_dot_exe(targets[std::rand() % 5]);
	fragTrap.takeDamage(30);
	fragTrap.vaulthunter_dot_exe(targets[std::rand() % 5]);
	fragTrap.takeDamage(30);
	fragTrap.takeDamage(30);
	fragTrap.vaulthunter_dot_exe(targets[std::rand() % 5]);
	fragTrap.beRepaired(50);
	fragTrap.vaulthunter_dot_exe(targets[std::rand() % 5]);
	fragTrap.vaulthunter_dot_exe(targets[std::rand() % 5]);
	return (0);
}
