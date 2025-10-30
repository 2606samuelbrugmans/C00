#include "Sed.hpp"

Sed::Sed(std::string file, std::string str1, std::string str2)
	: filename(file), s1(str1), s2(str2)
{}

Sed::~Sed() {}

void Sed::replace()
{
	if (s1.empty())
		return;

	if (filename.empty()) {
		std::cerr << "Error: Filename cannot be empty" << std::endl;
		return;
	}

	std::ifstream infile(filename.c_str());
	if (!infile.is_open()) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return;
	}

	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: Could not create output file" << std::endl;
		infile.close();
		return;
	}

	std::string line;
	while (std::getline(infile, line)) {
		size_t pos = 0;

		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outfile << line << std::endl;
	}

	infile.close();
	outfile.close();
}