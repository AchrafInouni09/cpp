SRCS= Bureaucrat.cpp main.cpp Form.cpp
OBJS= ${SRCS:.cpp=.o}
CXX= g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
OUT= a.out
RM = rm -rf

all : ${OUT}

${OUT} : ${OBJS}
	${CXX}  ${CXXFLAGS}    ${OBJS}  -o  ${OUT}

clean:
	${RM} ${OBJS}
re: fclean all

fclean: clean
	${RM} ${OUT}

.PHONY: clean fclean re make
