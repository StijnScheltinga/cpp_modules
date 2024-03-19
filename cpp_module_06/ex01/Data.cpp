#include "Data.hpp"

Data::Data(int value) : value(value)
{
}

Data::~Data()
{
}

Data::Data(const Data& copy) : value(copy.getValue())
{
}

Data& Data::operator=(const Data& copy)
{
	if (this != &copy)
		value = copy.getValue();
	return *this;
}

int	Data::getValue(void) const
{
	return (this->value);
}