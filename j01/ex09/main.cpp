#include "Logger.hpp"

int main ( void ) {
	Logger logger;

	logger.log("logToConsole", "my donerful message");
	logger.log("logToFile", "my donerful message");
}