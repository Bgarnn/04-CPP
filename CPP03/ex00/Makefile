NAME		=	claptrap

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp ClapTrap.cpp

OBJS		=	${SRCS:.cpp=.o}

HEADERS		=	ClapTrap.hpp

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

${OBJS} : ${HEADERS}

.PHONY: all clean fclean re
all: ${NAME}

clean:
	@rm -rf ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all