SRCS = Form.cpp Bureaucrat.cpp  ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
		    PresidentialPardonForm.cpp main.cpp  Intern.cpp
OBJS = ${SRCS:.cpp=.o}
OUT = a.out
CXX = g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
RM= rm -f

all : ${OUT}

${OUT} : ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${OUT}

clean:
	${RM} ${OBJS}
fclean : clean
	 ${RM} ${OUT}
re : fclean all

.PHONY : make re clean fclean

