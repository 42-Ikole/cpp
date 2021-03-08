#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main(int args, char **argv)
{
    std::ifstream	file;
	std::ofstream	replacement;
    std::string		read;
	std::string		new_file;
	size_t			loc = 0;

    if (args != 4) {
        std::cout << "invalid arguments!\n";
        return (1);
    }
	std::string		to_replace(argv[2]);
	std::string		replace_with(argv[3]);
    file.open(argv[1]);
    if (!file) {
        std::cout << "unable to open file!\n";
        return (1);
    }
	new_file.append(argv[1]);
	new_file.append(".replace");
	replacement.open(new_file, std::ios::trunc);
    if (!replacement) {
        std::cout << "unable to create file!\n";
        return (1);
    }
	while (!file.eof()) {
		if (std::getline(file, read).good() == 0) {
			if (!file.eof())
				std::cout << "getline failed" << std::endl;
		}
		loc = 0;
		while (read.find(to_replace, loc) != read.npos) {
			loc = read.find(to_replace, loc);
			if (loc == read.npos)
				break ;
			read.replace(loc, to_replace.length(), replace_with);
			loc += replace_with.length();
		}
		replacement << read;
		if (!file.eof())
			replacement << std::endl;
	}
	replacement.close();
	file.close();
}