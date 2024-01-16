NAME = ex03
SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)
CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make

.PHONY: all clean fclean re
