SRC = ft_printf.c print_hex.c print_str.c print_ptr.c print_nbr.c print_unsigned_nbr.c utils_output.c

SRCS = ${SRC}

OBJS = ${SRCS:.c=.o}

NAME = ft_printf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:    ${OBJS}
		ar -rsc ${NAME} ${OBJS}


all:     ${NAME}

clean:    
		rm -f ${OBJS}

fclean:    clean;
		rm -f ${NAME}

re:		fclean all

.PHONY: all clean fclean re 