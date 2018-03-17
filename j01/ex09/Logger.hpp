#ifndef LOGGER_H
# define LOGGER_H

# include <string>

class Logger {
	private:
		void logToConsole( std::string msg );
		void logToFile( std::string msg );
		std::string makeLogEntry( std::string msg );
	public:
		void log(std::string const & dest, std::string const & message);
};

#endif