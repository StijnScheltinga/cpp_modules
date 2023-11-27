SOURCES     := main.cpp

OBJECTS     := $(SOURCES:.cpp=.o)

NAME        := replace

TEST_FILE	:= test.txt

TEST_OUT	:= test.txt.replace

all: $(NAME)

$(NAME): $(OBJECTS)
	c++ -o $(NAME) $(OBJECTS)

%.o: %.cpp
	c++ -std=c++98 -Wall -Werror -Wextra -c $(SOURCES)

$(TEST_FILE):
	touch $(TEST_FILE)
	echo "this is a sentence used for testing\nlalalalalala" > $(TEST_FILE)

test: all $(TEST_FILE)
	./replace test.txt testing something

clean:
	rm -rf $(OBJECTS) $(TEST_FILE) $(TEST_OUT)

fclean: clean
	rm -rf $(NAME)

re: fclean all