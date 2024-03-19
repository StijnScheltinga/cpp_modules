#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main(void)
{
	Data	*data = new Data(1234);

	std::cout << "data value: " << data->getValue() << std::endl;
	std::cout << "data address: " << data << std::endl;

	uintptr_t serialNumber = Serializer::serialize(data);

	std::cout << "serial number uintptr_t: " << serialNumber << std::endl;

	data = Serializer::deserialize(serialNumber);

	std::cout << "data value after converting: " << data->getValue() << std::endl;
	std::cout << "data address after converting:  " << data << std::endl;
}