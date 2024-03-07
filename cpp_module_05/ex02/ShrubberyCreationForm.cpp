#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("ShrubberyCreationForm", 145, 137), _target(other.getTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		this->_target = other.getTarget();
	return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return (this->_target);
}

void    ShrubberyCreationForm::executeForm(void) const
{
	std::string	filename = getTarget() + "_shrubbery.txt";
	std::ofstream	outfile(filename.c_str());
	if (!outfile.is_open())
	{
		std::cout << "failed to open file" << std::endl;
		return ;
	}

	outfile << "      ^" << std::endl;
    outfile << "     / \\" << std::endl;
    outfile << "    /   \\" << std::endl;
    outfile << "   /     \\" << std::endl;
    outfile << "  /       \\" << std::endl;
 	outfile << " /         \\" << std::endl;
	outfile << "/___________\\" << std::endl;
    outfile << "     |||" << std::endl; 
    outfile << "     |||" << std::endl;
	
	outfile.close();
}