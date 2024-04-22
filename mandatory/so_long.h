/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:42:54 by Matprod           #+#    #+#             */
/*   Updated: 2024/04/22 17:19:06 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include "../lib/mlx/mlx.h"
# include <X11/keysym.h>
# include "../lib/ft_printf/ft_printf.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MALLOC_ERROR	1
# define ERROR  1

/*                   KEY VALUE                   */
# define ESC 65307
# define A 97
# define W 119
# define D 100
# define S 115
/*				IMAGES PATH	AND INDEX			*/

# define WALL_PATH "mandatory/Images/wall.xpm"
# define GRASS_PATH "mandatory/Images/grass64.xpm"
# define ROBOT_PATH "mandatory/Images/robot_grass.xpm"
# define COIN_PATH "mandatory/Images/coin_grass.xpm"
# define WALL2_PATH "mandatory/Images/wall2.xpm"


# define GRASS_INDEX 0
# define WALL_INDEX 1
# define ROBOT_INDEX 2
# define COIN_INDEX 3
# define WALL_INDEX2 4

# define TEXTURE_NUMBER 5
////////////////////////////////////////////////////

typedef enum
{
    FALSE = 0,
    TRUE = 1
} bool;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_player
{
	char	current;
	//char	*pos;   direction of the player
	int		x;
	int		y;
	int		move;
}				t_player;

typedef struct s_mlx_data
{
    void	*mlx;			// pointer of the mlx connection
    void	*win;			// pointer of the window
    void	*texture[5];	// [n] = number of texture
	
	char	**map;			//map
    int		img_size;   	// 64 * 64
    int		height_max;     // h * 64 in pixel
    int		width_max;      // w * 64 in pixel
    int		height;			// number of case
    int		width;          // number of case

    // ITEMS
    int			item_fill;
	int			item_total;
	int			items;			
    // PLAYER    
    t_player	player;
	t_point		start;
	t_point		end;
}				t_data;


/*				MANDATORY FUNCTIONS			*/

void	*new_window(void *mlx_connection, int height, int width, char *window_name);

int		free_everything(t_data *data);

void	free_array(char **array);

void	var_init(t_data *data);

//char	*ft_strdup(char *s);
//	MAP FUNCTION

char **fd_to_array(char *argv);

int		get_map_height(char **map);
int		get_map_width(char**map);
void 	map_len_init(t_data *data,char **map);
char	*map_array_to_string(char **map);
void	put_map_in_window(t_data *data, char **map);
// IMAGE FUNCTION
void	put_image(t_data *data, void *image, int x, int y);
void	*ft_open_xpm(t_data *data, char *path, int index);
void	img_init(t_data *data);
// GNL FUNCTION
char	*get_next_line(int fd);

char	*read_and_stock(int fd, char *stack);

size_t	ft_strlengnl(const char *s);

char	*ft_strjoin(char *s1, char const *s2);

int		ft_strchr(const char *s, int c);

char	*ft_strdup( char *s);

// ERROR
bool	check_size(t_data *data, char **map);

int     flood_fill(t_data *data);

bool check_error(t_data *data, char **map);

// MOVE
void	move(t_data *data, char *direction);

int	key_gestion(int keycode, t_data *data);


//UTILS

int		ft_strcmp(char *s1, char *s2);

void	item_collect(t_data *data);

#endif