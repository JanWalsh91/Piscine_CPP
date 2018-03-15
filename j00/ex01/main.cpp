#include <string>
#include <iostream>
#include "Phonebook.hpp"

using namespace std;

int	main() {

	cout << "Welcome to Phonebook!" << endl;
	Phonebook phonebook;
	while (1) {
		cout << "Looping" << endl;
		string command;
		cout << "Command: ";
		
		getline(cin, command);
		if (command.compare("EXIT") == 0) {
			cout << "Goodbye!" << endl;
			exit(0);
		}
		phonebook.executeCommand(command);
	}

	return (0);
};

