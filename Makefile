NAME = so_long

src  = 		get_next_line_bonus.c\
			get_next_line_utils_bonus.c\
			image.c\
			init.c\
			free_everything.c\
			main.c\
			map_display.c\
			map_error.c\
			map_parsing.c\
			map_traverse.c\
			move_input.c\
			new_window.c\
			utils.c\


SRCS = $(addprefix ./mandatory/, $(src))
SRC_BONUS = 

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = ${SRC_BONUS:.c=.o}

PRINTF_A = ft_printf.a
PRINTF_DIR = lib/ft_printf/

MLX_A = libmlx.a
MLX_DIR = lib/mlx/

FLAGS = lib/mlx/libmlx.a lib/mlx/libmlx_Linux.a -L. -lXext -L. -lX11
FT_PRINTF = $(addprefix $(PRINTF_DIR), $(PRINTF_A))

INCLUDE = includes/

.c.o :
	cc -Wall -Wextra -I/usr/include -Imlx_linux -O3 -c $< -o ${<:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
	$(MAKE) -C $(PRINTF_DIR)
	cc ${OBJS} $(FLAGS) $(FT_PRINTF) -o $(NAME)
	@echo "____________________________________________________________________________________________________________"

bonus: $(OBJS_BONUS)
	$(MAKE) -C $(PRINTF_DIR)
	cc ${OBJS_BONUS} $(FLAGS) $(FT_PRINTF) -o $(NAME)
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