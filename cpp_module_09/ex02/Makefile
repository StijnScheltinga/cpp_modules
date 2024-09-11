SOURCES     := main.cpp
BUILD		:= build
OBJECTS     := $(addprefix $(BUILD)/, $(SOURCES:.cpp=.o))
NAME        := PmergeMe

all: $(NAME)

$(NAME): $(OBJECTS)
	c++ -o $(NAME) $(OBJECTS)

$(BUILD)/%.o: %.cpp | $(BUILD)
	c++ -g -std=c++11 -c $< -o $@

$(BUILD):
	@mkdir -p build

clean:
	rm -rf $(OBJECTS) $(BUILD)

fclean: clean
	rm -rf $(NAME)

re: fclean all