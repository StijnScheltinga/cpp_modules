#include <string>
#include <iostream>

int main(void)
{
    std::string		str = "HI THIS IS BRAIN";
    std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "memaddress string: " << &str << std::endl;
	std::cout << "memaddress stringPTR: " << stringPTR << std::endl;
	std::cout << "memaddress stringREF: " << &stringREF << std::endl;

	std::cout << "value string: " << str << std::endl;
	std::cout << "value stringPTR: " << *stringPTR << std::endl;
	std::cout << "value stringREF: " << stringREF << std::endl;
}