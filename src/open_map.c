/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:46:30 by cheyo             #+#    #+#             */
/*   Updated: 2024/12/10 00:25:40 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(char **grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	count_lines(int fd)
{
	char	*line;
	int		lines;

	lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		lines++;
		free(line);
	}
	return (lines);
}

int	parsemap(int fd, int lines)
{
	char	**grid;
	char	*line;
	int		i;

	grid = (char **)malloc(sizeof(char *) * (lines + 1));
	i = 0;
	while (i < lines)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		grid[i] = ft_strdup(line);
		free(line);
		i++;
	}
	grid[i] = NULL;
	if (!gridcontent(grid))
	{
		free_grid(grid);
		return (0);
	}
	free_grid(grid);
	return (1);
}

int	process_file(char **argv, int lines)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("File couldn't be read");
		return (0);
	}
	if (!parsemap(fd, lines))
	{
		close(fd);
		ft_printf("Failed to parse map");
		return (0);
	}
	close(fd);
	return (1);
}

int	openmap(int argc, char **argv)
{
	int	fd;
	int	lines;

	if (argc < 2 || argc > 2)
	{
		ft_printf("Usage : ./so_long 'map.ber'");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	lines = count_lines(fd);
	if (lines <= 2)
	{
		ft_printf("Map too small");
		return (0);
	}
	if (!process_file(argv, lines))
		return (0);
	close(fd);
	return (1);
}
