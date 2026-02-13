##
## EPITECH PROJECT, 2025
## nanotekspice
## File description:
## Makefile
##

NAME = nanotekspice
SRC = main.cpp	\
	src/circuit_handler/HashMapCache.cpp \
	src/circuit_handler/Circuit.cpp \
	src/circuit_handler/AComponent.cpp \
	src/components/AndComponent.cpp \
	src/components/FalseComponent.cpp \
	src/components/TrueComponent.cpp \
	src/components/NotComponent.cpp \


OBJ = $(SRC:.cpp=.o)
CXX = clang++
CXXFLAGS = -std=c++20 -Wall -Wextra -g
CPPFLAGS = -I include

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
