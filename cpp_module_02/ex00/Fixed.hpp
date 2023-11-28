#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
    private:
        int                 value;
        static const int    n_fractional_bits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& old_obj);
        void	operator=( const Fixed& old_obj );
        int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif