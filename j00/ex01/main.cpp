#include "Phonebook.hpp"

#include <string>
#include <iostream>

using namespace std;

int	main() {

	cout << "Welcome to Phonebook!" << endl;
	Phonebook phonebook;
	while (cin) {
		cout << "Looping" << endl;
		string command;
		cout << "Command: ";
		
		if (!cin) {
			break ;
		}
		getline(cin, command);
		if (!cin) {
			break ;
		}
		if (command.compare("EXIT") == 0) {
			cout << "Goodbye!" << endl;
			exit(0);
		}
		if (!cin) {
			break ;
		}
		phonebook.executeCommand(command);
	}

	return (0);
};

