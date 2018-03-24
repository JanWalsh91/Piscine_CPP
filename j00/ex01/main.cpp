#include "Phonebook.hpp"

#include <iostream>

int	main() {

	std::cout << "Welcome to Phonebook!" << std::endl;
	Phonebook phonebook;
	while (std::cin) {
		std::string command;
		std::cout << "Pleaase enter a command: <ADD, SEARCH, EXIT>" << std::endl;
		
		getline(std::cin, command);
		if (!std::cin) {
			break ;
		}
		if (command.compare("EXIT") == 0) {
			std::cout << "Goodbye!" << std::endl;
			exit(0);
		}
		phonebook.executeCommand(command);
	}

	return (0);
};

