#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "incorrect num of arguments" << std::endl;
        return 1;
    }
    std::string input(argv[1]);
    ScalarConverter::convert(input);
}