#ifndef LOGGER_H
# define LOGGER_H

# include <string>

class Logger {
	private:
		std::string outputFile;
		void logToConsole( std::string msg );
		void logToFile( std::string msg );
		std::string makeLogEntry( std::string msg );
	public:
		Logger( std::string outputFile );
		void log(std::string const & dest, std::string const & message);
};

#endif