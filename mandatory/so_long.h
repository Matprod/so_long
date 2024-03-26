/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:42:54 by Matprod           #+#    #+#             */
/*   Updated: 2024/03/26 16:17:09 by mvoisin          ###   ########.fr       */
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
    void	*mlx;
    void	*win;
	
    void	*texture[2];
    int		img_size;
}				t_data;

/*				MANDATORY FUNCTIONS			*/

void	*new_window(void *mlx_connection, int height, int width, char *window_name);

void	free_everything(t_data *data);
//	MAP FUNCTION
char *fd_to_array(char *argv);
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

/*				IMAGES PATH				*/

#define GRASS_PATH "mandatory/Images/grass64.xpm"
#define WALL_PATH "mandatory/Images/wall.xpm"

#endif