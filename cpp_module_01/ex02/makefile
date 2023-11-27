SOURCES     := main.cpp

OBJECTS     := $(SOURCES:.cpp=.o)

NAME        := BRAIN

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