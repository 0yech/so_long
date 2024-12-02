/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:29:14 by cheyo             #+#    #+#             */
/*   Updated: 2024/11/30 19:36:55 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			break;
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

int	load_map(int argc, char **argv, t_game *game)
{
	int fd;
	int lines;

	fd = open(argv[1], O_RDONLY);
	lines = count_lines(fd);
	fd = open(argv[1], O_RDONLY);
	if (!fill_grid(game, fd, lines))
	{
		close(fd);
		ft_printf("Error 4 : load_map func failed");
		return (0);
	}
	close(fd);
	return (1); // Returns 1
}