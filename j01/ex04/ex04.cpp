#include <string>
#include <iostream>

int main( void ) {
	std::string brainSpeak = "HI THIS IS BRAIN";
	std::cout << brainSpeak << std::endl;
	std::string* brainSpeakPtr = &brainSpeak;
	std::cout << *brainSpeakPtr << std::endl;
	std::string& brainSpeakRef = brainSpeak;
	std::cout << brainSpeakRef << std::endl;
}