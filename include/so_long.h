/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:02:16 by cheyo             #+#    #+#             */
/*   Updated: 2024/12/13 02:06:43 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define BUFFER_SIZE 1000

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_textures
{
	void	*wall;
	void	*player;
	void	*collectible;
	void	*floor;
	void	*exit;
	void	*enemy;
	void	*pl;
	void	*pr;
	void	*pu;
	void	*pd;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_textures	textures;
	char		**grid;
	int			tile_size;
	int			moves;
	int			pxpos;
	int			pypos;
	int			expos;
	int			eypos;
	int			coins;
	int			visc;
	int			vise;
	int			ce;
	int			cp;
	int			cc;
	int			len;
	int			hei;
	int			tilehei;
	int			tilewit;
}	t_game;

int		openmap(int argc, char **argv);

int		load_map(int argc, char **argv, t_game *game);

void	free_grid(char **grid);
int		count_lines(int fd);

void	load_textures(t_game *game);

void	draw_grid(t_game *game);

char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strdup(const char *s1);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
size_t	gnl_strlen(const char *s);
char	*get_next_line(int fd);

int		getxpos(char **grid, char c);
int		getypos(char **grid, char c);

/*movement.c*/
int		keyhook(int keycode, t_game *game);

/*check_utils.c*/
int		countcoins(char **grid);
int		ffxsize(t_game *game);

/* map_checks.c */
int		gridcontent(char **grid);

/* count_checks.c */
int		checkep(t_game *game);

#endif