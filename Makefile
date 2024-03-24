NAME = so_long

src  = 		main.c\
			new_window.c\
			free_everything.c\

SRCS = $(addprefix ./mandatory/, $(src))

SRC_BONUS = 

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = ${SRC_BONUS:.c=.o}

PRINTF_A = ft_printf.a
PRINTF_DIR = lib/ft_printf/

MLX_A = libmlx.a
MLX_DIR = lib/mlx/

FT_PRINTF = $(addprefix $(PRINTF_DIR), $(PRINTF_A))

INCLUDE = includes/

.c.o :
	cc -Wall -Wextra -I/usr/include -Imlx_linux -O3 -c $< -o ${<:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
	$(MAKE) -C $(PRINTF_DIR)
	cc ${OBJS} lib/mlx/libmlx.a lib/mlx/libmlx_Linux.a -L. -lXext -L. -lX11 $(FT_PRINTF) -o $(NAME)
	@echo "____________________________________________________________________________________________________________"

bonus: $(OBJS_BONUS)
	$(MAKE) -C $(PRINTF_DIR)
	cc ${OBJS_BONUS} lib/mlx/libmlx.a lib/mlx/libmlx_Linux.a -L. -lXext -L. -lX11 $(FT_PRINTF) -o $(NAME)
	@echo "____________________________________________________________________________________________________________"

clean:
	$(MAKE) clean -C ./lib/ft_printf
	rm -f $(OBJS) ${OBJS_BONUS}
	@echo "____________________________________________________________________________________________________________"

fclean: clean
	$(MAKE) fclean -C ./lib/ft_printf
	rm -f ${NAME}
	@echo "____________________________________________________________________________________________________________"

re: fclean all

.PHONY: all clean fclean re