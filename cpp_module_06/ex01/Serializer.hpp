#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	protected:
		Serializer();
	public:
		~Serializer();
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& copy);

		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif