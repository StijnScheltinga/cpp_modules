#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>
# include <iostream>

class Cat: public Animal
{
    private:
        Brain   *_Brain;
    public:
        Cat();
        ~Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        void    makeSound(void) const;
};

#endif