INC = pipex.h
SRC = *.c
RM = rm -f
NAME = pipex

all:
	cc -Wextra -Werror -Wall ${SRC} -o ${NAME} -I ${INC}
clean:
	${RM} ${NAME}
fclean: clean

re: fclean all
