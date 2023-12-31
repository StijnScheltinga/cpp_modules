#include <string>
#include <iostream>
#include <fstream>

void	edit_line( std::string &line, std::string stringToReplace, std::string stringReplacement )
{
	size_t start_pos;

	start_pos = 0;
	while ((start_pos = line.find(stringToReplace, start_pos)) != std::string::npos)
	{
		line.erase(start_pos, stringToReplace.length());
		line.insert(start_pos, stringReplacement);
		start_pos += stringReplacement.length();
	}
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "program parameters: filename, string 1, string 2" << std::endl;
        return (1);
    }
    std::string 	filename(argv[1]);
    std::string 	stringToReplace(argv[2]);
    std::string 	stringReplacement(argv[3]);
	std::string		line;

    std::ifstream	inputfile(filename.c_str());
	if (!inputfile)
		return (1);
	std::ofstream	outputfile((filename + ".replace").c_str());
	if (!outputfile)
	{
		std::cout << "unable to open the file" << std::endl;
		return (1);
	}
	while (std::getline(inputfile, line))
	{ 
		edit_line(line, stringToReplace, stringReplacement );
		outputfile << line << std::endl;
	}
	outputfile.close();
	inputfile.close();
	return (0);
}
