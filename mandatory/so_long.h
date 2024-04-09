/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:42:54 by Matprod           #+#    #+#             */
/*   Updated: 2024/04/09 17:04:18 by mvoisin          ###   ########.fr       */
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

typedef struct s_mlx_data
{
    void	*mlx;			// pointer of the mlx connection
    void	*win;			// pointer of the window
	
    void	*texture[3];	// [n] = number of texture
    int		img_size;   	// 64 * 64
    int		height_max;     // h * 64
    int		width_max;      // w * 64
    int		height;			// number of case
    int		width;			// number of case
}				t_data;

/*				MANDATORY FUNCTIONS			*/

void	*new_window(void *mlx_connection, int height, int width, char *window_name);

void	free_everything(t_data *data);

void	free_array(char **array);

char	*ft_strdup(const char *s);
//	MAP FUNCTION

char **fd_to_array(char *argv);

int		get_map_height(char **map);
int		get_map_width(char**map);
void 	map_len_init(t_data *data,char **map);
char	*map_array_to_string(char **map);
void	put_map_in_window(t_data *data, char **map);
// IMAGE FUNCTION
void	put_image(t_data data, void *image, int x, int y);
void	*ft_open_xpm(t_data *data, char *path, int index);
void	img_init(t_data *data);
// GNL FUNCTION
char	*get_next_line(int fd);

char	*read_and_stock(int fd, char *stack);

size_t	ft_strlengnl(const char *s);

char	*ft_strjoin(char *s1, char const *s2);

int		ft_strchr(const char *s, int c);

char	*ft_strdup(const char *s);

/*				IMAGES PATH	AND INDEX			*/

#define WALL_PATH "mandatory/Images/wall.xpm"
#define GRASS_PATH "mandatory/Images/grass64.xpm"
#define ROBOT_PATH "mandatory/Images/robot.xpm"


#define GRASS_INDEX 0
#define WALL_INDEX 1
#define ROBOT_INDEX 2

#endif