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
        Fixed( const int value );
        Fixed( const float value );
        Fixed( const Fixed& old_obj );
        void	operator=( const Fixed& old_obj );
        int		getRawBits( void ) const;
		void	setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
        bool    operator>( const Fixed& other ) const;
        bool    operator<( const Fixed& other ) const;
        bool    operator<=( const Fixed& other ) const;
        bool    operator>=( const Fixed& other ) const;
        bool    operator==( const Fixed& other ) const;
        bool    operator!=( const Fixed& other ) const;
        float 	operator+( const Fixed& other ) const;
        float 	operator-( const Fixed& other ) const;
        float 	operator*( const Fixed& other ) const;
        float 	operator/( const Fixed& other ) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif