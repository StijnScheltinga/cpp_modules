#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

class Serializer
{
	protected:
		Serializer();
	public:
		~Serializer();
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& copy);
};

#endif