SOURCES     := main.cpp Bureaucrat.cpp Form.cpp
BUILD		:= build
OBJECTS     := $(addprefix $(BUILD)/, $(SOURCES:.cpp=.o))
NAME        := Form

all: $(NAME)

$(NAME): $(OBJECTS)
	c++ -o $(NAME) $(OBJECTS)

$(BUILD)/%.o: %.cpp | $(BUILD)
	c++ -std=c++98 -g -Wall -Werror -Wextra -c $< -o $@


$(BUILD):
	@mkdir -p build

clean:
	rm -rf $(OBJECTS) $(BUILD)

fclean: clean
	rm -rf $(NAME)

re: fclean all