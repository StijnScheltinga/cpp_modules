SOURCES     := main.cpp Animal.cpp
BUILD		:= build
OBJECTS     := $(addprefix $(BUILD)/, $(SOURCES:.cpp=.o))
NAME        := Animal

all: $(NAME)

$(NAME): $(OBJECTS)
	c++ -o $(NAME) $(OBJECTS)

$(BUILD)/%.o: %.cpp | $(BUILD)
	c++ -std=c++98 -Wall -Werror -Wextra -c $< -o $@


$(BUILD):
	@mkdir -p build

clean:
	rm -rf $(OBJECTS) $(BUILD)

fclean: clean
	rm -rf $(NAME)

re: fclean all