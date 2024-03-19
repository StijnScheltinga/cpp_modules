#ifndef DATA_HPP
# define DATA_HPP

class Data
{
	private:
		int value;
	public:
		Data(int value);
		~Data();
		Data(const Data& copy);
		Data& operator=(const Data& copy);
		int	getValue(void) const;
};

#endif