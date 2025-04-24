SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp  WrongCat.cpp WrongAnimal.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = a.out
CXX = g++
RM = rm -f
CXXFLAGS =  -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}: ${OBJS}
	@${CXX} ${CXXFLAGS}  ${OBJS} -o ${NAME}
clean:
	@${RM} ${OBJS}
fclean: clean
	@${RM} ${NAME}
re: fclean all

.PHONY: all clean fclean re%