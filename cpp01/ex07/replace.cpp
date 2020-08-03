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
	std::string		to_replace (argv[2]);
	std::string		replace_with (argv[3]);

    if (args != 4) {
        std::cout << "invalid arguments!\n";
        return (1);
    }
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
			std::cout << "getline failed" << std::endl;
		}
		while (read.find(to_replace) != (size_t)-1)
			read.replace(read.find(to_replace), to_replace.length(), replace_with);
		replacement << read;
		if (!file.eof())
			replacement << std::endl;
	}
	replacement.close();
	file.close();
}