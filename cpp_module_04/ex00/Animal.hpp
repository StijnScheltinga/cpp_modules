#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        ~Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        std::string getType(void);
        void    makeSound(void);
};

#endif