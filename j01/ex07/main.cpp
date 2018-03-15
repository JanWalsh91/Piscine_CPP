#include <fstream>
#include <iostream>

int main ( int ac, char ** av) {
	if (ac != 4) {
		std::cout << "Pass a file name and two strings" << std::endl;
		return (0);
	}
	std::string src(av[2]);
	std::string dst(av[3]);
	std::string filename(av[1]);

	std::ifstream is(filename);

	std::string fileContents;
	std::string line;
	if (is.is_open()) {
		while (getline(is, line)){
			fileContents += line + '\n';
		}
	}	
	is.close();

	int pos = 0;

	while (1) {
		pos = fileContents.find(src, pos);
		if (pos == -1) {
			break ;
		}
		fileContents.replace(pos, src.length(), dst);
		++pos;
	}
	
	std::ofstream os(filename + ".replace");
	os << fileContents;
	os.close();
	return (0);
}