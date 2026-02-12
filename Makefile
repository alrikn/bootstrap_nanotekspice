##
## EPITECH PROJECT, 2025
## nanotekspice
## File description:
## Makefile
##

NAME = nanotekspice
SRC = main.cpp	\


OBJ = $(SRC:.cpp=.o)
CXX = clang++
CXXFLAGS = -std=c++20 -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
