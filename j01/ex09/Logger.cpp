#include "Logger.hpp"

#include <iostream>
#include <fstream>
#include <ctime>

void Logger::logToConsole( std::string msg ) {
	std::cout << msg << std::endl;
};

void Logger::logToFile( std::string msg ) {
	std::string filename = "file.txt";

	std::ofstream os(filename);

	os << msg;

	os.close();
};

std::string Logger::makeLogEntry( std::string msg ) {
	time_t t = time(0);
    struct tm * now = localtime( & t );
    return ("[" 
			+ std::to_string(now->tm_year + 1900)
			+ (now->tm_mon + 1 < 10 ? "0" : "")
			+ std::to_string(now->tm_mon + 1)
			+ std::to_string(now->tm_mday)
			+ "_"
			+ std::to_string(now->tm_hour)
			+ std::to_string(now->tm_min)
			+ std::to_string(now->tm_sec)
			+ "] "
			+ msg);
};

void Logger::log(std::string const & dest, std::string const & message) {
	std::string actionNames[] = {"logToConsole", "logToFile"};
	typedef void (Logger::*Actions)( std::string msg );
	Actions actions[2] = { &Logger::logToConsole, &Logger::logToFile };
	for (int i = 0; i < 2; i++) {
		if (dest == actionNames[i]) {
			(this->*(actions[i]))( message );
		}
	}
};