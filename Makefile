# ----------------------------------------Name
NAME = libjson-parser.a

# ----------------------------------------Test
TEST = json-test

TEST_SRCS =		main.cpp \
				Jsp.cpp \

TEST_FILES =	tests/errors/*.json\
				tests/*.json \

# ----------------------------------------Files
FILES_SRCS =	Parser.cpp \
				Token.cpp \
				Node.cpp \

FILES_OBJS = $(FILES_SRCS:.cpp=.o)

# ----------------------------------------Directories
DIR_SRCS = ./src/
DIR_OBJS = ./obj/

vpath %.cpp \
	$(DIR_SRCS) \

# ----------------------------------------Sources
SRCS = $(FILES_SRCS:%=$(DIR_SRCS)%)

# ----------------------------------------Objects
OBJS = $(FILES_OBJS:%=$(DIR_OBJS)%)

# ----------------------------------------Flags
CC = c++

CFLAGS = -std=c++20
CFLAGS += -O3
CFLAGS += -Wall -Wextra -Werror
# CFLAGS += -g -fsanitize=address

INC =  -Iinc

# ----------------------------------------Making
all:
	@$(MAKE) $(NAME) -j4
.PHONY: all

$(NAME): $(DIR_OBJS) $(OBJS)
	ar -crs $(NAME) $(OBJS)

$(DIR_OBJS)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC) $(DFLAGS)

$(DIR_OBJS):
	mkdir -p $@

# ----------------------------------------Tests
$(TEST): $(NAME) $(TEST_SRCS)
	$(CC) src/main.cpp src/Jsp.cpp -o $(TEST) $(NAME) $(INC)
.PHONY: test

run-tests: $(TEST)
	./$(TEST) $(TEST_FILES)
.PHONY: run-tests

# ----------------------------------------Cleaning
clean:
	rm -f $(OBJS)
	rm -f $(TEST)
.PHONY: clean

fclean: clean
	rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re

# ----------------------------------------Util
lines:
	wc -l src/*.cpp inc/*.hpp
.PHONY: lines
