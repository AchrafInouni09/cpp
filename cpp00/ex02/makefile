SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = out
CXX = g++
RM = rm -f
CXXFLAGS =  -Wall -Wextra -Werror -std=c++98 -fsanitize=address

all: ${NAME}

${NAME}: ${OBJS}
	@${CXX} ${CXXFLAGS}  ${OBJS} -o ${NAME}
clean:
	@${RM} ${OBJS}
fclean: clean
	@${RM} ${NAME}
re: fclean all

.PHONY: all clean fclean re%