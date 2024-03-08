#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

    // std::cout << "char: " << c << "\n";
	// std::cout << "int: " << i << "\n";
    // std::cout << "float: " << f << "\n";
    // std::cout << "double: " << d << "\n";

void ScalarConverter::convert(std::string literal)
{
    type    type = getType(literal);
    switch (type)
    {
        case CHAR:
        {
            printChar(literal);
            break;
        }
        case INT:
        {
            printInt(literal);
            break;
        }
        case FLOAT:
        {
            printFloat(literal);
            break;
        }
        case DOUBLE:
        {
            break;
        }
        case NONE:
        {
            std::cout << "impossible" << std::endl;
            break;
        }
    }


}

type    getType(std::string literal)
{
    type    type = NONE;
    if (literal.length() == 1 && !isdigit(literal[0]) && isprint(literal[0]))
    {
        type = CHAR;
        std::cout << "type is char" << std::endl;
    }
    else if (isInt(literal))
    {
        type = INT;
        std::cout << "type is int" << std::endl;
    }
    else if (isDoubleFloat(literal) == FLOAT)
    {
        type = FLOAT;
        std::cout << "type is float" << std::endl;
    }
    else if (isDoubleFloat(literal) == DOUBLE)
    {
        type = DOUBLE;
        std::cout << "type is double" << std::endl;
    }
    return type;
}

int isInt(std::string literal)
{
    int i = 0;

    if (literal[i] == '-' || literal[i] == '+')
        i++;
    for (; literal[i]; i++)
    {
        if (!isdigit(literal[i]))
            return 0;
    }
    return 1;
}

int isDoubleFloat(std::string literal)
{
    int dotCounter = 0;
    int decimalCounter = 0;
    int i = 0;

    if (literal[0] == '-' || literal[0] == '+')
        i++;
    for (; literal[i]; i++)
    {
        if (!isdigit(literal[i]))
        {
            if (literal[i] == '.' && !dotCounter)
                dotCounter++;
            else if (dotCounter == 1 && decimalCounter > 0 && literal[i] == 'f' && !literal[i + 1])
                return FLOAT;
            else
                return 0;
        }
        else
            decimalCounter++;
    }
    if (dotCounter == 1 && decimalCounter > 0)
        return DOUBLE;
    return 0;
}

void    printChar(std::string literal)
{
    char c = literal[0];
    std::cout << "char: " << c << "\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << static_cast<float>(c) << ".0f" << "\n";
    std::cout << "double: " << static_cast<double>(c) << ".0" << "\n";
}

void    printInt(std::string literal)
{
    int i = atoi(literal.c_str());
    printChar2(i);
    std::cout << "int: " << i << "\n";
    std::cout << "float: " << static_cast<float>(i) << ".0f" << "\n";
    std::cout << "double: " << static_cast<double>(i) << ".0" << "\n";
}

void    printFloat(std::string literal)
{
    float f = atof(literal.c_str());
    printChar2(static_cast<int>(f));
    std::cout << "int: " << static_cast<int>(f) << "\n";
    std::cout << "float: " << f << "\n";
    std::cout << "double: " << static_cast<double>(f) << "\n";
}

void    printChar2(int i)
{
    std::cout << "char: ";
    if (i >= 32 && i <= 126)
        std::cout << static_cast<char>(i) << "\n";
    else if (i >= 0 && i <= 255)
        std::cout << "non displayable" << "\n";
    else
        std::cout << "impossible" << "\n";
}