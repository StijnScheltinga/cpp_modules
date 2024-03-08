#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <ctype.h>

typedef enum type {
    NONE,
    CHAR,
    INT,
    FLOAT,
    DOUBLE
} type;

int     isInt(std::string literal);
int     isDoubleFloat(std::string literal);
type    getType(std::string literal);

void    printChar(std::string literal);
void    printInt(std::string literal);
void    printFloat(std::string literal);
void    printDouble(std::string literal);

void    printChar2(int i);

class ScalarConverter
{
    protected:
        ScalarConverter();
    public:
        ScalarConverter(const ScalarConverter& other);
        ~ScalarConverter();
        ScalarConverter&	operator=(const ScalarConverter& other);

        static void convert(std::string literal);
};

#endif