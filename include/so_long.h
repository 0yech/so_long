/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:02:16 by cheyo             #+#    #+#             */
/*   Updated: 2024/11/26 11:20:05 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define BUFFER_SIZE 1000

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
} t_data;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
} t_image;

typedef struct s_map
{
	char	**grid;
	int		collectables;
	int		pos_px;
	int		pos_py;
	int		ec;
	int		pc;	
} t_map;

int		openmap(int argc, char **argv);

void	my_mlx_pixel_put(t_image *data, int x, int y, int color);

char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strdup(const char *s1);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
size_t	gnl_strlen(const char *s);
char	*get_next_line(int fd);

#endif