SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = megaphone
CXX = g++
RM = rm -f
CXXFLAGS =  -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}: ${OBJS}
	@${CXX} ${CXXFLAGS}  ${OBJS} -o ${NAME} -lpthread
clean:
	@${RM} ${OBJS}
fclean: clean
	@${RM} ${NAME}
re: fclean all

.PHONY: all clean fclean re%