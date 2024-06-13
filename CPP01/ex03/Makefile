NAME		=	weapon

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJS		=	${SRCS:.cpp=.o}

HEADERS		=	Weapon.hpp HumanA.hpp HumanB.hpp

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