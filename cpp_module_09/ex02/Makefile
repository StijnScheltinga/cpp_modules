SOURCES     := main.cpp PmergeMe.cpp
BUILD		:= build
OBJECTS     := $(addprefix $(BUILD)/, $(SOURCES:.cpp=.o))
NAME        := PmergeMe

all: $(NAME)

$(NAME): $(OBJECTS)
	c++ -o $(NAME) $(OBJECTS)

$(BUILD)/%.o: %.cpp | $(BUILD)
	c++ -g -std=c++11 -Wall -Wextra -Werror -c $< -o $@

$(BUILD):
	@mkdir -p build

clean:
	rm -rf $(OBJECTS) $(BUILD)

fclean: clean
	rm -rf $(NAME)

re: fclean all