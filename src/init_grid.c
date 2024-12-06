/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:29:14 by cheyo             #+#    #+#             */
/*   Updated: 2024/12/06 02:45:31 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	process_exit(t_game *game)
{
	game->eypos = getypos(game->grid, 'E');
	game->expos = getxpos(game->grid, 'E');
	game->grid[game->eypos][game->expos] = '0';
}

int	fill_grid(t_game *game, int fd, int lines)
{
	char	*line;
	int		i;

	game->grid = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!game->grid)
		return (0);
	i = 0;
	while (i < lines)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		game->grid[i] = ft_strdup(line);
		free(line);
		if (!game->grid[i])
		{
			free_grid(game->grid);
			return (0);
		}
		i++;
	}
	game->grid[i] = NULL;
	return (1);
}

int	checkep(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	game->cc = 0;
	game->ce = 0;
	game->cp = 0;
	while (game->grid[i])
	{
		j = 0;
		while (game->grid[i][j])
		{
			if (game->grid[i][j] == 'E')
				game->ce++;
			else if (game->grid[i][j] == 'P')
				game->cp++;		
			else if (game->grid[i][j] == 'C')
				game->cc++;
			j++;
		}
		i++;
	}
	if (game->ce != 1 || game->cp != 1 || game->cc < 1)
		return (0);
	return (1);
}

int	map_size(t_game *game)
{
	int len;
	int i;
	int	nexlen;

	i = 0;
	while (game->grid[i + 1])
	{
		len = ft_strlen(game->grid[i]);
		nexlen = ft_strlen(game->grid[i + 1]);
		if (game->grid[i][len - 1] == '\n')
			len--;
		if (game->grid[i + 1][nexlen - 1] == '\n')
			nexlen--;
		if (len != nexlen)
			return (0);
		i++;
	}
	len = ft_strlen(game->grid[0]);
    if (game->grid[0][len - 1] == '\n')
        len--;
	game->len = len;
	game->hei = i + 1;
	return (1);
}

int	load_map(int argc, char **argv, t_game *game)
{
	int fd;
	int lines;

	fd = open(argv[1], O_RDONLY);
	lines = count_lines(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (!fill_grid(game, fd, lines) || !map_size(game))
	{
		close(fd);
		ft_printf("Error 4 : load_map func failed");
		return (0);
	}
	close(fd);
	game->vise = 0;
	game->visc = 0;
	game->pypos = getypos(game->grid, 'P');
	game->pxpos = getxpos(game->grid, 'P');
	game->coins = countcoins(game->grid);
	process_exit(game);
	return (1);
}