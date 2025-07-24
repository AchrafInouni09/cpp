SRCS= main.cpp Base.cpp A.cpp B.cpp C.cpp
OBJS=${SRCS:.cpp=.o}
OUT= a.out
CXX=g++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
RM= rm -f


All : ${OUT}

${OUT} : ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${OUT}

clean :
	${RM} ${OBJS}
fclean : clean
	${RM} ${OUT}
re : fclean All

.PHONY: make re clean fclean
