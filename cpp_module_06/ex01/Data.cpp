#include "Data.hpp"

Data::Data(int value) : value(value)
{
}

Data::~Data()
{
}

int	Data::getValue(void)
{
	return (this->value);
}