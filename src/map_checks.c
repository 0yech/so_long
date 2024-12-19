/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:11:06 by cheyo             #+#    #+#             */
/*   Updated: 2024/12/13 01:45:11 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validchar(char **grid)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (!(grid[i][j] == '1' || grid[i][j] == '0' ||
				grid[i][j] == 'C' || grid[i][j] == 'P' ||
				grid[i][j] == 'Z' ||
				grid[i][j] == 'E' || grid[i][j] == '\n'))
			{
				ft_printf("yob");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_top_bottom_walls(char **grid, int last_row)
{
	int	j;

	j = 0;
	while (grid[0][j] && grid[last_row][j])
	{
		if (grid[0][j] != '1' || grid[last_row][j] != '1')
		{
			ft_printf("err1");
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_side_walls(char **grid, int last_row)
{
	int	i;
	int	len;

	len = ft_strlen(grid[0]);
	i = 1;
	while (i < last_row)
	{
		if (grid[i][0] != '1' || grid[i][len - 2] != '1')
		{
			ft_printf("err2\n%d %s", len - 2, grid[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	gridcontent(char **grid)
{
	int	last_row;

	last_row = 0;
	while (grid[last_row])
		last_row++;
	last_row--;
	if (!check_top_bottom_walls(grid, last_row))
		return (0);
	if (!check_side_walls(grid, last_row))
		return (0);
	if (!validchar(grid))
		return (0);
	return (1);
}
