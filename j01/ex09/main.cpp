#include "Logger.hpp"

int main ( void ) {
	Logger logger("file.txt") ;

	logger.log("logToConsole", "my wonderful message is in the console");
	logger.log("logToFile", "my wonderful message is in a file");
}