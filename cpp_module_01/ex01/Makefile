SOURCES     := main.cpp Zombie.cpp zombieHorde.cpp

OBJECTS     := $(SOURCES:.cpp=.o)

NAME        := Zombie

all: $(NAME)

$(NAME): $(OBJECTS)
	c++ -o $(NAME) $(OBJECTS)

%.o: %.cpp
	c++ -std=c++98 -Wall -Werror -Wextra -c $(SOURCES)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all